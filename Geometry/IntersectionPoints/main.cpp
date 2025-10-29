#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

struct BIT {
private:
    int n;
    std::vector<int> t;

    auto Get(int id) -> int {
        int sum = 0;

        for (id++; id > 0; id -= id & -id) sum += t[id];

        return sum;
    }

public:
    BIT(int n) {
        this->n = n;
        t.resize(n + 1);
    }

    void Update(int id, int val) {
        for (id++; id <= n; id += id & -id) t[id] += val;
    }

    auto Get(int l, int r) -> int {
        return Get(r) - Get(l - 1);
    }
};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    const int N = 1e+6;

    struct Event {
        int x, y1, y2, t;
    };

    std::vector<Event> e;

    for (int i = 1, x1, y1, x2, y2; i <= n; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            e.push_back({x1, y1 + N, y2 + N, 0});
        } else {
            e.push_back({x1, y1 + N, y1 + N, 1});
            e.push_back({x2, y1 + N, y1 + N, -1});
        }
    }
    std::ranges::sort(e,{},&Event::x);

    BIT tree(2 * N + 1);

    int64_t cnt = 0;

    for (auto [x, y1, y2, t] : e) {
        if (t != 0) {
            tree.Update(y1, t);
        } else {
            cnt += tree.Get(y1, y2);
        }
    }

    std::cout << cnt << "\n";
}