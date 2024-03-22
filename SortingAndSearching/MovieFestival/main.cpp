/**
 * @brief Movie Festival
 * @link https://cses.fi/problemset/task/1629
 * @date 15.01.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> movies;
    movies.reserve(n);
    while (n-- != 0) {
        int starting;
        int ending;
        std::cin >> starting >> ending;
        movies.emplace_back(ending, starting);
    }
    sort(movies.begin(), movies.end());
    int answer = 0;
    int curr = 0;
    for (auto const &[end, start]: movies) {
        if (start >= curr) {
            curr = end;
            answer++;
        }
    }
    std::cout << answer << '\n';
}
