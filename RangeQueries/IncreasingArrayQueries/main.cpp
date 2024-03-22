#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

class SegmentTree {
    std::vector<int> data;
    std::vector<std::vector<int64_t>> tree, pref;
    std::vector<int64_t> value;

public:
    explicit SegmentTree(std::vector<int> const& arr);
    [[nodiscard]] auto Query(int a, int b) const -> int64_t;

private:
    void Build(int64_t root, int64_t low, int64_t high);
    [[nodiscard]] auto Query(int64_t root, int64_t low, int64_t high, int64_t from, int64_t to,
                             int64_t st) const -> std::pair<int64_t, int64_t>;
};

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int q;
    std::cin >> q;
    std::vector<int> arr(n);
    for (int& elem : arr) {
        std::cin >> elem;
    }
    auto const seg_tree = SegmentTree(arr);
    for (int i = 0; i < q; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << seg_tree.Query(a, b) << '\n';
    }
}

SegmentTree::SegmentTree(std::vector<int> const& arr)
    : data(arr)
    , tree(4LL * arr.size())
    , pref(4LL * arr.size())
    , value(4LL * arr.size()) {
    auto n = static_cast<int64_t>(arr.size());
    Build(1, 0, n - 1);
}

void SegmentTree::Build(int64_t root, int64_t low, int64_t high) {
    if (low == high) {
        tree[root].push_back(data[low]);
        pref[root] = tree[root];
        value[root] = 0;
        return;
    }
    auto const mid = (low + high) / 2;
    auto const l = 2 * root;
    auto const r = 2 * root + 1;

    Build(l, low, mid);
    Build(r, mid + 1, high);

    value[root] = value[l] + value[r];
    tree[root] = tree[l];
    auto prev = tree[root].back();

    for (int64_t i = mid + 1, j = 0; i <= high; ++i, ++j) {
        value[root] += tree[r][j] > prev ? 0ll : prev - tree[r][j];
        tree[root].push_back(std::max(prev, tree[r][j]));
        prev = std::max(prev, tree[r][j]);
    }

    pref[root] = tree[root];
    for (size_t i = 1; i < pref[root].size(); ++i) {
        pref[root][i] += pref[root][i - 1];
    }
}

auto SegmentTree::Query(int64_t root, int64_t low, int64_t high, int64_t from, int64_t to,
                        int64_t st) const -> std::pair<int64_t, int64_t> {
    if (high < from || low > to) {
        return {0LL, st};
    }

    if (low == from && high == to) {
        auto const it = std::ranges::upper_bound(tree[root], st);
        auto const idx = std::ranges::distance(tree[root].cbegin(), it);
        auto const cost = idx * st - (idx == 0 ? 0LL : pref[root][idx - 1]);
        return {value[root] + cost, std::max(tree[root].back(), st)};
    }

    auto const mid = (low + high) / 2;
    auto const l = 2 * root;
    auto const r = 2 * root + 1;

    auto const res = Query(l, low, mid, from, std::min(to, mid), st);
    auto ans = res.first;
    auto const res2 = Query(r, mid + 1, high, std::max(from, mid + 1), to, res.second);
    ans += res2.first;
    return {ans, res2.second};
}

auto SegmentTree::Query(int a, int b) const -> int64_t {
    auto const n = static_cast<int64_t>(data.size());
    auto constexpr Min = static_cast<int64_t>(-1e12);
    return Query(1, 0, n - 1, a - 1, b - 1, Min).first;
}
