#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <functional>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int tc;
    std::cin >> tc;
    for (int _ = 0; _ < tc; _++) {
        int N;
        std::cin >> N;
        std::map<std::vector<int>, int> mp;
        int nodes = 0;
        std::vector<std::vector<std::vector<int>>> g(N, std::vector<std::vector<int >>(2));
        for (int turn = 0; turn < 2; turn++) {
            for (int i = 0; i < N - 1; i++) {
                int U, V;
                std::cin >> U >> V;
                U--, V--;
                g[U][turn].push_back(V);
                g[V][turn].push_back(U);
            }
        }
        std::function<int(int, int, int)> doit = [&](int turn, int u, int p) -> int {
            std::vector<int> res;
            for (auto v: g[u][turn])
                if (v != p) {
                    res.push_back(doit(turn, v, u));
                }
            std::sort(res.begin(), res.end());
            if (mp.count(res) == 0) mp[res] = nodes++;
            return mp[res];
        };
        std::vector<int> fa(N), dist(N), ord(N);
        std::iota(ord.begin(), ord.end(), 0);
        std::function<void(int, int, int)> dfs = [&](int turn, int u, int p) -> void {
            fa[u] = p;
            for (auto v: g[u][turn]) {
                if (v == p) continue;
                dist[v] = dist[u] + 1;
                dfs(turn, v, u);
            }
        };
        std::vector<std::vector<int>> root(2);
        for (int turn = 0; turn < 2; turn++) {
            dfs(turn, 0, -1);
            sort(ord.begin(), ord.end(), [&](int i, int j) { return dist[i] < dist[j]; });
            int c = ord.back();
            dist[c] = 0;
            dfs(turn, c, -1);
            std::sort(ord.begin(), ord.end(), [&](int i, int j) { return dist[i] < dist[j]; });
            int cc = ord.back();
            std::vector<int> path;
            while (cc != c) {
                path.push_back(cc);
                cc = fa[cc];
            }
            path.push_back(cc);
            int sz = static_cast<int>(path.size());
            root[turn].push_back(path[sz / 2]);
            if (sz % 2 == 0) root[turn].push_back(path[sz / 2 - 1]);
        }
        bool iSSuccess = false;
        for (auto ra: root[0]) {
            for (auto rb: root[1]) {
                mp.clear();
                if (doit(0, ra, -1) == doit(1, rb, -1)) {
                    iSSuccess = true;
                    break;
                }
            }
            if (iSSuccess) {
                break;
            }
        }
        std::cout << (iSSuccess ? "YES" : "NO") << "\n";

    }
    return 0;
}