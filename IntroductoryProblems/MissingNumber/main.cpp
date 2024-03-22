#include <iostream>

auto main() -> int {
    int n;
    std::cin >> n;
    long long sum = 0;
    for (int i = 1; i < n; ++i) {
        int x;
        std::cin >> x;
        sum += x;
    }
    long long progression = 1LL * n * (n + 1) / 2;
    printf("%lld\n", progression - sum);
    return 0;
}