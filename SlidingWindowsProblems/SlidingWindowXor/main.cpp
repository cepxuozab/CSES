#include <cstdint>
#include <iostream>
#include <algorithm>


auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    int64_t x, a, b, c;
    std::cin >> x >> a >> b >> c;
    auto element = x;
    int64_t answer = 0;
    for (int i = 1; i < n; ++i) {
        element = (a * element + b) % c;
        int t = k - std::max(0, k - i - 1) - std::max(0, i - (n - k));
        if (t & 1) answer ^= element;
    }
    std::cout << (answer ^ x) << '\n';


}