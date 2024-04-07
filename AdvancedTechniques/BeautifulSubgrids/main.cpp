#pragma GCC target("popcnt")
#include <iostream>
#include <vector>
#include <cstdint>
#include <bitset>

auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<std::bitset<3000>> v(n);
    for (auto &i: v)
        std::cin >> i;
    size_t ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto cnt = (v[i] & v[j]).count();
            ans += cnt * (cnt - 1) / 2;
        }
    }
    std::cout << ans;
}