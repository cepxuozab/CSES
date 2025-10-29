#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        parent[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    struct Edge {
        int u, v, w, idx;
    };
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
        edges[i].idx = i;
    }

    // Step 1: Build MST using Kruskal
    vector<Edge> sorted_edges = edges;
    sort(sorted_edges.begin(), sorted_edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    vector<vector<pair<int, long long>>> tree(n); // to, weight
    long long mst_weight = 0;

    for (const auto &e: sorted_edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            tree[e.u].emplace_back(e.v, e.w);
            tree[e.v].emplace_back(e.u, e.w);
        }
    }

    // Step 2: Preprocess LCA with max edge on path
    const int LOG = 18;
    vector<vector<int>> parent(LOG, vector<int>(n, -1));
    vector<vector<long long>> maxEdge(LOG, vector<long long>(n, 0));
    vector<int> depth(n, -1);

    // DFS from root 0
    depth[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, w]: tree[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                parent[0][v] = u;
                maxEdge[0][v] = w;
                q.push(v);
            }
        }
    }

    // Build binary lifting table
    for (int k = 1; k < LOG; ++k) {
        for (int v = 0; v < n; ++v) {
            int mid = parent[k - 1][v];
            if (mid != -1) {
                parent[k][v] = parent[k - 1][mid];
                maxEdge[k][v] = max(maxEdge[k - 1][v], maxEdge[k - 1][mid]);
            } else {
                parent[k][v] = -1;
                maxEdge[k][v] = maxEdge[k - 1][v]; // or 0, but won't be used
            }
        }
    }

    // Function to compute max edge on path u-v
    auto maxOnPath = [&](int u, int v) -> long long {
        if (depth[u] < depth[v]) swap(u, v);
        long long res = 0;

        // Lift u to depth of v
        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; ++k) {
            if (diff & (1 << k)) {
                res = max(res, maxEdge[k][u]);
                u = parent[k][u];
            }
        }

        if (u == v) return res;

        // Lift both until just below LCA
        for (int k = LOG - 1; k >= 0; --k) {
            if (parent[k][u] != parent[k][v]) {
                res = max({res, maxEdge[k][u], maxEdge[k][v]});
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        // Now u and v are children of LCA
        res = max({res, maxEdge[0][u], maxEdge[0][v]});
        return res;
    };

    // Step 3: Answer for each edge
    vector<long long> ans(m);
    for (int i = 0; i < m; ++i) {
        long long max_on_path = maxOnPath(edges[i].u, edges[i].v);
        ans[edges[i].idx] = mst_weight + edges[i].w - max_on_path;
    }

    for (long long x: ans) {
        cout << x << '\n';
    }

    return 0;
}