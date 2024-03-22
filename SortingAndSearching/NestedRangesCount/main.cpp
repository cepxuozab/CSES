#include <algorithm>
#include <iostream>
#include <map>
#include <ranges>
#include <set>
#include <vector>
struct Interval {
    int left{};
    int right{};
    int index{};
    bool operator<(Interval const &other) const { return left == other.left ? right > other.right : left < other.left; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<Interval> intervals;
    intervals.reserve(n);

    std::set<int> unique_vals;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        intervals.push_back({x, y, i});
        unique_vals.insert(x);
        unique_vals.insert(y);
    }
    std::map<int, int> maps;
    int val_id = 1;
    for (int x: unique_vals)
        maps[x] = val_id++;
    std::sort(intervals.begin(), intervals.end());
    std::vector<int> ds(2 * n + 2);
    auto query = [&](int idx) {
        int cnt = 0;
        for (int i = idx; i > 0; i -= -i & i)
            cnt += ds[i];
        return cnt;
    };
    auto update = [&](int idx, int val) {
        for (int i = idx; i < static_cast<int>(ds.size()); i += -i & i)
            ds[i] += val;
    };
    std::vector<int> it_contains_other(n);
    for (int i = n - 1; i >= 0; i--) {
        int const y = maps[intervals[i].right];
        int const id = intervals[i].index;
        it_contains_other[id] = query(y);
        update(y, 1);
    }
    std::vector<int> other_contains_it(n);
    std::ranges::fill(ds, 0);
    for (int i = 0; i < n; i++) {
        int const y = maps[intervals[i].right];
        int const id = intervals[i].index;

        other_contains_it[id] = i - query(y - 1);
        update(y, 1);
    }
    for (auto const &i: it_contains_other) {
        std::cout << i  << ' ';
    }
    std::cout << '\n';
    for (auto const &i: other_contains_it) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
