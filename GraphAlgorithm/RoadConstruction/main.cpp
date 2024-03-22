#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <vector>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Road {
    int size;
    std::vector<int> link;
    std::vector<int> sz;
    int counter = 0;
    explicit Road(int n)
        : size(n)
        , link(n + 1)
        , sz(n + 1, 1) {
        std::iota(link.begin(), link.end(), 0);
    }
    auto find(int x) -> int {
        if (x == link[x]) {
            return x;
        }
        return link[x] = find(link[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            link[a] = link[b];
            sz[b] += sz[a];
            counter = std::max(counter, sz[b]);
            size--;
        }
    }

    [[nodiscard]] auto get_answer() const {
        struct Ans {
            int number_of_component;
            int size_largest_component;
        };
        return Ans{size, counter};
    }
};

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    auto road = std::make_unique<Road>(n);
    while (m-- != 0) {
        int a;
        int b;
        std::cin >> a >> b;
        road->unite(a, b);
        std::cout << road->get_answer().number_of_component << ' '
                  << road->get_answer().size_largest_component << '\n';
    }
}
