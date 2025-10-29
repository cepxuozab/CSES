#include <iostream>
#include <vector>

int main() {
    constexpr int MOD = 1'000'000'007;

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> A(n + 1, std::vector<int>(n + 1, 0));
    A[1][0] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int k = 0; k < i; ++k) {
            long long val = 0;
            if (k > 0) val += 1LL * (i - k) * A[i - 1][k - 1];
            if (k < i - 1) val += 1LL * (k + 1) * A[i - 1][k];
            A[i][k] = static_cast<int>(val % MOD);
        }
    }

    for (int k = 1; k <= n; ++k) {
        std::cout << A[n][k - 1];
        if (k < n) std::cout << ' ';
    }
    std::cout << '\n';

    return 0;
}
