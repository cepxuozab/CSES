#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;


template<class T, class F>
struct tree {
    int n;
    T unit;
    F op;
    vector<T> s;

    tree(int n, T unit, F op) : n(n), unit(unit), op(op), s(2 * n, unit) {}

    void update(int i, T val) {
        for (s[i += n] = val; i /= 2;) s[i] = op(s[2 * i], s[2 * i + 1]);
    }

    auto query(int l, int r) -> T {  // [l, r)
        T x = unit, y = unit;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l % 2) x = op(x, s[l++]);
            if (r % 2) y = op(s[--r], y);
        }
        return op(x, y);
    }
};

const int MX = 1'000'000;

// (x, y) -> (-y + MX, x)
void rotate(vector<int> &x, vector<int> &y) {
    const int n = ssize(x);
    for (int i = 0; i < n; i++) {
        swap(x[i], y[i]);
        y[i] = MX - y[i];
    }
}

auto main() -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> x1(n), y1(n), x2(m), y2(m);
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> x2[i] >> y2[i];
    }
    vector<int> ans(m, 4 * MX);
    for (int _ = 0; _ < 4; _++) {
        vector<vector<int>> y1s(MX + 1);
        for (int i = 0; i < n; i++) {
            y1s[x1[i]].push_back(y1[i]);
        }
        vector<vector<pair<int, int>>> y2s(MX + 1);
        for (int i = 0; i < m; i++) {
            y2s[x2[i]].emplace_back(y2[i], i);
        }

        tree st(MX + 1, 4 * MX, ranges::min);
        for (int x = 0; x <= MX; x++) {
            for (int y: y1s[x]) {
                st.update(y, y - x);
            }
            for (auto [y, i]: y2s[x]) {
                ans[i] = min(ans[i], st.query(y + 1, MX + 1) + x - y);
            }
        }

        rotate(x1, y1);
        rotate(x2, y2);
    }
    cout << *ranges::max_element(ans) << "\n";
    return 0;
}