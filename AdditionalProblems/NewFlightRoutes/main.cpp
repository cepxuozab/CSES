#include<bits/stdc++.h>

using namespace std;

vector<bool> s, used;

void dfs_scc(int u, vector<int> &c, vector<vector<int>> &g) {
    s[u] = true;
    for (auto v: g[u]) {
        if (s[v]) continue;
        dfs_scc(v, c, g);
    }
    c.push_back(u);
}

auto dfs_mat(int u, vector<int> &c, vector<vector<int>> &g) -> int {
    s[u] = true;
    int res = 0;
    if (c[u] == 0 && !used[u]) return u;
    for (auto v: g[u]) {
        if (s[v]) continue;
        if (int t = dfs_mat(v, c, g)) res = t;
    }
    return res;
}

auto main() -> int {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n + 1, vector<int>()), r(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        f[a].push_back(b);
        r[b].push_back(a);
    }

    int c = 0;
    s.assign(n + 1, false);
    vector<int> tout, comp(n + 1), id(1, 0);
    for (int i = 1; i <= n; ++i) {
        if (!s[i]) dfs_scc(i, tout, f);
    }
    reverse(tout.begin(), tout.end());
    s.assign(n + 1, false);
    for (auto u: tout) {
        if (s[u]) continue;
        vector<int> t;
        dfs_scc(u, t, r);
        c++;
        for (auto v: t) {
            comp[v] = c;
        }
        id.push_back(t[0]);
    }

    if (c == 1) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> ind(c + 1, 0), outd(c + 1, 0);
    vector<vector<int>> scc(c + 1, vector<int>()), sccr(c + 1, vector<int>());
    for (int i = 1; i <= n; ++i) {
        for (auto v: f[i]) {
            if (comp[i] == comp[v]) continue;
            sccr[comp[v]].push_back(comp[i]);
            scc[comp[i]].push_back(comp[v]);
            ind[comp[v]]++;
            outd[comp[i]]++;
        }
    }

    vector<int> S, T; // sources, sinks
    for (int i = 1; i <= c; ++i) {
        if (ind[i] == 0) S.push_back(i);
        if (outd[i] == 0) T.push_back(i);
    }

    s.assign(c + 1, false);
    used.assign(c + 1, false);
    vector<pair<int, int>> mat;
    for (auto u: S) {
        int v = dfs_mat(u, outd, scc);
        if (!v) continue;
        mat.emplace_back(u, v);
        used[u] = used[v] = true;
    }
    s.assign(c + 1, false);
    for (auto v: T) {
        if (used[v]) continue;
        int u = dfs_mat(v, ind, sccr);
        if (!u) continue;
        mat.emplace_back(u, v);
        used[u] = used[v] = true;
    }

    vector<pair<int, int>> ans;
    for (int i = 0; std::cmp_less(i, mat.size()); ++i) {
        ans.emplace_back(mat[i].second, mat[(i + 1) % mat.size()].first);
    }

    for (int i = 0, j = 0;;) {
        while (std::cmp_less(i, S.size()) && used[S[i]]) i++;
        while (std::cmp_less(j, T.size()) && used[T[j]]) j++;
        if (std::cmp_greater_equal(i, S.size()) && std::cmp_greater_equal(j, T.size())) break;
        int u = S[i % S.size()], v = T[j % T.size()];
        used[u] = used[v] = true;
        ans.emplace_back(v, u);
    }

    cout << ans.size() << '\n';
    for (auto i: ans) {
        cout << id[i.first] << ' ' << id[i.second] << '\n';
    }

    return 0;
}