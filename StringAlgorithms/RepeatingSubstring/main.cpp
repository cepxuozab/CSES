#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>

auto buildSA(std::string_view s) -> std::vector<int> {
    int n = static_cast<int>(s.size());
    std::vector<int> sa(n);
    std::vector<int> rank(2ULL * n), temp(n, 1);

    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rank[i] = static_cast<int>(static_cast<unsigned char>(s[i]));
    }

    for (int k = 1; k < n; k <<= 1) {
        auto compare = [&](int a, int b) {
            if (rank[a] != rank[b]) return rank[a] < rank[b];
            return rank[a + k] < rank[b + k];
        };

        sort(sa.begin(), sa.end(), compare);
        for (int i = 1; i < n; ++i) {
            temp[i] = temp[i - 1] + compare(sa[i - 1], sa[i]);
        }
        for (int i = 0; i < n; ++i) {
            rank[sa[i]] = temp[i];
        }

        if (rank[sa[n - 1]] == n) break;
    }

    return sa;
}

auto buildLCP(std::string &s, std::vector<int> &sa) -> std::vector<int> {
    int n = static_cast<int>(s.size());
    std::vector<int> pos(n), lcp(n);

    for (int i = 0; i < n; ++i) {
        pos[sa[i]] = i;
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (pos[i] == n - 1) continue;

        int j = sa[pos[i] + 1];
        while (s[i + k] == s[j + k]) ++k;

        lcp[pos[i]] = k;
        if (k > 0) --k;
    }

    return lcp;
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    auto sa = buildSA(s);
    auto lcp = buildLCP(s, sa);

    auto k = std::max_element(lcp.begin(), lcp.end()) - lcp.begin();
    if (lcp[k] == 0) {
        std::cout << "-1";
    } else {
        std::cout << s.substr(sa[k], lcp[k]);
    }

    return 0;
}
