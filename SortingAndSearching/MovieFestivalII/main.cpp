/**
* @brief Movie Festival II
 * @link https://cses.fi/problemset/task/1632/
 * @date 22.01.2024
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <set>
#include <utility>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


auto main() -> int {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> arr(n);
    for (auto &[first, second]: arr) {
        std::cin >> first >> second;
    }
    std::ranges::sort(arr,[](auto const& lhs, auto const& rhs){return lhs.second < rhs.second;});
    std::multiset<int> e;
    int c = 0;
    for (auto const &[a, b]: arr) {
        int x = -a;
        int y = -b;
        if (e.empty()) {
            e.insert(y);
            c++;
        } else {
            auto z = e.lower_bound(x);
            if (z == e.end()) {
                if (std::cmp_less(e.size(), k)) {
                    e.insert(y);
                    c++;
                }
            } else {
                e.erase(z);
                e.insert(y);
                c++;
            }
        }
    }
    std::cout << c;

    return 0;
}

