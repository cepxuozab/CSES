#include <iostream>
#include <memory>
#include <optional>
#include <queue>
#include <vector>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr int mod = 1000000007;

class Graph {
private:
    size_t size;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> indegree;
    std::vector<int> ans;

public:
    Graph(size_t n)
        : size(n)
        , adj_list(n)
        , indegree(n) {
    }
    void add(int a, int b) {
        a--;
        b--;
        adj_list[a].push_back(b);
        indegree[b]++;
    }
    auto get_answer() -> std::optional<std::vector<int>> {
        topo_sort();
        if (ans.size() < size) {
            return std::nullopt;
        }
        return ans;
    }
    [[nodiscard]] auto get_list() const -> std::vector<std::vector<int>> {
        return adj_list;
    }

private:
    void topo_sort() {
        std::priority_queue<int, std::vector<int>, std::greater<>> queue;
        for (size_t i = 0; i < size; ++i) {
            if (indegree[i] == 0) {
                queue.emplace(i);
            }
        }
        while (!queue.empty()) {
            int i = queue.top();
            queue.pop();
            ans.push_back(i);
            for (int x : adj_list[i]) {
                if (--indegree[x] == 0) {
                    queue.push(x);
                }
            }
        }
    }
};
void add_mod(int& x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    auto grahp = std::make_unique<Graph>(n);
    while (m-- != 0) {
        int a;
        int b;
        std::cin >> a >> b;
        grahp->add(a, b);
    }
    auto result = grahp->get_answer().value();
    std::vector<int> dp(n);
    auto adj_list = grahp->get_list();
    dp[0] = 1;
    for (auto i : result) {
        for (auto j : adj_list[i]) {
            add_mod(dp[j], dp[i]);
        }
    }
    std::cout << dp.back() << '\n';
}
