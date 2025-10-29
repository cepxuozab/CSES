#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdint>
#include <utility>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k, n, m;
    std::cin >> n >> m >> k;

    std::vector<std::pair<int, int>> a(k);
    for (auto &[u, v]: a) {
        std::cin >> u >> v;
    }

    std::sort(a.begin(), a.end(), [&](auto const &lhs, auto const &rhs) {
        return lhs.second - lhs.first < rhs.second - rhs.first;
    });

    std::vector<int64_t> L(k + 3, 0), R(k + 3, 0);
    using Queue = std::priority_queue<int64_t, std::vector<int64_t>, std::greater<>>;

    {
        Queue pq;
        int64_t cur = 0;
        for (int i = 1; i <= k; i++) {
            cur += 1LL * a[i - 1].first;
            pq.push(a[i - 1].first);

            if (std::cmp_greater(pq.size(), n)) {
                cur -= pq.top();
                pq.pop();
            }

            L[i] = cur;
        }
    }

    {
        Queue pq;
        int64_t cur = 0;
        for (int i = k; i >= 1; i--) {
            cur += 1LL * a[i - 1].second;
            pq.push(a[i - 1].second);

            if (std::cmp_greater(pq.size(), m)) {
                cur -= pq.top();
                pq.pop();
            }

            R[i] = cur;
        }
    }

    int64_t ans = 0;
    for (int i = n; i <= k - m; i++) {
        ans = std::max(ans, L[i] + R[i + 1]);
    }

    std::cout << ans << '\n';

    return 0;
}