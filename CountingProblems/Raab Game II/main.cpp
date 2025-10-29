#include <iostream>
#include <vector>

int main() {
    constexpr int c = 5005;
    constexpr long long mod = 1000000007;

    std::vector<std::vector<long long>> dp(c, std::vector<long long>(c, 0));
    std::vector<std::vector<long long>> alatt(c, std::vector<long long>(c, 0));
    std::vector<long long> fact(c, 1);

    for (int i = 0; i < c; ++i) {
        if (i > 0) fact[i] = fact[i - 1] * i % mod;
        for (int j = 0; j <= i; ++j) {
            alatt[i][j] = (j == 0 ? 1 : (alatt[i - 1][j] + alatt[i - 1][j - 1]) % mod);
        }
    }

    dp[0][0] = 1;
    for (int i = 2; i < c; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i][j] = ((i - 1) * dp[i - 2][j - 1] % mod +
                        j * dp[i - 1][j] % mod +
                        (i - j) * dp[i - 1][j - 1] % mod) % mod;
        }
    }

    int w;
    std::cin >> w;
    while (w--) {
        int n, a, b;
        std::cin >> n >> a >> b;
        if (a + b > n) {
            std::cout << 0 << '\n';
        } else {
            long long res = alatt[n][a + b] * dp[a + b][a] % mod * fact[n] % mod;
            std::cout << res << '\n';
        }
    }

    return 0;
}
