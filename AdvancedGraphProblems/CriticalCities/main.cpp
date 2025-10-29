#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <numeric>

class DominatorTree {
    std::vector<std::vector<int>> g, rg, bucket;
    std::vector<int> arr, par, rev, sdom, dom, dsu, label;
    int n{}, t{};
public:
    DominatorTree(int n) : g(n), rg(n), bucket(n), arr(n, -1),
                           par(n), rev(n), sdom(n), dom(n), dsu(n), label(n), n(n) {}

    void AddEdge(int u, int v) { g[u].push_back(v); }

    auto Run(int root = 0) -> std::vector<int> {
        Dfs(root);
        std::iota(dom.begin(), dom.end(), 0);
        for (int i = t - 1; i >= 0; i--) {
            for (int w: rg[i])
                sdom[i] = std::min(sdom[i], sdom[Find(w)]);
            if (i)
                bucket[sdom[i]].push_back(i);
            for (int w: bucket[i]) {
                int v = Find(w);
                if (sdom[v] == sdom[w])
                    dom[w] = sdom[w];
                else
                    dom[w] = v;
            }
            if (i > 1)
                dsu[i] = par[i];
        }
        for (int i = 1; i < t; i++) {
            if (dom[i] != sdom[i])
                dom[i] = dom[dom[i]];
        }
        std::vector<int> outside_dom(n);
        std::iota(begin(outside_dom), end(outside_dom), 0);
        for (int i = 0; i < t; i++)
            outside_dom[rev[i]] = rev[dom[i]];
        return outside_dom;
    }

private:
    void Dfs(int u) {
        arr[u] = t;
        rev[t] = u;
        label[t] = sdom[t] = dsu[t] = t;
        t++;
        for (int w: g[u]) {
            if (arr[w] == -1) {
                Dfs(w);
                par[arr[w]] = arr[u];
            }
            rg[arr[w]].push_back(arr[u]);
        }
    }

    auto Find(int u, int x = 0) -> int {
        if (u == dsu[u])
            return x ? -1 : u;
        int v = Find(dsu[u], x + 1);
        if (v < 0)
            return u;
        if (sdom[label[dsu[u]]] < sdom[label[u]])
            label[u] = label[dsu[u]];
        dsu[u] = v;
        return x ? v : label[u];
    }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    DominatorTree dt(n);
    for ([[maybe_unused]]int i: std::ranges::iota_view(0, m)) {
        int x, y;
        std::cin >> x >> y;
        dt.AddEdge(x - 1, y - 1);
    }
    auto od = dt.Run();
    std::vector<int> sol;
    for (int x = n - 1; x; x = od[x]) {
        sol.push_back(x);
    }
    sol.push_back(0);
    std::ranges::sort(sol);
    std::cout << sol.size() << '\n';
    for (auto &&elem: sol) {
        std::cout << elem + 1 << ' ';
    }
}