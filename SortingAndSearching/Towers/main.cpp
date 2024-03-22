/**
* @brief Towers
 * @link https://cses.fi/problemset/task/1073/
 * @date 21.01.2024
*/

#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <utility>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> towers;
    while (n-- != 0) {
        int x;
        std::cin >> x;
        auto poz = std::ranges::distance(towers.begin(), std::ranges::upper_bound(towers, x));
        if (std::cmp_equal(poz, towers.size())) {
            towers.push_back(x);
        } else {
            towers[poz] = x;
        }
    }
    std::cout << towers.size() << '\n';
}