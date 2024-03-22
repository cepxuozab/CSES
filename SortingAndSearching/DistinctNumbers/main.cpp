/**
 * @brief Distinct Numbers
 * @link https://cses.fi/problemset/task/1621
 * @date 15.01.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int &i: arr) {
        std::cin >> i;
    }
    sort(arr.begin(), arr.end());
    auto it = std::unique(arr.begin(), arr.end());
    std::cout << it - arr.begin() << '\n';
    return 0;
}
