#include <iostream>
#include <vector>
#include <queue>
#include <climits>


struct Edge {
    int to;
    long long w;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<Edge>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int l, r;
        long long s;
        std::cin >> l >> r >> s;
        --l; // чтобы использовать p_{l-1}
        g[l].push_back({r, s});
        g[r].push_back({l, -s});
    }

    std::vector<long long> p(n + 1, LLONG_MAX);
    std::vector<char> vis(n + 1, 0);
    bool ok = true;

    for (int start = 0; start <= n && ok; ++start) {
        if (vis[start]) continue;
        p[start] = 0;
        std::queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty() && ok) {
            int v = q.front(); q.pop();
            for (auto [to, w] : g[v]) {
                long long val = p[v] + w;
                if (p[to] == LLONG_MAX) {
                    p[to] = val;
                    vis[to] = 1;
                    q.push(to);
                } else if (p[to] != val) {
                    ok = false;
                    break;
                }
            }
        }
    }

    if (!ok) {
        std:: cout << "NO\n";
        return 0;
    }

    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << (p[i] - p[i - 1]) << (i == n ? '\n' : ' ');
    }

    return 0;
}
