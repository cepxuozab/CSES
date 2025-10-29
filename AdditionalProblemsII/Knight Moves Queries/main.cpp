#include <iostream>
#include <numeric>

auto main()->int{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) return 0;

    while (n--) {
        long long x, y;
        std::cin >> x >> y;

        long long dx = llabs(x - 1);
        long long dy = llabs(y - 1);
        long long a = std::max(dx, dy);
        long long b = std::min(dx, dy);

        long long ans = 0;
        if (a == 0 && b == 0) {
            ans = 0;
        } else if (a == 1 && b == 0) {
            ans = 3;
        } else if (a == 2 && b == 2) {
            ans = 4;
        } else if (a == 1 && b == 1) {
            ans = 4;
        } else {

            long long h1 = (a + 1) / 2;
            long long h2 = (a + b + 2) / 3;
            ans = std::max(h1, h2);

            if ((ans & 1) != ((a + b) & 1)) ++ans;
        }

        std::cout << ans << '\n';
    }
    return 0;
}
