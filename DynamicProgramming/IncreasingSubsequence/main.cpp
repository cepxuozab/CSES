#include <iostream>
#include <algorithm>
#include <vector>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> dp;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        auto it = std::ranges::lower_bound(dp, x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }
    std::cout << dp.size() << '\n';
}
