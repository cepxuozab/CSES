#include <iostream>
#include <vector>
#include <queue>


auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> courses (n + 1);
    std::vector<int> in(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        courses [b].push_back(a);
        in[a]++;
    }
    std::priority_queue<int> queue;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            queue.push(i);
        }
    }
    int idx = n;
    std::vector<int> ans(n + 1);


    while (!queue.empty()) {
        int u = queue.top();
        queue.pop();
        ans[idx--] = u;
        for (int v: courses [u]) {
            in[v]--;
            if (in[v] == 0)
                queue.push(v);
        }
    }

    for (int i = 1; i <= n; i++)
        printf("%d%c", ans[i], (" \n")[i == n]);
}