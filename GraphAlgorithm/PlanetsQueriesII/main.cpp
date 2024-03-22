#include <array>
#include <iostream>
#include <tuple>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    constexpr int INF = 1e9;
    constexpr int LOG = 20;

    int n, q;
    std::cin >> n >> q;

    std::vector<std::array<int, LOG>> nxt(n);
    std::vector<std::vector<int>> g(n);  // undirected graph
    int to;

    for (int i = 0; i < n; i++) {
        std::cin >> to;
        nxt[i][0] = --to;
        g[i].push_back(to);
        g[to].push_back(i);
    }

    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }

    std::vector<int> cmp(n, -1), dist(n, INF), pos_cycle(n, -1), tree_id(n, -1), cycle_len(n, -1);
    int id = 0;

    for (int i = 0; i < n; i++) {
        if (cmp[i] >= 0) continue;

        cmp[i] = id;
        std::vector<std::tuple<int, int>> st = {{i, -1}};
        int start{};

        while (!st.empty()) {
            auto [u, p] = st.back();
            st.pop_back();
            for (int v : g[u]) {
                if (p == v) continue;
                if (cmp[v] == -1) {
                    cmp[v] = id;
                    st.emplace_back(v, u);
                } else {
                    start = v;
                }
            }
        }

        int len = 0;
        int x = start;

        dist[x] = 0;
        pos_cycle[x] = len++;

        while (nxt[x][0] != start) {
            x = nxt[x][0];
            dist[x] = 0;
            pos_cycle[x] = len++;
        }

        // each vertex in the cycle is a root of a tree
        x = start;
        do {
            cycle_len[x] = len;
            for (int y : g[x]) {
                if (dist[y] == INF) {
                    st.emplace_back(y, x);
                    tree_id[x] = x;
                }
            }
            x = nxt[x][0];
        } while (x != start);

        while (!st.empty()) {
            auto [u, p] = st.back();
            st.pop_back();
            dist[u] = dist[p] + 1;
            tree_id[u] = tree_id[p];
            for (int v : g[u]) {
                if (v == p) continue;
                st.emplace_back(v, u);
            }
        }

        id++;
    }

    auto solve_queries = [&](int x, int y) -> int {
        if (cmp[x] != cmp[y] || dist[y] > dist[x]) {
            return -1;
        } else if (dist[x] == 0 && dist[y] == 0) {
            return (cycle_len[x] + pos_cycle[y] - pos_cycle[x]) % cycle_len[x];
        } else if (dist[x] > 0 && dist[y] == 0) {
            return dist[x] + (cycle_len[y] + pos_cycle[y] - pos_cycle[tree_id[x]]) % cycle_len[y];
        } else {
            if (tree_id[x] != tree_id[y]) {
                return -1;
            } else {
                // x must be an ancestor of y
                int d = dist[x] - dist[y];
                int l = x;
                int j = 0;
                while (d) {
                    if (d & 1) l = nxt[l][j];
                    j++;
                    d >>= 1;
                }
                return (l == y ? dist[x] - dist[y] : -1);
            }
        }
    };

    int a, b;
    for (int i = 0; i < q; i++) {
        std::cin >> a >> b;
        a--;
        b--;
        std::cout << solve_queries(a, b) << "\n";
    }

    return 0;
}