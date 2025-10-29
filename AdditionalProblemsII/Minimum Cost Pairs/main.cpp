#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>

struct DisjointSet {
    std::vector<int> parent;
    std::vector<int> max_right;

    explicit DisjointSet(int n) : parent(n), max_right(n) {
        std::iota(parent.begin(), parent.end(), 0);
        std::iota(max_right.begin(), max_right.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        max_right[a] = std::max(max_right[a], max_right[b]);
        parent[b] = a;
        return true;
    }
};

struct Item {
    int left;
    int right;
    long long cost;

    bool operator<(const Item &other) const {
        return cost > other.cost; // min-heap via max-heap
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    std::vector<long long> diff(n, 0);
    for (int i = 1; i < n; ++i) {
        diff[i] = a[i] - a[i - 1];
    }

    // Префиксная сумма с шагом 2: psa[i] = sum of diff[j] for j ≡ i (mod 2), j < i
    std::vector<long long> prefix(n + 2, 0);
    for (int i = 1; i < n; ++i) {
        prefix[i + 2] = diff[i];
        if (i >= 2) {
            prefix[i + 2] += prefix[i];
        }
    }

    auto get_sum = [&](int l, int r) -> long long {
        if (l > r) return 0;
        return prefix[r + 2] - prefix[l];
    };

    std::priority_queue<Item> pq;
    for (int i = 1; i < n; ++i) {
        pq.push({i, i, get_sum(i, i)});
    }

    DisjointSet dsu(n + 1);
    long long answer = 0;

    for (int k = 1; k <= n / 2; ++k) {
        while (true) {
            Item current = pq.top();
            pq.pop();

            int l = current.left;
            int r = current.right;
            long long cost = current.cost;

            if (dsu.find(l) != l) continue;
            if (dsu.max_right[l] != r) continue;

            answer += cost;

            int left_component = dsu.find(l - 1);
            while (dsu.max_right[left_component] < r + 1) {
                int next = dsu.max_right[left_component] + 2;
                if (next >= static_cast<int>(dsu.parent.size())) break;
                dsu.unite(left_component, next);
            }

            int new_right = dsu.max_right[left_component];
            if (left_component >= 1 && new_right <= n - 1) {
                long long inner_sum = get_sum(left_component + 1, new_right - 1);
                long long total_sum = get_sum(left_component, new_right);
                pq.push({left_component, new_right, total_sum - inner_sum});
            }

            break;
        }

        std::cout << answer;
        if (k == n / 2) {
            std::cout << '\n';
        } else {
            std::cout << ' ';
        }
    }

    return 0;
}