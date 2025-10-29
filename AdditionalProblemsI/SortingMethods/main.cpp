#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

struct Fenw {
    std::vector<long long> fenw;
    int n;

    explicit Fenw(int n) : fenw(n + 1, 0), n(n) {}

    void upd(int i, int val) {
        for (; i <= n; i += i & -i) {
            fenw[i] += val;
        }
    }

    auto get(int i) -> long long {
        long long cnt = 0;
        for (; i > 0; i -= i & -i) {
            cnt += fenw[i];
        }
        return cnt;
    }

    auto get(int l, int r) -> long long {
        return get(r) - get(l - 1);
    }
};

auto count(auto &a) -> long long {
    int n = static_cast<int>(a.size());
    long long ans = 0;
    Fenw fn(n);
    for (auto &x: a) {
        if (!x) continue;
        ans += fn.get(x, n);
        fn.upd(x, 1);
    }
    return ans;
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> us(n + 1);
    int cycle = 0;
    for (int i = 1; i <= n; i++) {
        if (us[i]) continue;
        int u = a[i];
        do {
            cycle++;
            us[u] = true;
            u = a[u];
        } while (!us[u]);
        cycle--;
    }
    const int inf = std::numeric_limits<int>::max();
    std::vector<int> dp(n + 2, inf);
    for (int i = 1; i <= n; i++) {
        auto j = std::ranges::lower_bound(dp, a[i]) - dp.begin();
        dp[j] = a[i];
    }
    int lis = 0, cnt = 0, req = n;
    while (dp[lis] != inf) ++lis;
    for (int i = n; i > 0; i--) {
        if (a[i] == req) {
            ++cnt;
            --req;
        }
    }
    std::cout << count(a) << " " << cycle << " " << n - lis << " " << n - cnt;
}
