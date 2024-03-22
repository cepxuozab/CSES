#include <cstdint>
#include <iostream>

constexpr int MOD = 1e9 + 7;

auto FastPow(int64_t a, int64_t b) -> int64_t
{
    int64_t res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

auto main() -> int
{
    int64_t n;
    std::cin >> n;
    int64_t A = n * n;
    int64_t B = (A + 3 * (n & 1)) / 4;
    int64_t C = (A + (n & 1)) / 2;
    std::cout << (FastPow(2, A) + 2 * FastPow(2, B) + FastPow(2, C)) * FastPow(4, MOD - 2) % MOD;
}
