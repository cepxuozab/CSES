#include <cstdint>
#include <iostream>
#include <vector>

class Tree {
    std::vector<std::vector<int>> adj_list;
    int time = 0;
    std::vector<int> t_in;
    std::vector<int> t_out;
    std::vector<int64_t> t_val;
    std::vector<int> values;

public:
    Tree(int n) : adj_list(n + 1), t_in(n + 1, -1), t_out(n + 1, -1) {}
    void SetVal(std::vector<int> const &val) {
        values.emplace_back();
        values.insert(values.end(), val.begin(), val.end());
    }
    void AddEdges(std::vector<std::pair<int, int>> const &edges);
    std::vector<int> GetT_In() const { return t_in; }
    std::vector<int> GetT_Out() const { return t_out; }
    std::vector<int64_t> GetT_Val() const { return t_val; }

private:
    void Dfs(int u, int p);
};

class SegTree {
    std::vector<int64_t> tree;
    int size{};

public:
    void Build(std::vector<int64_t> const &a);
    void Update(int i, int v);
    int64_t Sum(int l, int r);

private:
    void Init(int n);
    void Build(std::vector<int64_t> const &a, int x, int lx, int rx);
    void Update(int i, int v, int x, int lx, int rx);
    int64_t Sum(int l, int r, int x, int lx, int rx);
};

int main() {
    int n, query;
    std::cin >> n >> query;
    Tree tree(n);
    std::vector<int> val(n);
    for (auto &i: val) {
        std::cin >> i;
    }
    tree.SetVal(val);
    std::vector<std::pair<int, int>> edges(n - 1);
    for (auto &[from, to]: edges) {
        std::cin >> from >> to;
    }
    tree.AddEdges(edges);
    auto const t_val = tree.GetT_Val();
    auto const t_in = tree.GetT_In();
    auto const t_out = tree.GetT_Out();
    SegTree st;
    st.Build(t_val);
    for (int q = 0; q < query; ++q) {
        int cmd, s;
        std::cin >> cmd >> s;
        if (cmd == 1) {
            int x;
            std::cin >> x;
            st.Update(t_in[s], x);
            st.Update(t_out[s], -x);
        } else {
            std::cout << st.Sum(0, t_in[s] + 1) << '\n';
        }
    }
}


void Tree::AddEdges(std::vector<std::pair<int, int>> const &edges) {
    for (auto const &[from, to]: edges) {
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    Dfs(1, 1);
}

void Tree::Dfs(int u, int p) {
    t_in[u] = time++;
    t_val.push_back(values[u]);
    for (int v: adj_list[u]) {
        if (v != p) {
            Dfs(v, u);
        }
    }
    t_out[u] = time++;
    t_val.push_back(-values[u]);
}

void SegTree::Init(int n) {
    size = 1;
    while (size < n) {
        size *= 2;
    }
    tree.resize(2 * size - 1);
}

void SegTree::Build(std::vector<int64_t> const &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
        if (lx < (int) a.size()) {
            tree[x] = a[lx];
        }
    } else {
        int m = (lx + rx) / 2;
        Build(a, 2 * x + 1, lx, m);
        Build(a, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
}

void SegTree::Build(std::vector<int64_t> const &a) {
    Init(a.size());
    Build(a, 0, 0, size);
}

void SegTree::Update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
        tree[x] = v;
        return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
        Update(i, v, 2 * x + 1, lx, m);
    } else {
        Update(i, v, 2 * x + 2, m, rx);
    }
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}

void SegTree::Update(int i, int v) { Update(i, v, 0, 0, size); }

int64_t SegTree::Sum(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) {
        return 0;
    } else if (lx >= l && rx <= r) {
        return tree[x];
    } else {
        int m = (lx + rx) / 2;
        int64_t sl = Sum(l, r, 2 * x + 1, lx, m);
        int64_t sr = Sum(l, r, 2 * x + 2, m, rx);
        return sl + sr;
    }
}

int64_t SegTree::Sum(int l, int r) { return Sum(l, r, 0, 0, size); }
