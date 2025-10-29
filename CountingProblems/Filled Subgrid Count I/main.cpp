#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> grid(n);
    for (std::string &row: grid) {
        std::cin >> row;
    }

    for (int target_char_index = 0; target_char_index < k; ++target_char_index) {
        long long total_squares = 0;
        // dp[0] и dp[1] — текущая и предыдущая строка
        std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int current_row = i % 2;
            int previous_row = current_row ^ 1;

            for (int j = 1; j <= n; ++j) {
                dp[current_row][j] = 0;
                char expected_char = static_cast<char>('A' + target_char_index);
                if (grid[i - 1][j - 1] == expected_char) {
                    dp[current_row][j] = 1 + std::min({
                                                              dp[previous_row][j],
                                                              dp[current_row][j - 1],
                                                              dp[previous_row][j - 1]
                                                      });
                    total_squares += dp[current_row][j];
                }
            }
        }

        std::cout << total_squares << '\n';
    }

    return 0;
}