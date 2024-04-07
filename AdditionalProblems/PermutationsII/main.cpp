#include <iostream>
#include <cstdint>
#include <vector>

constexpr int MOD = 1e9 + 7;

auto Permutation(int64_t n) -> int64_t {
    if (n < 4) {
        return n < 2 ? 1 : 0;
    }
    std::vector<int64_t> dp(n + 1);
    dp[0] = dp[1] = 1;
    dp[2] = dp[3] = 0;
    for (int64_t i = 4; i <= n; i++) {
        int64_t a = (i + 1) * dp[i - 1] % MOD;
        int64_t b = (i - 2) * dp[i - 2] % MOD;
        int64_t c = (i - 5) * dp[i - 3] % MOD;
        int64_t d = (i - 3) * dp[i - 4] % MOD;

        dp[i] = (a - b - c + d);
        while (dp[i] < 0)
            dp[i] += MOD;
        dp[i] %= MOD;
    }
    return dp.back();
}

auto main() -> int {
    int64_t n;
    std::cin >> n;
    std::cout << Permutation(n);
}