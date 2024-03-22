#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>
static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Planet {
    size_t size;
    std::vector<int> planets;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> visited;
    std::vector<int> pre;
    std::vector<int> cycles;
    std::vector<int> answer;

public:
    Planet() = default;
    explicit Planet(size_t n)
        : size(n)
        , planets(n + 1)
        , adj_list(n + 1)
        , visited(n + 1, 0)
        , pre(n + 1)
        , answer(n + 1) {
    }
    void add(size_t idx, int value) {
        planets[idx] = value;
        adj_list[value].emplace_back(idx);
    }
    auto get_answer() -> std::vector<int> {
        for (int i = 1; std::cmp_less_equal(i,size); ++i) {
            if (visited[i] == 0) {
                build(i);
            }
        }
        return {answer.begin() + 1, answer.end()};
    }

private:
    void dfs(int u, int depth) {
        answer[u] = depth;
        visited[u] = 2;

        for (int v : adj_list[u]) {
            if (visited[v] != 2) {
                dfs(v, depth + 1);
            }
        }
    }
    void build(int node) {
        while (visited[node] == 0) {
            pre[planets[node]] = node;
            visited[node] = 1;
            node = planets[node];
        }

        cycles.clear();
        int cur = node;
        do {
            cycles.push_back(cur);
            cur = pre[cur];
        } while (cur != node);

        std::ranges::reverse(cycles);

        for (int u : cycles) {
            answer[u] = static_cast<int>(cycles.size());
            visited[u] = 2;
        }

        for (int u : cycles) {
            dfs(u, answer[u]);
        }
    }
};

auto main() -> int {
    int n;
    std::cin >> n;
    auto road = std::make_unique<Planet>(n);
    for (int i = 1; i <= n; ++i) {
        int planet;
        std::cin >> planet;
        road->add(i, planet);
    }
    auto result = road->get_answer();
    for (int i : result) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}
