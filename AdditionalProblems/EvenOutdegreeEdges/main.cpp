#include <iostream>
#include <utility>
#include <vector>

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n + 1);
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<int> vis(n + 1);
    int timer = 1;
    std::vector<bool> odd(n + 1);

    std::vector<std::pair<int, int>> ans;
    auto DFS = [&](auto&& self, int s, int v) -> void {
        vis[s] = timer++;
        for (int u : adj[s]) {
            if (u == v) continue;

            if (!vis[u]) {
                self(self, u, s);

                if (odd[u]) {
                    ans.emplace_back(u, s);
                    odd[u] = false;
                } else {
                    ans.emplace_back(s, u);
                    odd[s] = !odd[s];
                }
            } else if (vis[u] < vis[s]) {
                ans.emplace_back(u, s);
                odd[u] = !odd[u];
            }
        }
    };

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        DFS(DFS, i, 0);
        if (odd[i]) {
            std::cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    for (auto const& [first, second] : ans) std::cout << first << ' ' << second << '\n';
}