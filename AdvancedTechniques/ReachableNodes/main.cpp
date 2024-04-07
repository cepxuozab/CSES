#include <iostream>
#include <vector>
#include <bitset>

constexpr int MAX_N = 5e4;

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    std::vector<std::bitset<MAX_N>> reach(n);
    std::vector<bool> vis(n);

    auto dfs = [&](auto &&self, int v) -> void {
        vis[v] = true;
        reach[v][v] = true;
        for (int u: g[v]) {
            if (!vis[u]) {
                self(self, u);
            }
            reach[v] |= reach[u];
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(dfs, i);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << reach[i].count() << " \n"[i == n - 1];
    }
}