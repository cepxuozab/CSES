/**
* @brief Subarray Sums I
 * @link https://cses.fi/problemset/task/1660/
 * @date 20.01.2024
*/

#include <iostream>
#include <vector>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int x;
    std::cin >> n >> x;
    std::vector<int> arr(n);
    for (auto &num: arr) {
        std::cin >> num;
    }
    int a = 0;
    int cnt = 0;
    for (int i = 0, j = 0; j < n; j++) {
        a += arr[j];
        while (a > x)
            a -= arr[i++];
        if (a == x)
            cnt++;
    }
    std::cout << cnt;
    return 0;
}