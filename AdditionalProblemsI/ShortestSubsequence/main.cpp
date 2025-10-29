#include <iostream>
#include <string>
#include <string_view>

auto ShortestDNA(std::string_view str) -> std::string {
    size_t const n = str.length();
    bool a = false, c = false, g = false, t = false;
    auto check = [&]() { return a + c + g + t == 4; };
    size_t l = 0, r = 0;
    std::string ans;
    while (l < n) {
        a = (str[l] == 'A');
        c = (str[l] == 'C');
        g = (str[l] == 'G');
        t = (str[l] == 'T');
        r = l + 1;
        while (r < n && !check()) {
            a += (str[r] == 'A');
            c += (str[r] == 'C');
            g += (str[r] == 'G');
            t += (str[r] == 'T');
            r++;
        }
        if (check())
            ans += str[r - 1];
        l = r;
    }
    if (check() || !a) ans += 'A';
    else if (!c) ans += 'C';
    else if (!g) ans += 'G';
    else if (!t) ans += 'T';
    return ans;
}

auto main() -> int {
    std::string dna;
    std::cin >> dna;
    std::cout << ShortestDNA(dna);
}