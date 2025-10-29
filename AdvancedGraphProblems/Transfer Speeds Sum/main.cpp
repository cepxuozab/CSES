#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> parent;
    vector<long long> size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    struct Edge {
        int u, v, w;
    };
    vector<Edge> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    // Sort by weight DESCENDING
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w > b.w;
    });

    DSU dsu(n);
    long long ans = 0;

    for (const auto &e: edges) {
        int ru = dsu.find(e.u);
        int rv = dsu.find(e.v);
        ans += 1LL * e.w * dsu.size[ru] * dsu.size[rv];
        dsu.unite(ru, rv);
    }

    cout << ans << '\n';

    return 0;
}
