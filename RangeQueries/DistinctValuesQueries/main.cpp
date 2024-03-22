#include <array>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <class T>
class Bit {
public:
    explicit Bit(int n)
        : n_(n)
        , t_(n + 1) {
    }

    void add(int x, int d) {
        for (++x; x <= n_; x += lowbit(x)) {
            t_[x] += d;
        }
    }

    // Query sum of interval [0...x].
    auto query(int x) -> T {
        T ans = 0;
        for (++x; x > 0; x -= lowbit(x)) {
            ans += t_[x];
        }
        return ans;
    }

    auto query(int l, int r) -> T {
        return query(r) - query(l - 1);
    }

private:
    auto static lowbit(int x) -> int {
        return x & -x;
    }
    int n_;
    vector<T> t_;
};

auto main() -> int {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<array<int, 2>>> query(N);
    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        query[b].push_back({a, i});
    }
    Bit<int> bit(N);
    map<int, int> mp;
    vector<int> ans(Q);
    for (int i = 0; i < N; i++) {
        bit.add(i, 1);
        if (mp.contains(A[i])) {
            // -1 + 1 == 0
            bit.add(mp[A[i]], -1);
        }
        mp[A[i]] = i;
        for (auto const& [first, second] : query[i]) {
            ans[second] = bit.query(first, i);
        }
    }
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
}
