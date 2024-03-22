#include <deque>
#include <iostream>
#include <stack>
#include <vector>

[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::deque<int>> g(n + 1);
    std::vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 != 0) {
            std::cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    std::vector<int> ans;
    std::stack<int> st;
    st.push(1);

    while (!st.empty()) {
        int v = st.top();
        if (!g[v].empty()) {
            int u = g[v].front();
            g[v].pop_front();
            for (auto it = g[u].begin(); it != g[u].end(); ++it) {
                if (*it == v) {
                    g[u].erase(it);
                    break;
                }
            }
            st.push(u);
        } else {
            ans.push_back(v);
            st.pop();
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!g[i].empty()) {
            std::cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
        std::cout << *it << ' ';
    }
}