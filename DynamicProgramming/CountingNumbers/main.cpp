#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto Xpow(int64_t x, unsigned int y) -> int64_t {
    int64_t res = 1;
    while (y > 0) {
        if (y & 1) res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

auto Solution(int64_t x) -> int64_t {
    if (x < 0) return 0;
    if (x == 0) return 1;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int64_t i = static_cast<int64_t>(log10(1.0 * x)) - 1; i >= 0; i--) {
            int64_t m = Xpow(10, i);
            if (x / (m * 10) % 10 == x / m % 10) {
                x = (x / m - 1) * m + (m - 1);
                flag = 1;
            }
        }
    }
    int64_t n = static_cast<int64_t>(log10(1.0 * x)) + 1;
    std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(2)); //dp[n][0] = free, dp[n][1] = contrained
    dp[0][0] = 1, dp[0][1] = 1;
    int64_t ans = 1;
    int64_t m = 1;
    for (int64_t i = 1; i < n; i++, m *= 10) {
        dp[i][0] = Xpow(9, i);
        dp[i][1] = (x / m % 10) * dp[i - 1][0] + dp[i - 1][1];
        if (x / m % 10 > x / (m * 10) % 10) dp[i][1] -= dp[i - 1][0];
        ans += dp[i][0];
    }
    dp[n][1] = (x / m % 10 - 1) * dp[n - 1][0] + dp[n - 1][1];
    return ans + dp[n][1];
}

auto main() -> int {
    int64_t x, y;
    std::cin >> x >> y;
    std::cout << Solution(y) - Solution(x - 1);


}