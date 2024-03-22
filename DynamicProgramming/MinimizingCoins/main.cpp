#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

auto MinimumNumbersCoins(std::vector<int> const &coins, int x) -> int;

auto main() -> int {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int &coin: coins) {
        std::cin >> coin;
    }
    std::cout << MinimumNumbersCoins(coins, x);
}


auto MinimumNumbersCoins(std::vector<int> const &coins, int x) -> int {
    std::vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; std::cmp_less(j, coins.size()); j++) {
            if (coins[j] <= i) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp.back() == x + 1 ? -1 : dp.back();
}