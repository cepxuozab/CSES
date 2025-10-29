#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k, m;
    std::cin >> n >> k >> m;

    std::vector<int> t(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> t[i];
    }

    std::sort(t.begin() + 1, t.end());

    long long initial_sum = 0;
    for (int i = 1; i <= k; ++i) {
        initial_sum += t[i];
    }

    // State: {neg_sum, a, b, c, d}
    struct State {
        long long neg_sum;
        int a, b, c, d;

        bool operator<(const State &other) const {
            return neg_sum < other.neg_sum;
        }
    };

    std::priority_queue<State> pq;
    pq.push({-initial_sum, 0, -1, 1, k});

    for (int i = 0; i < m; ++i) {
        State current = pq.top();
        pq.pop();

        long long current_sum = -current.neg_sum;
        std::cout << current_sum << " ";

        int a = current.a;
        int b = current.b;
        int c_val = current.c;
        int d = current.d;

        if (d + 1 <= n) {
            long long new_sum = current_sum - t[d] + t[d + 1];
            pq.push({-new_sum, c_val, d - 1, d + 1, d + 1});
        }

        if (a <= b && b + 2 == c_val) {
            long long new_sum = current_sum - t[b] + t[b + 1];
            pq.push({-new_sum, a, b - 1, c_val - 1, d});
        }
    }

    std::cout << '\n';
    return 0;
}