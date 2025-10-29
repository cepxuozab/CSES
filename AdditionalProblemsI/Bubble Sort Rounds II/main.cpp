#include <iostream>
#include <vector>
#include <queue>

using namespace std;

auto main() -> int {
    int n;
    int k;
    cin >> n >> k;
    std::vector<int> x(n);
    for (auto &i: x)
        cin >> i;
    priority_queue<int, vector<int>, greater<>> pq;
    std::vector<int> result(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && j <= i + k) {
            pq.push(x[j]);
            j++;
        }
        result[i] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
}