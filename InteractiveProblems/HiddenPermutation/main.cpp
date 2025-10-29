#include <iostream>
#include <algorithm>
#include <vector>

bool ask(int x, int y) {
    std::cout << "? " << x << " " << y << std::endl;
    std::string res;
    std::cin >> res;
    return res == "YES";
}


auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> ara(n), bara(n);
    for (int i = 0; i < n; i++) {
        ara[i] = i + 1;
    }

    std::ranges::stable_sort(ara, [](int a, int b) {
        return ask(a, b);
    });
    for (int i = 0; i < n; i++) {
        bara[ara[i] - 1] = i + 1;
    }
    std::cout << "! ";
    for (int i = 0; i < n; i++) {
        std::cout << bara[i] << " ";
    }

}
