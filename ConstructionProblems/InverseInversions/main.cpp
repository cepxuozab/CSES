#include <iostream>
#include <cstdint>

auto main() -> int {
    int64_t n, k;
    std::cin >> n >> k;
    int64_t start = 1, end = n;
    for (int64_t i = n; i > 0; i--) {
        if (k > (i - 1) * (i - 2) / 2) {
            std::cout << end << " ";
            end--;
            k -= i - 1;
        } else {
            std::cout << start << " ";
            start++;
        }
    }
}