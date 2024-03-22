#include <array>
#include <iostream>
#include <algorithm>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    constexpr int N = 8;
    std::array<int, N> dr = {-1, -1, 1, 1, -2, -2, 2, 2};
    std::array<int, N> dc = {-2, 2, -2, 2, -1, 1, -1, 1};

    int x, y;
    std::cin >> x >> y;
    x--, y--;

    std::vector <std::vector<int>> res(N, std::vector<int>(N, -1));
    int it = 0;

    auto warnsdorf = [&](std::pair<int, int> p) -> int {
        // returns number of available moves
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int nr = p.first + dr[i];
            int nc = p.second + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N || res[nr][nc] != -1) continue;
            ans++;
        }
        return ans;
    };

    auto dfs = [&](auto &self, int r, int c) -> void {
        res[r][c] = ++it;

        if (it == N * N) {
            for (auto &row: res) {
                for (int i = 0; i < N; i++) {
                    std::cout << row[i] << " \n"[i == N - 1];
                }
            }
            exit(0);
        }

        std::vector <std::pair<int, int>> nxt;
        for (int i = 0; i < N; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= N || res[nr][nc] != -1) continue;
            nxt.emplace_back(nr, nc);
        }

        std::sort(nxt.begin(), nxt.end(), [&](auto &pa, auto &pb) {
            return warnsdorf(pa) < warnsdorf(pb);
        });

        for (auto [nr, nc]: nxt) {
            self(self, nr, nc);
        }

        res[r][c] = -1;
        it--;
    };


    dfs(dfs, y, x);
    return 0;
}