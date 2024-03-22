#include <iostream>
#include <vector>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    int lgmax = 30;
    std::vector<std::vector<int>> a(lgmax + 2, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        std::cin >> a[0][i];
    }

    for (int i = 1; i <= lgmax; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = a[i - 1][a[i - 1][j]];
        }
    }
    auto ancestor = [&](int x, int k) {
        for (int h = lgmax; 0 <= h; h--)
            if ((1 << h) <= k) {
                x = a[h][x];
                k -= (1 << h);
            }
        return x;
    };
    while (q--) {
        int x, k;
        std::cin >> x >> k;
        int y = ancestor(x, k);
        std::cout << y << '\n';
    }
}