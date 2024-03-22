#include <iostream>
#include <vector>

static const auto FastIo = []() {    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
const int inf = 1e9;

struct Segtree {
    std::vector<int> tree;
    int base = 1;
    Segtree() = default;
    Segtree(int n);
    void Update(int v, int x);
    int Query(int l, int r);
};

struct HLD {
    int timer{};
    std::vector<std::vector<int>> g;
    std::vector<int> pre, post, d, path, p, sz, c;
    Segtree t;
    HLD(const std::vector<std::vector<int>> &graph);
    void Dfs(int v, int father);
    void Make_hld(int v);
    void Update(int v, int x);
    int Query(int a, int b);
};

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto &e: a)
        std::cin >> e;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto hld = HLD(graph);
    for (int i = 0; i < n; ++i) {
        hld.Update(i, a[i]);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int v, x;
            std::cin >> v >> x;
            hld.Update(v - 1, x);
        } else {
            int u, v;
            std::cin >> u >> v;
            std::cout << hld.Query(u - 1, v - 1) << ' ';
        }
    }
}

Segtree::Segtree(int n) {
    while (base < n)
        base *= 2;
    tree.resize(2 * base, -inf);
}

void Segtree::Update(int v, int x) {
    v += base;
    tree[v] = x;
    v /= 2;
    while (v)
        tree[v] = std::max(tree[2 * v], tree[2 * v + 1]), v /= 2;
}
int Segtree::Query(int l, int r) {
    int res = -inf;
    l += base - 1;
    r += base + 1;
    while (l / 2 != r / 2) {
        if (l % 2 == 0)
            res = std::max(res, tree[l + 1]);
        if (r % 2 == 1)
            res = std::max(res, tree[r - 1]);
        l /= 2;
        r /= 2;
    }
    return res;
}

HLD::HLD(const std::vector<std::vector<int>> &graph) :
    g(graph), pre(graph.size()), post(graph.size()), d(graph.size()), path(graph.size()), p(graph.size()),
    sz(graph.size()), c(graph.size(), -1), t(2 * graph.size()) {
    d[0] = 0;
    Dfs(0, 0);
    path[0] = 0;

    timer = 0;
    path[0] = 0;
    Make_hld(0);
}

void HLD::Dfs(int v, int father) {
    p[v] = father;
    sz[v] = 1;
    for (auto u: g[v]) {
        if (u == father)
            continue;
        d[u] = d[v] + 1;
        Dfs(u, v);
        sz[v] += sz[u];
        if (c[v] == -1 || sz[c[v]] < sz[u])
            c[v] = u;
    }
}

void HLD::Make_hld(int v) {
    pre[v] = timer++;
    if (c[v] != -1) {
        path[c[v]] = path[v];
        Make_hld(c[v]);
    }
    for (auto u: g[v]) {
        if (u == p[v] || u == c[v])
            continue;
        path[u] = u;
        Make_hld(u);
    }
    post[v] = timer++;
}

void HLD::Update(int v, int x) { t.Update(pre[v], x); }

int HLD::Query(int a, int b) {
    int res = -inf;
    auto get_path = [&](int v) { return v < 0 ? -1 : path[v]; };
    while (get_path(a) != get_path(b)) {
        if (d[path[a]] < d[path[b]])
            std::swap(a, b);
        res = std::max(res, t.Query(pre[path[a]], pre[a]));
        a = p[path[a]];
    }

    if (d[a] < d[b])
        std::swap(a, b);
    res = std::max(res, t.Query(pre[b], pre[a]));
    return res;
}
