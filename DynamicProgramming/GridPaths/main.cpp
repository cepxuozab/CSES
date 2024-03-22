#include <iostream>
#include <vector>
#include <string>

auto NumberOfPath(std::vector<std::string> const &grid) -> int;

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<std::string> grid(n);
    for (auto &row: grid) {
        std::cin >> row;
    }
    std::cout << NumberOfPath(grid);
}

auto NumberOfPath(std::vector<std::string> const &grid) -> int {
    constexpr int MOD = 1000000007;
    size_t const n = grid.size();
    std::vector<int> dp(n, 0);
    dp[0] = 1;
    for (size_t i = 0; i < n; ++i) {
        auto const &row = grid[i];
        std::vector<int> ndp(n, 0);
        ndp[0] = row[0] == '.' ? dp[0] : 0;
        for (size_t j = 1; j < n; ++j) {
            if (row[j] == '.') {
                ndp[j] = (ndp[j - 1] + dp[j]) % MOD;
            }
        }
        dp.swap(ndp);
    }
    return dp.back();
}
