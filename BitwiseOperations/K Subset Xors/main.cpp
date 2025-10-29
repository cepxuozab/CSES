#include <bits/stdc++.h>
using namespace std;
vector<int> build_xor_basis(const vector<int>& a) {
    vector<int> b;
    for(int x : a) {
        for(int v : b) {
            x = min(x, x ^ v);
        }
        if(x) b.push_back(x);
    }
    sort(b.rbegin(), b.rend());
    for(int i = (int)b.size() - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            b[j] = min(b[j], b[i] ^ b[j]);
        }
    }
    reverse(b.begin(), b.end());
    return b;
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> b = build_xor_basis(a);
    int r = b.size();
    int repeat = (n - r >= 20 ? k : (1 << (n - r)));
    vector<int> ans;
    int cnt = 0;
    for(int mask = 0; mask < (1 << r) && cnt < k; ++mask) {
        int val = 0;
        for(int i = 0; i < r; ++i) {
            if(mask & (1 << i)) val ^= b[i];
        }
        for(int j = 0; j < repeat && cnt < k; ++j) {
            cout << val << " ";
            cnt++;
        }
    }
    cout << "\n";
}
