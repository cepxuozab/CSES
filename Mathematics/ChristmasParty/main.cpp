#include <cstdint>
#include <iostream>
#include <vector>

constexpr int MOD = 1e9 + 7;

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int64_t> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
    std::cout << dp.back();
}
