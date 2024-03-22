#include <cstdint>
#include <iostream>

auto Exponentiation(int64_t a, int64_t b) -> int64_t {
    int64_t ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
        constexpr int MOD = 1000000007;
        a %= MOD;
        ans %= MOD;
    }
    return ans;
}

auto main() -> int {
    int number_of_queries;
    std::cin >> number_of_queries;
    for (int i = 0; i < number_of_queries; ++i) {
        int64_t a, b;
        std::cin >> a >> b;
        std::cout << Exponentiation(a, b) << '\n';
    }
}