#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>
constexpr int MOD = 1e9 + 7;

auto FastPow(int64_t a, int64_t b) -> int64_t {
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
	//burnside's lemma
    //no. of objects = avg. no of symmetrical pictures over all symmetries.
    int64_t ans = 0;
    for (int k = 0; k < n; k++) ans = (ans + FastPow(m, std::gcd(k, n))) % MOD;
    std::cout << (ans * FastPow(n, MOD - 2)) % MOD;
}
