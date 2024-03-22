#include <iostream>
#include <string>
#include <string_view>
#include <cstdint>

auto LengthLongestRepetition(std::string_view str) -> uint32_t {
    uint64_t ans = 1, curr = 1;
    for (size_t i = 1; i < str.length(); ++i) {
        if (str[i] == str[i - 1]) {
            curr++;
        } else {
            ans = ans > curr ? ans : curr;
            curr = 1;
        }
    }
    return ans > curr ? ans : curr;
}

auto main() -> int {
    std::string str;
    std::cin >> str;
    std::cout << LengthLongestRepetition(str) << '\n';
    return 0;
}