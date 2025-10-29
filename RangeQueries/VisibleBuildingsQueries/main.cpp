#include <iostream>
#include <vector>
#include <array>
#include <algorithm>


auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int &i: a)
        std::cin >> i;
    std::vector<std::vector<std::array<int, 2>>> qs(n); // qs[i] = queries at left endpoint
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        qs[l].push_back({r, i});
    }
    std::vector<int> ans(q);
    std::vector<int> stk; // smallest at top
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && a[i] >= a[stk.back()])
            stk.pop_back();
        stk.push_back(i);
        for (auto [r, idx]: qs[i])
            ans[idx] = upper_bound(rbegin(stk), rend(stk), r) - rbegin(stk);
    }
    for (int i: ans)
        std::cout << i << '\n';


}