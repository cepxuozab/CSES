#include <iostream>

auto main() -> int {
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        int xum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            xum ^= (x % 4);
        }
        xum ? puts("first") : puts("second");
    }
}
