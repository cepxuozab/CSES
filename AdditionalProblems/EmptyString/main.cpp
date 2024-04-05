#include <iostream>
#include <string>
#include <vector>
#include <string_view>

constexpr int MOD = 1e9 + 7;

auto Add(int a, int b) -> int {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

auto Multiply(int a, int b) -> int { return int(1LL * a * b % MOD); }

auto EmptyString(std::string_view str) -> int {
    int n = static_cast<int>(str.size());
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> choose(n / 2 + 1, std::vector<int>(n / 2 + 1));
    choose[0][0] = 1;
    for (int i = 1; i <= n / 2; ++i) {
        choose[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            choose[i][j] = Add(choose[i - 1][j], choose[i - 1][j - 1]);
    }
    for (int i = 0; i + 1 <= n; ++i) dp[i + 1][i] = 1;
    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j < n; j += 2) {
            for (int k = i + 1; k <= j; k += 2)
                if (str[i] == str[k]) {
                    int temp = Multiply(dp[i + 1][k - 1], dp[k + 1][j]);
                    temp = Multiply(temp, choose[(j - i + 1) / 2][(k - i + 1) / 2]);
                    dp[i][j] = Add(dp[i][j], temp);
                }
        }

    return dp[0][n - 1];
}

auto main() -> int {
    std::string str;
    std::cin >> str;
    std::cout << EmptyString(str);
}