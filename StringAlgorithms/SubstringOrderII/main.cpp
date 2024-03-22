#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cstdint>


struct SuffixArray {
    std::vector<int> sa, lcp;

    SuffixArray(std::string &s, int lim = 256) { // or basic_string<int>
        int n = static_cast<int>(std::size(s)) + 1, k = 0, a, b;
        std::vector<int> x(std::begin(s), std::end(s) + 1), y(n), ws(std::max(n, lim)), rank(n);
        sa = lcp = y, iota(std::begin(sa), std::end(sa), 0);
        for (int j = 0, p = 0; p < n; j = std::max(1, j * 2), lim = p) {
            p = j, iota(std::begin(y), std::end(y), n - j);
            for (int i = 0; i < n; ++i) if (sa[i] >= j) y[p++] = sa[i] - j;
            fill(std::begin(ws), std::end(ws), 0);
            for (int i = 0; i < n; ++i) ws[x[i]]++;
            for (int i = 1; i < lim; ++i) ws[i] += ws[i - 1];
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                a = sa[i - 1], b = sa[i], x[b] =
                        (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
        }
        for (int i = 1; i < n; ++i) rank[sa[i]] = i;
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = sa[rank[i] - 1];
                    s[i + k] == s[j + k];
        k++);
    }
};

std::string s;
std::vector<int> sa;

auto get(int saInd, int letInd) -> char {
    if (std::cmp_less_equal(std::size(s), letInd + sa[saInd])) return (char) ('a' - 1);
    return s[sa[saInd] + letInd];
}

auto upper(int l, int r, int pos, char c) -> int {
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (get(mid, pos) > c) r = mid - 1;
        else l = mid;
    }
    if (get(l, pos) == c) return l;
    else return -1;
}

auto main() -> int {
    std::cin >> s;
    int n = static_cast<int>(std::size(s));
    sa = SuffixArray(s).sa;

    std::vector<int64_t> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = v[i - 1] + n - sa[i];
    }
    int64_t k;
    std::cin >> k;
    int l = 1;
    int r = n;
    int pos = 0;

    while (true) {
        int up = upper(l, r, pos, s[sa[l] + pos]);
        if (get(l, pos) == 'a' - 1) {
            l++;
            continue;
        }
        if (k <= v[up] - v[l - 1] - 1LL * pos * (up - l + 1)) {
            if (k <= up - l + 1) {
                std::cout << s.substr(sa[l], pos + 1) << '\n';
                return 0;
            } else {
                r = up;
                k -= up - l + 1;
                pos++;
            }
        } else {
            k -= v[up] - v[l - 1] - 1LL * pos * (up - l + 1);
            l = up + 1;
        }
    }
}