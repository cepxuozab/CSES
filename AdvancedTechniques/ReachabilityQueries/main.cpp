#include <iostream>
#include <vector>
#include <bitset>

constexpr int mx = 50000;
std::vector<int> post_order, scc, scc_post_order;

void
post_order_dfs(int curr, std::vector<int> &visited, std::vector<std::vector<int>> const &adj, std::vector<int> &order) {
    if (visited[curr]) return;
    visited[curr] = 1;
    for (auto u: adj[curr])
        post_order_dfs(u, visited, adj, order);
    order.push_back(curr);
}

void scc_dfs(int curr, std::vector<std::vector<int>> const &adj, int label) {
    if (scc[curr] != -1) return;
    scc[curr] = label;
    for (auto u: adj[curr])
        scc_dfs(u, adj, label);
}

void reachable_dfs(int curr, std::bitset<mx> &visited, std::vector<std::vector<int>> const &adj) {
    if (visited[curr]) return;
    visited[curr] = true;
    for (auto u: adj[curr])
        reachable_dfs(u, visited, adj);
}

auto main() -> int {
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<int>> adj(n), radj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    std::vector<int> visited(n, 0);
    for (int i = 0; i < n; i++)
        post_order_dfs(i, visited, adj, post_order);

    int label = 0;
    scc.resize(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        if (scc[post_order[i]] == -1) {
            scc_dfs(post_order[i], radj, label);
            label++;
        }
    }

    std::vector<std::vector<int>> scc_adj(label);
    for (int i = 0; i < n; i++) {
        for (auto u: adj[i])
            scc_adj[scc[i]].push_back(scc[u]);
    }

    std::vector<std::bitset<mx>> scc_reachable(label);
    visited = std::vector<int>(label, 0);
    for (int i = 0; i < label; i++)
        post_order_dfs(i, visited, scc_adj, scc_post_order);

    for (int i = 0; i < label; i++) {
        int s = scc_post_order[i];
        scc_reachable[s][s] = true;
        for (auto u: scc_adj[s])
            scc_reachable[s] |= scc_reachable[u];
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        std::cout << (scc_reachable[scc[a]][scc[b]] ? "YES\n" : "NO\n");
    }
}