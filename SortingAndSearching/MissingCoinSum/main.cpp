/**
 * @brief Missing Coin Sum
 * @link https://cses.fi/problemset/task/2183
 * @date 15.01.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int64_t> coins(n);
    for (auto &coin: coins) {
        std::cin >> coin;
    }
    std::sort(coins.begin(), coins.end());
    std::vector<int64_t> arr(n + 1);
    arr[0] = 1;
    std::copy(coins.begin(), coins.end(), arr.begin() + 1);
    std::partial_sum(arr.begin(), arr.end(), arr.begin());
    for (int i = 0; i < n; ++i) {
        if (arr[i] < coins[i]) {
            std::cout << arr[i];
            return 0;
        }
    }
    std::cout << arr.back();
    return 0;

}
