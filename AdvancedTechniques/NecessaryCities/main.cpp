#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int p, int u, int d, vector<vector<int>> const &adj, vector<int> &depth, vector<int> &low, vector<int> &res) {
    depth[u] = d;
    low[u] = d;
    for (auto const &v: adj[u]) {
        if (v == p) continue;
        if (!depth[v]) {
            dfs(u, v, d + 1, adj, depth, low, res);
            low[u] = min(low[u], low[v]);
            if (d > low[v]) continue;
            res.emplace_back(u);
        } else if (depth[v] < d) {
            low[u] = min(low[u], depth[v]);
        }
    }
}

auto main() -> int {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0, a, b; i < m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<int> cut_vertex;
    vector<int> depth(n, 0), low(n, 0);
    dfs(-1, 0, 1, adj, depth, low, cut_vertex);
    std::ranges::sort(cut_vertex, std::greater<>());
    auto [first, last] = std::ranges::unique(cut_vertex);
    cut_vertex.erase(first, last);
    cut_vertex.pop_back();

    bool root_cut = true;
    for (auto const &v: adj[0]) {
        if (depth[v] == 2) {
            root_cut = !root_cut;
            if (root_cut) break;
        }
    }
    if (root_cut)
        cut_vertex.emplace_back(0);

    cout << cut_vertex.size() << "\n";
    for (auto const &i: cut_vertex) cout << i + 1 << " ";
    cout << flush;

    return 0;
}