#include <iostream>
#include <vector>

auto main() -> int {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> moves(k);
    for (auto &elem: moves) {
        std::cin >> elem;
    }
    std::vector<bool> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++)
            if (i - moves[j] >= 0 && !dp[i - moves[j]])
                dp[i] = true;
        printf("%c", ("LW")[dp[i]]);
    }
}
