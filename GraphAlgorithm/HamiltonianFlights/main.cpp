#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

[[maybe_unused]] static auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr int P = 1e9 + 7;

void Add(int &x, int y) {
    x += y;
    if (x >= P)
        x -= P;
}

auto main() -> int {
    int n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> graph(n);
    while (q--) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
    }
    int M = 1 << n;
    std::vector<std::vector<int>> dp(n, std::vector<int>(M));
    dp[0][1] = 1;
    for (int m = 0; m < M; ++m) {
        for (int i = 0; i < n; ++i) {
            if ((m & (1 << i)) && dp[i][m]) {
                for (int j: graph[i]) {
                    if (!(m & (1 << j))) {
                        Add(dp[j][m ^ (1 << j)], dp[i][m]);
                    }
                }
            }
        }
    }
    std::cout << dp.back().back();
}