/**
* @brief Sliding Window Median
 * @link https://cses.fi/problemset/task/1076/
 * @date 20.01.2024
*/

#include <iostream>
#include <vector>
#include <queue>


auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int k;
    std::cin >> n >> k;
    std::priority_queue<std::pair<int, int>> max_heap;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> min_heap;
    std::vector<int> arr(n);
    for (int &elem: arr) {
        std::cin >> elem;
    }
    arr.emplace_back();
    int m = (k + 1) / 2;
    int b = 0;

    for (int i = 0; i < n; ++i) {
        while (!min_heap.empty() && min_heap.top().second <= i - k) min_heap.pop();
        while (!max_heap.empty() && max_heap.top().second <= i - k) max_heap.pop();
        if (b < m) { //store in left heap (the least elements)
            min_heap.emplace(arr[i], i);
            max_heap.push(min_heap.top());
            min_heap.pop();
            b++;
        } else { //store in right heap (greatest elements)
            max_heap.emplace(arr[i], i);
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (!min_heap.empty() && min_heap.top().second <= i - k) min_heap.pop();
        while (!max_heap.empty() && max_heap.top().second <= i - k) max_heap.pop();
        if (i < k - 1) continue;
        std::cout << max_heap.top().first << ' ';
        if (arr[i - k + 1] <= max_heap.top().first) b--;//element to be removed lies in left heap then decrease balance
        //to cause next addition in left heap

    }

    return 0;
}