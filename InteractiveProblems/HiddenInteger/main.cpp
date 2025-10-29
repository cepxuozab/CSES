#include <iostream>

auto qry(int x) -> bool {
    std::cout << "? " << x << std::endl;
    std::string s;
    std::cin >> s;
    return s == "YES";
}

auto main() -> int {
    int l = 0, r = 1e9;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (qry(m)) l = m;
        else r = m;
    }

    std::cout << "! " << r << "\n";
}
