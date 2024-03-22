#include <iostream>
#include <vector>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> arr(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> arr[i];
        sum += arr[i];
    }
    std::vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= arr[i]; --j) {
            if (dp[j - arr[i]] != 0) { dp[j] = 1; }
        }
    }
    std::vector<int> ans;
    for (int i = 1; i <= sum; ++i) {
        if (dp[i] != 0) {
            ans.push_back(i);
        }
    }
    std::cout << ans.size() << '\n';
    for (auto &&a: ans) {
        std::cout << a << ' ';
    }

}
