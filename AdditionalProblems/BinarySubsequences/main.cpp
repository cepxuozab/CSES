#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int mn = n + 1, ans = -1;
    for (int i = 0; i <= n / 2; i++) {
        // try i and n - i
        int cnt = 0;
        int a = i, b = n - i;
        bool ok = true;
        while (a || b) {
            if (a < b) std::swap(a, b);
            if (a == b) {
                ok = false;
                break;
            }
            cnt += a / (b + 1);
            a %= (b + 1);
        }
        if (ok && cnt < mn) {
            mn = cnt;
            ans = i;
        }
    }
    std::string s;
    int a = ans, b = n - a, z = 0;
    while (a || b) {
        if (a < b) {
            std::swap(a, b);
            z ^= 1;
        }
        int tot = a / (b + 1);
        for (int i = 0; i < tot; i++) s += static_cast<char>( '0' + z);
        a %= (b + 1);
    }
    std::cout << s << '\n';
}