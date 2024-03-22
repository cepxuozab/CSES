/**
 * @brief Playlist
 * @link https://cses.fi/problemset/task/1141
 * @date 15.01.2024
 */

#include <map>
#include <iostream>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int N;
    std::cin >> N;
    int l = 1;
    int ans = 0;
    std::map<int, int> mp;
    for (int r = 1; r <= N; r++) {
        int k;
        std::cin >> k;
        if (mp.contains(k)) {
            ans = std::max(ans, r - l);
            l = std::max(l, mp[k] + 1);
        } else {
            ans = std::max(ans, r - l + 1);
        }
        mp[k] = r;
    }
    ans = std::max(N - l + 1, ans);
    std::cout << ans;
    return 0;
}