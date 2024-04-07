#include <bits/stdc++.h>

using namespace std;


// Block-Cut Tree {{{
struct BlockCutTree {
    int N;
    vector<vector<int>> const &G;

    stack<pair<int, int>> S;
    int TIMER = -1;
    vector<int> pre, low;

    vector<int> art;
    vector<bool> is_art;
    vector<vector<pair<int, int>>> bcc;

    vector<vector<int>> BCT;
    vector<int> comp;

    void make_bcc(pair<int, int> until) {
        bcc.emplace_back();
        pair<int, int> e{-1, -1};
        while (e != until) {
            e = S.top();
            S.pop();
            bcc.back().push_back(e);
        }
    }

    void dfs(int v, int p) {
        pre[v] = low[v] = ++TIMER;

        int children = 0;
        bool low_child = false;

        for (auto u: G[v]) {
            if (u == p) continue;
            if (pre[u] == -1) {
                S.emplace(v, u);
                dfs(u, v);
                children++;

                low[v] = min(low[v], low[u]);
                if (low[u] >= pre[v]) {
                    low_child = true;
                    make_bcc({v, u});
                }
            } else {
                low[v] = min(low[v], pre[u]);
            }
        }

        if ((p == -1 && children >= 2) || (p != -1 && low_child))
            art.push_back(v);
    }


    BlockCutTree(vector<vector<int>> const &G_) : N(size(G_)), G(G_) {
        pre.assign(N, -1);
        low.assign(N, -1);
        for (int i = 0; i < N; i++) {
            if (pre[i] == -1) {
                dfs(i, -1);
            }
        }

        is_art.resize(N, false);
        for (auto v: art) is_art[v] = true;

        BCT.resize(N + size(bcc));
        comp.resize(N);
        for (int i = 0; i < (int) size(bcc); i++) {
            for (auto [v, u]: bcc[i]) {
                if (is_art[v] && (empty(BCT[v]) || BCT[v].back() != N + i))
                    BCT[v].push_back(N + i), BCT[N + i].push_back(v);
                if (is_art[u] && (empty(BCT[u]) || BCT[u].back() != N + i))
                    BCT[u].push_back(N + i), BCT[N + i].push_back(u);
                comp[v] = comp[u] = N + i;
            }
        }

        for (auto v: art) comp[v] = v;
    }
};
//}}}

// Lowest Common Ancestor (Never tested) {{{
struct LCA {
    const int LOG = 22;

    int N;
    vector<vector<int>> const &G;

    int TIMER = -1;
    vector<int> pre, pos;
    vector<vector<int>> parent;

    void dfs(int v, int p) {
        parent[v][0] = p;
        for (int b = 1; b < LOG; b++) {
            parent[v][b] = parent[parent[v][b - 1]][b - 1];
        }

        pre[v] = ++TIMER;
        for (auto u: G[v]) {
            if (u == p) continue;
            dfs(u, v);
        }
        pos[v] = TIMER;
    }

    auto is_ancestor(int anc, int child) -> bool {
        return pre[anc] <= pre[child] && pos[child] <= pos[anc];
    }

    auto lca(int v, int u) -> int {
        if (is_ancestor(v, u)) return v;
        if (is_ancestor(u, v)) return u;

        for (int b = LOG - 1; b >= 0; b--) {
            int nv = parent[v][b];
            if (!is_ancestor(nv, u)) v = nv;
        }
        v = parent[v][0];
        return v;
    }

    LCA(vector<vector<int>> const &G_) : N(size(G_)), G(G_) {
        pre.assign(N, -1);
        pos.assign(N, -1);
        parent.resize(N, vector<int>(LOG));
        for (int i = 0; i < N; i++) {
            if (pre[i] == -1) {
                dfs(i, i);
            }
        }
    }
};
//}}}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> G(N);
    for (int i = 0; i < M; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        G[v].push_back(u);
        G[u].push_back(v);
    }

    BlockCutTree bct(G);
    LCA lca(bct.BCT);

    auto on_path = [&](int a, int b, int c) {
        int lab = lca.lca(a, b);
        int lac = lca.lca(a, c);
        int lbc = lca.lca(b, c);

        if (lab == c || (lac == lab && lbc == c) || (lbc == lab && lac == c)) return true;
        return false;
    };

    while (Q--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        if (c == a || c == b) cout << "NO\n";
        else if (!bct.is_art[c]) cout << "YES\n";
        else if (on_path(bct.comp[a], bct.comp[b], bct.comp[c])) cout << "NO\n";
        else cout << "YES\n";
    }
}
