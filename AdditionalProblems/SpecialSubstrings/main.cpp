#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string str;
    std::cin >> str;
    int cnt = 0;
    std::map<char, int> freq;
    for (char ch : str) {
        if (!freq.contains(ch)) {
            freq[ch] = cnt++;
        }
    }
    std::map<std::vector<int>, int> mdiff;
    std::vector<int> prefix_cnt(cnt);
    int64_t ans = 0;
    std::vector<int> v(cnt, 0);
    mdiff.insert({v, 1});
    for (char ch : str) {
        prefix_cnt[freq[ch]]++;
        for (int j = 0; j < cnt; j++) {
            v[j] = prefix_cnt[j] - prefix_cnt[0];
        }
        ans += mdiff[v];
        mdiff[v]++;
    }
    std::cout << ans;
}