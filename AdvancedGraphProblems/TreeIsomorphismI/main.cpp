#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using Neighborth = std::vector<int>;

auto HashGraph(std::map<Neighborth, int> &m, std::vector<Neighborth> const &graph, int curr, int father) -> int {
    std::vector<int> children;
    for (int a: graph[curr])
        if (a != father) children.push_back(HashGraph(m, graph, a, curr));
    std::ranges::sort(children);
    if (!m.contains(children)) m[children] = static_cast<int>(m.size());
    return m[children];
}

auto main() -> int {
    int t;
    std::cin >> t;
    for (int k = 0; k < t; ++k) {
        std::map<Neighborth, int> m;
        int n;
        std::cin >> n;
        std::vector<Neighborth> graph(n + 1), graph2(n + 1);
        for (int i = 1; i < n; i++) {
            int a, b;
            std::cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for (int i = 1; i < n; i++) {
            int a, b;
            std::cin >> a >> b;
            graph2[a].push_back(b);
            graph2[b].push_back(a);
        }
        int hash1 = HashGraph(m, graph, 1, 0), hash2 = HashGraph(m, graph2, 1, 0);
        std::cout << (hash1 == hash2 ? "YES\n" : "NO\n");
    }
}
