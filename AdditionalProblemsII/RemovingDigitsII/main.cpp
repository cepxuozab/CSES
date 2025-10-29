#include <iostream>
#include <map>
#include <cstdint>
#include <vector>

using Pair = std::pair<int64_t, int64_t>;
using DP = std::vector<std::map<int64_t, Pair>>;


auto NumbersOfStep(DP &dp, int64_t cMax, int64_t val) -> Pair {
    if (val < 10) return {cMax || val, val - std::max(cMax, val)};
    if (dp[cMax].contains(val)) {
        return dp[cMax][val];
    }
    int64_t p = 1;
    while (p <= val / 10) p *= 10;
    auto Z = NumbersOfStep(dp, std::max(cMax, val / p), val % p);
    auto Z2 = NumbersOfStep(dp, cMax, val / p * p + Z.second);
    return dp[cMax][val] = {Z.first + Z2.first, Z2.second};
}


auto main() -> int {
    int64_t n;
    std::cin >> n;
    DP dp(10);
    std::cout << NumbersOfStep(dp, 0, n).first;
}