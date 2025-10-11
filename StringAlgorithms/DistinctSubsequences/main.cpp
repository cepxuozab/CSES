#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

constexpr int MOD = 1e9 + 7;
auto main() -> int {
    std::string str;
    std::cin >> str;
    constexpr int ALPHABET = 26;
    std::array<int64_t, ALPHABET> dp {};
    for (char ch : str) {
        int idx = static_cast<int>(static_cast<unsigned char>(ch - 'a'));
        dp[idx]++;
        for (int i = 0; i < ALPHABET; ++i) {
            if (i != idx) {
                dp[idx] = (dp[idx] + dp[i]) % MOD;
            }
        }
    }
    int64_t total = 0;
    for (auto& num : dp) {
        total = (total + num) % MOD;
    }
    std::cout << total;
}