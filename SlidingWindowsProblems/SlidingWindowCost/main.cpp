/**
* @brief Sliding Window Cost
 * @link https://cses.fi/problemset/task/1077/
 * @date 20.01.2024
*/

#include <iostream>
#include <memory>
#include <queue>
#include <vector>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


template<typename T>
void print_vector(std::vector<T> const &nums) {
    for (auto n: nums) {
        std::cout << n << ' ';
    }
    putchar('\n');
}


class Costs {
    int n;
    int window;
    std::vector<int> nums;
    std::priority_queue<std::pair<int, int>> left;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> right;
    std::vector<int64_t> costs;

public:
    Costs(int n_, int w)
            : n(n_), window(w), nums(n_) {}

    auto get_costs() -> std::vector<int64_t> {
        make_costs();
        return costs;
    }

private:
    void make_costs() {
        int middle = (window + 1) / 2;
        int size = 0;
        int64_t l_sum = 0;
        int64_t s_sum = 0;
        for (int i = 0; i < n; ++i) {
            auto &value = nums[i];
            std::cin >> value;
            s_sum += value;
            balance_queue(i);
            if (size < middle) {
                right.emplace(value, i);
                left.push(right.top());
                l_sum += right.top().first;
                right.pop();
                size++;
            } else {
                left.emplace(value, i);
                l_sum += value;
                right.push(left.top());
                l_sum -= left.top().first;
                left.pop();
            }
            balance_queue(i);
            if (i < window - 1) {
                continue;
            }
            auto curr_result =
                    1LL * size * left.top().first - l_sum + s_sum - l_sum - (1LL * window - size) * left.top().first;
            costs.push_back(curr_result);
            auto const prev_value = nums[i - window + 1];
            if (prev_value <= left.top().first) {
                l_sum -= prev_value;
                size--;
            }
            s_sum -= prev_value;
        }
    }

    void balance_queue(int i) {
        while (!left.empty() && left.top().second <= (i - window)) {
            left.pop();
        }
        while (!right.empty() && right.top().second <= (i - window)) {
            right.pop();
        }
    }
};

auto main() -> int {
    int n;
    std::cin >> n;
    int window;
    std::cin >> window;
    auto costs = std::make_unique<Costs>(n, window);
    print_vector(costs->get_costs());
    return 0;
}
