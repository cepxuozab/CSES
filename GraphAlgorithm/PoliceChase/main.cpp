#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <limits>

struct Dinic {
    struct Edge {
        int to, rev;
        int64_t c, oc;
    };

    std::vector<int> lvl, ptr, q;
    std::vector<std::vector<Edge>> adj;
public:
    explicit Dinic(int n);

    void AddEdge(int a, int b, int64_t c, int64_t rcap = 0);

    auto Dfs(int v, int t, int64_t f) -> int64_t;

    [[nodiscard]] auto LeftOfMinCut(int a) const -> bool { return lvl[a] != 0; }

    void Calc(int s, int t);
};

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    Dinic d(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        d.AddEdge(u - 1, v - 1, 1, 1);
    }
    d.Calc(0, n - 1);

}

Dinic::Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {
}

void Dinic::AddEdge(int a, int b, int64_t c, int64_t rcap) {
    adj[a].push_back({b, static_cast<int>(std::size(adj[b])), c, c});
    adj[b].push_back({a, static_cast<int>(std::size(adj[a])) - 1, rcap, rcap});
}

auto Dinic::Dfs(int v, int t, int64_t f) -> int64_t {
    if (v == t || !f) return f;
    for (int &i = ptr[v]; std::cmp_less(i, std::size(adj[v])); i++) {
        Edge &e = adj[v][i];
        if (lvl[e.to] == lvl[v] + 1)
            if (auto p = Dfs(e.to, t, std::min(f, e.c))) {
                e.c -= p, adj[e.to][e.rev].c += p;
                return p;
            }
    }
    return 0;
}

void Dinic::Calc(int s, int t) {
    int64_t flow = 0;
    q[0] = s;
    for (int L = 0; L < 31; ++L) {
        do {  // 'int L=30' maybe faster for random data
            lvl = ptr = std::vector<int>(std::size(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e: adj[v]) if (!lvl[e.to] && e.c >> (30 - L)) { q[qe++] = e.to, lvl[e.to] = lvl[v] + 1; }
            }
            while (auto p = Dfs(s, t, std::numeric_limits<int64_t>::max())) flow += p;
        } while (lvl[t]);
    }
    std::cout << flow << '\n';
    std::set<std::pair<int, int>> ans;
    for (int i = 0; std::cmp_less(i, std::size(adj)); ++i) {
        for (auto &e: adj[i]) {
            if (LeftOfMinCut(i) && !LeftOfMinCut(e.to)) {
                ans.insert({std::min(i, e.to) + 1, std::max(i, e.to) + 1});
            }
        }
    }
    for (auto const &[a, b]: ans) {
        std::cout << a << ' ' << b << '\n';
    }
}