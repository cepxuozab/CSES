#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <algorithm>

auto PalindromeReorder(std::string_view str) -> std::string {
    constexpr int ALPHABET = 26;
    std::array<int, ALPHABET> frequency{};
    for (char ch: str) {
        int idx = static_cast<int>(static_cast<unsigned char>(ch) - 'A');
        frequency[idx]++;
    }
    if (std::ranges::count_if(frequency, [](int a) { return a & 1; }) > 1) {
        return "NO SOLUTION";
    }
    std::string answer;
    char ch{'#'};
    for (int i = 0; i <ALPHABET;++i) {
        answer.append(std::string(frequency[i] / 2, static_cast<char>(i + 'A')));
        if (frequency[i] & 1) {
            ch = static_cast<char>(i + 'A');
        }
    }
    std::string tmp{answer.rbegin(), answer.rend()};
    int num = ch == '#' ? 0 : 1;
    return answer + std::string(num, ch) + tmp;
}

auto main() -> int {
    std::string str;
    std::cin >> str;
    std::cout << PalindromeReorder(str) << '\n';
    return 0;
}

