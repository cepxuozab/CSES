#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

auto psum(std::vector<int64_t> const &A, int64_t l, int64_t r) -> int64_t {
    if (r < l) return 0;
    return A[r] - (l ? A[l - 1] : 0);
}


auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for (auto &x: A) std::cin >> x;
    std::partial_sum(begin(A), end(A), begin(A));

    std::vector cost(N, std::vector<int64_t>(N));
    for (int i = 0; i < N; i++) {
        int64_t opt = i;
        int64_t cur = 0;
        for (int j = i; j < N; j++) {
            while (psum(A, i, opt) < psum(A, opt + 1, j)) {
                cur += psum(A, i, opt);
                cur -= psum(A, opt + 1, j);
                opt++;
            }
            cost[i][j] = cur;
            if (j + 1 < N) cur += psum(A, j + 1, j + 1) * (j + 1 - opt);
        }
    }

    constexpr int64_t INF = 1e18;
    std::vector<int64_t> last(N + 1, INF);
    last[0] = 0;

    for (int i = 0; i < K; i++) {
        std::vector<int64_t> DP(N + 1);
        auto compute = [&](auto &&self, int64_t l, int64_t r, int64_t optl, int64_t optr) {
            if (l > r) return;
            auto m = std::midpoint(l, r);

            std::pair<int64_t, int64_t> best{INF, -1};
            for (int64_t i = optl; i <= std::min(optr, m - 1); i++) {
                best = min(best, {last[i] + cost[i][m - 1], i});
            }
            DP[m] = best.first;

            self(self, l, m - 1, optl, best.second);
            self(self, m + 1, r, best.second, optr);
        };

        compute(compute, 1, N, 0, N - 1);
        last.swap(DP);
    }

    std::cout << last.back();
}