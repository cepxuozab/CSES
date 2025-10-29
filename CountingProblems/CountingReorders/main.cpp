#include <iostream>
#include <vector>
#include <string>

auto main() -> int {
    std::string s;
    std::cin >> s;
    const int mod = 1e9 + 7;
    int n = static_cast<int>(s.length()), ans = 0, cnt[26] = {};
    std::vector<int> letters;
    for (auto x: s)
        ++cnt[x - 'a'];
    for (int i = 0; i < 26; ++i)
        if (cnt[i])
            letters.emplace_back(i);
    int m = static_cast<int>(letters.size());
    std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1)), comb(n + 1, std::vector<int>(n + 1));
    comb[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }
    dp[1][0] = 1;
    for (int i = 0; i < m; ++i) {
        fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
        for (int j = 1; j <= cnt[letters[i]]; ++j)
            for (int k = 0; k <= n - j; ++k)
                dp[i & 1][j + k] = (dp[i & 1][j + k] +
                                    1LL * dp[(i & 1) ^ 1][k] * comb[cnt[letters[i]] - 1][j - 1] % mod *
                                    comb[j + k][j]) % mod;
    }
    for (int i = n, sgn = 1; i; --i, sgn *= -1) {
        ans += sgn * dp[(m & 1) ^ 1][i];
        if (ans < 0)
            ans += mod;
        else if (ans >= mod)
            ans -= mod;
    }
    std::cout << ans;
}