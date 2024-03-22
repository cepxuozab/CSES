#include <iostream>
#include <vector>

void dfs(int at, std::vector<std::vector<int>> const &graph, std::vector<bool> &visited) {
    if (visited[at])
        return;
    visited[at] = true;
    for (int v: graph[at])
        dfs(v, graph, visited);
}

auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj_list(n), rev_adj_list(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        adj_list[a].push_back(b);
        rev_adj_list[b].push_back(a);
    }
    auto visited = std::vector<bool>(n);
    dfs(0, adj_list, visited);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            std::cout << "NO" << '\n';
            std::cout << 1 << ' ' << (i + 1) << '\n';
            return 0;
        }
    }
    visited = std::vector<bool>(n);
    dfs(0, rev_adj_list, visited);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            std::cout << "NO" << '\n';
            std::cout << (i + 1) << ' ' << 1 << '\n';
            return 0;
        }
    }
    std::cout << "YES" << '\n';
}