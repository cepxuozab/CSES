#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

auto find(int j, std::vector<std::vector<int>> const &g, std::vector<int> &btoa, std::vector<int> &vis) -> bool {
    if (btoa[j] == -1) {
        return true;
    }
    vis[j] = 1;
    int di = btoa[j];
    for (int e: g[di]) {
        if ((vis[e] == 0) && find(e, g, btoa, vis)) {
            btoa[e] = di;
            return true;
        }
    }
    return false;
}

auto dfsMatching(std::vector<std::vector<int>> const &g, std::vector<int> &btoa) -> int {
    std::vector<int> vis;
    for (int i = 0; std::cmp_less(i, g.size()); ++i) {
        vis.assign(btoa.size(), 0);
        for (int j: g[i]) {
            if (find(j, g, btoa, vis)) {
                btoa[j] = i;
                break;
            }
        }
    }
    return static_cast<int>(btoa.size() - std::ranges::count(btoa, -1));
}

auto main() -> int {

    int n;
    int m;
    int k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> g(n);
    while ((k--) != 0) {
        int a;
        int b;
        std::cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
    }
    std::vector<int> btoa(m, -1);
    std::cout << dfsMatching(g, btoa) << '\n';
    for (int i = 0; i < m; ++i) {
        if (btoa[i] >= 0) {
            std::cout << btoa[i] + 1 << " " << i + 1 << '\n';
        }
    }
    return 0;
}