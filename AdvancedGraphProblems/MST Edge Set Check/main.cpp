#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n = 0) { init(n); }

    void init(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
};

struct LightDSU {
    unordered_map<int, int> parent;

    int find(int x) {
        if (!parent.count(x)) {
            parent[x] = x;
            return x;
        }
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        parent[x] = y;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    struct Edge {
        int u, v, w;
    };
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return edges[i].w < edges[j].w;
    });

    DSU dsu_global(n);
    vector<bool> can_use(m, false);
    vector<int> comp_u(m), comp_v(m);

    for (int i = 0; i < m;) {
        int j = i;
        int w = edges[idx[i]].w;
        while (j < m && edges[idx[j]].w == w) ++j;

        for (int k = i; k < j; ++k) {
            int e_id = idx[k];
            int u = edges[e_id].u;
            int v = edges[e_id].v;
            comp_u[e_id] = dsu_global.find(u);
            comp_v[e_id] = dsu_global.find(v);
            can_use[e_id] = (comp_u[e_id] != comp_v[e_id]);
        }

        for (int k = i; k < j; ++k) {
            int e_id = idx[k];
            dsu_global.unite(edges[e_id].u, edges[e_id].v);
        }

        i = j;
    }

    while (q--) {
        int k;
        cin >> k;
        vector<int> set_edges(k);
        for (int i = 0; i < k; ++i) {
            cin >> set_edges[i];
            set_edges[i]--;
        }

        // Check 1: all edges must be usable
        bool valid = true;
        for (int e_id: set_edges) {
            if (!can_use[e_id]) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "NO\n";
            continue;
        }

        // Sort by weight
        vector<pair<int, int>> list;
        for (int e_id: set_edges) {
            list.emplace_back(edges[e_id].w, e_id);
        }
        sort(list.begin(), list.end());

        // Check acyclicity in contracted graph using LightDSU
        LightDSU dsu;
        for (auto [w, e_id]: list) {
            int a = comp_u[e_id];
            int b = comp_v[e_id];
            // a != b guaranteed by can_use
            if (!dsu.unite(a, b)) {
                valid = false;
                break;
            }
        }

        cout << (valid ? "YES" : "NO") << '\n';
    }

    return 0;
}