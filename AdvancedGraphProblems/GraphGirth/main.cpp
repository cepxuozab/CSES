#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Graph {
    std::vector<std::vector<int>> adj_list;
    std::vector<bool> visited;
    std::vector<int> dist;
    std::vector<int> parent;
    int best;
    std::vector<int> leaves;

public:
    explicit Graph(int n)
        : adj_list(n)
        , visited(n)
        , dist(n)
        , parent(n)
        , best(n + 1) {
    }
    void AddEdges(std::vector<std::pair<int, int>> const& edges) {
        for (auto const& [from, to] : edges) {
            adj_list[from - 1].push_back(to - 1);
            adj_list[to - 1].push_back(from - 1);
        }
    }
    auto LengthShortedCycle() -> int {
        for (size_t i = 0; i < adj_list.size(); ++i) {
            Reset();
            Bfs(i);
        }
        return best;
    }

private:
    void Reset() {
        std::fill(visited.begin(), visited.end(), false);
        std::fill(dist.begin(), dist.end(), 0);
        std::fill(parent.begin(), parent.end(), -1);
    }
    void Bfs(int start) {
        std::queue<int> queue;
        queue.push(start);
        visited[start] = true;
        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            for (int v : adj_list[u]) {
                if (!visited[v]) {
                    dist[v] = dist[u] + 1;
                    visited[v] = true;
                    parent[v] = u;
                    queue.push(v);
                } else if (v != parent[u]) {
                    best = std::min(best, dist[u] + dist[v] + 1);
                }
            }
        }
    }
};

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, int>> edges(m);
    for (auto& [u, v] : edges) {
        std::cin >> u >> v;
    }
    auto graph = Graph(n);
    graph.AddEdges(edges);
    auto ans = graph.LengthShortedCycle();
    ans = ans == n + 1 ? -1 : ans;
    std::cout << ans;
}