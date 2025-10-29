#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

auto DFS(int v, int p, std::vector<std::vector<int>> const &adj,
         std::vector<int> &vis, std::vector<int> &depth, std::vector<int> &up,
         std::vector<std::array<int, 2>> &edges, bool &hasBridge) -> int {
    int count = 1;
    vis[v] = true;
    depth[v] = depth[p] + 1;
    up[v] = depth[v];
    for (int u: adj[v]) {
        if (u == p) continue;
        if (!vis[u] || depth[u] < depth[v]) {
            edges.push_back({v, u});
        }
        if (vis[u]) { //back edge
            up[v] = std::min(up[v], depth[u]);
        } else {
            count += DFS(u, v, adj, vis, depth, up, edges, hasBridge);
            up[v] = std::min(up[v], up[u]);
        }
    }
    if (up[v] == depth[v] && v != 1) {
        hasBridge = true;
    }
    return count;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1, u, v; i <= m; ++i) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    std::vector<int> vis(n + 1);
    std::vector<int> depth(n + 1);
    std::vector<int> up(n + 1);
    std::vector<std::array<int, 2>> edges;
    bool hasBridge = false;
    if (DFS(1, 0, adj, vis, depth, up, edges, hasBridge) < n || hasBridge) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (auto &[u, v]: edges) {
        std::cout << u << ' ' << v << '\n';
    }

}