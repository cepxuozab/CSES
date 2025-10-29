#include <iostream>
#include <vector>
#include <set>

struct DisjointSet {
    int cc_cnt;
    std::vector<int> parent;

    DisjointSet(int n) : cc_cnt(n), parent(n + 1, -1) {}

    auto Root(int x) -> int { return parent[x] < 0 ? x : (parent[x] = Root(parent[x])); }

    void Join(int x, int y) {
        x = Root(x), y = Root(y);
        if (x == y) return;
        if (parent[x] > parent[y]) std::swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        --cc_cnt;
    }

    [[nodiscard]] auto ComponentCount() const -> int { return cc_cnt; }
};

auto main() -> int {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::set<std::pair<int, int>> edges;
    for (int a, b; m--;) {
        std::cin >> a >> b;
        if (a > b) std::swap(a, b);
        edges.emplace(a, b);
    }
    std::vector<std::pair<int, int>> op(k + 1);
    for (int a, b, i = 0; i < k; i++) {
        std::cin >> a >> b;
        if (a > b) std::swap(a, b);
        op[i] = {a, b};
        edges.erase({a, b});
    }
    DisjointSet dsu(n);
    for (auto [u, v]: edges) dsu.Join(u, v);
    std::vector<int> ans(k + 1);
    for (int i = k; i--;) {
        auto [u, v] = op[i];
        ans[i] = dsu.ComponentCount();
        dsu.Join(u, v);
    }
    for (int i = 0; i < k; i++) std::cout << ans[i] << ' ';


}