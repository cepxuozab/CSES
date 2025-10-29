#include <iostream>
#include <string>
#include <string_view>
#include <vector>

auto qry(std::string_view s) -> std::string {
    std::cout << "? " << s << std::endl;
    std::string res;
    std::cin >> res;
    return res;
}


int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    // just go bit by bit lol
    int n;
    std::cin >> n;
    std::vector<int> a(n, 0);
    for (int i = 0; i < 10; i++) {
        std::string s(n, '0');
        for (int j = 0; j < n; j++) {
            if ((j >> i) & 1)
                s[j] = '1';
        }
        std::string t = qry(s);
        for (int j = 0; j < n; j++)
            a[j] += (t[j] - '0') << i;
    }
    std::cout << "! ";
    for (int i: a)
        std::cout << i + 1 << ' ';
    std::cout << std::endl;
    return 0;
}
