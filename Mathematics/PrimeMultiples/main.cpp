#include <bitset>
#include <cstdint>
#include <iostream>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    constexpr int64_t INF = 1LL << 60;
    int64_t n;
    int k;
    std::cin >> n >> k;
    std::vector<int64_t> primes(k);
    for (auto& prime : primes) {
        std::cin >> prime;
    }
    int64_t ans = 0;
    for (int64_t i = 1; i < 1LL << k; i++) {
        int64_t x = -1;
        if (auto const count = std::bitset<64>(i).count(); count & 1) x = 1;
        int64_t y = n;
        int64_t z = 1;
        for (int j = 0; j < k; j++) {
            if (i >> j & 1) {
                if (z >= n / primes[j] + 1) {
                    z = INF;
                    break;
                }
                z = z * primes[j];
            }
        }
        y /= z;
        ans += x * y;
    }
    std::cout << ans;
}