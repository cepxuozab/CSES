/**
 * @brief Find tree centroid.
 * @link https://cses.fi/problemset/task/2079
 * @date 14.01.2024
 */
#include <iostream>
#include <vector>
#include <span>
#include <ranges>
#include <numeric>


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

int Centroid(int n, std::span<Edge> edges) {
    std::vector<std::vector<int>> adj_list(n);
    for (auto const &[from, to]: edges) {
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    std::vector<int> prev(n, -1);
    std::vector<int> size(n);
    auto dfs = [&](auto &&self, int u) -> void {
        size[u] = 1;
        for (int v: adj_list[u]) {
            if (v != prev[u]) {
                prev[v] = u;
                self(self, v);
                size[u] += size[v];
            }
        }
    };
    dfs(dfs, 0);
    for (int i: std::ranges::views::iota(0, n)) {
        bool isCentroid = true;
        if (prev[i] != -1 && n - size[i] > n / 2)
            isCentroid = false;

        for (int v: adj_list[i])
            if (v != prev[i] && size[v] > n / 2)
                isCentroid = false;

        if (isCentroid) {
            return i + 1;
        }
    }
    return -1;
}


void Test();

int main() {
    Test();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    auto edges = ReadEdges(n);
    std::cout << Centroid(n, edges);
    return 0;
}

#include <cassert>

void Test() {
    std::vector<Edge> edges{
            {1, 2},
            {2, 3},
            {3, 4},
            {3, 5}
    };
    assert(Centroid(5, edges) == 3);
}
