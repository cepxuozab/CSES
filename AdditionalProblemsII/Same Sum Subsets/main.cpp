#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int mid = n / 2;

    auto f = [&](int l, int r) -> std::vector<std::pair<long long, long long>> {
        int sz = r - l + 1;
        std::vector<std::pair<long long, long long>> ans(1 << sz);

        for (int mask = 0; mask < (1 << sz); mask++) {
            long long sum = 0;
            long long msk = 0;
            for (int i = 0; i < sz; i++) {
                if ((mask >> i) & 1) {
                    msk |= 1LL << (i + l);
                    sum += a[i + l];
                }
            }
            ans[mask] = std::make_pair(sum, msk);
        }
        std::sort(ans.begin(), ans.end());
        return ans;
    };

    auto print = [&](long long msk0, long long msk1) {
        std::vector<long long> res0, res1;
        for (int j = 0; j < 40; j++) {
            if (((msk0 >> j) & 1) && ((msk1 >> j) & 1)) continue;
            if ((msk0 >> j) & 1) res0.emplace_back(a[j]);
            if ((msk1 >> j) & 1) res1.emplace_back(a[j]);
        }
        std::cout << res0.size() << '\n';
        for (auto x : res0) std::cout << x << ' ';
        std::cout << '\n';
        std::cout << res1.size() << '\n';
        for (auto x : res1) std::cout << x << ' ';
        std::cout << '\n';
    };

    auto work = [&](std::vector<std::pair<long long, long long>>& g) {
        for (int i = 1; i < static_cast<int>(g.size()); i++) {
            auto [sum0, msk0] = g[i];
            auto [sum1, msk1] = g[i - 1];
            if (sum0 == sum1) {
                print(msk0, msk1);
                return true;
            }
        }
        return false;
    };

    auto l = f(0, mid);
    auto r = f(mid + 1, n - 1);

    if (work(l)) return;
    if (work(r)) return;

    std::unordered_map<long long, long long> cache;

    auto subsetcnt = [&](long long x) {
        auto it = cache.find(x);
        if (it != cache.end()) return it->second;
        long long ans = 0;
        for (int i = 0, j = static_cast<int>(r.size()) - 1; i < static_cast<int>(l.size()); i++) {
            while (j >= 0 && l[i].first + r[j].first > x) {
                j--;
            }
            ans += j + 1;
        }
        return cache[x] = ans - 1;
    };

    long long low = 0;
    long long high = 1LL << n;
    long long sum = -1;

    while (low <= high) {
        long long midv = (low + high) >> 1;
        if (subsetcnt(midv) - subsetcnt(low - 1) > (midv - low + 1)) {
            sum = midv;
            high = midv - 1;
        } else {
            low = midv + 1;
        }
    }

    long long msk0 = -1;
    long long msk1 = -1;
    for (int i = 0, j = static_cast<int>(r.size()) - 1; i < static_cast<int>(l.size()); i++) {
        while (j >= 0 && l[i].first + r[j].first > sum) {
            j--;
        }
        if (j >= 0 && l[i].first + r[j].first == sum) {
            if (msk0 == -1) msk0 = l[i].second | r[j].second;
            else if (msk1 == -1) msk1 = l[i].second | r[j].second;
        }
    }

    print(msk0, msk1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
