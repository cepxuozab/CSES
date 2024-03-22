#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

[[maybe_unused]] static auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Graph {
private:
    size_t const size;
    std::vector<std::vector<int>> graph;
    std::vector<int> degree;
    std::vector<int> answer;

public:
    Graph(size_t n);
    void add(int a, int b);
    auto check() -> bool;
    void get_result() const;
};

auto main() -> int {
    int n;
    int m;
    std::cin >> n >> m;
    Graph graph(n);
    while (m-- != 0) {
        int a;
        int b;
        std::cin >> a >> b;
        graph.add(a, b);
    }
    if (!graph.check()) {
        std::cout << "IMPOSSIBLE\n";
        return 0;
    }
    graph.get_result();
}

Graph::Graph(size_t n)
        : size(n), graph(n), degree(n) {
}

void Graph::add(int a, int b) {
    a--, b--;
    graph[a].push_back(b);
    degree[a]++;
    degree[b]--;
}

auto Graph::check() -> bool {
    if (degree.front() != 1 || degree.back() != -1) {
        return false;
    }
    for (size_t i = 1; i + 1 < size; ++i) {
        if (degree[i] != 0) {
            return false;
        }
    }
    std::stack<int> st;
    st.push(0);
    while (!st.empty()) {
        int v = st.top();
        if (graph[v].empty()) {
            answer.push_back(v + 1);
            st.pop();
        } else {
            int u = graph[v].back();
            graph[v].pop_back();
            st.push(u);
        }
    }
    for (size_t i = 0; i < size; ++i) {
        if (!graph[i].empty()) {
            return false;
        }
    }
    return true;
}

void Graph::get_result() const {
    copy(answer.rbegin(), answer.rend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}


