#include <iostream>


auto main() -> int {
    short n;
    std::cin >> n;
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < n; j++) {
            std::cout << (i ^ j) << " ";
        }
        std::cout << '\n';
    }
}