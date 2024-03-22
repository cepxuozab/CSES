/**
 * @brief Tree Distances II
 * @link https://cses.fi/problemset/task/1133/
 * @date 14.01.2024
 */
#include <iostream>
#include <vector>
#include <span>
#include <ranges>
#include <numeric>
#include <cstdint>

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

std::vector<int64_t> TreeDistances2(int n, std::span<Edge> edges) {
    std::vector<std::vector<int>> adj_list(n);
    for (auto const &[from, to]: edges) {
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }    
    std::vector<int> size(n);
    std::vector<int64_t> down(n), up(n);
    auto dfs1 = [&](auto &&self, int u = 0, int p = -1) -> void {
        size[u] = 1;
        for (int v: adj_list[u]) {
            if (v != p) {
                self(self, v, u);
                size[u] += size[v];
                down[u] += down[v] + size[v];
            }
        }
    };
    dfs1(dfs1);
    auto dfs2 = [&](auto &&self, int u = 0, int p = -1) -> void {
        if (p != -1)
            up[u] = (up[p] + down[p]) + n - (2 * size[u] + down[u]);
        for (int v: adj_list[u])
            if (v != p)
                self(self, v, u);
    };
    dfs2(dfs2);
    std::vector<int64_t> answer;
    for (int i: std::ranges::views::iota(0, n)) {
        answer.push_back(down[i] + up[i]);

    }
    return answer;
}


void Test();

int main() {
    Test();
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    auto edges = ReadEdges(n);
    auto result = TreeDistances2(n, edges);
    for (auto &elem: result) {
        std::cout << elem << ' ';
    }

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
    std::vector<int64_t> expected{6, 9, 5, 8, 8};
    assert(TreeDistances2(5, edges) == expected);
}
