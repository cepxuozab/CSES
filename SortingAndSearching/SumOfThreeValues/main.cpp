/**
* @brief Sum of Three Values
 * @link https://cses.fi/problemset/task/1641/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <span>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto ThreeSumClosest(std::span<int> nums_, int target) -> std::vector<int> {
    std::vector<std::pair<int, int>> nums(nums_.size());
    for (size_t i = 0; i < nums_.size(); ++i) {
        nums[i] = {nums_[i], i + 1};
    }
    std::ranges::sort(nums);
    for (size_t i = 0; i + 2 < nums.size(); i++) {
        auto [k, y] = nums[i];
        if (k >= target) {
            return {};
        }
        for (size_t j = i + 1; j + 1 < nums.size(); j++) {
            auto [l, z] = nums[j];
            if (k + l >= target) {
                break;
            }
            auto it = std::lower_bound(nums.begin() + j + 1, nums.end(), std::pair(target - (k + l), 0));
            if (k + l + it->first != target) {
                continue;
            }
            return {y, z, it->second};
        }
    }
    return {};
}

auto main() -> int {
    int n;
    int target;
    std::cin >> n >> target;
    std::vector<int> nums(n);
    for (auto &num: nums) {
        std::cin >> num;
    }
    auto result = ThreeSumClosest(nums, target);
    if (result.empty()) {
        puts("IMPOSSIBLE");
        return 0;
    }
    for (int pos: result) {
        std::cout << pos << ' ';
    }
    return 0;
}

