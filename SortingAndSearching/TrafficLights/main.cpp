/**
* @brief Traffic Lights
 * @link https://cses.fi/problemset/task/1163/
 * @date 21.01.2024
*/

#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <span>
#include <set>
#include <limits>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto TrafficLights(std::span<int> positions, int length) -> std::vector<int> {
    int const size = static_cast<int>(positions.size());
    std::set<int> sets{0, length};
    sets.insert(positions.begin(), positions.end());
    std::vector<int> length_of_the_longest_passage;
    length_of_the_longest_passage.reserve(size);
    int ans = std::numeric_limits<int>::min();
    for (auto it = sets.begin(); next(it) != sets.end(); ++it) {
        ans = std::max(ans, *next(it) - *it);
    }
    length_of_the_longest_passage.push_back(ans);
    for (int i = size - 1; i >= 1; --i) {
        auto it = sets.find(positions[i]);
        ans = std::max(*next(it) - *prev(it), ans);
        sets.erase(it);
        length_of_the_longest_passage.push_back(ans);
    }
    std::ranges::reverse(length_of_the_longest_passage);
    return length_of_the_longest_passage;
}

auto main() -> int {
    int length;
    int n;
    std::cin >> length >> n;
    std::vector<int> positions(n);
    for (int &position: positions) {
        std::cin >> position;
    }
    auto const ans = TrafficLights(positions, length);
    for (int i: ans) {
        std::cout << i << ' ';
    }

}