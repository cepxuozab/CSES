#include <iostream>
#include <vector>
#include <cstdint>
#include <deque>


auto main() -> int {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> h(n), s(n), k(n);
    for (int &i: h) std::cin >> i;
    for (int &i: s) std::cin >> i;
    for (int &i: k) std::cin >> i;
    std::vector<std::vector<int64_t>> dp(n + 1, std::vector<int64_t>(x + 1));
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < h[i - 1]; j++) {
            std::deque<std::pair<int64_t, int64_t>> dq;
            for (int l = j; l <= x; l += h[i - 1]) {
                auto ps = dp[i - 1][l] - ((l - j) / h[i - 1]) * s[i - 1];
                while (!dq.empty() && dq.back().second < ps) {
                    dq.pop_back();
                }
                while (!dq.empty() && (l - dq.front().first) / h[i - 1] > k[i - 1]) {
                    dq.pop_front();
                }
                dq.emplace_back(l, ps);
                dp[i][l] = dq.front().second + ((l - j) / h[i - 1]) * s[i - 1];
                ans = std::max(ans, dp[i][l]);
            }
        }
    }
    std::cout << ans;
}