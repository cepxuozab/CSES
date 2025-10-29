#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    struct Segment {
        long long sum;
        int len;
    };

    vector<Segment> stk;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        long long current_sum = x[i];
        int current_len = 1;

        while (!stk.empty()) {
            Segment top = stk.back();
            // Check if merging increases or maintains the average
            // (current_sum + top.sum) / (current_len + top.len) >= current_sum / current_len
            if ((current_sum + top.sum) * current_len >= current_sum * (current_len + top.len)) {
                current_sum += top.sum;
                current_len += top.len;
                stk.pop_back();
            } else {
                break;
            }
        }

        stk.push_back({current_sum, current_len});
        ans[i] = current_len;
    }

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}