#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = LLONG_MIN / 4;

struct Line {
    ll m, b; // y = m*x + b
    Line(ll _m = 0, ll _b = NEG) : m(_m), b(_b) {}
    inline ll eval(ll x) const { if (b==NEG) return NEG; return m * x + b; }
};

struct LiChaoSeg {
    int L, R;               // domain [L, R]
    vector<Line> st;        // segment tree (1-indexed)
    LiChaoSeg(int l = 0, int r = 0) { init(l, r); }
    void init(int l, int r) {
        L = l; R = r;
        if (L > R) { L = 0; R = -1; } // empty
        int sz = max(1, R - L + 1);
        st.assign(4 * (sz + 5), Line());
    }

    void insert_line(Line nw, int idx, int l, int r) {
        int m = (l + r) >> 1;
        Line cur = st[idx];
        // keep in st[idx] the line that is better at m
        if (cur.eval(m) < nw.eval(m)) {
            st[idx] = nw;
            nw = cur;
        }
        if (l == r) return;
        if (nw.eval(l) > st[idx].eval(l)) {
            insert_line(nw, idx << 1, l, m);
        } else if (nw.eval(r) > st[idx].eval(r)) {
            insert_line(nw, idx << 1 | 1, m + 1, r);
        }
    }

    void add_segment(Line nw, int ql, int qr, int idx, int l, int r) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            insert_line(nw, idx, l, r);
            return;
        }
        int m = (l + r) >> 1;
        add_segment(nw, ql, qr, idx << 1, l, m);
        add_segment(nw, ql, qr, idx << 1 | 1, m + 1, r);
    }

    void add_segment(Line nw, int ql, int qr) {
        if (L > R) return;
        ql = max(ql, L); qr = min(qr, R);
        if (ql > qr) return;
        add_segment(nw, ql, qr, 1, L, R);
    }

    ll query_point(int x, int idx, int l, int r) const {
        if (L > R) return NEG;
        ll res = st[idx].eval(x);
        if (l == r) return res;
        int m = (l + r) >> 1;
        if (x <= m) return max(res, query_point(x, idx << 1, l, m));
        else return max(res, query_point(x, idx << 1 | 1, m + 1, r));
    }
    ll query_point(int x) const {
        if (L > R) return NEG;
        if (x < L || x > R) return NEG;
        return query_point(x, 1, L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    vector<int> left(n), right(n);
    {
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && h[st.top()] >= h[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    {
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && h[st.top()] >= h[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    int Smax = n - k; // start positions: 0..Smax
    LiChaoSeg lichao(0, max(0, Smax));

    for (int i = 0; i < n; ++i) {
        int A = left[i] + 1;
        int B = right[i] - 1;
        if (A > B) continue;
        int sL = max(0, A - (k - 1));
        int sR = min(Smax, B);
        if (sL > sR) continue;

        long long s1 = min((long long)A, (long long)B - (long long)k + 1LL);
        long long s2 = max((long long)A, (long long)B - (long long)k + 1LL);

        // segment 1: [sL, min(sR, s1)]  -> increasing: w = s - A + k  => area = h*s + h*(k-A)
        int seg1L = sL;
        int seg1R = (int)min((long long)sR, s1);
        if (seg1L <= seg1R) {
            ll m = h[i];
            ll b = h[i] * ( (ll)k - (ll)A );
            lichao.add_segment(Line(m, b), seg1L, seg1R);
        }

        // segment 2: [max(sL, s1+1), min(sR, s2)] -> constant (pick represent s0)
        int seg2L = (int)max((long long)sL, s1 + 1);
        int seg2R = (int)min((long long)sR, s2);
        if (seg2L <= seg2R) {
            int s0 = seg2L;
            ll leftBound = max((ll)A, (ll)s0);
            ll rightBound = min((ll)B, (ll)s0 + k - 1);
            ll width0 = rightBound - leftBound + 1;
            if (width0 > 0) {
                ll area = h[i] * width0;
                lichao.add_segment(Line(0, area), seg2L, seg2R);
            }
        }

        // segment 3: [max(sL, s2+1), sR] -> decreasing: w = B - s + 1 => area = -h*s + h*(B+1)
        int seg3L = (int)max((long long)sL, s2 + 1);
        int seg3R = sR;
        if (seg3L <= seg3R) {
            ll m = -h[i];
            ll b = h[i] * ( (ll)B + 1LL );
            lichao.add_segment(Line(m, b), seg3L, seg3R);
        }
    }

    // Query and output
    vector<long long> ans;
    ans.reserve(max(0, Smax + 1));
    for (int s = 0; s <= Smax; ++s) {
        ll v = lichao.query_point(s);
        if (v == NEG) v = 0;
        ans.push_back(v);
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
