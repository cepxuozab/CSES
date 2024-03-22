#include <iostream>
#include <algorithm>
#include <vector>

auto main() -> int {
    constexpr int MOD = 1e9 + 7;
    int n;
    std::cin >> n;
    int target = n * (n + 1) / 2;
    if (target & 1) {
        std::cout << 0;
        return 0;
    }
    target /= 2;

    std::vector<std::vector<int>> dp(n, std::vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            int left = j - i;
            if (left >= 0) {
                (dp[i][j] += dp[i - 1][left]) %= MOD;
            }
        }
    }
    std::cout << dp.back().back();
}
