#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

auto main() -> int {
    constexpr int MOD = 1e9 + 7;
    int n, k;
    std::cin >> n >> k;
    int const maxK = n * (n - 1) / 2;
    std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(maxK + 1));
    for (int i = 1; i <= n; i++) {
        int r = i * (i - 1) / 2;
        dp[i][0] = dp[i][r] = 1;
        for (int j = 1; j <= r / 2; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            if (j - i >= 0) dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
        }
        for (int j = r / 2 + 1; j < r; j++) dp[i][j] = dp[i][r - j];
    }
    std::cout << dp[n][k];
}