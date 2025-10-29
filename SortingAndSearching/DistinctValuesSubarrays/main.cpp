#include <iostream>
#include <vector>
#include <unordered_map>


auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::unordered_map<int, int> freq;
    bool U = true;
    long long ans = 0;
    for (int r = 0, l = 0; r < n; r++) {
        if (++freq[a[r]] == 2) U = false;
        while (l < r && !U) {
            if (--freq[a[l++]] == 1) U = true;
        }
        ans += (r - l + 1);
    }
    std::cout << ans << '\n';


}