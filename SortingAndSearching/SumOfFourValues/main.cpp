/**
* @brief Sum of Four Values
 * @link https://cses.fi/problemset/task/1642/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <optional>


[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Triplet {
    int one;
    int two;
    int three;

    Triplet() = default;

    Triplet(int a, int b, int c)
            : one(a), two(b), three(c) {
    }

    auto operator<=>(Triplet const &other) const = default;
};

auto Four_value(std::vector<int> const &nums, int target) -> std::optional<std::vector<int>> {
    size_t const size = nums.size();
    std::vector<Triplet> triplets;
    for (size_t i = 0; i + 1 < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            triplets.emplace_back(nums[i] + nums[j], i + 1, j + 1);
        }
    }
    sort(triplets.begin(), triplets.end());
    for (size_t i = 0; i + 1 < triplets.size(); ++i) {
        int k = triplets[i].one;
        if (k > target / 2) {
            return std::nullopt;
        }
        auto it = lower_bound(triplets.begin() + i + 1, triplets.end(), Triplet{target - k, 0, 0});
        while (k + it->one == target) {
            auto curr = triplets[i];
            if (curr.two != it->two && curr.two != it->three && curr.three != it->two && curr.three != it->three) {
                return std::vector{curr.two, curr.three, it->two, it->three};
            }
            it++;
        }
    }
    return std::nullopt;
}


auto main() -> int {
    int n;
    int target;
    std::cin >> n >> target;
    std::vector<int> nums(n);
    for (auto &num: nums) {
        std::cin >> num;
    }
    auto result = Four_value(nums, target);
    if (!result.has_value()) {
        puts("IMPOSSIBLE");
        return 0;
    }
    for (int pos: result.value()) {
        std::cout << pos << ' ';
    }
    return 0;
}

