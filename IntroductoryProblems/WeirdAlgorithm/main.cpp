#include <iostream>

auto main() -> int {
    long long n;
    std::cin >> n;
    printf("%lld ", n);
    while (n > 1) {
        n = (n & 1) ? 3 * n + 1 : n / 2;
        printf("%lld ", n);
    }
    return 0;
}