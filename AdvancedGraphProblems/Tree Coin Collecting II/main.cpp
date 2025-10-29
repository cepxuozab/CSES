#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> coin(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> coin[i];
    }

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 1) Применим "prune leaves" — удалим листья, не содержащие монет.
    vector<int> deg(n + 1);
    queue<int> qu;
    vector<char> alive(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        deg[i] = (int) g[i].size();
    }
    for (int i = 1; i <= n; ++i) {
        if (deg[i] <= 1 && coin[i] == 0) {
            qu.push(i);
            alive[i] = 0; // пометим как удалённый
        }
    }
    while (!qu.empty()) {
        int v = qu.front();
        qu.pop();
        for (int to: g[v]) {
            if (!alive[to]) continue;
            --deg[to];
            if (deg[to] <= 1 && coin[to] == 0) {
                alive[to] = 0;
                qu.push(to);
            }
        }
    }

    // Найдём количество рёбер в поддереве T (оставшиеся вершины)
    long long edgesInT = 0;
    int nodesInT = 0;
    for (int v = 1; v <= n; ++v)
        if (alive[v]) {
            ++nodesInT;
            for (int to: g[v]) if (alive[to]) ++edgesInT;
        }
    edgesInT /= 2; // считали ориентированные
    // Если нет рёбер (все монеты в одной вершине) edgesInT = 0.

    // 2) Multi-source BFS из всех вершин T, чтобы получить proj[v] и distToT[v]
    vector<int> distToT(n + 1, -1);
    vector<int> proj(n + 1, -1);
    queue<int> bfs;
    if (nodesInT == 0) {
        // случается, если totalCoins == 0, но по условию хотя бы одна монета есть
        // эта ветка на всякий случай
        for (int i = 1; i <= n; ++i) {
            distToT[i] = 0;
            proj[i] = i;
            bfs.push(i);
        }
    } else {
        for (int v = 1; v <= n; ++v) {
            if (alive[v]) {
                distToT[v] = 0;
                proj[v] = v;
                bfs.push(v);
            }
        }
        while (!bfs.empty()) {
            int v = bfs.front();
            bfs.pop();
            for (int to: g[v]) {
                if (distToT[to] == -1) {
                    distToT[to] = distToT[v] + 1;
                    proj[to] = proj[v];
                    bfs.push(to);
                }
            }
        }
    }

    // 3) Подготовка LCA (binary lifting) для быстрых dist(u,v)
    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;
    vector<int> parent(n + 1, 0), depth(n + 1, 0);
    // root tree at 1 (tree connected)
    int root = 1;
    // iterative BFS to set parent and depth
    queue<int> qv;
    qv.push(root);
    parent[root] = 0;
    depth[root] = 0;
    vector<char> seen(n + 1, 0);
    seen[root] = 1;
    while (!qv.empty()) {
        int v = qv.front();
        qv.pop();
        for (int to: g[v])
            if (!seen[to]) {
                seen[to] = 1;
                parent[to] = v;
                depth[to] = depth[v] + 1;
                qv.push(to);
            }
    }
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int v = 1; v <= n; ++v) up[0][v] = parent[v];
    for (int k = 1; k < LOG; ++k) {
        for (int v = 1; v <= n; ++v) {
            int mid = up[k - 1][v];
            up[k][v] = (mid ? up[k - 1][mid] : 0);
        }
    }
    auto lift = [&](int v, int diff) {
        for (int i = 0; i < LOG; ++i)
            if (diff & (1 << i)) {
                v = up[i][v];
                if (v == 0) break;
            }
        return v;
    };
    auto lca = [&](int a, int b) {
        if (a == 0 || b == 0) return 0;
        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        return up[0][a];
    };
    auto dist = [&](int a, int b) {
        int L = lca(a, b);
        if (L == 0) return 0; // shouldn't happen in connected tree
        return depth[a] + depth[b] - 2 * depth[L];
    };

    // 4) Обработка запросов
    // Формула: ans = distToT[a] + distToT[b] + 2*edgesInT - dist(proj[a], proj[b])
    for (int iq = 0; iq < q; ++iq) {
        int a, b;
        cin >> a >> b;
        int pa = proj[a], pb = proj[b];
        long long dproj = 0;
        if (pa != -1 && pb != -1) dproj = dist(pa, pb);
        long long ans = (long long) distToT[a] + distToT[b] + 2LL * edgesInT - dproj;
        cout << ans << '\n';
    }

    return 0;
}