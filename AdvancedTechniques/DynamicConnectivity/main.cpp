#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vll = vector<ll>;

struct DSU {
    stack<ll> us, vs;
    vll par, sz;
    ll comps;

    DSU(ll n) : par(n), sz(n, 1), comps(n) { iota(par.begin(), par.end(), 0); }

    auto find(ll u) -> ll { return (u == par[u] ? u : find(par[u])); }

    void join(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (sz[u] > sz[v]) swap(u, v);
        us.push(u);
        vs.push(v);
        if (u == v) return;
        par[u] = v;
        sz[v] += sz[u];
        comps--;
    }

    void rollback() {
        assert(us.size());
        ll u = us.top();
        us.pop();
        ll v = vs.top();
        vs.pop();
        if (u == v) return;
        par[u] = u;
        sz[v] -= sz[u];
        comps++;
    }
};

#define mid ((l+r)>>1)
#define off (2*(mid-l+1))

struct SegTree {

    vector<vector<pair<ll, ll> > > tree;
    ll n;
    DSU dsu;
    vll vans;


    SegTree(ll n, ll m) : tree(2 * n), n(n), dsu(m), vans(0) {}

    void update(ll ql, ll qr, ll u, ll v) { update(ql, qr, u, v, 0, n - 1, 0); }

    void update(ll ql, ll qr, ll u, ll v, ll l, ll r, ll id) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            tree[id].emplace_back(u, v);
            return;
        }
        update(ql, qr, u, v, l, mid, id + 1);
        update(ql, qr, u, v, mid + 1, r, id + off);
    }

    void dfs() { dfs(0, n - 1, 0); }

    void dfs(ll l, ll r, ll id) {
        for (auto [u, v]: tree[id]) dsu.join(u, v);
        if (l == r) {
            vans.push_back(dsu.comps);
            for ([[maybe_unused]] auto dummy: tree[id]) dsu.rollback();
            return;
        }
        dfs(l, mid, id + 1);
        dfs(mid + 1, r, id + off);
        for ([[maybe_unused]] auto dummy: tree[id]) dsu.rollback();
    }
};

auto main() -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll n, m, Q;
    cin >> n >> m >> Q;
    set<pair<pair<ll, ll>, ll> > sett;
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        sett.insert({{u, v}, 0});
    }
    SegTree st(Q + 1, n);
    for (ll q = 1; q <= Q; q++) {
        char type;
        cin >> type;
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) swap(u, v);
        switch (type) {
            case '1':
                sett.insert({{u, v}, q});
                break;
            case '2': {
                auto it = sett.lower_bound({{u, v}, 0});
                st.update(it->second, q - 1, u, v);
                sett.erase(it);
            }
                break;
            default:
                break;
        }
    }
    while (sett.size()) {
        auto it = sett.begin();
        auto [u, v] = it->first;
        st.update(it->second, Q, u, v);
        sett.erase(it);
    }
    st.dfs();
    for (ll i: st.vans) cout << i << ' ';
    cout << '\n';
    return 0;
}