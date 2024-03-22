#include <iostream>
#include <vector>

auto DiceCombinations(int n) -> int {
    constexpr int mod = 1'000'000'007;
    std::vector<int> a(n + 1);
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        int const start = i - 6 > 0 ? i - 6 : 0;
        for (int j = start; j < i; j++) {
            a[i] = (a[i] + a[j]) % mod;
        }
    }
    return a.back();
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::cout << DiceCombinations(n);
}