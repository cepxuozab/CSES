#include <iostream>
#include <queue>
#include <vector>

int power[10];

auto Swap(int grid, int i, int j) -> int {
    int a = (grid % power[i + 1]) / power[i];
    int b = (grid % power[j + 1]) / power[j];
    return grid - (a * power[i]) - (b * power[j]) + (a * power[j]) + (b * power[i]);
}

auto main() -> int {
    const std::vector<std::pair<int, int>> moves = {{0, 1},
                                                    {3, 4},
                                                    {6, 7},
                                                    {1, 2},
                                                    {4, 5},
                                                    {7, 8},
                                                    {0, 3},
                                                    {1, 4},
                                                    {2, 5},
                                                    {3, 6},
                                                    {4, 7},
                                                    {5, 8}};
    power[0] = 1;
    for (int i = 1; i < 10; i++) {
        power[i] = power[i - 1] * 9;
    }
    std::vector<bool> vis(power[9], false);
    int target = 0;
    for (int i = 8; i >= 0; i--) {
        target += (8 - i) * power[i];
    }
    int start = 0;
    for (int i = 8; i >= 0; i--) {
        int num;
        std::cin >> num;
        start += (num - 1) * power[i];
    }
    std::queue<std::pair<int, int>> q;
    q.emplace(start, 0);
    while (!q.empty()) {
        auto [x,d]=q.front();
        q.pop();

        if (x == target) {
            std::cout << d << '\n';
            break;
        }
        vis[x] = true;
        for (auto [one, two]: moves) {
            int nw = Swap(x, one, two);
            if (!vis[nw]) {
                vis[nw] = true;
                q.emplace(nw, d + 1);
            }
        }
    }
    return 0;
}
