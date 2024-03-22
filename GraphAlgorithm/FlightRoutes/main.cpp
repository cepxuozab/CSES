#include <cstdint>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
[[maybe_unused]] static auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct City {
    int64_t cost;
    int idx;
    City() = default;
    City(int64_t c, int i)
        : cost(c)
        , idx(i) {
    }
    auto operator<(City const& other) const -> bool {
        return std::tie(cost, idx) > std::tie(other.cost, other.idx);
    }
};

auto main() -> int {
    int cities_num;
    int flights_num;
    int parameter;
    std::cin >> cities_num >> flights_num >> parameter;
    std::vector<std::vector<City>> graph(cities_num);
    for (int i = 0; i < flights_num; ++i) {
        int src;
        int dst;
        int64_t cost;
        std::cin >> src >> dst >> cost;
        src--, dst--;
        graph[src].emplace_back(cost, dst);
    }
    int cnt = 0;
    std::vector<int> base(cities_num, 0);
    std::priority_queue<City> queue;
    queue.emplace(0, 0);
    std::vector<int64_t> result;
    result.reserve(parameter);
    while (true) {
        auto [w, u] = queue.top();
        queue.pop();
        if (base[u] > parameter) {
            continue;
        }
        if (u == cities_num - 1) {
            cnt++;
            result.push_back(w);
            if (cnt == parameter) {
                break;
            }
        }
        base[u]++;
        for (auto const& [x, v] : graph[u]) {
            if (base[v] > parameter) {
                continue;
            }
            queue.emplace(w + x, v);
        }
    }
    for (auto const& i : result) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}