#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> a(n);
    for (auto &row : a) {
        std::cin >> row;
    }

    std::vector<std::vector<int>> t(k, std::vector<int>(n, 0));
    std::vector<std::vector<int>> dp(k, std::vector<int>(n, 0));
    std::vector<long long> res(k, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cur = a[i][j] - 'A';

            if (i > 0 && a[i][j] != a[i - 1][j]) {
                int prev = a[i - 1][j] - 'A';
                t[prev][j] = 0;
            }

            t[cur][j]++;
        }

        std::vector<std::vector<int>> st(k, std::vector<int>{-1});

        for (int j = 0; j < n; ++j) {
            int id = a[i][j] - 'A';
            if (j > 0 && a[i][j] != a[i][j - 1]) {
                st[id] = {-1, j - 1};
            }

            while (st[id].back() != -1 && t[id][st[id].back()] >= t[id][j]) {
                st[id].pop_back();
            }

            int p = (st[id].back() == -1 ? 0 : dp[id][st[id].back()]);
            dp[id][j] = p + t[id][j] * (j - st[id].back());
            res[id] += dp[id][j];
            st[id].push_back(j);
        }

        for (int j = 0; j < n; ++j) {
            dp[a[i][j] - 'A'][j] = 0;
        }
    }

    for (long long val : res) {
        std::cout << val << '\n';
    }

    return 0;
}
