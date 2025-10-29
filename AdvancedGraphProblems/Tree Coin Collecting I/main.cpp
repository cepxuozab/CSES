#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> coin(n + 1);
    vector<int> coins;
    for (int i = 1; i <= n; ++i) {
        cin >> coin[i];
        if (coin[i]) coins.push_back(i);
    }
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 1) distToCoin: multi-source BFS from all coins
    vector<int> distToCoin(n + 1, INF);
    queue<int> bfs;
    for (int v: coins) {
        distToCoin[v] = 0;
        bfs.push(v);
    }
    while (!bfs.empty()) {
        int v = bfs.front();
        bfs.pop();
        for (int to: g[v]) {
            if (distToCoin[to] > distToCoin[v] + 1) {
                distToCoin[to] = distToCoin[v] + 1;
                bfs.push(to);
            }
        }
    }

    // 2) Prepare LCA (binary lifting) and depths
    int LOG = 1;
    while ((1 << LOG) <= n) ++LOG;
    vector<int> parent(n + 1, 0), depth(n + 1, 0), sz(n + 1, 0);
    // BFS to set parent and depth (tree is connected)
    {
        queue<int> qu;
        qu.push(1);
        parent[1] = 0;
        depth[1] = 0;
        vector<char> vis(n + 1, 0);
        vis[1] = 1;
        while (!qu.empty()) {
            int v = qu.front();
            qu.pop();
            for (int to: g[v])
                if (!vis[to]) {
                    vis[to] = 1;
                    parent[to] = v;
                    depth[to] = depth[v] + 1;
                    qu.push(to);
                }
        }
    }
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int v = 1; v <= n; ++v) up[0][v] = parent[v];
    for (int k = 1; k < LOG; ++k)
        for (int v = 1; v <= n; ++v)
            up[k][v] = up[k - 1][v] ? up[k - 1][up[k - 1][v]] : 0;

    auto lift = [&](int v, int diff) {
        for (int i = 0; i < LOG; ++i)
            if (diff & (1 << i)) {
                v = up[i][v];
                if (!v) break;
            }
        return v;
    };
    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        a = lift(a, depth[a] - depth[b]);
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; --k)
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        return up[0][a];
    };
    auto dist = [&](int a, int b) {
        int L = lca(a, b);
        return depth[a] + depth[b] - 2 * depth[L];
    };

    // 3) HLD to support min on path queries
    // compute sizes and heavy child
    vector<int> heavy(n + 1, -1);
    function<int(int, int)> dfs_sz = [&](int v, int p) -> int {
        sz[v] = 1;
        int maxsz = 0;
        for (int to: g[v])
            if (to != p) {
                parent[to] = v;
                depth[to] = depth[v] + 1;
                int s = dfs_sz(to, v);
                sz[v] += s;
                if (s > maxsz) {
                    maxsz = s;
                    heavy[v] = to;
                }
            }
        return sz[v];
    };
    dfs_sz(1, 0);

    vector<int> head(n + 1), pos(n + 1);
    int curPos = 0;
    function<void(int, int, int)> decompose = [&](int v, int p, int h) {
        head[v] = h;
        pos[v] = curPos++;
        if (heavy[v] != -1) decompose(heavy[v], v, h);
        for (int to: g[v])
            if (to != p && to != heavy[v]) {
                decompose(to, v, to);
            }
    };
    decompose(1, 0, 1);

    // segment tree for min over distToCoin mapped by pos
    int N = 1;
    while (N < n) N <<= 1;
    vector<int> seg(2 * N, INF);
    for (int v = 1; v <= n; ++v) seg[N + pos[v]] = distToCoin[v];
    for (int i = N - 1; i >= 1; --i) seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    auto seg_query = [&](int l, int r) { // inclusive l..r
        l += N;
        r += N;
        int res = INF;
        while (l <= r) {
            if (l & 1) res = min(res, seg[l++]);
            if (!(r & 1)) res = min(res, seg[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    };

    auto query_path_min = [&](int a, int b) {
        int res = INF;
        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) swap(a, b);
            int h = head[a];
            res = min(res, seg_query(pos[h], pos[a]));
            a = parent[h];
        }
        if (depth[a] > depth[b]) swap(a, b);
        res = min(res, seg_query(pos[a], pos[b]));
        return res;
    };

    // 4) answer queries
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        int d = dist(a, b);
        int mn = query_path_min(a, b); // min distToCoin on path
        // mn is finite because at least one coin exists
        long long ans = (long long) d + 2LL * mn;
        cout << ans << '\n';
    }
    return 0;
}