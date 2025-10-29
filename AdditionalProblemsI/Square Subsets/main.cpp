#include <iostream>
#include <vector>
#include <set>


const int mod = 1e9 + 7;

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::set<int>> b;
    long long ans = 1;
    while (n--) {
        int x;
        std::cin >> x;
        int v = x;
        std::set<int> cur;
        for (int i = 2; i * i <= x; i++)
            if (v % i == 0) {
                bool c = false;
                while (v % i == 0) {
                    v /= i;
                    c = !c;
                }
                if (c) cur.insert(i);
            }
        if (v != 1) cur.insert(v);
        for (auto &a: b) {
            if (cur.count(*a.rbegin())) {
                for (int i: a)
                    if (cur.count(i))
                        cur.erase(i);
                    else
                        cur.insert(i);
            }
        }
        if (cur.size() == 0)
            ans = ans * 2 % mod;
        else
            b.push_back(cur);
    }
    std::cout << ans << "\n";
}