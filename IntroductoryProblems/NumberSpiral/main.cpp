#include <iostream>

auto NumberSpiral(long long x, long long y) -> long long {
    long long l = (x > y ? x : y) - 1;
    if (l & 1) {
        return x < y ? l * l + x : l * l + 2 * l - y + 2;
    } else {
        return x < y ? l * l + 2 * l - x + 2 : l * l + y;
    }
}

auto main() -> int {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        long long a, b;
        std::cin >> a >> b;
        printf("%lld\n", NumberSpiral(a, b));
    }
    return 0;
}