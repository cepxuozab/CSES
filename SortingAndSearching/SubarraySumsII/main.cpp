/**
* @brief Subarray Sums II
 * @link https://cses.fi/problemset/task/1661
 * @date 20.01.2024
*/

#include <iostream>
#include <map>
#include <vector>
#include <cstdint>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int x;
    std::cin >> n >> x;
    std::vector<int> arr(n);
    int64_t cnt = 0;
    int64_t pre = 0;
    std::map<int64_t, int> freq;
    freq[0] = 1;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        pre += num;
        cnt += freq[pre - x];
        freq[pre]++;
    }
    std::cout << cnt;
    return 0;
}