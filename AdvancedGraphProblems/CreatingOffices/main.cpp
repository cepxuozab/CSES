#include <bits/stdc++.h>

using namespace std;


auto main() -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    const int inf = 1e8;
    vector<int> depth(n), min_depth_took(n, inf);
    vector<int> candid(n);
    vector<bool> used(n);
    auto dfs = [&](auto &&self, int u, int p) -> void {
        candid[u] = u;
        for (int v: adj[u]) {
            if (v == p)
                continue;
            depth[v] = depth[u] + 1;
            self(self, v, u);
            min_depth_took[u] = min(min_depth_took[u], min_depth_took[v]);
            if (candid[v] == -1)
                continue;
            if (2 * (depth[candid[v]] - depth[u]) >= k) {
                used[candid[v]] = true;
                min_depth_took[u] = min(min_depth_took[u], depth[candid[v]]);
            } else if (depth[candid[v]] > depth[candid[u]]) {
                candid[u] = candid[v];
            }
        }
        if (min_depth_took[u] - depth[u] + depth[candid[u]] - depth[u] < k)
            candid[u] = -1;
    };
    dfs(dfs, 0, 0);
    if (candid[0] != -1)
        used[candid[0]] = true;
    int out = 0;
    for (int i = 0; i < n; i++)
        out += used[i];
    cout << out << '\n';
    for (int i = 0; i < n; i++)
        if (used[i])
            cout << i + 1 << ' ';
    return 0;
}
