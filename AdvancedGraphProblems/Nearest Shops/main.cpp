#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> isShop(n + 1, false);
    vector<int> shops(k);
    for (int i = 0; i < k; i++) {
        cin >> shops[i];
        isShop[shops[i]] = true;
    }

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.emplace_back(a, b);
    }

    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    vector<int> source(n + 1, -1); // -1 means not reached
    queue<int> q;

    for (int shop: shops) {
        dist[shop] = 0;
        source[shop] = shop;
        q.push(shop);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                source[v] = source[u];
                q.push(v);
            }
        }
    }

    vector<int> ans(n + 1, INF);
    // For non-shop cities, ans will be dist[city]
    // For shop cities, we will compute using edges

    for (auto [u, v]: edges) {
        if (source[u] != -1 && source[v] != -1 && source[u] != source[v]) {
            int candidate = dist[u] + 1 + dist[v];
            ans[source[u]] = min(ans[source[u]], candidate);
            ans[source[v]] = min(ans[source[v]], candidate);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!isShop[i]) {
            if (dist[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << dist[i] << " ";
            }
        } else {
            if (ans[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << ans[i] << " ";
            }
        }
    }
    cout << "\n";
}
