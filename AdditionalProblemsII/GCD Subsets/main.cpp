#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    const int mod = 1'000'000'007;
    std::vector<int> count(n + 1, 0);
    std::vector<long long> pow2(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        if (x <= n) {
            count[x]++;
        }
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }

    std::vector<long long> dp(n + 1, 0);

    for (int i = n; i >= 1; --i) {
        long long total_multiples = 0;
        for (int j = i; j <= n; j += i) {
            total_multiples += count[j];
        }

        long long ways = (pow2[total_multiples] - 1 + mod) % mod;

        for (int j = 2 * i; j <= n; j += i) {
            ways = (ways - dp[j] + mod) % mod;
        }

        dp[i] = ways;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << dp[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}