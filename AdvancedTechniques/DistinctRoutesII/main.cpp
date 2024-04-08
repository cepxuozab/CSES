#include <bits/stdc++.h>

using namespace std;


// Dinitz Min Cost {{{
const int INF = INT32_MAX;

struct Dinitz {
    struct Edge {
        int v, u, cap, flow = 0, cost;

        Edge(int v, int u, int cap, int cost) : v(v), u(u), cap(cap), cost(cost) {}
    };

    int n, s, t;

    Dinitz(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
    }

    vector<Edge> edges;
    vector<vector<int>> adj;

    void add_edge(int v, int u, int cap, int cost1) {
        edges.emplace_back(v, u, cap, cost1);
        adj[v].push_back(size(edges) - 1);
        edges.emplace_back(u, v, 0, -cost1);
        adj[u].push_back(size(edges) - 1);
    }

    vector<int> dist;

    auto spfa() -> bool {
        dist.assign(n, INF);

        queue<int> Q;
        vector<bool> inqueue(n, false);

        dist[s] = 0;
        Q.push(s);
        inqueue[s] = true;

        vector<int> cnt(n);

        while (!Q.empty()) {
            int v = Q.front();
            Q.pop();
            inqueue[v] = false;

            for (auto eid: adj[v]) {
                auto const &e = edges[eid];
                if (e.cap - e.flow <= 0) continue;
                if (dist[e.u] > dist[e.v] + e.cost) {
                    dist[e.u] = dist[e.v] + e.cost;
                    if (!inqueue[e.u]) {
                        Q.push(e.u);
                        inqueue[e.u] = true;
                    }
                }
            }
        }

        return dist[t] != INF;
    }

    int cost = 0;
    vector<int> ptr;

    auto dfs(int v, int f) -> int {
        if (v == t || f == 0) return f;
        for (auto &cid = ptr[v]; cid < (int) size(adj[v]);) {
            auto eid = adj[v][cid];
            auto &e = edges[eid];
            cid++;
            if (e.cap - e.flow <= 0) continue;
            if (dist[e.v] + e.cost != dist[e.u]) continue;
            int newf = dfs(e.u, min(f, e.cap - e.flow));
            if (newf == 0) continue;
            e.flow += newf;
            edges[eid ^ 1].flow -= newf;
            cost += e.cost * newf;
            return newf;
        }
        return 0;
    }

    int total_flow = 0;

    auto flow(int amount) -> int {
        while (spfa() && amount) {
            ptr.assign(n, 0);
            while (int newf = dfs(s, amount)) {
                total_flow += newf;
                amount -= newf;
            }
        }
        return total_flow;
    }
};
//}}}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    Dinitz D(N, 0, N - 1);

    for (int i = 0; i < M; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        D.add_edge(v, u, 1, 1);
    }

    int f = D.flow(K);
    if (f < K) {
        cout << -1 << '\n';
        exit(0);
    }

    vector<vector<int>> G(N);
    for (auto [v, u, cap, flow, cost]: D.edges) {
        if (cap == 0 || flow == 0) continue;
        G[v].push_back(u);
    }

    cout << D.cost << '\n';
    for (int rep = 0; rep < K; rep++) {

        int cur = 0;
        vector<int> path{cur};

        while (cur != N - 1) {
            int u = G[cur].back();
            G[cur].pop_back();
            cur = u;
            path.push_back(cur);
        }

        cout << size(path) << '\n';
        for (auto x: path) cout << x + 1 << ' ';
        cout << '\n';
    }
}