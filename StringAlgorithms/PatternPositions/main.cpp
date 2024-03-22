#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

struct suffix_array {
    int n;
    string s;

    suffix_array(string const &s) : n(static_cast<int>(s.size()) + 1), s(s + "$") {}

    vector<int> sa, rk;

    inline void getSA() {
        sa = rk = vector<int>(n);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int i, int j) {
            return s[i] < s[j];
        });
        rk[n - 1] = 0;
        for (int i = 1; i < n; i++) {
            int cur = sa[i], lst = sa[i - 1];
            rk[cur] = s[cur] == s[lst] ? rk[lst] : i;
        }
        for (int len = 1; len < n; len <<= 1) {
            vector<int> osa(sa), ork(rk), pos(n);
            iota(pos.begin(), pos.end(), 0);
            for (const int &cur2: osa) {
                if (cur2 >= len) {
                    int cur1 = cur2 - len;
                    sa[pos[rk[cur1]]++] = cur1;
                }
            }
            for (int i = 1; i < n; i++) {
                int cur = sa[i], lst = sa[i - 1];
                rk[cur] = (ork[cur] == ork[lst] && ork[cur + len] == ork[lst + len]) ? rk[lst] : i;
            }
        }
    }

    vector<vector<int>> table;

    inline void getST() {
        int lg = __lg(n);
        table.assign(lg + 1, vector<int>(n));
        table[0] = sa;
        for (int j = 0; j < lg; j++) {
            for (int i = 0; i + (2 << j) <= n; i++)
                table[j + 1][i] = min(table[j][i], table[j][i + (1 << j)]);
        }
    }

    inline auto minid(int l, int r) -> int {
        if (l == r) return -1;
        int lg = __lg(r - l);
        return min(table[lg][l], table[lg][r - (1 << lg)]) + 1;
    }
};

auto main() -> int {

    string s;
    cin >> s;
    suffix_array SA(s);
    SA.getSA();
    SA.getST();
    int k, l, r;
    for (cin >> k; k; k--) {
        string t;
        cin >> t;
        l = 0, r = static_cast<int>(s.size()) + 1;
        while (l < r) {
            int mid = (l + r) >> 1, cur = SA.sa[mid];
            if (SA.s.compare(cur, t.size(), t) >= 0) r = mid;
            else l = mid + 1;
        }
        int tmp = l;

        l = 0, r = static_cast<int>(s.size()) + 1;
        while (l < r) {
            int mid = (l + r) >> 1, cur = SA.sa[mid];
            if (SA.s.compare(cur, t.size(), t) > 0) r = mid;
            else l = mid + 1;
        }
        cout << SA.minid(tmp, r) << '\n';
    }
    return 0;
}