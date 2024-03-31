#include <iostream>
#include <vector>
#include <array>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)std::cin >> a[i];
    std::vector<bool> vis(n + 1);
    std::vector<std::vector<std::pair<int, int>>> ans(2);
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i])continue;
        std::vector<int> c;
        for (int j = i; !vis[j]; j = a[j]) {
            c.push_back(j);
            vis[j] = true;
        }
        int l = 1, r = static_cast<int>(c.size()) - 1;
        while (l < r) {
            ans[k].emplace_back(c[l], c[r]);
            std::swap(a[c[l]], a[c[r]]);
            l++, r--;
        }
    }
    if (!ans[k].empty())k++;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i) {
            ans[k].emplace_back(i, a[i]);
            std::swap(a[i], a[a[i]]);
        }
    }
    if (!ans[k].empty())k++;
    std::cout << k << "\n";
    for (int i = 0; i < k; i++) {
        std::cout << ans[i].size() << "\n";
        for (auto &[u, v]: ans[i])std::cout << u << ' ' << v << "\n";
    }

}