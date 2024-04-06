#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <numeric>
#include <utility>

class WT {
    struct Node {
        std::vector<int> cnt;
        std::vector<int64_t> sm;
        int64_t l{}, r{};
        int lc = -1, rc = -1;
    };
    std::vector<Node> nodes;
    int root = 0;
public:
    explicit WT(std::vector<int64_t> const &arr) : root(Build(arr)) {
    }

    auto leq(int l, int r, int64_t v) -> int64_t { return leq(l, r, v, root); }

private:
    auto Build(std::vector<int64_t> const &a) -> int {
        if (a.empty()) return -1;
        Node my;
        my.sm.resize(a.size() + 1);
        std::partial_sum(a.begin(), a.end(), my.sm.begin() + 1);
        my.l = std::ranges::min(a);
        my.r = std::ranges::max(a);
        if (my.l < my.r) {
            auto m = (my.l + my.r) / 2;
            std::vector<int64_t> na[2];
            my.cnt.resize(a.size() + 1);
            for (int i = 0; std::cmp_less(i, a.size()); ++i) {
                na[m < a[i]].push_back(a[i]);
                my.cnt[i + 1] = my.cnt[i] + (m >= a[i]);
            }
            my.lc = Build(na[0]);
            my.rc = Build(na[1]);
        }
        nodes.emplace_back(my);
        return static_cast<int>(nodes.size()) - 1;
    }

    auto GetSum(int l, int r, int id) -> int64_t { return ~id ? nodes[id].sm[r] - nodes[id].sm[l] : 0; }

    auto leq(int l, int r, int64_t v, int id) -> int64_t {
        if (id == -1) return 0;
        auto &n = nodes[id];
        if (n.l == n.r) return n.l <= v ? GetSum(l, r, id) : 0;
        auto m = (n.l + n.r) / 2;
        return m < v ? GetSum(n.cnt[l], n.cnt[r], n.lc) + leq(l - n.cnt[l], r - n.cnt[r], v, n.rc) : leq(n.cnt[l],
                                                                                                         n.cnt[r], v,
                                                                                                         n.lc);
    }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int64_t> a(n);
    for (auto &v: a) std::cin >> v;
    WT wt(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r, --l;
        int64_t res = 1;
        for (int64_t pres = 0; pres != res;) {
            pres = res;
            res = wt.leq(l, r, pres) + 1;

        }
        std::cout << res << '\n';
    }
}