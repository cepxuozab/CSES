#include <algorithm>
#include <iostream>
#include <vector>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct LCA {
private:
    struct LOG {
        std::vector<int> lg;

        LOG(int n) : lg(n + 2) {
            lg[1] = 0;
            for (int i = 2; i < n + 2; i++) {
                lg[i] = lg[i - 1];
                while ((1 << lg[i]) <= i) {
                    ++lg[i];
                }
                --lg[i];
            }
        }
    };

    LOG const LG = LOG(200'000);
public:

    int n;
    std::vector<int> depth;
    std::vector<std::vector<int>> up;

    LCA(std::vector<std::vector<int>> &adj, int root = 1) {
        n = int(adj.size());

        up = std::vector<std::vector<int>>(n, std::vector<int>(LG.lg[n] + 1));
        depth = std::vector<int>(n);

        auto dfs = [&](auto self, int node, int parent) -> void {
            up[node][0] = parent;
            for (int i = 1; i < LG.lg[n] + 1; ++i) {
                up[node][i] = up[up[node][i - 1]][i - 1];
            }
            for (auto &child: adj[node]) {
                if (child == parent) {
                    continue;
                }
                depth[child] = depth[node] + 1;
                self(self, child, node);
            }
        };

        dfs(dfs, root, 0);

    }

    auto get_lca(int a, int b) -> int {
        if (depth[a] < depth[b]) {
            std::swap(a, b);
        }

        int k = depth[a] - depth[b];
        for (int i = LG.lg[n]; i >= 0; --i) {
            if (k & (1 << i)) {
                a = up[a][i];
            }
        }

        if (a == b) {
            return a;
        }

        for (int i = LG.lg[n]; i >= 0; --i) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }

        return up[a][0];
    }

    auto distance(int a, int b) -> int {
        int c = get_lca(a, b);

        int x = depth[a] - depth[c];
        int y = depth[b] - depth[c];

        return x + y;
    }


};


auto main() -> int {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1, a, b; i < n; ++i) {
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    LCA lca(adj);

    for (int i = 0, u, v; i < q; ++i) {
        std::cin >> u >> v;
        std::cout << lca.distance(u, v) << '\n';
    }
}
