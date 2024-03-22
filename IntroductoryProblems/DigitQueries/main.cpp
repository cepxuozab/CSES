#include <cmath>
#include <iostream>
#include <string>
#include <cstdint>

auto main() -> int {
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int64_t k;
        std::cin >> k;
        int64_t length = 1, first = 1;
        while (k > 9LL * first * length) {
            k -= 9LL * length * first;
            length++;
            first *= 10LL;
        }
        auto [u, r] = std::lldiv(k - 1, length);
        std::cout << (std::to_string(first + u))[r] << '\n';
    }
}
