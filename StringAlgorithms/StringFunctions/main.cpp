#include <iostream>
#include <vector>
#include <string>
#include <string_view>

template<typename T>
auto operator<<(std::ostream &out, std::vector<T> const &arr) -> std::ostream & {
    bool first = true;
    for (auto &&elem: arr) {
        if (!first) {
            out << ' ';
        }
        first = false;
        out << elem;
    }
    return out;
}

auto PrefixFunction(std::string_view str) -> std::vector<int> {
    std::vector<int> pi(str.length());
    int N = static_cast<int>(str.length());
    for (int i = 1; i < N; i++) {
        int j = pi[i - 1];
        while (j > 0 && str[i] != str[j]) { j = pi[j - 1]; }
        if (str[i] == str[j]) { j++; }
        pi[i] = j;
    }
    return pi;
}

auto ZFunction(std::string_view str) -> std::vector<int> {
    std::vector<int> z(str.length());
    int N = static_cast<int>(str.length());
    for (int i = 1, l = 0, r = 0; i < N; i++) {
        if (i <= r) { z[i] = std::min(r - i + 1, z[i - l]); }
        while (i + z[i] < N && str[z[i]] == str[i + z[i]]) { z[i]++; }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

auto main() -> int {
    std::string str;
    std::cin >> str;
    std::cout << ZFunction(str) << '\n' << PrefixFunction(str);
}