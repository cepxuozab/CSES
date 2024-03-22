/**
* @brief Building Roads
 * @link https://cses.fi/problemset/task/1666/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <functional>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    int m;
    int u;
    int v;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::vector<bool> visited(n, false);
    std::vector<int> roads;
    std::function<void(int)> dfs = [&](int x) {
        visited[x] = true;
        for (int i: graph[x]) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            roads.push_back(i+1);
            dfs(i);
        }
    }
    auto const len = roads.size();
    std::cout << len - 1 << '\n';
    for (auto i = 1UL; i < len; i++) {
        std::cout << roads[i] << ' ' << roads[i-1] << '\n';
    }

}

