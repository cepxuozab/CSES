#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <optional>
#include <vector>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr int64_t INFINITY = 1LL << 60;

class Graph {
private:
    size_t size;
    std::vector<std::vector<int64_t>> graph;

public:
    Graph() = default;

    Graph(size_t n)
            : size(n + 1), graph(n + 1, std::vector<int64_t>(n + 1, INFINITY)) {
    }

    void add(int64_t a, int64_t b, int64_t c) {
        graph[a][b] = graph[b][a] = std::min<int64_t>(graph[a][b], c);
    }

    auto get_route(int i, int j) -> std::optional<int64_t> {
        if (graph[i][j] < INFINITY) {
            return graph[i][j];
        }
        return std::nullopt;
    }

    void floydWarshall() {
        for (size_t i = 0; i < size; ++i) {
            graph[i][i] = 0;
        }
        for (size_t k = 1; k < size; ++k) {
            for (size_t i = 1; i < size; ++i) {
                for (size_t j = 1; j < size; ++j) {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
};

void process(std::istream &input = std::cin) {
    int n;
    int m;
    int query;
    input >> n >> m >> query;
    auto graph = std::make_unique<Graph>(n);
    while (m-- != 0) {
        int a;
        int b;
        int c;
        input >> a >> b >> c;
        graph->add(a, b, c);
    }
    graph->floydWarshall();
    while (query-- != 0) {
        int a;
        int b;
        input >> a >> b;
        auto result = graph->get_route(a, b);
        if (result.has_value()) {
            std::cout << result.value() << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
}

auto main() -> int {
    process();
}