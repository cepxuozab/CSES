#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Precompute minDist[start][v][parity]
    // We'll store as minDist[start][v] = pair(odd, even) or two 2D arrays
    vector<vector<array<int, 2>>> minDist(n, vector<array<int, 2>>(n, {INF, INF}));

    for (int start = 0; start < n; ++start) {
        // BFS over (node, parity)
        queue<pair<int, int>> qq; // (node, parity)
        minDist[start][start][0] = 0;
        qq.emplace(start, 0);

        while (!qq.empty()) {
            auto [u, p] = qq.front();
            qq.pop();
            int d = minDist[start][u][p];
            for (int v: adj[u]) {
                int np = p ^ 1;
                if (minDist[start][v][np] == INF) {
                    minDist[start][v][np] = d + 1;
                    qq.emplace(v, np);
                }
            }
        }
    }

    while (q--) {
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        b--;
        int need_parity = x & 1;
        if (minDist[a][b][need_parity] <= x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}