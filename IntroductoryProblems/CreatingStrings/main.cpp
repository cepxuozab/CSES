#include <iostream>
#include <set>
#include <algorithm>
#include <string>

auto CreateStrings(std::string str) -> std::set<std::string> {
    std::ranges::sort(str);
    std::set<std::string> strings{str};
    while (std::next_permutation(str.begin(), str.end())) {
        strings.insert(str);
    }
    return strings;
}

auto main() -> int {
    std::string str;
    std::cin >> str;
    auto const strings = CreateStrings(str);
    std::cout << strings.size() << '\n';
    for (auto &&s: strings) {
        std::cout << s << '\n';
    }
    return 0;
}