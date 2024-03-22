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

    auto get_kth_ancestor(int a, int k) -> int {
        if (depth[a] < k) {
            return -1;
        }

        for (int i = LG.lg[n]; i >= 0; --i) {
            if (k >= (1 << i)) {
                a = up[a][i];
                k -= (1 << i);
            }
        }

        return a;
    }


};


auto main() -> int {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1, x; i < n; ++i) {
        std::cin >> x;
        adj[i + 1].push_back(x);
        adj[x].push_back(i + 1);
    }
    LCA lca(adj);

    for (int i = 0, nod, k; i < q; ++i) {
        std::cin >> nod >> k;
        std::cout << lca.get_kth_ancestor(nod, k) << '\n';
    }
}


