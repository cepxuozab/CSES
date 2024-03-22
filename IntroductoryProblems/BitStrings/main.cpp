#include <iostream>

auto BinPow(int n) -> long long {
    constexpr int MOD = 1'000'000'007;
    long long res = 1;
    long long a = 2;
    while (n > 0) {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::cout << BinPow(n) << '\n';
    return 0;
}