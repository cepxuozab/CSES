#include <iostream>
#include <vector>

auto NumbersOfArray(std::vector<int> const &arr, int upper_bound_value) -> int;

auto main() -> int {
    int n;
    int upper_bound_value;
    std::cin >> n >> upper_bound_value;
    std::vector<int> arr(n);
    for (int &i: arr) {
        std::cin >> i;
    }
    std::cout << NumbersOfArray(arr, upper_bound_value);
}

auto NumbersOfArray(std::vector<int> const &arr, int upper_bound_value) -> int {
    constexpr int MOD = 1000000007;
    size_t const n = arr.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(upper_bound_value + 1));
    for (int i = 1; i <= upper_bound_value; i++) {
        if (arr[0] == 0 || arr[0] == i) { dp[1][i] = 1; }
    }
    for (size_t i = 2; i <= n; i++) {
        for (int j = 1; j <= upper_bound_value; j++) {
            if (arr[i - 1] != 0 && arr[i - 1] != j) {
                dp[i][j] = 0;
                continue;
            }
            for (int prev = j - 1; prev <= j + 1; prev++) {
                if (prev > 0 && prev <= upper_bound_value) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= upper_bound_value; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }
    return ans;
}
