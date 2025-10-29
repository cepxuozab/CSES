#include <iostream>
#include <vector>

constexpr long long mod = 1000000007;

long long mod_exp(long long a, long long b) {
    long long x = 1;
    while (b) {
        if (b & 1) x = x * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return x;
}

long long comb(int n, int k, const std::vector<long long> &fact, const std::vector<long long> &finv) {
    return fact[n] * finv[k] % mod * finv[n - k] % mod;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> fact(n + 1, 1), finv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = i * fact[i - 1] % mod;
        finv[i] = mod_exp(fact[i], mod - 2);
    }

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; ++i) {
        long long s = 0;
        for (int j = 2; j <= i; ++j) {
            for (int k = 1; k <= i; ++k) {
                dp[i][j] = (dp[i][j] + (comb(i, k, fact, finv) * dp[i - k][j - 1] % mod) * dp[k][1] % mod) % mod;
            }
            s = (s + dp[i][j]) % mod;
        }
        long long power = mod_exp(2, (i * (i - 1) / 2) % (mod - 1));
        dp[i][1] = (power + mod - s) % mod;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << dp[n][i] % mod << '\n';
    }

    return 0;
}
