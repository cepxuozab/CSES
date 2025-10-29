#include <iostream>
#include <vector>
#include <algorithm>


class SegTree {
    int n_;
    std::vector<int> tree_;
public:
    explicit SegTree(int n) : n_(n), tree_(4ULL * n) {}

    auto RangeSum(int ql, int qr) -> int {
        return RangeSumImpl(1, 0, n_ - 1, ql, qr);
    }

    void Update(int p) {
        UpdateImpl(1, 0, n_ - 1, p);
    }

private:
    auto RangeSumImpl(int ind, int l, int r, int ql, int qr) -> int {
        if (ql <= l && r <= qr) { return tree_[ind]; }
        if (ql > r || qr < l) { return 0; }
        int m = (l + r) / 2;
        return RangeSumImpl(ind * 2, l, m, ql, qr) + RangeSumImpl(ind * 2 + 1, m + 1, r, ql, qr);
    }

    void UpdateImpl(int ind, int l, int r, int p, int t = 1) {
        if (l == r) {
            tree_[ind] = t;
            return;
        }
        int m = (l + r) / 2;
        if (p <= m) UpdateImpl(ind * 2, l, m, p, t);
        else UpdateImpl(ind * 2 + 1, m + 1, r, p, t);
        tree_[ind] = tree_[ind * 2ULL] + tree_[ind * 2ULL + 1];
    }
};

auto main() -> int {
    int n;
    std::cin >> n;
    SegTree segTree(n);
    std::vector<std::pair<int, int>> values;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        values.emplace_back(-x, i);
    }
    std::ranges::sort(values);
    long long ans = 0;
    for (auto const &[_, idx]: values) {
        ans += std::min(segTree.RangeSum(idx, n - 1), segTree.RangeSum(0, idx));
        segTree.Update(idx);
    }
    std::cout << ans;
}