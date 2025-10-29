#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include <cstdint>
#include <algorithm>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, int>>> gr(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--, v--;
        gr[u].emplace_back(v, c);
    }
    std::priority_queue<std::array<int64_t, 3>> pq;
    pq.push({0, 0, 0});
    std::vector<int64_t> vis(n, -1);
    std::vector<std::vector<int>> gr2(n);
    while (pq.size()) {
        auto [d, x, p] = pq.top();
        pq.pop();
        if (~vis[x]) {
            if (-d == vis[x])gr2[x].push_back(p);
            continue;
        }
        vis[x] = -d;
        if (x != p)gr2[x].push_back(p);
        for (auto y: gr[x]) {
            pq.push({d - y.second, y.first, x});
        }
    }
    std::queue<int> Q;
    std::vector<int> deg(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto x: gr2[i])deg[x]++;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (!deg[i])Q.push(i);
    }
    while (!Q.empty()) {
        auto x = Q.front();
        Q.pop();
        if (x == n - 1)continue;
        for (auto y: gr2[x])if (!--deg[y])Q.push(y);
    }
    std::vector<int> ans;
    std::set<int> am;
    Q.push(n - 1);
    while (!Q.empty()) {
        auto x = Q.front();
        Q.pop();
        am.erase(x);
        if (am.empty())ans.push_back(x);
        for (auto y: gr2[x]) {
            am.insert(y);
            if (!--deg[y])Q.push(y);
        }
    }
    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for (auto x: ans)std::cout << x + 1 << ' ';

}