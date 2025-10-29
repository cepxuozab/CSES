#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>

constexpr int MOD = 1e9 + 7;

auto LogExp(int64_t base, int64_t power) -> int64_t {
    int64_t res = 1;
    while (power) {
        if (power & 1)
            res = (res * base) % MOD;

        base = (base * base) % MOD;
        power >>= 1;
    }
    return res;
}

auto InvMod(int64_t x) { return LogExp(x, MOD - 2); }

auto Comb(int64_t n, int64_t k, std::vector<int64_t> const &fact) -> int64_t {
    auto res = fact[n];
    res = (res * InvMod(fact[k])) % MOD;
    res = (res * InvMod(fact[n - k])) % MOD;
    return res;
}

auto main() -> int {
    int n, k;
    std::cin >> n >> k;
    std::vector<int64_t> fact;
    fact.resize(std::max(n, k) + 5);
    fact[0] = 1;
    for (int64_t i = 1; std::cmp_less(i, fact.size()); ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    auto ans = LogExp(k, n);
    for (int64_t i = 1; i < k; ++i)
        ans = (ans - LogExp(-1, k - 1 - i) * (LogExp(i, n) * Comb(k, i, fact)) % MOD + MOD) % MOD;
    std::cout<<ans;
}

