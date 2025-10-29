#include <iostream>
#include <algorithm>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        a < b ? printf("%d %d\n", a, b) : printf("%d %d\n", b, a);
    }
}