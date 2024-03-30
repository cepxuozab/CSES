#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<int64_t> h(m + 2, 0), l(m), r(m);
    int64_t ans = 0;
    for (int k = 0; k < n; ++k) {
        std::string s;
        std::cin >> s;
        for (int i = 0; i < m; i++) {
            if (s[i] == '.') h[i + 1]++;
            else h[i + 1] = 0;
        }
        std::stack<int> st;
        st.push(0);
        for (int i = 0; i < m; i++) {
            while (st.top() != 0 && h[st.top()] >= h[i + 1]) st.pop();
            l[i] = st.top();
            st.push(i + 1);
        }
        while (!st.empty()) st.pop();
        st.push(m + 1);
        for (int i = m - 1; i >= 0; i--) {
            while (st.top() != m + 1 && h[st.top()] >= h[i + 1]) st.pop();
            r[i] = st.top() - 2;
            st.push(i + 1);
        }
        for (int i = 0; i < m; i++) {
            ans = std::max(ans, h[i + 1] * (r[i] - l[i] + 1));
        }
    }
    std::cout << ans;
}