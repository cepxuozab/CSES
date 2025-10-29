#include <iostream>
#include <vector>
#include <queue>
#include <array>


auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    const int INF = 1'000'000'007;
    const std::array<int, 8> dx = {2, 1, -1, -2, -2, -1, 1, 2}, dy = {1, 2, 2, 1, -1, -2, -2, -1};
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> d(n, std::vector<int>(n, INF));
    std::queue<std::array<int, 2>> bfs;
    bfs.push({0, 0});
    d[0][0] = 0;
    while (!empty(bfs)) {
        auto [x, y] = bfs.front();
        bfs.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (d[nx][ny] == INF) {
                d[nx][ny] = d[x][y] + 1;
                bfs.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cout << d[i][j] << " \n"[j == n - 1];
    return 0;
}