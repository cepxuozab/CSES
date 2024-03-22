#include <cmath>
#include <iostream>
#include <vector>

class LCA {
    int n = 0, l = 1, timer = 0;
    std::vector<std::vector<int>> g, up;
    std::vector<int> tin, tout;

public:
    LCA(int _n) :n(_n),l(log2(_n)+1) {
        g.resize(n + 1);
        up.resize(l + 1);
        tin.resize(n + 1, 0);
        tout.resize(n + 1, 0);
        for (int i = 0; i <= l; i++) {
            up[i].resize(n + 1, 0);
        }
    }
    void addEdge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int lca(int u, int v) {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;
        for (int i = l; i >= 0; i--) {
            if (!isAncestor(up[i][u], v)) {
                u = up[i][u];
            }
        }
        return up[0][u];
    }
    void prepare(int root) {
        g[0].push_back(root);
        dfs(0, -1);
        for (int i = 1; i <= l; i++) {
            for (int j = 0; j <= n; j++) {
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }
    }

    int GetLCA(int u) const { return up[0][u]; }
    std::vector<std::vector<int>> GetTree() const { return g; }

private:
    void dfs(int u, int par) {
        tin[u] = timer++;
        for (auto v: g[u]) {
            if (v == par)
                continue;
            up[0][v] = u;
            dfs(v, u);
        }
        tout[u] = timer;
    }

    bool isAncestor(int u, int v) { return (tin[u] <= tin[v] && tout[u] >= tout[v]); }
};

int main() { 
    int n, q;
    std::cin >> n >> q;
    auto lca = LCA(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        lca.addEdge(u, v);
    }
    lca.prepare(1);
    std::vector<int> f(n+1);
    for (int i = 1; i <= q; i++) {
        int u, v;
        std::cin >> u >> v;
        f[u]++;
        f[v]++;
        int _lca = lca.lca(u, v);
        f[_lca]--;
        f[lca.GetLCA(_lca)]--;
    }
    auto graph = lca.GetTree();
    auto dfs = [&](auto &&self, int u, int v) -> void {
        for (int e: graph[u]) {
            if (e == v)
                continue;
            self(self, e, u);
            f[u] += f[e];
        }
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cout << f[i] << ' ';
    }
   
}
