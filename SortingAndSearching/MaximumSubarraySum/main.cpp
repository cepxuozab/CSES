/**
 * @brief Maximum Subarray Sum
 * @link https://cses.fi/problemset/task/1643
 * @date 15.01.2024
 */

#include <limits>
#include <iostream>
#include <cstdint>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    int64_t maximum = std::numeric_limits<int>::min();
    int64_t current = std::numeric_limits<int>::min();
    while (n-- != 0) {
        int64_t num;
        std::cin >> num;
        current = current + num > num ? current + num : num;
        maximum = maximum > current ? maximum : current;
    }
    std::cout << maximum << '\n';
    return 0;
}

