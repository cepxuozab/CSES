#include <iostream>
#include <vector>
#include <cstdint>
#include <ranges>

constexpr int kMod = int(1e9) + 7;

void add(auto &x, auto y) {
    x = (x + y) % kMod;
}

auto solve_parity(int n, int k, int i) -> std::vector<int64_t> {
    std::vector dp(n, std::vector<int64_t>(k + 3, 0));

    if (i == 0) {
        if (n == 1) {
            dp[i][0] = 1;
            dp[i][1] = 1;
            return dp[i];
        } else {
            dp[i][0] = 1;
            dp[i][1] = 2;
        }
    } else if (n >= 2) {
        if (n == 2) {
            dp[i][0] = 1;
            dp[i][1] = 2;
            return dp[i];
        } else {
            dp[i][0] = 1;
            dp[i][1] = 4;
            dp[i][2] = 2;
        }
    }

    for (i += 2; i < n - 1; i += 2) {
        for (auto j: std::ranges::iota_view(0, k + 1)) {
            add(dp[i][j], dp[i - 2][j]);
            add(dp[i][j + 1], dp[i - 2][j] * 2 * (i - j + 1));
            add(dp[i][j + 2], dp[i - 2][j] * (i - j + 1) * (i - j));
        }
    }

    if (i == n - 1) {
        for (auto j: std::ranges::iota_view(0, k + 1)) {
            add(dp[i][j], dp[i - 2][j]);
            add(dp[i][j + 1], dp[i - 2][j] * (i - j + 1));
        }
        return dp[i];
    } else {
        return dp[i - 2];
    }
}

auto solve() -> int64_t {
    int n, k;
    std::cin >> n >> k;

    if (n == 1) return 1;
    if (k > 2 * n - 2) return 0;

    auto ans1 = solve_parity(n, k, 0);
    auto ans2 = solve_parity(n, k, 1);

    int64_t ans = 0;
    for (auto i: std::ranges::iota_view(0, k + 1)) {
        add(ans, ans1[i] * ans2[k - i]);
    }
    return ans;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << solve() << '\n';
}