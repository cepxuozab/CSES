#include<bits/stdc++.h>

using namespace std;
struct Edge {
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int> &d, vector<int> &p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v: adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

auto min_cost_flow(int N, const vector<Edge> &edges, int K, int s, int t) -> int {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e: edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int _cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        flow += f;
        _cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return -_cost;
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> r(n), c(n);
    vector<vector<int>> cst(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cst[i][j];
        }
    }
    vector<Edge> edges;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        s1 += r[i];
        edges.push_back({0, i + 1, r[i], 0});
    }
    int s = 0, t = n * n + 2 * n + 1;
    for (int i = 0; i < n; i++) {
        s2 += c[i];
        edges.push_back({n * n + n + 1 + i, t, c[i], 0});
    }
    if (s1 != s2) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            int num = n + 1 + i * n + j;
            edges.push_back({i + 1, num, 1, -cst[i][j]});
            edges.push_back({num, n * n + n + 1 + j, 1, 0});
        }
    }
    auto f = min_cost_flow(t + 1, edges, s1, s, t);
    if (f == -1) {
        cout << -1;
        return 0;
    }
    cout << f << '\n';
    vector<string> ans(n, string(n, '.'));
    for (int i = 1; i <= n; i++) {
        for (int j = n + 1; j <= n + n * n; ++j) {
            if (capacity[j][i] == 1) {
                int num = j - n - 1;
                ans[num / n][num % n] = 'X';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}