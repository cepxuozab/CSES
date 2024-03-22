#include <cstdint>
#include <iostream>

auto Exponentiation(int64_t a, int64_t b, int const MOD) -> int64_t {
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
    int number_of_queries;
    std::cin >> number_of_queries;
    for (int i = 0; i < number_of_queries; ++i) {
        constexpr int MOD = 1000000007;
        int64_t a, b, c;
        std::cin >> a >> b >> c;
        std::cout << Exponentiation(a, Exponentiation(b, c, MOD - 1), MOD) << '\n';
    }
}