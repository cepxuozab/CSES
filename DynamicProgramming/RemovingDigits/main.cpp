#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

auto Digits(int n) -> std::vector<int>;

auto MinimumNumberSteps(int n) -> int;

auto main() -> int {
    int n;
    std::cin >> n;
    std::cout << MinimumNumberSteps(n);
}

auto Digits(int n) -> std::vector<int> {
    std::vector<int> ans;
    while(n!=0){
        ans.push_back(n%10);
        n/=10;
    }
    std::ranges::sort(ans);
    auto [start,end]=std::ranges::unique(ans);
    ans.erase(start,end);
    return ans;
}

auto MinimumNumberSteps(int n) -> int {
    std::vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        dp[i] = std::numeric_limits<int>::max() / 2;
        for (int j: Digits(i)) {
            dp[i] = std::min(dp[i], dp[i - j] + 1);
        }
    }
    return dp.back();
}
