#include <iostream>
#include <vector>
#include <queue>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> x(n);
    for (int &i: x) {
        std::cin >> i;
    }

    std::priority_queue<int> S;
    long long ans = 0;
    for (auto &&elem: x) {
        if (S.empty() || elem >= S.top()) {
            S.push(elem);
        } else {
            ans += S.top() - elem;
            S.pop();
            S.push(elem);
            S.push(elem);
        }
    }
    std::cout << ans << '\n';
}