#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <vector>

static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Graph {
private:
    using Pair = std::pair<int64_t, int64_t>;
    size_t size;
    std::vector<std::vector<Pair>> adj_list;
    std::vector<int64_t> dist;

public:
    Graph(size_t n)
        : size(n)
        , adj_list(2 * n)
        , dist(2 * n, std::numeric_limits<int64_t>::max()) {
    }
    void add(int64_t a, int64_t b, int64_t w) {
        a--;
        b--;
        adj_list[a].emplace_back(b, w);
        adj_list[a + size].emplace_back(b + size, w);
        adj_list[a].emplace_back(b + size, w / 2);
    }

    auto get_discount() -> int64_t {
        dijkstra();
        return dist.back();
    }

private:
    void dijkstra() {
        dist[0] = 0;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<>> queue;
        for (queue.emplace(0, 0); !queue.empty(); queue.pop()) {
            auto [d, v] = queue.top();
            if (dist[v] < d) {
                continue;
            }
            for (auto const& [x, y] : adj_list[v]) {
                if (dist[x] > d + y) {
                    dist[x] = d + y;
                    queue.emplace(dist[x], x);
                }
            }
        }
    }
};
auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    auto grahp = std::make_unique<Graph>(n);
    while (m-- != 0) {
        int64_t a;
        int64_t b;
        int64_t c;
        std::cin >> a >> b >> c;
        grahp->add(a, b, c);
    }
    std::cout << grahp->get_discount() << '\n';
}
