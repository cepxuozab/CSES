/**
* @brief Subarray Divisibility
 * @link https://cses.fi/problemset/task/1662/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <cstdint>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int64_t> arr(n);
    int64_t sum = 0;
    int64_t cnt = 0;
    arr[0] = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        sum = (sum + x) % n;
        if (sum < 0) {
            sum += n;
        }
        cnt += arr[sum % n];
        ++arr[sum % n];
    }
    std::cout << cnt << '\n';

    return 0;
}

