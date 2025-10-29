#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <utility>

constexpr int64_t MOD = 1e9 + 7;

auto FastPow(int64_t a, int64_t b) -> int64_t {
    int64_t res = 1;
    while (b) {
        if (b % 2) {
            res = res * a;
            res %= MOD;
        }
        a = a * a;
        b /= 2;
        a %= MOD;
    }
    return res;
}

auto Coeff(int64_t m1, int64_t n1, std::vector<int64_t> const &fact, std::vector<int64_t> const &rev) -> int64_t {
    if (m1 == n1) return 1;
    if (n1 == 1) return m1;
    auto res = fact[m1] * rev[n1] % MOD * rev[m1 - n1] % MOD;
    return res % MOD;
}

auto main() -> int {
    int m, n;
    std::cin >> n >> m;
    std::vector<int64_t> fact, rev;
    fact.resize(2 * n + 1);
    rev.resize(2 * n + 1);
    fact[0] = 1;
    rev[0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        rev[i] = FastPow(fact[i], MOD - 2) % MOD;
    }
    std::vector<std::pair<int64_t, int64_t>> t;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        t.emplace_back(a, b);
    }
    t.emplace_back(n, n);
    std::sort(begin(t), end(t));
    std::vector<int64_t> dp(t.size(), 0);
    for (int i = 0; std::cmp_less(i, t.size()); i++) {
        auto [x, y] = t[i];
        dp[i] = Coeff(x + y - 2, x - 1, fact, rev);
        for (int j = 0; j < i; j++) {
            auto [a, b] = t[j];
            if (b > y) continue;
            dp[i] = (dp[i] - dp[j] * Coeff(x - a + y - b, x - a, fact, rev) % MOD + MOD) % MOD;
        }
    }
    std::cout << dp.back();
}
