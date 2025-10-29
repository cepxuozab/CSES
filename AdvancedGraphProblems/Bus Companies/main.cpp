#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> costs(m);
    for (int i = 0; i < m; i++) {
        cin >> costs[i];
    }

    // Total vertices: n (cities 0..n-1) + m (companies n..n+m-1)
    vector<vector<pair<int, long long>>> adj(n + m);

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> cities(k);
        for (int j = 0; j < k; j++) {
            cin >> cities[j];
            cities[j]--; // to 0-indexed
        }

        int comp_node = n + i;
        for (int city: cities) {
            // city -> company (free)
            adj[city].emplace_back(comp_node, 0);
            // company -> city (pay ticket)
            adj[comp_node].emplace_back(city, costs[i]);
        }
    }

    const long long INF = (1LL << 60);
    vector<long long> dist(n + m, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w]: adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";
