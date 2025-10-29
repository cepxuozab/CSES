#include <iostream>
#include <vector>
#include <string>


auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<short>> a(n, std::vector<short>(m));
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++)
            a[i][j] = s[j] - 'A';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            short avoid1 = i == 0 ? -1 : a[i - 1][j];
            short avoid2 = j == 0 ? -1 : a[i][j - 1];
            do {
                a[i][j] = (a[i][j] + 1) & 3;
            } while (a[i][j] == avoid1 || a[i][j] == avoid2);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << (char) (a[i][j] + 'A');
        std::cout << '\n';
    }
    return 0;

}