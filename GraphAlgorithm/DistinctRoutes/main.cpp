#include <cstdint>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>
#include <stack>

struct Dinic {
    struct Edge {
        int to, rev;
        int64_t c, oc;
        bool vis = false;

        auto flow() -> int64_t { return oc - c > 0 ? oc - c : 0; }
    };

    std::vector<int> lvl, ptr, q;
    std::vector<std::vector<Edge>> adj;
public:
    explicit Dinic(int n);

    void AddEdge(int a, int b, int64_t c, int64_t rcap = 0);

    auto Dfs(int v, int t, int64_t f) -> int64_t;

    void Calc(int s, int t);
};

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    Dinic d(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        d.AddEdge(u - 1, v - 1, 1);
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
    std::vector<bool> vis(std::size(adj), false);
    std::stack<int> st;
    auto MyDfs = [&](auto self, int u) -> void {
        st.push(u);
        vis[u] = true;
        if (std::cmp_equal(u + 1, std::size(adj))) {
            vis[u] = false;
            std::vector<int> v;
            std::stack<int> st2;
            while (st.top() != 0) {
                st2.push(st.top());
                st.pop();
            }
            st2.push(0);
            std::cout << std::size(st2) << '\n';
            while (!st2.empty()) {
                std::cout << st2.top() + 1 << ' ';
                st2.pop();
            }
            std::cout << '\n';
            return;
        }
        for (Edge &e: adj[u]) {
            if (e.flow() != 1 || vis[e.to] || e.vis) continue;
            e.vis = true;
            self(self, e.to);
            if (st.top() != u) {
                e.vis = true;
                vis[u] = false;
                return;
            }
            if (u) e.vis = false;
        }
        vis[u] = false;
        st.pop();
    };
    MyDfs(MyDfs, 0);

}