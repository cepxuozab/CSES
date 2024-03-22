#include <cstdint>
#include <iostream>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr int MOD = 1000000007;

auto Exponentiation(int64_t a, int64_t b) -> int64_t {
    int64_t ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int64_t> x(n), k(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> k[i];
    }
    int64_t tau = 1;
    for (int i = 0; i < n; i++) tau = (tau * (k[i] + 1)) % MOD;
    int64_t sigma = 1;
    for (int i = 0; i < n; i++) {
        auto numerator = (Exponentiation(x[i], k[i] + 1) - 1 + MOD) % MOD;
        auto denominator = Exponentiation(x[i] - 1, MOD - 2);
        auto geoSum = numerator * denominator % MOD;
        sigma = (sigma * geoSum) % MOD;
    }
    int64_t pi = 1;
    int64_t mu = 1;
    for (int i = 0; i < n; i++) {
        auto p = Exponentiation(x[i], k[i] * (k[i] + 1) / 2);
        mu = Exponentiation(mu, k[i] + 1) * Exponentiation(p, pi) % MOD;
        pi = (pi * (k[i] + 1)) % (MOD - 1);
    }
    printf("%lld %lld %lld\n", tau, sigma, mu);
}