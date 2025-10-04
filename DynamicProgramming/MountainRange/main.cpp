#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> left(n, -1), right(n, -1);

    // nearest smaller to left
    {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] <= h[i]) st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }
    }

    // nearest smaller to right
    {
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && h[st.top()] <= h[i]) st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }
    }

    vector<int> dp(n, -1);

    function<int(int)> dfs = [&](int v) -> int {
        if (dp[v] != -1) return dp[v];
        int res = 1;
        if (left[v] != -1) res = max(res, 1 + dfs(left[v]));
        if (right[v] != -1) res = max(res, 1 + dfs(right[v]));
        return dp[v] = res;
    };

    int ans = 1;
    for (int i = 0; i < n; i++) ans = max(ans, dfs(i));

    cout << ans << "\n";
}
