#include <iostream>
#include <string>
#include <vector>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    int q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> arr(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        std::string str;
        std::cin >> str;
        for (int j = 1; j <= n; j++) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            arr[i][j] += static_cast<int>(str[j - 1] == '*');
        }
    }
    while ((q--) != 0) {
        int w;
        int x;
        int y;
        int z;
        std::cin >> w >> x >> y >> z;
        std::cout << arr[y][z] - arr[y][x - 1] - arr[w - 1][z] + arr[w - 1][x - 1] << "\n";
    }
    return 0;
}
