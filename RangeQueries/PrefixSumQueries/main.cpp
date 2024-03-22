#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

struct Prefix {
    int64_t lsum = 0;
    int64_t sum = 0;
};

class SegTree {
    int n = 0;
    std::vector<Prefix> tree;

public:
    explicit SegTree(int const n_)
        : n(n_)
        , tree(4LL * n) {
    }

    void upd(int k, int64_t x) {
        k += n;
        tree[k] = {x, x};
        k >>= 1;
        while (k >= 1) {
            tree[k].sum = tree[2LL * k].sum + tree[2 * k + 1].sum;
            tree[k].lsum = std::max(tree[2LL * k].lsum, tree[2LL * k].sum + tree[2 * k + 1].lsum);
            k >>= 1;
        }
    }
    [[nodiscard]] auto query(int a, int b) const -> int64_t {
        a += n;
        b += n;
        Prefix x = {0, 0};
        Prefix y = {0, 0};
        while (a <= b) {
            if (a & 1) {
                x = {std::max(x.lsum, x.sum + tree[a].lsum), x.sum + tree[a++].sum};
            }
            if (~b & 1) {
                y = {std::max(tree[b].lsum, tree[b].sum + y.lsum), y.sum + tree[b--].sum};
            }
            a >>= 1;
            b >>= 1;
        }
        return std::max(x.lsum, x.sum + y.lsum);
    }
};

auto main() -> int {
    int n;
    int t;
    std::cin >> n >> t;
    auto tree = std::make_unique<SegTree>(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        tree->upd(i, x);
    }
    while (t--) {
        int x;
        int a;
        int b;
        std::cin >> x >> a >> b;
        if (x == 1) {
            tree->upd(a - 1, b);
        } else {
            std::cout << tree->query(a - 1, b - 1) << '\n';
        }
    }
}
