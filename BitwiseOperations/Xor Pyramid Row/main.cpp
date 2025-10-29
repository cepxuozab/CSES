#include <iostream>
#include <vector>
#include <cmath>    // std::log2, std::floor
  // std::size_t

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int& x : a) {
        std::cin >> x;
    }

    const int m = n - k;

    // Стандартный способ посчитать floor(log2(n))
    const int lg = static_cast<int>(std::floor(std::log2(n))) + 1;

    std::vector<int> dp = a;

    // Вычисляем XOR-свёртку (по сути — разность по степеням двойки)
    for (int i = 0; i < lg; ++i) {
        if ((m >> i) & 1) {
            const int b = 1 << i;
            for (int j = 0; j + b < n; ++j) {
                dp[j] ^= dp[j + b];
            }
        }
    }

    for (int i = 0; i < k; ++i) {
        std::cout << dp[i];
        if (i + 1 < k) std::cout << ' ';
    }
    std::cout << '\n';

    return 0;
}
