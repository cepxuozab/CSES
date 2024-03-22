/**
* @brief Tasks and Deadlines
 * @link https://cses.fi/problemset/task/1630/
 * @date 21.01.2024
*/

#include <iostream>
#include <vector>
#include <algorithm>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Task {
    int duration{};
    int deadline{};

    auto operator<=>(Task const &other) const = default;
};


auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<Task> tasks(n);
    for (auto &[duration, deadline]: tasks) {
        std::cin >> duration >> deadline;
    }
    std::ranges::sort(tasks);
    long long timer{};
    long long reward{};
    for (auto const &[duration, deadline]: tasks) {
        timer += duration;
        reward += (deadline - timer);
    }
    std::cout << reward;
    return 0;
}

