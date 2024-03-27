#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
public:
    int n{};
    vector<vector<T>> mat{};
    F func;

    SparseTable(const vector<T>& a, F f)
        : n(static_cast<int>(a.size()))
        , mat({})
        , func(std::move(f)) {
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    [[nodiscard]] auto get(int from, int to) const -> T {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    constexpr int N = 1e6 + 5;
    vector<int> t(N + 1, INT_MAX);
    vector<pair<int, int>> mv;
    vector<int> num(N + 1, -1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mv.emplace_back(a, b);
        t[a] = min(t[a], b);
    }
    t[N - 1] = N - 1;
    SparseTable<int> st(t, [&](int i, int j) {
        return min(i, j);
    });
    vector<int> to(N);
    for (int i = 0; i < N; i++) {
        to[i] = st.get(i, N);
    }
    vector<vector<int>> jump(N, vector<int>(22));
    for (int i = 0; i < N; ++i) {
        jump[i][0] = to[i];
    }
    for (int i = 1; i < 22; ++i) {
        for (int j = 0; j < N; ++j) {
            jump[j][i] = jump[jump[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        int cur = a;
        int cnt = 0;
        for (int j = 21; j >= 0; --j) {
            if (jump[cur][j] <= b) {
                cnt += (1 << j);
                cur = jump[cur][j];
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}