#include <iostream>
#include <queue>
#include <vector>

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<int> a(n - 2);
    std::vector<int> deg(n + 1,1);
    for (int i = 0; i < n - 2; ++i) {
        std::cin >> a[i];
        deg[a[i]]++;
    }
    std::priority_queue<int, std::vector<int>, std::greater<>> Q;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            Q.push(i);
        }
    }
    for (int i = 0; i < n - 2; i++) {
        int u = a[i];
        int v = Q.top();
        Q.pop();

        deg[u]--;
        deg[v]--;
        if (deg[u] == 1)
            Q.push(u);

        std::cout << u << ' ' << v << '\n';
    }
    for (int i = 1; i <= n; i++)
        if (deg[i])
            std::cout << i << ' ';
}