#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
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

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    vector<string> ans(m);

    for (int i = 0; i < m;) {
        int j = i;
        while (j < m && edges[j].w == edges[i].w) ++j;

        // Сначала проверяем все рёбра в группе [i, j)
        for (int k = i; k < j; ++k) {
            int u = dsu.find(edges[k].u);
            int v = dsu.find(edges[k].v);
            if (u == v) {
                ans[edges[k].idx] = "NO";
            } else {
                ans[edges[k].idx] = "YES";
            }
        }

        // Теперь объединяем
        for (int k = i; k < j; ++k) {
            dsu.unite(edges[k].u, edges[k].v);
        }

        i = j;
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
