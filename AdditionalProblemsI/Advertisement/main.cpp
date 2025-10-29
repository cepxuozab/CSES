#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> heights(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> heights[i];
    }
    std::vector<int> left(n + 1);
    for (int i = 1; i <= n; i++) {
        left[i] = i - 1;
        while (heights[left[i]] >= heights[i]) left[i] = left[left[i]];
    }
    std::vector<int> right(n + 1);
    for (int i = n; i >= 1; i--) {
        right[i] = i + 1;
        while (heights[right[i]] >= heights[i]) right[i] = right[right[i]];
    }
    int64_t best = 0;
    for (int i = 1; i <= n; ++i) {
        best = std::max(best, static_cast<int64_t>(heights[i]) * (right[i] - left[i] - 1));
    }
    std::cout << best;
}
