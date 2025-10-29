#include <iostream>
#include <vector>
#include <algorithm>

class GraphColoring {
private:
    int n;
    std::vector<std::vector<int>> adj;
    std::vector<int> degree;
    std::vector<int> order;
    std::vector<int> color;

    bool dfs(int idx, int current_max_color, int k) {
        if (current_max_color > k) {
            return false;
        }
        if (idx == n) {
            return true;
        }

        int u = order[idx];
        std::vector<bool> used_color(k + 1, false);
        for (int v: adj[u]) {
            if (color[v] != 0 && color[v] <= k) {
                used_color[color[v]] = true;
            }
        }

        for (int c = 1; c <= std::min(current_max_color + 1, k); ++c) {
            if (used_color[c]) continue;
            color[u] = c;
            int new_max = std::max(current_max_color, c);
            if (dfs(idx + 1, new_max, k)) {
                return true;
            }
            color[u] = 0;
        }
        return false;
    }

public:
    GraphColoring(int node_count)
            : n(node_count), adj(node_count + 1), degree(node_count + 1, 0), order(node_count),
              color(node_count + 1, 0) {
        for (int i = 0; i < node_count; ++i) {
            order[i] = i + 1;
        }
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    void solve() {
        std::sort(order.begin(), order.end(), [&](int x, int y) {
            return degree[x] > degree[y];
        });

        int k = 1;
        for (; k <= n; ++k) {
            std::fill(color.begin(), color.end(), 0);
            if (dfs(0, 0, k)) {
                break;
            }
        }

        std::cout << k << '\n';
        for (int i = 1; i <= n; ++i) {
            std::cout << color[i] << (i == n ? '\n' : ' ');
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    GraphColoring solver(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        solver.add_edge(a, b);
    }

    solver.solve();
    return 0;
}