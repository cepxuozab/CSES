#include <iostream>
#include <vector>

auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj_list(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    std::vector<bool> visited(n + 1);
    std::vector<std::pair<int, int>> edges;
    std::vector<int> dp(n + 1), dep(n + 1);

    auto dfs = [&](auto &&self, int node, int pai) -> void {
        dep[node] = dep[pai] + 1;
        visited[node] = true;
        for (int x: adj_list[node]) {
            if (x == pai) continue;
            if (visited[x]) {
                if (dep[node] > dep[x]) dp[node]--;
                else dp[node]++;
            } else {
                self(self, x, node);
                dp[node] += dp[x];
            }
        }
        if (!dp[node] && node > 1) edges.emplace_back(node, pai);
    };
    dfs(dfs, 1, -1);
    std::cout << edges.size() << '\n';
    for (auto x: edges) std::cout << x.first << ' ' << x.second << '\n';
}