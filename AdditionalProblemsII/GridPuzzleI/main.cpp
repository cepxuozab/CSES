#include <iostream>
#include <vector>
#include <queue>


auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int &x: a) std::cin >> x;
    for (int &x: b) std::cin >> x;

    int sum = 0;
    for (int x: a) sum += x;
    for (int x: b) sum -= x;
    if (sum != 0) {
        std::cout << "-1";
        return 0;
    }

    std::priority_queue<std::pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) q.emplace(b[i], i);
    }

    std::vector ans(n, std::vector<bool>(n));
    for (int i = 0; i < n; i++) {
        std::vector<int> used;
        while (a[i] > 0) {
            if (q.empty()) {
                std::cout << "-1\n";
                return 0;
            }

            int j = q.top().second;
            q.pop();

            ans[i][j] = true;
            a[i]--;
            b[j]--;

            used.push_back(j);
        }

        for (int x: used) if (b[x] > 0) q.emplace(b[x], x);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (ans[i][j]) std::cout << "X";
            else std::cout << ".";
        std::cout << "\n";
    }
}
