#include <iostream>
#include <vector>
#include <queue>


struct DSU {
    std::vector<int> rank;

    DSU(int n) : rank(n + 1, -1) {}

    auto root(int x) -> int { return rank[x] < 0 ? x : (rank[x] = root(rank[x])); }

    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y]) std::swap(x, y);
        rank[x] += rank[y];
        rank[y] = x;
    }
};

auto main() -> int {

    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<bool> has_cyc(n + 1);
    DSU dsu(n);
    std::vector<int> in_degree(n + 1, 0);
    for (int a, b; m--;) {
        std::cin >> a >> b;
        graph[a].push_back(b);
        in_degree[b]++;
        dsu.merge(a, b);
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++) if (in_degree[i] == 0) q.emplace(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto to: graph[x]) if (--in_degree[to] == 0) q.emplace(to);
    }
    for (int i = 1; i <= n; i++) if (in_degree[i]) has_cyc[dsu.root(i)] = true;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (dsu.rank[i] < 0) {
            ans += -dsu.rank[i] - (!has_cyc[i]);
        }
    std::cout << ans;
}