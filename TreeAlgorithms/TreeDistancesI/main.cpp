#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Tree {
    std::vector<std::vector<int>> adj_list;
    std::vector<int> ans;
    std::vector<int> depth;
public:
    explicit Tree(size_t N);

    void AddEdge(int u, int v);

    auto GetDistances() -> std::vector<int>;

private:
    void Dfs1(int u = 0, int p = -1);

    void Dfs2(int u = 0, int p = -1, int d = 0);
};

auto main() -> int {
    int n;
    std::cin >> n;
    auto tree = std::make_unique<Tree>(n);
    for (int i = 0; i + 1 < n; ++i) {
        int a;
        int b;
        std::cin >> a >> b;
        a--, b--;
        tree->AddEdge(a, b);
    }

    auto const answer = tree->GetDistances();
    for (int i: answer) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}


Tree::Tree(size_t N) : adj_list(N), ans(N), depth(N) {

}

void Tree::AddEdge(int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);

}

void Tree::Dfs1(int u, int p) {
    for (int v: adj_list[u]) {
        if (v != p) {
            Dfs1(v, u);
            depth[u] = std::max(depth[u], depth[v] + 1);
        }
    }

}

void Tree::Dfs2(int u, int p, int d) {
    int max1 = 0, max2 = 0;
    for (int v: adj_list[u]) {
        if (v != p) {
            int dpt = depth[v] + 1;
            if (dpt > max1) {
                max2 = max1;
                max1 = dpt;
            } else if (dpt > max2) {
                max2 = dpt;
            }
        }
    }
    ans[u] = std::max(max1, d);

    for (int v: adj_list[u]) {
        if (v != p) {
            int take = max1;
            if (1 + depth[v] == max1) {
                take = max2;
            }
            Dfs2(v, u, std::max(take, d) + 1);
        }
    }

}

auto Tree::GetDistances() -> std::vector<int> {
    Dfs1();
    Dfs2();
    return ans;
}
