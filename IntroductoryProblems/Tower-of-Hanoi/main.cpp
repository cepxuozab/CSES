#include <iostream>

void TowerOfHanoi(int a, int b, int c, int n) {
    if (n == 0)
        return;
    TowerOfHanoi(a, c, b, n - 1);
    std::cout << a << ' ' << c << '\n';
    TowerOfHanoi(b, a, c, n - 1);
}


auto main() -> int {
    int n;
    std::cin >> n;
    std::cout << (1 << n) - 1 << '\n';
    TowerOfHanoi(1, 2, 3, n);
    return 0;
}