#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

auto Manacher(std::string s) -> std::vector<int64_t> {
    s = '$' + s + '^';
    auto n = static_cast<int64_t>(s.length());
    std::vector<int64_t> z(n, 0);
    int64_t l = 0, r = 0;
    for (int64_t i = 1; i < n; i++) {
        z[i] = std::max<int64_t>(0ll, std::min(r - i, z[l + r - i]));
        while (s[i + z[i]] == s[i - z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i - z[i];
            r = i + z[i];
        }
    }
    return {begin(z) + 1, end(z) - 1};
}


auto LongestPalindrome(std::string s) -> std::string {
    auto n = static_cast<int>(s.length());
    std::string temp = "#";
    for (int64_t i = 0; i < n; i++) {
        temp += s[i];
        temp += '#';
    }
    int64_t len = 0, ind = -1;
    auto z = Manacher(temp);
    for (int64_t i = 0; i < n; i++) {
        auto odd = z[2 * i + 1] - 1;
        if (odd > len) {
            ind = i - (odd / 2);
            len = odd;
        }
        auto even = z[2 * i + 2] - 1;
        if (even > len) {
            ind = i - (even / 2) + 1;
            len = even;
        }
    }
    return s.substr(ind, len);


}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::cin >> str;
    std::cout << LongestPalindrome(str);
}

