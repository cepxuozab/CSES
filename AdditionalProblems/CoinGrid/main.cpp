#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

template<class T = int>
struct MaxFlow {
    struct Edge {
        int next, v;
        T cap, flow;
    };

    int s, t;
    std::vector<int> start, level, used, q;
    std::vector<Edge> g;

    MaxFlow(int n, int s, int t) : s(s), t(t), start(n, -1), level(n, -1), used(n, -1), q(n) {}

    void AddEdge(int u, int v, T cap, T rev = T()) {
        g.push_back({start[u], v, cap, T()});
        start[u] = g.size() - 1;
        g.push_back({start[v], u, rev, T()});
        start[v] = g.size() - 1;
    }

    auto Bfs(int u, int v) -> bool {
        size_t qs = 0, qe = 1;
        std::fill(level.begin(), level.end(), -1);
        q[0] = u;
        level[u] = 0;
        while (qs != qe) {
            int x = q[qs++];
            for (int i = start[x]; i != -1; i = g[i].next) {
                if (g[i].flow < g[i].cap && level[g[i].v] == -1) {
                    level[g[i].v] = level[x] + 1;
                    q[qe++] = g[i].v;
                }
            }
        }
        return level[v] != -1;
    }

    auto Dfs(int x, int u, T f) -> T {
        if (x == u)
            return f;
        for (int &i = used[x]; i != -1; i = g[i].next) {
            int v = g[i].v;
            if (level[v] == level[x] + 1 && g[i].flow < g[i].cap) {
                T z = Dfs(v, u, std::min(f, g[i].cap - g[i].flow));
                if (z > 0) {
                    g[i].flow += z;
                    g[i ^ 1].flow -= z;
                    return z;
                }
            }
        }
        return T();
    }

    auto operator()() -> T {
        T f = T();
        while (Bfs(s, t)) {
            used = start;
            while (true) {
                T z = Dfs(s, t, std::numeric_limits<T>::max());
                f += z;
                if (!z) break;
            }
        }
        return f;
    }

    auto MinCut() -> std::vector<std::pair<int, int>> {
        (*this)();
        std::vector<std::pair<int, int>> r;
        for (int x = 0; x < (int) start.size(); x++) {
            if (level[x] == -1) continue;
            for (int i = start[x]; i != -1; i = g[i].next) {
                if (level[g[i].v] == -1) {
                    r.emplace_back(x, g[i].v);
                }
            }
        }
        return r;
    }
};

auto main() -> int {
    std::ios::sync_with_stdio(!std::cin.tie(0));

    int n;
    std::cin >> n;
    MaxFlow e(2 * n + 2, 2 * n, 2 * n + 1);
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'o') {
                e.AddEdge(i, n + j, 1000);
            }
        }
        e.AddEdge(2 * n, i, 1);
        e.AddEdge(n + i, 2 * n + 1, 1);
    }

    std::set<std::pair<int, int>> sol;
    for (auto [x, y]: e.MinCut()) {
        if (x == 2 * n) {
            sol.emplace(1, y);
        } else {
            sol.emplace(2, x - n);
        }
    }

    std::cout << sol.size() << '\n';
    for (auto [x, y]: sol) {
        std::cout << x << ' ' << y + 1 << '\n';
    }
}