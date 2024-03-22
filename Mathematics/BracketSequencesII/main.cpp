#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
constexpr int MOD = 1e9 + 7;

auto Inverse(int64_t i) -> int64_t {
    if (i == 1) return 1;
    return (MOD - ((MOD / i) * Inverse(MOD % i)) % MOD + MOD) % MOD;
}

auto main() -> int {
    int n;
    std::string str;
    std::cin >> n >> str;
    if (n & 1) {
        std::cout << 0;
        return 0;
    }
    int closed = 0, opened = 0;
    for (char ch : str) {
        if (ch == '(') {
            opened++;
            closed++;
        } else {
            closed--;
        }
        if (closed < 0) {
            std::cout << 0;
            return 0;
        }
    }
    n /= 2;
    n -= opened;
    if (n < 0) {
        std::cout << 0;
        return 0;
    }
    std::vector<int64_t> fact(2 * n + closed + 1);
    fact[0] = 1;
    for (int i = 1; i <= 2 * n + closed; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    int64_t ans = (fact[2 * n + closed] * Inverse(fact[n])) % MOD;
    ans *= (Inverse(fact[n + closed])) % MOD;
    ans %= MOD;
    ans *= ((closed + 1) * Inverse(n + closed + 1)) % MOD;
    ans %= MOD;
    std::cout << ans;
}
