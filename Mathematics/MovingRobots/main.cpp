#include <array>
#include <iostream>
#include <vector>

using ld = long double;

constexpr int N = 8;
const std::vector<std::pair<int, int>> DIRECTIONS = { { -1, 0 }, { 0, +1 }, { +1, 0 }, { 0, -1 } };

auto main() -> int
{
    // dp[k][i][j] is probability that robot k is at (i, j).
    std::array<std::array<std::array<ld, N>, N>, N * N> dp{};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) { dp[i * N + j][i][j] = 1; }
    }

    int t;
    std::cin >> t;

    while (t--) {
        std::array<std::array<std::array<ld, N>, N>, N * N> ndp{};
        for (int k = 0; k < N * N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    std::vector<std::pair<int, int>> candidates;
                    for (auto [di, dj] : DIRECTIONS) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (0 <= ni && ni < N && 0 <= nj && nj < N) { candidates.emplace_back(ni, nj); }
                    }
                    ld to_add = dp[k][i][j] / candidates.size();
                    for (auto [ni, nj] : candidates) { ndp[k][ni][nj] += to_add; }
                }
            }
        }
        dp.swap(ndp);
    }

    ld ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ld p = 1;
            for (int k = 0; k < N * N; ++k) {
                p *= (1 - dp[k][i][j]);// It can't have this robot!
            }
            ans += p;
        }
    }

    std::cout << std::to_string(ans) << '\n';
}