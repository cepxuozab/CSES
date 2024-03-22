/**
 * @brief String Matching
 * @link https://cses.fi/problemset/task/1753
 * @date 15.01.2024
 */

#include <string>
#include <iostream>
#include <vector>
#include <string_view>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto Prefix(std::string_view s) -> std::vector<int>;

auto NumberOfOccurrences(std::string const &text, std::string const &pattern) -> int;

auto main() -> int {
    std::string text;
    std::string pattern;
    std::cin >> text >> pattern;
    std::cout << NumberOfOccurrences(text, pattern);
    return 0;
}

auto Prefix(std::string_view s) -> std::vector<int> {
    int n = (int) s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

auto NumberOfOccurrences(std::string const &text, std::string const &pattern) -> int {
    using namespace std::string_literals;
    std::string const matched = pattern + "#"s + text;
    auto const prefix = Prefix(matched);
    int cnt = 0;
    int const size = static_cast<int>(pattern.size());
    for (int i: prefix) {
        if (i == size) {
            cnt++;
        }
    }
    return cnt;
}