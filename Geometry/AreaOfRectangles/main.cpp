#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

struct segment_tree {
    int n;
    std::vector<int> sum, sig;
    segment_tree(int _n) : n(_n), sum(4 * _n + 2), sig(4 * _n + 2) {}

    void add(int qL, int qR, int t, int o, int L, int R) {
        int lc = 2 * o, rc = 2 * o + 1, m = (L + R) / 2;
        int& s = sum[o];
        int& ls = sum[lc];
        int& rs = sum[rc];

        if ((qL <= L) && (R <= qR)) {
            sig[o] += t;
            if (sig[o]) s = R - L + 1;
            else if (L < R) s = ls + rs;
            else s = 0;
            return;
        }

        if (qL <= m) add(qL, qR, t, lc, L, m);
        if (qR > m) add(qL, qR, t, rc, m + 1, R);

        sum[o] = sig[o] ? R - L + 1 : ls + rs;
    }
};

struct event {
    int x, type, d, u;
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, maxy = 0;
    std::cin >> n;
    std::vector<event> E;

    for (int i = 0, x1, y1, x2, y2; i < n; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        maxy = std::max({maxy, std::abs(y1) + 1, std::abs(y2) + 1});
        E.push_back({x1, 1, y1, y2});
        E.push_back({x2, -1, y1, y2});
    }

    std::ranges::sort(E,{},&event::x);
    segment_tree s(2 * maxy);

    int64_t ans = 0, lx = 0;

    for (event e : E) {
        int l = e.d + maxy, r = e.u + maxy;
        ans += static_cast<int64_t>(e.x - lx) * s.sum[1];
        lx = e.x;
        s.add(l, r - 1, e.type, 1, 1, 2 * maxy);
    }

    std::cout << ans << "\n";
    return 0;
}