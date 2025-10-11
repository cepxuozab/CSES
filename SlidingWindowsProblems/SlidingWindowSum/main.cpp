#include <cstdint>
#include <iostream>
#include <vector>

auto sliding_windows_sum(int64_t k, int64_t n, int64_t x, int64_t a, int64_t b, int64_t c) -> int64_t {
    std::vector<int64_t> prefix(k + 1);
    prefix[0] = 0;
    prefix[1] = x;
    for (int64_t i = 2; i <= k; ++i) {
        prefix[i] = (a * (prefix[i - 1] - prefix[i - 2]) + b) % c + prefix[i - 1];
    }
    int64_t right = n;
    int64_t xorAnswer = 0;
    while (right <= k) {
        xorAnswer ^= prefix[right] - prefix[right - n];
        right++;
    }
    return xorAnswer;
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t k, n;
    std::cin >> k >> n;
    int64_t x, a, b, c;
    std::cin >> x >> a >> b >> c;
    std::cout << sliding_windows_sum(k, n, x, a, b, c) << '\n';
}