#include <cstdint>
#include <iostream>
#include <vector>

constexpr int MOD = 1e9 + 7;

auto Bin_exp(int64_t n, int64_t pow) -> int64_t {
    int64_t res = 1;
    while (pow) {
        if (pow % 2 == 0) {
            n = (n % MOD * n % MOD) % MOD;
            pow /= 2;
        }

        res = (n % MOD * res % MOD) % MOD;
        pow--;
    }
    return res % MOD;
}

auto main() -> int {
    std::vector<int64_t> fact(2 * 1e6 + 1, 1);
    for (int i = 1; i <= 2 * 1e6; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    int n, m;
    std::cin >> n >> m;
    auto ans = fact[n - 1 + m];
    std::cout << ans * ((Bin_exp(fact[m], MOD - 2)) * (Bin_exp(fact[n - 1], MOD - 2)) % MOD) % MOD;
}
