#include <iostream>
#include <vector>
#include <algorithm>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].first;
        arr[i].second = i;
    }
    std::ranges::sort(arr);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = std::max(ans, arr[i].second - i);
    }
    std::cout << ans;
}
