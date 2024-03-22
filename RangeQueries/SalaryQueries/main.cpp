#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
#include <utility>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

using query = std::tuple<char, int, int>;

class Fenwick {
    std::vector<int> ft;
    size_t n;

public:
    explicit Fenwick(size_t n)
        : ft(n + 1, 0)
        , n(n) {
    }

    [[nodiscard]] auto query(int r) const -> int {
        int ans = 0;
        while (r > 0) {
            ans += ft[r];
            r -= r & -r;
        }
        return ans;
    }

    void update(int k, int v) {
        while (std::cmp_less_equal(k,n)) {
            ft[k] += v;
            k += k & -k;
        }
    }
};

auto main() -> int {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> salary(n);
    std::vector<int> numbers;
    std::vector<int> pos(n);

    for (int& k : salary) {
        std::cin >> k;
        numbers.push_back(k);
    }

    std::vector<query> queries(q);

    for (auto& [type, k, x] : queries) {
        std::cin >> type >> k >> x;
        if (type == '!') {
            numbers.push_back(x);
        }
    }
    std::ranges::sort(numbers);
    auto [first, last] = std::ranges::unique(numbers);
    numbers.erase(first, last);

    Fenwick ft(numbers.size());

    for (int k = 0; k < n; ++k) {
        auto const shift
            = std::ranges::distance(numbers.begin(), std::ranges::lower_bound(numbers, salary[k]));
        pos[k] = 1 + shift;
        ft.update(pos[k], 1);
    }

    for (auto [type, k, x] : queries) {
        if (type == '!') {
            --k;
            ft.update(pos[k], -1);
            auto const shift
                = std::ranges::distance(numbers.begin(), std::ranges::lower_bound(numbers, x));
            pos[k] = 1 + shift;
            ft.update(pos[k], 1);
        }

        else {
            auto const a
                = std::ranges::distance(numbers.begin(), std::ranges::lower_bound(numbers, k));
            auto b = std::ranges::distance(numbers.begin(), std::ranges::lower_bound(numbers, x));

            if (numbers[b] > x) {
                --b;
            }
            std::cout << ft.query(b + 1) - ft.query(a) << '\n';
        }
    }

    return 0;
}