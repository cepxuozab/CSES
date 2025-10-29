#include <iostream>
#include <vector>
#include <cstdint>

struct Line {
    int64_t k, b;

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

        if (mid) std::swap(tree[node], nw);

        if (l == r) return;

        if (left != mid)
            add_line_internal(nw, node * 2, l, m);
        else
            add_line_internal(nw, node * 2 + 1, m + 1, r);
    }

    void add_segment_internal(Line nw, int node, int64_t l, int64_t r, int64_t ql, int64_t qr) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            add_line_internal(nw, node, l, r);
            return;
        }
        int64_t m = (l + r) / 2;
        add_segment_internal(nw, node * 2, l, m, ql, qr);
        add_segment_internal(nw, node * 2 + 1, m + 1, r, ql, qr);
    }

    [[nodiscard]] auto query_internal(int64_t x, int node, int64_t l, int64_t r) const -> int64_t {
        int64_t cur = hasLine[node] ? tree[node].eval(x) : -INF;
        if (l == r) return cur;
        int64_t m = (l + r) / 2;
        if (x <= m)
            return std::max(cur, query_internal(x, node * 2, l, m));
        else
            return std::max(cur, query_internal(x, node * 2 + 1, m + 1, r));
    }

public:
    LiChaoTree(int64_t size) : n(size) {
        tree.resize(4 * (n + 1));
        hasLine.assign(4 * (n + 1), false);
    }

    void add_segment(Line nw, int64_t l, int64_t r) {
        add_segment_internal(nw, 1, 0, n, l, r);
    }

    [[nodiscard]] auto query(int64_t x) const -> int64_t { return query_internal(x, 1, 0, n); }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t n, m;
    std::cin >> n >> m;

    LiChaoTree cht(m);

    for (int i = 0; i < n; ++i) {
        int64_t x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        int64_t k = (y2 - y1) / (x2 - x1);
        int64_t b = y1 - k * x1;

        cht.add_segment({.k=k, .b=b}, x1, x2);
    }

    for (int64_t x = 0; x <= m; ++x) {
        int64_t val = cht.query(x);
        if (val < -(1LL << 61)) val = -1;
        std::cout << val << ' ';
    }

    return 0;
}