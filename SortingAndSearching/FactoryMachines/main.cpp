/**
* @brief Factory Machines
 * @link https://cses.fi/problemset/task/1620/
 * @date 21.01.2024
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
    int time;
    std::cin >> n >> time;
    std::vector<int> needed_time(n);
    for (auto &need: needed_time) {
        std::cin >> need;
    }
    auto check = [&](int64_t val) -> bool {
        int64_t cnt{};
        for (auto &&elem: needed_time) {
            cnt += val / elem;
            if (cnt >= time) {
                return true;
            }
        }
        return false;
    };
    int64_t low = 0;
    int64_t hight = 1e18;
    while (low <= hight) {
        auto mid = low + (hight - low) / 2;
        check(mid) ? hight = mid - 1 : low = mid + 1;
    }
    std::cout << low;
    return 0;
}

