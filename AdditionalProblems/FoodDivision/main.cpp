#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        int b;
        std::cin >> b;
        x[i] += (x[i - 1] - b);
    }
    std::sort(std::next(std::begin(x)), std::end(x));
    long long ans = 0;
    for (int i = 1; i <= n; i++)
        ans += abs(x[i] - x[(n + 1) / 2]);
    std::cout << ans;
}
