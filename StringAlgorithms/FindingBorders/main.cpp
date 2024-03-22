/**
 * @brief Finding Borders
 * @link https://cses.fi/problemset/task/1732
 * @date 15.01.2024
 */

#include <string>
#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

template<typename T>
auto operator<<(std::ostream &out, std::vector<T> const &arr) -> std::ostream & {
    for (auto &&elem: arr) {
        out << elem << ' ';
    }
    return out;
}

auto Prefix(std::string_view s) -> std::vector<int>;

auto AllBorderLengths(std::string_view text) -> std::vector<int>;

auto main() -> int {
    std::string text;
    std::cin >> text;
    std::cout << AllBorderLengths(text);
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

auto AllBorderLengths(std::string_view text) -> std::vector<int> {
    auto const prefix = Prefix(text);
    std::vector<int> ans;
    int j = prefix.back();
    while (j > 0) {
        ans.push_back(j);
        j = prefix[j - 1];
    }
    std::ranges::sort(ans);
    return ans;
}