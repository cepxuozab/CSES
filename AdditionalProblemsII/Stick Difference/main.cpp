#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <limits>

inline long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

struct NodeU {
    long long a, d;
    long long cur() const { return ceil_div(a, d); }
    NodeU(long long _a, long long _d) : a(_a), d(_d) {}
    bool operator<(const NodeU& other) const {
        return cur() < other.cur();
    }
};

struct NodeL {
    long long a, d;
    long long next_floor() const { return a / (d + 1); }
    long long cur() const { return a / d; }
    NodeL(long long _a, long long _d) : a(_a), d(_d) {}
    bool operator<(const NodeL& other) const {
        return next_floor() < other.next_floor();
    }
};

long long length(const std::pair<long long, long long>& p) {
    return p.second - p.first;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i];
    }

    std::priority_queue<NodeU> pqU;
    std::priority_queue<NodeL> pqL;

    for (int i = 0; i < n; i++) {
        pqU.push(NodeU(A[i], 1));
        pqL.push(NodeL(A[i], 1));
    }

    std::vector<long long> U(m + 1);
    std::vector<long long> L(m + 1);
    std::vector<long long> ans(m + 1);
    std::vector<std::pair<long long, long long>> ban_mi_mx;

    long long cur_min = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; i++) {
        cur_min = std::min(cur_min, A[i]);
    }

    for (int k = 1; k <= m; k++) {
        auto t = pqU.top();
        pqU.pop();
        t.d++;
        pqU.push(t);
        cur_min = std::min(cur_min, t.a / t.d);
        U[k] = pqU.top().cur();
        ban_mi_mx.emplace_back(cur_min, U[k]);
    }

    cur_min = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; i++) {
        cur_min = std::min(cur_min, A[i]);
    }

    for (int k = 1; k <= m; k++) {
        auto t = pqL.top();
        pqL.pop();
        t.d++;
        cur_min = std::min(cur_min, t.cur());
        L[k] = cur_min;
        pqL.push(t);
    }

    int l = 0, r = -1;
    std::multiset<long long> lens;

    for (int k = 1; k <= m; k++) {
        while (r + 1 < m && ban_mi_mx[r + 1].second >= U[k]) {
            lens.insert(length(ban_mi_mx[r + 1]));
            r++;
        }
        while (l < r && ban_mi_mx[l].first > L[k]) {
            lens.erase(lens.find(length(ban_mi_mx[l])));
            l++;
        }

        if (lens.empty()) {
            ans[k] = U[k] - L[k];
        } else if (l - 1 >= 0) {
            ans[k] = std::min(*lens.begin(), ban_mi_mx[l - 1].second - L[k]);
        } else {
            ans[k] = *lens.begin();
        }
    }

    for (int k = 1; k <= m; ++k) {
        std::cout << ans[k] << " ";
    }
    std::cout << "\n";

    return 0;
}
