#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

auto NumberOfWay(std::vector<int> const &coins, int sum) -> int;

auto main() -> int {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int &coin: coins) {
        std::cin >> coin;
    }
    std::ranges::sort(coins);
    std::cout << NumberOfWay(coins, x);
}


auto NumberOfWay(std::vector<int> const &coins, int sum) -> int {
    constexpr int MOD = 1'000'000'007;
    std::vector<long long> dp(sum + 1);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++) {
        for (int j = 0; std::cmp_less(j, coins.size()) && i - coins[j] >= 0; ++j) {
            dp[i] += dp[i - coins[j]];
        }
        if (dp[i] >= MOD) {
            dp[i] %= MOD;
        }

    }
    return static_cast<int>(dp.back());
}