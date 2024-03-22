#include <cstdint>
#include <iostream>
#include <vector>

[[maybe_unused]] static auto const FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr int64_t MOD = 1000000007;
constexpr int64_t SIZE = 1000001;

static const auto factorial = []() {
    std::vector<int64_t> fact(SIZE);
    fact[0] = 1;
    for (int64_t i = 1; i < SIZE; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    return fact;
}();

auto bin_pow(int64_t base, int64_t p) -> int64_t {
    if (p == 1) {
        return base;
    }

    if (p % 2 == 0) {
        int64_t t = bin_pow(base, p / 2);
        return t * t % MOD;
    }
    return bin_pow(base, p - 1) * base % MOD;
}

auto inverse_element(int64_t x) -> int64_t {
    return bin_pow(x, MOD - 2);
}

auto divide(int64_t a, int64_t b) -> int64_t {
    return a * inverse_element(b) % MOD;
}

auto binomial_coeff(int64_t n, int64_t r) -> int64_t {
    auto one = (factorial[r] * factorial[n - r]) % MOD;
    return divide(factorial[n], one);
}

auto main() -> int {
    int n;
    std::cin >> n;
    while (n-- != 0) {
        int a;
        int b;
        std::cin >> a >> b;
        std::cout << binomial_coeff(a, b) << '\n';
    }
    return 0;
}
