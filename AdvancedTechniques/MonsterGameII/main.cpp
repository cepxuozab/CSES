#include<iostream>
#include <algorithm>
#include <vector>
#include <cstdint>


constexpr int64_t INF_LL = 2e18;


struct LiChao {
    struct Line {
        int64_t k, b;

        explicit Line(int64_t k, int64_t b) : k(k), b(b) {}

        [[nodiscard]] auto get(int64_t x) const { return k * x + b; }
    };

    std::vector<Line> t;
    int n;
    const Line NONE{0, INF_LL};

    LiChao(int n) : n(n) { t.resize(4LL * n, NONE); }


    void upd(int64_t k, int64_t x) {
        return updImpl(0, 0, n, Line(k, x));
    }

    auto get(int q) -> int64_t {
        return getImpl(0, 0, n, q);
    }

private:
    void updImpl(int p, int l, int r, Line line) {
        if (line.k == t[p].k) {
            if (line.b < t[p].b)
                t[p] = line;
            return;
        }
        if (r - l == 1) {
            if (line.get(l) < t[p].get(l))
                t[p] = line;
            return;
        }
        int m = (l + r) / 2;
        if (line.get(m) < t[p].get(m))
            std::swap(line, t[p]);
        if (line.k > t[p].k)
            updImpl(2 * p + 1, l, m, line);
        else
            updImpl(2 * p + 2, m, r, line);
    }

    auto getImpl(int p, int l, int r, int q) -> int64_t {
        if (r - l == 1) return t[p].get(q);
        int m = (l + r) / 2;
        if (q < m)
            return std::min(t[p].get(q), getImpl(2 * p + 1, l, m, q));
        else
            return std::min(t[p].get(q), getImpl(2 * p + 2, m, r, q));
    }

};


auto main() -> int {
    int n, x;
    std::cin >> n >> x;
    std::vector<int64_t> s(n + 1), f(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> s[i];
    for (int i = 1; i <= n; ++i) std::cin >> f[i];

    int64_t dp = 0;
    const int N = 1e6;
    LiChao lch(N + 1);
    lch.upd(x, 0);
    for (int i = 1; i <= n; ++i) {
        dp = lch.get(s[i]);
        lch.upd(f[i], dp);
    }
    std::cout << dp;
}