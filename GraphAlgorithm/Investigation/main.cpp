#include <algorithm>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <vector>

static auto const fastest = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

constexpr long long INF = std::numeric_limits<long long>::max() / 2, MOD = 1000000007;

class Graph {
private:
    /*
        what is the minimum price of such a route?
        how many minimum-price routes are there? (modulo 109+7)
        what is the minimum number of flights in a minimum-price route?
        what is the maximum number of flights in a minimum-price route?
        */
    struct Answer {
        int64_t min_price = 0;
        int64_t min_price_routes = 0;
        int64_t min_number_flights = 0;
        int64_t max_number_flights = 0;
    };
    size_t size;
    using Pair = std::pair<int, int>;
    std::vector<std::vector<Pair>> adj_list;
    std::vector<int64_t> p, d, mi, ma;
    Answer answer{};

public:
    Graph(size_t n)
        : size(n)
        , adj_list(n)
        , p(n)
        , d(n, INF)
        , mi(n, INF)
        , ma(n) {
    }
    void add(int u, int v, int w) {
        u--, v--;
        adj_list[u].emplace_back(v, w);
    }

    auto get_answer() -> Answer {
        make_answer();
        return answer;
    }

private:
    using L_Pair = std::pair<int64_t, int>;
    void make_answer() {
        std::vector<bool> visited(size, false);
        std::priority_queue<L_Pair, std::vector<L_Pair>, std::greater<>> queue;
        d[0] = 0, p[0] = 1, mi[0] = 0;
        queue.emplace(0, 0);
        while (!queue.empty()) {
            auto u = queue.top().second;
            queue.pop();
            if (visited[u]) {
                continue;
            }
            visited[u] = true;
            for (auto const& [v, w] : adj_list[u]) {
                if (d[v] == d[u] + w) {
                    p[v] += p[u];
                    if (p[v] > MOD) {
                        p[v] -= MOD;
                    }
                    mi[v] = std::min(mi[v], mi[u] + 1);
                    ma[v] = std::max(ma[v], ma[u] + 1);
                } else if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    queue.emplace(d[v], v);
                    p[v] = p[u];
                    mi[v] = mi[u] + 1;
                    ma[v] = ma[u] + 1;
                }
            }
        }
        answer = Answer{d.back(), p.back(), mi.back(), ma.back()};
    }
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
    auto answer = graph->get_answer();
    std::cout << answer.min_price << ' ' << answer.min_price_routes << ' '
              << answer.min_number_flights << ' ' << answer.max_number_flights << '\n';
}
