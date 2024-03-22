#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    std::vector<int> d(n, -1), low(n, 0), scc(n, -1);
    std::vector<bool> stacked(n, false);
    std::stack<int> s;
    int ticks = 0, current_scc = 0;
    auto tarjan = [&](auto tarjan, int u) -> void {
        d[u] = low[u] = ticks++;
        s.push(u);
        stacked[u] = true;
        for (int &v: g[u]) {
            if (d[v] == -1) {
                tarjan(tarjan, v);
                low[u] = std::min(low[u], low[v]);
            } else if (stacked[v]) {
                low[u] = std::min(low[u], low[v]);
            }
        }
        if (d[u] == low[u]) {
            int v;
            do {
                v = s.top();
                s.pop();
                stacked[v] = false;
                scc[v] = current_scc;
            } while (u != v);
            current_scc++;
        }
    };
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) {
            tarjan(tarjan, i);
        }
    }

    std::cout << current_scc << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << scc[i] + 1 << " \n"[i == n - 1];
    }

}
