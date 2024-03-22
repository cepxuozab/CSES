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

class Graph {
private:
    size_t size;
    std::vector<std::vector<int>> adj_list;
    std::vector<int> ans;

public:
   explicit Graph(size_t n)
        : size(n)
        , adj_list(n) {
    }
    void add(int a, int b) {
        a--;
        b--;
        adj_list[a].push_back(b);
    }
    auto get_answer() -> std::optional<std::vector<int>> {
        topo_sort();
        if (ans.size() < size) {
            return std::nullopt;
        }
        return ans;
    }

private:
    void topo_sort() {
        std::vector<int> indeg(size);
        for (auto const& list : adj_list) {
            for (int i : list) {
                indeg[i]++;
            }
        }
        std::priority_queue<int, std::vector<int>, std::greater<>> queue;
        for (size_t i = 0; i < size; ++i) {
            if (indeg[i] == 0) {
                queue.emplace(i);
            }
        }
        while (!queue.empty()) {
            int i = queue.top();
            queue.pop();
            ans.push_back(i);
            for (int x : adj_list[i]) {
                if (--indeg[x] == 0) {
                    queue.emplace(x);
                }
            }
        }
    }
};

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
    auto result = grahp->get_answer();
    if (!result.has_value()) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }
    auto ans = result.value();
    for (int i : ans) {
        std::cout << i + 1 << ' ';
    }
    std::cout << '\n';
}
