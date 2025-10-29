#include <iostream>
#include <vector>
#include <memory>
#include <limits>

struct Line {
    std::int64_t k{};
    std::int64_t b{};

    [[nodiscard]] auto eval(std::int64_t x) const -> std::int64_t {
        return k * x + b;
    }
};

class LiChao {
    struct Node {
        Line line;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        explicit Node(Line l) : line(l) {}
    };

    const std::int64_t L{};
    const std::int64_t R{};
    static constexpr std::int64_t INF = (static_cast<std::int64_t>(1) << 62);
    std::unique_ptr<Node> root;

    auto add(Line nw, std::unique_ptr<Node> &node, std::int64_t l, std::int64_t r) -> void {
        if (!node) {
            node = std::make_unique<Node>(nw);
            return;
        }
        const std::int64_t m = (l + r) / 2;
        const bool leftBetter = nw.eval(l) > node->line.eval(l);
        const bool midBetter = nw.eval(m) > node->line.eval(m);

        if (midBetter) {
            std::swap(nw, node->line);
        }
        if (r - l == 0) {
            return;
        }
        if (leftBetter != midBetter) {
            add(nw, node->left, l, m);
        } else {
            add(nw, node->right, m + 1, r);
        }
    }

    [[nodiscard]] auto
    query(std::int64_t x, const std::unique_ptr<Node> &node, std::int64_t l, std::int64_t r) const -> std::int64_t {
        if (!node) {
            return -INF;
        }
        const std::int64_t res = node->line.eval(x);
        if (l == r) {
            return res;
        }
        const std::int64_t m = (l + r) / 2;
        if (x <= m) {
            return std::max(res, query(x, node->left, l, m));
        }
        return std::max(res, query(x, node->right, m + 1, r));
    }

public:
    LiChao(std::int64_t left, std::int64_t right)
            : L(left), R(right), root(nullptr) {}

    auto add_line(std::int64_t k, std::int64_t b) -> void {
        add({.k=k, .b=b}, root, L, R);
    }

    [[nodiscard]] auto get(std::int64_t x) const -> std::int64_t {
        return query(x, root, L, R);
    }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    struct Query {
        int t;
        std::int64_t a;
        std::int64_t b;
        std::int64_t x;
    };

    std::vector<Query> q(n);
    std::int64_t minX = std::numeric_limits<std::int64_t>::max();
    std::int64_t maxX = std::numeric_limits<std::int64_t>::min();

    for (int i = 0; i < n; ++i) {
        std::cin >> q[i].t;
        if (q[i].t == 1) {
            std::cin >> q[i].a >> q[i].b;
        } else {
            std::cin >> q[i].x;
            minX = std::min(minX, q[i].x);
            maxX = std::max(maxX, q[i].x);
        }
    }

    if (minX == std::numeric_limits<std::int64_t>::max()) {
        minX = 0;
        maxX = 1;
    }

    LiChao cht(minX - 5, maxX + 5);

    for (const auto &qq: q) {
        if (qq.t == 1) {
            cht.add_line(qq.a, qq.b);
        } else {
            std::cout << cht.get(qq.x) << '\n';
        }
    }

    return 0;
}
