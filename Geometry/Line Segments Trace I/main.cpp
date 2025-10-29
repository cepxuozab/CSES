#include <iostream>
#include <vector>
#include <cstdint>

struct Line {
    int64_t k{}, b{};

    [[nodiscard]] auto eval(int64_t x) const -> int64_t { return k * x + b; }
};

class LiChaoTree {
private:
    std::vector<Line> tree;
    std::vector<bool> hasLine;
    int64_t n;
    const int64_t INF = (1LL << 62);

    void add_line_internal(Line nw, int node, int64_t l, int64_t r) {
        if (!hasLine[node]) {
            hasLine[node] = true;
            tree[node] = nw;
            return;
        }

        int64_t m = (l + r) / 2;
        bool left = nw.eval(l) > tree[node].eval(l);
        bool mid = nw.eval(m) > tree[node].eval(m);

        if (mid) {
            std::swap(tree[node], nw);
        }

        if (l == r)
            return;

        if (left != mid) {
            add_line_internal(nw, 2 * node, l, m);
        } else {
            add_line_internal(nw, 2 * node + 1, m + 1, r);
        }
    }

    [[nodiscard]] auto query_internal(int64_t x, int node, int64_t l, int64_t r) const -> int64_t {
        int64_t cur = hasLine[node] ? tree[node].eval(x) : -INF;
        if (l == r) {
            return cur;
        }
        int64_t m = (l + r) / 2;
        if (x <= m) {
            return std::max(cur, query_internal(x, 2 * node, l, m));
        } else {
            return std::max(cur, query_internal(x, 2 * node + 1, m + 1, r));
        }
    }

public:
    LiChaoTree(int64_t size)
            : n(size) {
        tree.resize(4 * (n + 1));
        hasLine.assign(4 * (n + 1), false);
    }

    void add_line(Line nw) { add_line_internal(nw, 1, 0, n); }

    [[nodiscard]] auto query(int64_t x) const -> int64_t { return query_internal(x, 1, 0, n); }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t n, m;
    std::cin >> n >> m;

    LiChaoTree cht(m);

    for (int i = 0; i < n; ++i) {
        int64_t y1, y2;
        std::cin >> y1 >> y2;
        int64_t dy = y2 - y1;
        int64_t k = dy / m;
        cht.add_line({.k=k, .b=y1});
    }

    for (int64_t x = 0; x <= m; ++x) {
        std::cout << cht.query(x) << ' ';
    }

    return 0;
}