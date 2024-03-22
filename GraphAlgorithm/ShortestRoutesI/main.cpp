#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

[[maybe_unused]] static auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr int64_t INFINITY{std::numeric_limits<int64_t>::max()};

class Graph {
public:
    Graph(int n);

    void add(int a, int b, int c);

    [[nodiscard]] auto get_ans() const -> std::vector<int64_t>;

    void find_path();

private:
    std::vector<std::vector<std::pair<int, int>>> graph;
    std::vector<int64_t> ans;
};

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    auto graph = std::make_unique<Graph>(n);
    while (m-- != 0) {
        int a;
        int b;
        int c;
        std::cin >> a >> b >> c;
        graph->add(a, b, c);
    }
    graph->find_path();
    auto const res = graph->get_ans();
    for (int i = 1; i <= n; ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
    return 0;
}

Graph::Graph(int n)
        : graph(n + 1), ans(n + 1, INFINITY) {}

void Graph::add(int a, int b, int c) {
    graph[a].emplace_back(b, c);
}

auto Graph::get_ans() const -> std::vector<int64_t> {
    return ans;
}

void Graph::find_path() {
    using value = std::pair<int64_t, int>;
    std::priority_queue<value, std::vector<value>, std::greater<>> q;
    for (q.emplace(0, 1); !q.empty(); q.pop()) {
        auto const [cur, i] = q.top();
        if (ans[i] < INFINITY) {
            continue;
        }
        ans[i] = cur;
        for (auto &p: graph[i]) {
            q.emplace(cur + p.second, p.first);
        }
    }
}

