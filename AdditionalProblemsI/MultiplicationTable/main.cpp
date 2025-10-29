#include <algorithm>
#include <cstdint>
#include <iostream>

auto Check(int64_t n, int64_t x) -> int64_t {
    int64_t cnt = 0;
    for (int64_t i = 1; i <= n; i++) cnt += std::min(n, x / i);
    return cnt;
}

auto main() -> int {
    int64_t n;
    std::cin >> n;
    int64_t lo = 0, hi = n * n;
    int64_t target = (n * n + 1) / 2;
    while (hi - lo > 1) {
        auto const mid = lo + (hi - lo) / 2;
        if (Check(n, mid) < target)
            lo = mid;
        else
            hi = mid;
    }
    std::cout << lo + 1;
}