#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <numeric>
#include <optional>
#include <vector>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
// Find minimum spanning tree and check if all nodes are in the same component at the end

class Graph {
    struct Road {
        int64_t cost;
        int src;
        int dst;
        Road() = default;
        Road(int64_t a, int b, int c)
            : cost(a)
            , src(b)
            , dst(c) {
        }
        auto operator<(Road const& other) const -> bool {
            return std::tie(cost, src, dst) < std::tie(other.cost, other.src, other.dst);
        }
    };
    size_t size;
    std::vector<Road> edges;
    // link[x] -> next element towards representitive, sz[x] -> Size of component
    std::vector<int> link;
    std::vector<int> sz;
    int64_t total_cost = 0;

public:
    Graph() = default;
    Graph(size_t n)
        : size(n)
        , link(n + 1)
        , sz(n + 1, 1) {
        std::iota(link.begin(), link.end(), 0);
    }
    void add(int64_t a, int b, int c) {
        edges.emplace_back(a, b, c);
    }

    auto get_cost() -> std::optional<int64_t> {
        if (!has_answer()) {
            return std::nullopt;
        }
        return total_cost;
    }

private:
    auto find(int x) -> int {
        if (x == link[x]) {
            return x;
        }
        return link[x] = find(link[x]);
    }
    auto same(int a, int b) -> bool {
        return find(a) == find(b);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (sz[a] < sz[b]) {
            std::swap(a, b);
        }
        sz[a] += sz[b];
        link[b] = a;
    }

    void disjoint() {
        sort(edges.begin(), edges.end());
        for (auto const& [cost, src, dst] : edges) {
            if (!same(src, dst)) {
                unite(src, dst);
                total_cost += cost;
            }
        }
    }

    auto has_answer() -> bool {
        disjoint();
        for (size_t i = 2; i <= size; i++) {
            if (!same(1, i)) {
                return false;
            }
        }
        return true;
    }
};

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    auto grahp = std::make_unique<Graph>(n);
    while (m-- != 0) {
        int a;
        int b;
        int64_t c;
        std::cin >> a >> b >> c;
        grahp->add(c, a, b);
    }
    auto result = grahp->get_cost();
    if (!result.has_value()) {
        std::cout << "IMPOSSIBLE\n";
    } else {
        std::cout << result.value() << '\n';
    }
}
