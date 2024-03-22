/**
* @brief Array Division
 * @link https://cses.fi/problemset/task/1085/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto check(std::vector<int> const &arr, int64_t sum, int k) -> bool {
    auto comp = [&](auto z) { return z > sum; };
    if (std::any_of(arr.begin(), arr.end(), comp)) {
        return false;
    }
    int64_t s = 0;
    int i = 1;
    for (auto x: arr) {
        s + x > sum ? s = x, i++ : s += x;
    }
    return i <= k;
}

auto main() -> int {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    int64_t sum = 0;
    for (auto &a: arr) {
        std::cin >> a;
        sum += a;
    }
    int64_t answer = 0;
    for (int64_t i = sum / 2; i >= 1; i /= 2) {
        while (answer + i < sum && !check(arr, answer + i, k)) {
            answer += i;
        }
    }
    std::cout << answer + 1 << '\n';

    return 0;
}

