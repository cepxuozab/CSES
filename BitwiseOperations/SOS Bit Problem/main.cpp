#include <iostream>
#include <vector>

auto main() -> int {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    static int M = 22;
    std::vector<int> a(n), dp(1 << M, 0);
    for (int &i: a) {
        std::cin >> i;
        dp[i]++;
    }
    auto dp1 = dp;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (1 << M); j++) {
            if ((j >> i) & 1) {
                dp[j] += dp[j ^ (1 << i)];
            } else
                dp1[j] += dp1[j ^ (1 << i)];
        }
    }
    int cur = (1 << (M)) - 1;
    for (int i: a) {
        std::cout << dp[i] << ' ' << dp1[i] << ' ' << n - dp[(i ^ cur)] << "\n";
    }
}