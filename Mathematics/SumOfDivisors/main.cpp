#include <cstdint>
#include <iostream>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr int MOD = 1000000007;

auto sigma(int64_t x) -> int64_t {
    return ((x % MOD) * ((x + 1) % MOD) / 2) % MOD;
}
auto main() -> int {
    int64_t N;
    std::cin >> N;
    int64_t sum = 0;
    for (int64_t l = 1; l <= N; l++) {
        int64_t r = N / (N / l);
        sum += (N / l) % MOD * (sigma(r) - sigma(l - 1) + MOD) % MOD;
        sum = (sum + MOD) % MOD;
        l = r;
    }
    std::cout << sum;
}