#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

auto main() -> int {
    int n;
    std::cin >> n;
    int m = n * (n - 1) / 2;
    std::vector<int> v(m);
    for (auto &x: v)
        std::cin >> x;
    std::vector<int> ans;
    auto test = [&](int id) -> bool {
        ans.clear();
        int s = v[0] + v[1] + v[id];
        if (s % 2)
            return false;
        s /= 2;
        ans.push_back(v[0] + v[1] - s);
        ans.push_back(s - v[1]);
        ans.push_back(s - v[0]);
        std::priority_queue<int, std::vector<int>, std::greater<>> queue;
        for (int i = 2; i < m; i++) {
            if (i == id)
                continue;
            if (!queue.empty() && v[i] == queue.top())
                queue.pop();
            else {
                int x = v[i] - ans[0];
                for (int j = 1; std::cmp_less(j, ans.size()); j++)
                    queue.emplace(x + ans[j]);
                ans.push_back(x);
                if (std::cmp_greater(ans.size(), n))
                    break;
            }
        }
        return queue.empty();
    };
    std::ranges::sort(v);
    for (int i = 2; i < m; i++)
        if (test(i))
            break;
    for (auto &x: ans)
        std::cout << x << " ";
}