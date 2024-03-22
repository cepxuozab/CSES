#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cstdint>


auto Suffix_array(std::string s) -> std::vector<int> {
    s += "$";
    int n = static_cast<int>(s.size()), N = std::max(n, 260);
    std::vector<int> sa(n), ra(n);
    for (int i = 0; i < n; i++) sa[i] = i, ra[i] = static_cast<int>(static_cast<unsigned char>(s[i]));

    for (int k = 0; k < n; k ? k *= 2 : k++) {
        std::vector<int> nsa(sa), nra(n), cnt(N);

        for (int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n, cnt[ra[i]]++;
        for (int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i + 1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

        for (int i = 1, r = 0; i < n; i++)
            nra[sa[i]] = r += ra[sa[i]] !=
                              ra[sa[i - 1]] or ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n];
        ra = nra;
        if (ra[sa[n - 1]] == n - 1) break;
    }
    return {sa.begin() + 1, sa.end()};
}

auto Kasai(std::string s, std::vector<int> sa) -> std::vector<int> {
    int n = static_cast<int>(s.size()), k = 0;
    std::vector<int> ra(n), lcp(n);
    for (int i = 0; i < n; i++) ra[sa[i]] = i;

    for (int i = 0; i < n; i++, k -= !!k) {
        if (ra[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = sa[ra[i] + 1];
        while (i + k < n and j + k < n and s[i + k] == s[j + k]) k++;
        lcp[ra[i]] = k;
    }
    return lcp;
}

auto main() -> int {
    std::string s;
    std::cin >> s;

    int n = static_cast<int>(s.size());
    std::vector<int64_t> ans(n + 2);

    auto sa = Suffix_array(s);
    auto ka = Kasai(s, sa);


    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans[1]++;
            ans[n - sa[i] + 1]--;
        } else {
            int l = ka[i - 1] + 1;
            int r = n - sa[i];
            if (l <= r) {
                ans[l]++;
                ans[n - sa[i] + 1]--;
            }
        }
    }
    int64_t cnt = 0;

    for (int i = 1; i <= n; i++) {
        cnt += ans[i];
        std::cout << cnt << " ";
    }
}