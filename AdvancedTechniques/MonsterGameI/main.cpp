#include <iostream>
#include <vector>
#include <cstdint>
#include <deque>

struct Line {
    int64_t m = 0, b = 0;

    auto operator()(int64_t x) -> int64_t {
        return m * x + b;
    }
};

auto under(Line l, Line l1, Line l2) -> bool {
    return (l2.m - l.m) * (l2.b - l1.b) >= (l1.m - l2.m) * (l.b - l2.b);
}

auto main() -> int {
    int n, x;
    std::cin >> n >> x;
    std::vector<int64_t> s(n + 1), f(n + 1), dp(n + 1);
    f[0] = x;
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
        std::cin >> s[i];

    for (int i = 1; i <= n; i++)
        std::cin >> f[i];

    std::deque<Line> hull;
    hull.push_back({f[0], dp[0]});

    for (int i = 1; i <= n; i++) {
        while (hull.size() > 1 && hull[0](s[i]) >= hull[1](s[i]))
            hull.pop_front();
        dp[i] = hull[0](s[i]);

        Line curr = {f[i], dp[i]};
        while (hull.size() > 1 && under(curr, hull[hull.size() - 2], hull[hull.size() - 1]))
            hull.pop_back();
        hull.push_back(curr);
    }

    std::cout << dp[n] << '\n';
    return 0;
}

