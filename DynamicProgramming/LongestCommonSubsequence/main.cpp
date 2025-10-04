#include <iostream>
#include <numeric>
#include <vector>

auto longest_common_subsequence(std::vector<int> const &lhs, std::vector<int> const &rhs) -> std::vector<int> {
    size_t const m = lhs.size();
    size_t const n = rhs.size();
    std::vector<std::vector<int>> lcs(m + 1, std::vector<int>(n + 1));
    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (lhs[i - 1] == rhs[j - 1])lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
        }
    }
    size_t i = m, j = n;
    std::vector<int> answer;
    while (i > 0 && j > 0) {
        if (lhs[i - 1] == rhs[j - 1]) {
            answer.push_back(lhs[i - 1]);
            i -= 1;
            j -= 1;
        } else if (lcs[i - 1][j] > lcs[i][j - 1]) {
            i -= 1;
        } else {
            j -= 1;
        }
    }
    return {answer.rbegin(), answer.rend()};
}

auto main() -> int {
    unsigned m, n;
    std::cin >> m >> n;
    std::vector<int> lhs(m), rhs(n);
    for (auto &a: lhs)std::cin >> a;
    for (auto &a: rhs)std::cin >> a;
    auto ans = longest_common_subsequence(lhs, rhs);
    std::cout << ans.size() << '\n';
    for (int a: ans)std::cout << a << ' ';
}

