#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Graph {
    int n_{};
    std::vector<std::vector<int>> adi_list;
    std::vector<bool> visited;
    int cnt = 0;
    std::map<int, int> mp;
public:
    explicit Graph(int n) : n_(n), adi_list(n + 1), visited(n) {}

    void AddEdge(int from, int to) {
        adi_list[from].push_back(to);
        adi_list[to].push_back(from);
    }

    auto Excursion() -> std::vector<int> {
        Dfs();
        std::vector<int> v;
        for (auto [i, c]: mp) {
            int x = 0;
            while (1 << x < c) {
                v.push_back((1 << x) * i);
                c -= 1 << x;
                x++;
            }
            if (c)
                v.push_back(c * i);
        }
        int m = static_cast<int>(v.size());
        std::vector<int> dp(n_ + 1);
        dp[0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = n_; j >= 1; j--) {
                if (j >= v[i]) {
                    dp[j] = std::max(dp[j - v[i]], dp[j]);
                }
            }
        }
        return {std::next(dp.begin()), dp.end()};
    }

private:

    void Dfs() {
        for (int i = 0; i < n_; i++) {
            if (!visited[i + 1]) {
                cnt = 0;
                DfsImpl(i + 1);
                mp[cnt]++;
            }
        }
    }

    void DfsImpl(int u) {
        if (visited[u]) return;
        visited[u] = true;
        cnt++;
        for (auto i: adi_list[u]) DfsImpl(i);
    }
};

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    Graph graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        graph.AddEdge(x, y);
    }
    auto const ans = graph.Excursion();
    for (int i: ans) {
        std::cout << i;
    }
}