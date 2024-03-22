#include <iostream>
#include <vector>
#include <string>
#include <string_view>

auto PrefixFunction(std::string_view s) -> std::vector<int> {
    int n = static_cast<int>(s.size());
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            j++;
        pi[i] = j;
    }
    return pi;
}

auto Get_kmp_automaton(std::string s) -> std::vector<std::vector<int>> {
    s += '#';
    int n = static_cast<int>(s.size());
    auto pi = PrefixFunction(s);
    std::vector<std::vector<int>> aut(n, std::vector<int>(26));
    aut[0][s[0] - 'A'] = 1;
    for (int i = 1; i < n; i++)
        for (int c = 0; c < 26; c++) {
            if ('A' + c == s[i])
                aut[i][c] = i + 1;
            else
                aut[i][c] = aut[pi[i - 1]][c];
        }
    return aut;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    int m = static_cast<int>(s.size());
    auto aut = Get_kmp_automaton(s);
    long long mod = 1e9 + 7;
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m + 1));
    dp[n][m] = 1;
    for (int i = n - 1; i >= 0; i--) {
        dp[i][m] = 26 * dp[i + 1][m] % mod;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 26; k++)
                dp[i][j] += dp[i + 1][aut[j][k]];
            dp[i][j] %= mod;
        }
    }

    std::cout << dp[0][0] << "\n";

    return 0;
}

