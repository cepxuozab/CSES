#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

int main() {
    long long n, k;
    std::cin >> n >> k;

    std::vector<long long> a;
    std::vector<long long> c(n + 1, 0);
    std::vector<long long> d(n + 1, 0);

    long long sum_negative = 0;
    for (long long i = 0; i < n; ++i) {
        long long value;
        std::cin >> value;
        a.push_back(std::abs(value));
        if (value < 0) {
            sum_negative += value;
        }
    }
    a.push_back(0);
    std::sort(a.begin(), a.end());

    using Pair = std::array<long long, 2>;
    std::vector<Pair> b;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    pq.push({sum_negative, 0});

    for (long long iter = 0; iter < k; ++iter) {
        Pair current = pq.top();
        pq.pop();
        std::cout << current[0] << " ";

        long long s = current[1];
        b.push_back(current);

        long long m = c[s];
        if (m == 0 && s < n) {
            pq.push({a[s + 1] + b[0][0], s + 1});
        }

        ++d[s];
        if (std::log2(static_cast<double>(d[s])) < static_cast<double>(s - 1)) {
            ++m;
            while (m < static_cast<long long>(b.size()) && b[m][1] >= s) {
                ++m;
            }
            if (m < static_cast<long long>(b.size())) {
                pq.push({a[s] + b[m][0], s});
            }
        }
        c[s] = m;
    }
    std::cout << '\n';

    return 0;
}