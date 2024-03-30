#include <iostream>

auto TwoDivisibility(int x) -> int {
    int res = 0;
    while (x) {
        x >>= 1;
        res += x;
    }
    return res;
}

auto main() -> int {
    int n;
    std::cin >> n;
    int D = TwoDivisibility(n - 1);
    int xum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        int d1 = TwoDivisibility(i);
        int d2 = TwoDivisibility(n - i - 1);
        if (D - d1 - d2 == 0)
            xum ^= a;
    }
    std::cout << xum;
}