/**
* @brief Josephus Problem II
 * @link https://cses.fi/problemset/task/2163/
 * @date 21.01.2024
*/

#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    int k;
    std::cin >> n >> k;
    tree<int, null_type, std::less<>, rb_tree_tag,
            tree_order_statistics_node_update> tree_;
    for (int i = 1; i <= n; ++i) {
        tree_.insert(i);
    }
    size_t idx = k;
    while (!tree_.empty()) {
        idx %= tree_.size();
        int x = *tree_.find_by_order(idx);
        std::cout << x << ' ';
        tree_.erase(x);
        idx += k;
    }
    return 0;
}

