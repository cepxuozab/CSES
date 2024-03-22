#include <iostream>

auto main() -> int {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        bool even = true;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            even &= !(x & 1);
        }
        !even ? puts("first") : puts("second");
    }
}
