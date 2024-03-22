/**
 * @brief Collecting Numbers II
 * @link https://cses.fi/problemset/task/2217
 * @date 15.01.2024
 */

#include <algorithm>
#include <iostream>
#include <vector>


[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<int> ind(n + 2);
    std::vector<int> a(n + 1);
    ind[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        ind[x] = i;
        a[i] = x;
    }
    int c = 1;
    int l = 1;
    for (int i = 1; i <= n; i++) {
        if (l > ind[i])
            c++;
        l = ind[i];
    }
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        int r = a[x], s = a[y];
        std::swap(a[x], a[y]);
        if (ind[r - 1] <= ind[r] && ind[r - 1] > y) c++;
        if (ind[r - 1] > ind[r] && ind[r - 1] <= y) c--;
        if (ind[r] <= ind[r + 1] && y > ind[r + 1]) c++;
        if (ind[r] > ind[r + 1] && y <= ind[r + 1]) c--;
        ind[r] = y;
        if (ind[s - 1] <= ind[s] && ind[s - 1] > x) c++;
        if (ind[s - 1] > ind[s] && ind[s - 1] <= x) c--;
        if (ind[s] <= ind[s + 1] && x > ind[s + 1]) c++;
        if (ind[s] > ind[s + 1] && x <= ind[s + 1]) c--;
        ind[s] = x;
        std::cout << c << '\n';
    }
    return 0;

}
