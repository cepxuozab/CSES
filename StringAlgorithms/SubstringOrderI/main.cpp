#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>


struct SuffixArray {
    std::vector<int> sa, lcp;
    SuffixArray(std::string &s, int lim = 256) { // or basic_string<int>
        int n = static_cast<int>(s.size()) + 1, k = 0, a, b;
        std::vector<int> x(s.begin(), s.end() + 1), y(n), ws(std::max(n, lim)), rank(n);
        sa = lcp = y, std::iota(sa.begin(), sa.end(), 0);
        for (int j = 0, p = 0; p < n; j = std::max(1, j * 2), lim = p) {
            p = j, std::iota(y.begin(), y.end(), n - j);
            for (int i = 0; i < n; i++)
                if (sa[i] >= j)
                    y[p++] = sa[i] - j;
            fill(ws.begin(), ws.end(), 0);
            for (int i = 0; i < n; i++)
                ws[x[i]]++;
            for (int i = 1; i < lim; i++)
                ws[i] += ws[i - 1];
            for (int i = n; i--;)
                sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; i++)
                a = sa[i - 1], b = sa[i],
                x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 1; i < n; i++)
            rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++)
        ;
    }
};

auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string str;
    std::cin >> str;
    long long k;
    std::cin >> k;
    SuffixArray SA(str);
    auto lcp = SA.lcp;
    auto sa = SA.sa;

    long long res = 0;
    int pos = 0;
    for (int i = 1; std::cmp_less(i,lcp.size()); i++) {
        res += static_cast<int>(str.size()) - sa[i] - lcp[i];
        if (res >= k) {
            pos = i;
            break;
        }
    }
    auto remain = res - k;
    std::string substr = str.substr(sa[pos]);
    for (int i = 1; i <= remain; i++) {
        substr.pop_back();
    }
    std::cout << substr;
    return 0;
}