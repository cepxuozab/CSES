/**
 * @brief Stick Lengths
 * @link https://cses.fi/problemset/task/1074
 * @date 15.01.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int64_t n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &a: arr) {
        std::cin >> a;
    }
    sort(arr.begin(), arr.end());
    auto mid = arr[n / 2];
    int64_t answer = 0;
    for (int a: arr) {
        answer += abs(a - mid);
    }
    std::cout << answer << '\n';

    return 0;
}
