/**
* @brief Maximum Subarray Sum II
 * @link https://cses.fi/problemset/task/1644/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <deque>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


template<typename T>
void read_vector(std::vector<T> &nums) {
    for (auto &n: nums) {
        std::cin >> n;
    }
}

void solver() {
    int n;
    std::cin >> n;
    int left;
    std::cin >> left;
    int right;
    std::cin >> right;
    int diff = right - left;
    std::vector<int64_t> nums(n);
    read_vector(nums);
    std::vector<int64_t> summ(n);
    std::partial_sum(nums.begin(), nums.end(), summ.begin());
    int64_t left_sum = summ[left - 1];
    int64_t maxi = std::numeric_limits<int64_t>::min();
    std::deque<std::pair<int64_t, int>> deque;
    for (int i = left; i < right; ++i) {
        while (!deque.empty() && summ[i] > deque.back().first) {
            deque.pop_back();
        }
        deque.emplace_back(summ[i], i);
    }
    for (int i = left;; i++) {
        int64_t k = 0;
        if (!deque.empty()) {
            k = deque.front().first;
            k -= summ[i - 1];
        }
        auto r = left_sum;
        if (k > 0) {
            r += k;
        }
        if (r > maxi) {
            maxi = r;
        }
        if (i == n) {
            break;
        }
        left_sum -= nums[i - left];
        left_sum += nums[i];

        while (!deque.empty() && deque.front().second <= i) {
            deque.pop_front();
        }
        if (i + diff < n) {
            while (!deque.empty() && summ[i + diff] > deque.back().first) {
                deque.pop_back();
            }
            deque.emplace_back(summ[i + diff], i + diff);
        }
    }
    std::cout << maxi;
}

auto main() -> int {
    solver();
    return 0;
}