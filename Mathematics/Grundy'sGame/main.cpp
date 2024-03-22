#include <iostream>
#include <set>
#include <vector>

auto Mex(std::vector<int> const &v) -> int {
    constexpr int mxN = 1e6 + 6;
    std::set<int> s(v.begin(), v.end());
    for (int i = 0; i < mxN; i++) {
        if (!s.contains(i)) return i;
    }
    return mxN;
}

auto main() -> int {
    std::vector<int> dp = {0, 0, 0};
    for (int i = 3; i < 2000; i++) {
        std::vector<int> v;
        for (int j = 1; i - j > j; j++) {
            v.push_back(dp[j] ^ dp[i - j]);
        }
        dp.push_back(Mex(v));
    }
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        if (n >= 2000) puts("first");
        else dp[n] > 0 ? puts("first") : puts("second");
    }
}
