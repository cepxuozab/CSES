/**
 * @brief Find tree diameter.
 * @link https://cses.fi/problemset/task/1131
 * @date 13.01.2024
 */
#include <iostream>
#include <vector>
#include <span>
#include <ranges>
#include <algorithm>

struct Edge {
    int from{}, to{};

    Edge(int a, int b) : from(a - 1), to(b - 1) {}
};

std::vector<Edge> ReadEdges(int n) {
    std::vector<Edge> edges;
    edges.reserve(n - 1);
    for (int i = 1; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        edges.emplace_back(x, y);
    }
    return edges;
}

int TreeDiameter(int n, std::span<Edge> edges) {
    std::vector<std::vector<int>> adj_list(n);
    for (auto const &[from, to]: edges) {
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    std::vector<int> dist(n);
    auto dfs = [&](auto &&dfs, int u, int p = -1) -> void {
        for (int v: adj_list[u]) {
            if (v != p) {
                dist[v] = dist[u] + 1;
                dfs(dfs, v, u);
            }
        }
    };
    dfs(dfs, 0);
    int last = static_cast<int>(std::distance(dist.begin(), std::ranges::max_element(dist)));
    dist[last] = 0;
    dfs(dfs, last);
    return *std::ranges::max_element(dist);
}

void Test();

int main() {
    Test();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    auto edges = ReadEdges(n);
    std::cout << TreeDiameter(n, edges);
    return 0;
}

#include <cassert>

void Test() {
    std::vector<Edge> edges{
            {1, 2},
            {1, 3},
            {3, 4},
            {3, 5}
    };
    assert(TreeDiameter(5, edges) == 3);
}