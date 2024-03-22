/**
 * @brief Word Combinations
 * @link https://cses.fi/problemset/task/1731/
 * @date 14.01.2024
 */
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <array>
#include <algorithm>
#include <cstdint>

struct Node {
    static constexpr int ALPHABET = 26;
    std::array<int, ALPHABET> child{};
    bool is_leaf = false;

    Node() { std::ranges::fill(child, -1); }
};

class Trie {
    std::vector<Node> trie;
public:
    Trie() : trie(1) {}

    void Add(std::string_view word) {
        int v = 0;
        for (char ch: word) {
            int c = static_cast<int>(ch - 'a');
            if (trie[v].child[c] == -1) {
                trie[v].child[c] = static_cast<int>(trie.size());
                trie.emplace_back();
            }
            v = trie[v].child[c];
        }
        trie[v].is_leaf = true;
    }

    int64_t CountWayCreateString(std::string_view str) {
        constexpr int MOD = 1'000'000'007;
        int const m = static_cast<int>(str.length());
        std::vector<int64_t> dp(m + 1);
        dp[m] = 1;
        for (int i = m - 1; i >= 0; i--) {
            int v = 0;
            for (int j = i; j < m; j++) {
                int c = (int) (str[j] - 'a');
                if (trie[v].child[c] == -1) break;
                v = trie[v].child[c];

                if (trie[v].is_leaf)
                    dp[i] = (dp[i] + dp[j + 1]) % MOD;
            }
        }
        return dp[0];
    }
};

int main() {
    std::string str;
    std::cin >> str;
    auto trie = Trie();
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string word;
        std::cin >> word;
        trie.Add(word);
    }
    std::cout << trie.CountWayCreateString(str);
    return 0;
}