/**
* @brief Nearest Smaller Values
 * @link https://cses.fi/problemset/task/1645/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>


[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto Nearest(std::vector<int> const &arr) -> std::vector<int> {
    size_t const size = arr.size();
    std::vector<std::pair<int, int>> stack;
    std::vector<int> result(size);
    for (size_t i = 0; i < arr.size(); ++i) {
        while (!stack.empty() && stack.back().first >= arr[i]) {
            stack.pop_back();
        }
        result[i] = (stack.empty() ? 0 : stack.back().second);
        stack.emplace_back(arr[i], i + 1);
    }
    return result;
}


auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    for (auto &num: nums) {
        std::cin >> num;
    }
    auto const answer = Nearest(nums);
    for (int ans: answer) {
        std::cout << ans << '\n';
    }
    std::cout << '\n';

    return 0;
}

