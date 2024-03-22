#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>

[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int a;
    int b;
    std::cin >> a >> b;
    std::vector<std::vector<int>> dp(a + 1, std::vector<int>(b + 1));
    for (int i = 2; i <= a; ++i) {
        dp[i][1] = i - 1;
    }
    for (int i = 2; i <= b; ++i) {
        dp[1][i] = i - 1;
    }
    for (int i = 2; i <= a; ++i) {
        for (int j = 2; j <= b; ++j) {
            if (i != j) {
                int ans = std::numeric_limits<int>::max();
                for (int k = 1; k < i; ++k) {
                    ans = std::min(ans, dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k = 1; k < j; ++k) {
                    ans = std::min(ans, dp[i][k] + dp[i][j - k] + 1);
                }
                dp[i][j] = ans;
            }
        }
    }
    std::cout << dp[a][b] << '\n';
}