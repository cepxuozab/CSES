#include <iomanip>
#include <iostream>
#include <vector>

auto main() -> int
{
    std::vector<double> dp(610, 0.0);
    int n, a, b;
    std::cin >> n >> a >> b;
    dp[0] = 1.0;
    for (int i = 1; i <= n; i++) {
        for (int j = 6 * i; j >= 0; j--) {
            dp[j] = 0;
            for (int k = 1; k <= 6; k++) {
                if (j - k < 0) continue;
                dp[j] += dp[j - k];
            }
            dp[j] /= 6.0;
        }
    }
    double ans = 0.0;
    for (int i = a; i <= b; i++) { ans += dp[i]; }
    std::cout << std::setprecision(6) << std::fixed << ans;
}
