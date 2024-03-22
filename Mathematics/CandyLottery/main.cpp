#include <cmath>
#include <iostream>

auto main() -> int {
    int n, k;
    std::cin >> n >> k;
    double d = pow(k, n);
    double s = 0;
    for (int i = 0; i < k; ++i) {
        s += pow(i, n);
    }
    printf("%.6f\n", k - s / d);
}