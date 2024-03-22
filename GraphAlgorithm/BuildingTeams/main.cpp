#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::vector<int> ans(n + 1, 0);
    std::function<void(int, int)> dfs = [&](int now, int c) {
        ans[now] = c + 1;

        for (int u : graph[now]) {
            if (!ans[u])
                dfs(u, 1 - c);
            else if (ans[u] == ans[now]) {
                std::cout << "IMPOSSIBLE\n";
                exit(0);
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!ans[i]) dfs(i, 0);
    }
    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << ' ';
    }
}