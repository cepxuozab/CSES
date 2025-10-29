#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    constexpr int ALPHABET = 26;
    const long long INF = std::numeric_limits<long long>::max() / 4;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; ++j) {
            a[i][j] = s[j] - 'A';
        }
    }

    std::vector<std::vector<std::vector<long long>>> dp(
            ALPHABET, std::vector<std::vector<long long>>(2, std::vector<long long>(n + 1, INF))
    );

    long long ans = 0;
    int now = 1, old = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long mx = 0;
            for (int k = 0; k < m; ++k) {
                if (k == a[i - 1][j - 1]) {
                    dp[k][now][j] = 0;
                } else {
                    dp[k][now][j] = std::min({
                                                     dp[k][old][j],
                                                     dp[k][now][j - 1],
                                                     dp[k][old][j - 1]
                                             }) + 1;
                }
                mx = std::max(mx, dp[k][now][j]);
            }
            ans += std::max<long long>(std::min(i - mx, j - mx), 0);
        }
        std::swap(now, old);
    }

    std::cout << ans << '\n';
    return 0;
}
