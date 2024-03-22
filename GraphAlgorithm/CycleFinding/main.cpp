#include <iostream>
#include <vector>
#include <cstdint>
#include <unordered_set>
#include <algorithm>

struct Edge {
    int src;
    int dest;
    int64_t cost;
};

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        int64_t x;
        std::cin >> a >> b >> x;
        a--, b--;
        edges.push_back(Edge{a, b, x});
    }
    std::vector<int64_t> dist(n, 1e18);
    dist[0] = 0;
    std::vector<int> parent(n, -1);
    int x = -1;
    for (int i = 0; i < n; i++) {
        for (auto const [src, dest, cost]: edges) {
            if (dist[dest] > dist[src] + cost) {
                dist[dest] = dist[src] + cost;
                parent[dest] = src;
                if (i == n - 1) {
                    x = dest;
                    break;
                }
            }
        }
    }
    if (x == -1) {
        std::cout << "NO\n";
        return 0;
    }
    std::unordered_set<int> set;
    std::vector<int> cycle;
    while (!set.contains(x)) {
        set.insert(x);
        cycle.push_back(x);
        x = parent[x];
    }
    cycle.push_back(x);
    std::ranges::reverse(cycle);
    std::cout << "YES\n";
    for (auto &node: cycle)std::cout << node + 1 << ' ';
    std::cout << '\n';


}
