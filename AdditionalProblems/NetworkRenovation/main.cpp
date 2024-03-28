#include <iostream>
#include <vector>

class Graph {
    std::vector<std::vector<int>> adj_list;
    std::vector<int> leaves;

public:
    explicit Graph(int n)
        : adj_list(n) {
    }
    void AddEdges(std::vector<std::pair<int, int>> const& edges) {
        for (auto const& [from, to] : edges) {
            adj_list[from - 1].push_back(to - 1);
            adj_list[to - 1].push_back(from - 1);
        }
    }
    auto NewConnections() -> std::vector<int> {
        Dfs();
        return leaves;
    }

private:
    void Dfs(int u = 0, int p = -1) {
        if (adj_list[u].size() == 1) {
            leaves.push_back(u + 1);
        }
        for (auto v : adj_list[u]) {
            if (v != p) {
                Dfs(v, u);
            }
        }
    }
};

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> edges(n - 1);
    for (auto& [u, v] : edges) {
        std::cin >> u >> v;
    }
    auto graph = Graph(n);
    graph.AddEdges(edges);
    auto new_connections = graph.NewConnections();
    size_t cnt = (new_connections.size() + 1) / 2;
    std::cout << cnt << '\n';
    for (size_t i = 0; i < cnt; ++i) {
        std::cout << new_connections[i] << ' ' << new_connections[i + new_connections.size() / 2]
                  << '\n';
    }
}