#include <iostream>
#include <vector>
#include <algorithm>

class SegTree {
    struct Node {
        int maxs{}, mins{}, addv{};

        void Add(int v) {
            maxs += v;
            mins += v;
            addv += v;
        }
    };

    int n;
    std::vector<Node> tree;
public:
    explicit SegTree(int _n) : n(_n), tree(4 * _n + 2) {}

    void PushDown(int o) {
        int &a = tree[o].addv;
        if (a != 0) {
            tree[2LL * o].Add(a);
            tree[2LL * o + 1].Add(a);
            a = 0;
        }
    }

    void Add(int aL, int aR, int v, int o = 1, int L = 1, int R = -1) {
        if (R == -1) R = n;
        int lc = 2 * o;
        int rc = 2 * o + 1;
        int m = (L + R) / 2;
        auto &x = tree[o];
        auto &lx = tree[lc];
        auto &rx = tree[rc];
        if (aL <= L && R <= aR) { return x.Add(v); }
        PushDown(o);
        if (aL <= m) { Add(aL, aR, v, lc, L, m); }
        if (aR > m) { Add(aL, aR, v, rc, m + 1, R); }
        x.maxs = std::max(lx.maxs, rx.maxs);
        x.mins = std::min(lx.mins, rx.mins);
    }

    [[nodiscard]] auto GetMax() const {
        return tree[1].maxs;
    }

    [[nodiscard]] auto GetMin() const {
        return tree[1].mins;
    }
};

auto main() -> int {
    int n;
    std::cin >> n;
    SegTree segtree(n);
    for (int i = 1; i <= n; ++i) {
        int c, s;
        std::cin >> c >> s;
        segtree.Add(1, c, (s == 1 ? 1 : -1));
        if (segtree.GetMax() <= 0) {
            puts("<");
        } else if (segtree.GetMin() >= 0) {
            puts(">");
        } else {
            puts("?");
        }
    }
}