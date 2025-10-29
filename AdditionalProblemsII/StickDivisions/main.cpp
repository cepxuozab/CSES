#include <iostream>
#include <queue>
#include <vector>

auto main() -> int {
    int x, n;
    std::cin >> x >> n;
    std::priority_queue<int, std::vector<int>, std::greater<>> sticks;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        sticks.push(x);
    }
    long long sum = 0;
    while (sticks.size() > 1) {
        auto a = sticks.top();
        sticks.pop();
        auto b = sticks.top();
        sticks.pop();
        sticks.push(a + b);
        sum += (a + b);
    }
    std::cout << sum;
}