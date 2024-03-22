/**
* @brief Reading Books
 * @link https://cses.fi/problemset/task/1631/
 * @date 21.01.2024
*/

#include <iostream>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


auto main() -> int {
    int n;
    std::cin >> n;
    long long sum{};
    long long mx{};
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        mx = mx < x ? x : mx;
        sum += x;
    }
    std::cout << std::max(sum, 2 * mx);
    return 0;
}

