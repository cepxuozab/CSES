#include <iostream>
#include <vector>

[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    constexpr int MOD = 1000000007;
    int n, m;
    std::cin >> n >> m;
    std::vector<int> dp(1 << n);
    dp[0] = 1;

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::vector<int> ndp(1 << n);
            for (int mask = 0; mask < (1 << n); ++mask) {
                (ndp[mask] = dp[mask ^ (1 << j)]) %= MOD;
                if (j && (mask & (1 << j)) && (mask & (1 << (j - 1)))) {
                    (ndp[mask] += dp[mask ^ (1 << (j - 1))]) %= MOD;
                }
            }
            dp = ndp;
        }

    }
    std::cout << dp[(1 << n) - 1] ;
}