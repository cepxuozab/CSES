#include <iostream>
#include <cstdint>

auto TwoKnights(int64_t n) -> int64_t {
    if (n == 1) {
        std::cout << 0 << '\n';
        return 0;
    }
    int64_t c = 0;
    int64_t t = n * n - 1;
    for (int i = 1; i < n + 1; ++i) {
        int x = 0;
        if (1 + 1 <= n && i + 2 <= n) x++;
        if (1 + 2 <= n && i + 1 <= n) x++;
        if (1 + 2 <= n && i - 1 > 0) x++;
        if (1 + 1 <= n && i - 2 > 0) x++;
        c = c + t - x;
        t--;
    }
    for (int i = 2; i < n + 1; ++i) {
        int x = 0;
        if (i + 1 <= n && 1 + 2 <= n) x++;
        if (i + 2 <= n && 1 + 1 <= n) x++;
        if (i - 1 > 0 && 1 + 2 <= n && i != 2) x++;
        if (i - 2 > 0 && 1 + 1 <= n && i != 3) x++;
        c = c + t - x;
        t--;
    }
    c = c + TwoKnights(n - 1);
    std::cout << c << '\n';
    return c;
}

auto main() -> int {
    int64_t n;
    std::cin >> n;
    TwoKnights(n);
    return 0;
}