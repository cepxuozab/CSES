#include <array>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

struct FlowNetwork {
    static const long long INF = 1e18;
    int n;
    std::vector<std::vector<int>> adj; //adjacency list
    std::vector<std::vector<long long>> residue; //residual capacity matrix
    FlowNetwork(int n, std::vector<std::array<int, 3>> &edges) {
        this->n = n;
        adj = std::vector<std::vector<int>>(n);
        residue = std::vector<std::vector<long long>>(n, std::vector<long long>(n));
        for (auto &[u, v, c]: edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
            residue[u][v] += c;
        }
        for (auto &arr: adj) {
            std::ranges::sort(arr);
            auto const [first, last] = std::ranges::unique(arr);
            arr.erase(first, last);
        }
    }

    auto maxFlow(int source, int sink) -> long long {
        long long ans = 0;
        for (int hasAugmentingPath = 1; hasAugmentingPath;) {
            std::vector<int> prevNode(n, -1);
            std::vector<long long> minResidue(n);
            std::queue<int> q;
            q.push(source);
            minResidue[source] = INF;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int u: adj[v]) {
                    if (u != source && prevNode[u] == -1 && residue[v][u] > 0) {
                        prevNode[u] = v;
                        minResidue[u] = std::min(minResidue[v], residue[v][u]);
                        q.push(u);
                    }
                }
            }
            if (prevNode[sink] != -1) {
                for (int v = sink; prevNode[v] != -1;) {
                    int u = prevNode[v];
                    residue[u][v] -= minResidue[sink];
                    residue[v][u] += minResidue[sink];
                    v = u;
                }
                ans += minResidue[sink];
            } else {
                hasAugmentingPath = 0;
            }
        }
        return ans;
    }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<int, 3>> edges(m);
    for (int i = 0, u, v, c; i < m; ++i) {
        std::cin >> u >> v >> c;
        edges[i] = {u - 1, v - 1, c};
    }
    std::cout << FlowNetwork(n, edges).maxFlow(0, n - 1) << '\n';
}
