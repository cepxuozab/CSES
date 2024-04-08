#include <iostream>
#include <vector>
#include <cstdint>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> arr(n + 1);
    std::vector<int64_t> prefix(n + 1);
    std::vector pos(n + 1, std::vector<int>(n + 1));
    std::vector dp(n + 2, std::vector<int64_t>(n + 2));
    for (int i = 1; i <= n; i++) {
        std::cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
        pos[i][i] = i;
    }
    for (int tam = 1; tam < n; tam++) {
        for (int i = 1; i + tam <= n; i++) {
            int j = i + tam;
            dp[i][j] = dp[i][pos[i][j - 1]] + dp[pos[i][j - 1] + 1][j] + prefix[j] - prefix[i - 1];
            pos[i][j] = pos[i][j - 1];
            for (int k = pos[i][j] + 1; k <= pos[i + 1][j]; k++) {
                if (dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1];
                    pos[i][j] = k;
                }
            }
        }
    }
    std::cout << dp[1][n];
}