#include <iostream>
#include <climits>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long min_u = LLONG_MAX, max_u = LLONG_MIN;
    long long min_v = LLONG_MAX, max_v = LLONG_MIN;

    for (int i = 0; i < n; ++i) {
        long long x, y;
        std::cin >> x >> y;

        long long u = x + y;
        long long v = x - y;

        min_u = std::min(min_u, u);
        max_u = std::max(max_u, u);
        min_v = std::min(min_v, v);
        max_v = std::max(max_v, v);

        if (i == 0) {
            std::cout << 0 << '\n';
        } else {
            long long ans = std::max(max_u - min_u, max_v - min_v);
            std::cout << ans << '\n';
        }
    }

    return 0;
}
