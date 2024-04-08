#include <iostream>
#include <vector>
#include <cstdint>

auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;
    std::vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    int64_t lo = 1, hi = 1e18, cost;
    while (lo < hi) {
        auto mid = (hi + lo) / 2;
        std::vector<int64_t> dp(n + 1, 1e18), f(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int64_t s = 0;
            for (int j = i; j > 0; --j) {
                s += a[j];
                int64_t r = dp[j - 1] + mid + s * s;
                if (r <= dp[i]) {
                    dp[i] = r;
                    f[i] = f[j - 1] + 1;
                }
            }
        }

        if (f[n] > k) lo = mid + 1;
        else hi = mid, cost = dp[n] - mid * k;
    }
    std::cout << cost << '\n';
}