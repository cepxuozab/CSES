#include <bits/stdc++.h>

using namespace std;

struct Event {
    long long t;
    int a, b, id;
    int sign; // +1 for d, -1 for c-1
    bool operator<(Event const &o) const {
        if (t != o.t) return t < o.t;
        return sign > o.sign; // doesn't matter much, stable ordering
    }
};

struct Fenwick {
    int n{};
    vector<int> bit;

    Fenwick(int n_ = 0) : n(n_), bit(n_ + 1) {}


    void add(int i, int delta) {
        for (; i <= n; i += i & -i) bit[i] += delta;
    }

    int sumPrefix(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }

    int rangeSum(int l, int r) {
        if (r < l) return 0;
        return sumPrefix(r) - sumPrefix(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> x(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i];

    vector<pair<long long, int>> items;
    items.reserve(n);
    for (int i = 1; i <= n; ++i) items.emplace_back(x[i], i);
    sort(items.begin(), items.end()); // by value asc

    vector<Event> events;
    events.reserve(2 * q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        long long c, d;
        cin >> a >> b >> c >> d;
        events.push_back({d, a, b, i, +1});
        events.push_back({c - 1, a, b, i, -1});
    }
    sort(events.begin(), events.end());

    Fenwick bit(n);
    vector<long long> ans(q, 0);
    int ptr = 0; // pointer in items
    for (auto &ev: events) {
        // add all items with value <= ev.t
        while (ptr < n && items[ptr].first <= ev.t) {
            bit.add(items[ptr].second, 1);
            ++ptr;
        }
        int cnt = bit.rangeSum(ev.a, ev.b);
        ans[ev.id] += (long long) ev.sign * cnt;
    }

    for (int i = 0; i < q; ++i) cout << ans[i] << '\n';
    return 0;
}
