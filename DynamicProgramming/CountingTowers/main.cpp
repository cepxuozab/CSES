#include <iostream>
#include <cstdint>
#include <vector>

auto main() -> int {
    int mod = 1000000007;
    int t;
    std::cin >> t;
    std::vector<std::vector<int64_t>> dp(1e6 + 1, std::vector<int64_t>(2, 0));
    //dp[i][0] - ith level row united
    //dp[i][1] - ith level row not united
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        dp[i][0] = ((2 * dp[i - 1][0]) % mod + dp[i - 1][1] % mod) % mod;
        dp[i][1] = ((4 * dp[i - 1][1]) % mod + dp[i - 1][0] % mod) % mod;
    }
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }
    return 0;
}
