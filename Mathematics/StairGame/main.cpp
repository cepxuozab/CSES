#include <iostream>

auto main() -> int {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        int xum = 0;
        for (int i = 0; i < n; ++i) {
            int p;
            std::cin >> p;
            if (i & 1)xum ^= p;
        }
        xum ? puts("first") : puts("second");
    }
}
