#include <algorithm>
#include <string>
#include <string_view>
#include <iostream>
#include <utility>
#include <vector>

[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


auto MinDistance(std::string_view word1, std::string_view word2) -> int {
    size_t const m = word1.size();
    size_t const n = word2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; std::cmp_less_equal(i, m); ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; std::cmp_less_equal(j, n); ++j) {
        dp[0][j] = j;
    }
    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
            }
        }
    }
    return dp.back().back();
}

auto main() -> int {
    std::string one, two;
    std::cin >> one >> two;
    std::cout << MinDistance(one, two) << '\n';
}