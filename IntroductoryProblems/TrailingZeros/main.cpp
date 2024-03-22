#include <iostream>

auto TrailingZero(int n) -> int {
    int cnt = 0;
    while (n > 0) {
        cnt += n / 5;
        n /= 5;
    }
    return cnt;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::cout << TrailingZero(n) << '\n';
    return 0;
}