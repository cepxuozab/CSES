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
    for(int i =0;std::cmp_less(i, coins.size());++i){
        for (int j = 1; j <= sum; j++){
            if (j-coins[i]>=0)dp[j]+= dp[j-coins[i]];
            dp[j]%=MOD;
        }
    }
    return static_cast<int>(dp.back());
}