#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

constexpr int M = 1e9 + 7;
auto bin_exp(int64_t n, int64_t pow) -> int64_t {
    int64_t res = 1;
    while (pow) {
        if (pow % 2 == 0) {
            n = (n % M * n % M) % M;
            pow /= 2;
        }

        res = (n % M * res % M) % M;
        pow--;
    }
    return res % M;
}
auto main() -> int {
    std::string s;
    std::cin >> s;
    int n = static_cast<int>(s.size());
    std::vector<int64_t> fact(1e6 + 1, 1);
    for (int i = 1; i <= 1e6; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    std::vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    int64_t ans = fact[n];
    for (int i = 0; i < 26; i++) {
        ans = (ans * (bin_exp(fact[cnt[i]], M - 2))) % M;
    }
    std::cout << ans;
}