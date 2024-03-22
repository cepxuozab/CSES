#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    int m;

    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    std::vector<bool> visited(n, false);
    for (int i = 0; i < m; i++) {
        int u;
        int v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::vector<int> r;
    std::function<bool(int, int)> dfs = [&](int u, int p) {
        visited[u] = true;
        r.push_back(u);
        for (int v : graph[u]) {
            if (visited[v] && u != v && p != v) {
                r.push_back(v);
                return true;
            }
            if (!visited[v] && dfs(v, u)) {
                return true;
            }
        }
        r.pop_back();
        return false;
    };
    std::function<void(void)> print = [&]() {
        auto pos = std::ranges::find(r, r.back());
        std::cout << std::ranges::distance(pos, r.end()) << '\n';
        for (; pos != r.end(); ++pos) {
            std::cout << *pos + 1 << ' ';
        }
        std::cout << '\n';
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            r.clear();
            if (dfs(i, -1)) {
                print();
                return 0;
            }
        }
    }
    std::cout << "IMPOSSIBLE\n";
}