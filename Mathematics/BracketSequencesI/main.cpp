#include <cstdint>
#include <iostream>

constexpr int MOD = 1e9 + 7;

auto pm(long long a, long long b, long long mod) -> long long {
    long long amn = a, ans = 1;
    for (long long i = 0; (1 << i) <= b; i++) {
        if ((1 << i) & b) ans = amn * ans % mod;
        amn = amn * amn % mod;
    }
    return ans;
}
auto invrtm(long long a, long long mod) -> long long {
    return pm(a, mod - 2, mod);
}
auto gt(long long n, long long mod) -> long long {
    long long ans = 1;
    for (long long i = 2; i <= n; i++) ans = ans * i % mod;
    return ans;
}
auto Catalan(long long n, long long r, long long mod) -> long long {
    return gt(n, mod) * invrtm(gt(r, mod) * gt(n - r, mod) % mod * (n / 2 + 1) % mod, mod) % mod;
}
auto main() -> int {
    long long n;
    std::cin >> n;
    if (n % 2 != 0)
        std::cout << "0\n";
    else
        std::cout << Catalan(n, n / 2, MOD) << '\n';
}