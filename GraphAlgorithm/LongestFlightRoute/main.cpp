#include <algorithm>
#include <iostream>
#include <memory>
#include <optional>
#include <vector>
#include <utility>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Graph {
private:
    size_t size;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> ans;
    std::vector<int> topo, parent;
    std::vector<bool> visited;

public:
    explicit Graph(size_t n)
        : size(n)
        , adj_list(n)
        , ans(n, -1)
        , parent(n, -1)
        , visited(n, false)

    {
    }
    void add(int a, int b) {
        a--;
        b--;
        adj_list[a].push_back(b);
    }
    auto get_answer() -> std::optional<std::vector<int>> {
        for (int i = 0; std::cmp_less(i,size); i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        std::ranges::reverse(topo);
        ans[0] = 1;
        for (int i = 0; std::cmp_less(i,size); i++) {
            int x = topo[i];
            if (ans[x] == -1) {
                continue;
            }
            for (int u : adj_list[x]) {
                if (ans[x] + 1 > ans[u]) {
                    ans[u] = ans[x] + 1;
                    parent[u] = x;
                }
            }
        }
        if (ans.back() == -1) {
            return std::nullopt;
        }
        std::vector<int> path;
        int u = static_cast<int>(size) - 1;
        while (true) {
            path.push_back(u);
            if (u == 0) {
                break;
            }
            u = parent[u];
        }
        std::ranges::reverse(path);
        return path;
    }

private:
    void dfs(int v) {
        visited[v] = true;
        for (int u : adj_list[v]) {
            if (!visited[u]) {
                dfs(u);
            }
        }
        topo.push_back(v);
    }
};

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    auto grahp = std::make_unique<Graph>(n);
    while (m-- != 0) {
        int a;
        int b;
        std::cin >> a >> b;
        grahp->add(a, b);
    }
    auto result = grahp->get_answer();
    if (!result.has_value()) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }
    auto ans = result.value();
    std::cout << ans.size() << '\n';
    for (int i : ans) {
        std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
}
