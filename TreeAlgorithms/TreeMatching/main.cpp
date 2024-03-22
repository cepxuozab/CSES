/**
 * @brief Find maximum number of  pair matching tree.
 * @link https://cses.fi/problemset/task/1130/
 * @date 13.01.2024
 */
#include <iostream>
#include <vector>
#include <span>

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

int MaximumNumbers(int n, std::span<Edge> edges) {
    std::vector<std::vector<int>> adj_list(n);
    for (auto &[from, to]: edges) {
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    std::vector<short> used(n);
    int ans{};
    auto dfs = [&](auto &&dfs, int u, int p) -> void {
        for (int v: adj_list[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
        }
        if (p != -1 && used[p] + used[u] == 0) {
            used[u] = used[p] = 1;
            ans++;
        }
    };
    dfs(dfs, 0, -1);
    return ans;
}

void Test();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Test();
    int n;
    std::cin >> n;
    auto edges = ReadEdges(n);
    std::cout << MaximumNumbers(n, edges);
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
    assert(MaximumNumbers(5, edges) == 2);
}