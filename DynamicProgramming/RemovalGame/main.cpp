#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (auto &num: arr) {
        std::cin >> num;
    }
    std::vector<std::vector<int64_t>> table(n, std::vector<int64_t>(n));
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {
            auto x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            auto y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            auto z = (i <= (j - 2)) ? table[i][j - 2] : 0;

            table[i][j] = std::max(arr[i] + std::min(x, y), arr[j] + std::min(y, z));
        }
    }

    std::cout << table.front().back();
}
