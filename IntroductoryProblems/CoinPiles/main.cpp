#include <iostream>

auto CoinPiles(int a, int b) {
    return ((a + b) % 3 != 0 || a > 2 * b || b > 2 * a) ? "NO" : "YES";
}

auto main() -> int {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << CoinPiles(a, b) << '\n';
    }
    return 0;
}