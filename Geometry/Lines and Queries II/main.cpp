#include <iostream>
#include <vector>
#include <algorithm>
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

struct Query {
    int t;
    int64_t a, b, l, r, x;
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;

    std::vector<Query> queries(q);
    int64_t maxX = 0;

    for (int i = 0; i < q; ++i) {
        std::cin >> queries[i].t;
        if (queries[i].t == 1) {
            std::cin >> queries[i].a >> queries[i].b >> queries[i].l >> queries[i].r;
            maxX = std::max({maxX, queries[i].l, queries[i].r});
        } else {
            std::cin >> queries[i].x;
            maxX = std::max(maxX, queries[i].x);
        }
    }

    LiChaoTree cht(maxX);

    for (auto &qu: queries) {
        if (qu.t == 1) {
            cht.add_segment({qu.a, qu.b}, qu.l, qu.r);
        } else {
            int64_t val = cht.query(qu.x);
            if (val < -(1LL << 61)) std::cout << "NO\n";
            else std::cout << val << "\n";
        }
    }

    return 0;
}