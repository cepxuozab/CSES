/**
* @brief Pizzeria Queries
 * @link https://cses.fi/problemset/task/2205/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <limits>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class SegmentTree {
    const int INF = std::numeric_limits<int>::max();
    int size;
    std::vector<int> tree;
public:
    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2ULL * size, INF);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    auto getMin(int l, int r) -> int {
        return getMin(l, r, 0, 0, size);
    }

private:

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }

        int left = 2 * x + 1, right = 2 * x + 2, m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, left, lx, m);
        } else {
            set(i, v, right, m, rx);
        }
        tree[x] = std::min(tree[left], tree[right]);

    }

    auto getMin(int l, int r, int x, int lx, int rx) -> int {
        if (lx >= r || rx <= l) return INF;
        if (lx >= l && rx <= r) return tree[x];

        int left = 2 * x + 1, right = 2 * x + 2, m = (lx + rx) / 2;
        int min1 = getMin(l, r, left, lx, m);
        int min2 = getMin(l, r, right, m, rx);
        return std::min(min1, min2);
    }
};

auto main() -> int { 
    int n, q;
    std::cin >> n >> q;
    SegmentTree st1(n), st2(n);

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        st1.set(i, x - i);
        st2.set(i, x + i);
    }

    while (q--) {
        int op;
        std::cin >> op;

        if (op == 1) {
            int k, x;
            std::cin >> k >> x;
            --k;
            st1.set(k, x - k);
            st2.set(k, x + k);
        } else {
            int k;
            std::cin >> k;
            --k;
            int min1 = st1.getMin(0, k) + k;
            int min2 = st2.getMin(k, n) - k;
            std::cout << std::min(min1, min2) << "\n";
        }
    }
}