#include <iostream>
#include <cstdint>
#include <vector>

auto main() -> int {
    int64_t n;
    std::cin >> n;
    constexpr int SIZE = 19;
    std::vector<int64_t> p{1};
    for (int i = 1; i < SIZE; ++i) {
        p.push_back(p.back() * 10);
    }

    auto check = [&](int64_t N) {
        int64_t cnt = 0, l = N, r = 0;
        for (int i = 0; l; i++) {
            int64_t d = l % 10;
            l /= 10;
            cnt += (d == 1 ? l * p[i] + r + 1 : (l + (d != 0)) * p[i]);
            r += p[i] * d;
        }
        return cnt;
    };

    int64_t lo = 1, hi = 1e18;
    while (hi - lo > 1) {
        auto mid = lo + (hi - lo) / 2;
        if (check(mid) <= n) lo = mid;
        else hi = mid;
    }
    std::cout << lo;
}