#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
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
    for (int i = 0; i < m; i++) {
        int u;
        int v;
        std::cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::vector<int> p(n);
    p[0] = -1;
    std::queue<int> queue;
    queue.push(0);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        if (u == n - 1) {
            break;
        }
        for (int v : graph[u]) {
            if (p[v] == 0) {
                p[v] = u + 1;
                queue.push(v);
            }
        }
    }
    if (p[n - 1] == 0) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }
    std::vector<int> result;
    int pos = n;
    while (pos > 0) {
        result.push_back(std::exchange(pos, p[pos - 1]));
    }
    std::cout << result.size() << '\n';
    std::copy(result.rbegin(), result.rend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
    return 0;
}
