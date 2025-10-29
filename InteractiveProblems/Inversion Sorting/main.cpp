#include <iostream>

int qry(int i, int j) {
    std::cout << i << ' ' << j << std::endl;
    int res;
    std::cin >> res;
    if (res == 0)
        exit(0);
    return res;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int n;
    std::cin >> n;
    // just do insertion sort
    if (n == 1) {
        qry(1, 1);
        return 0;
    }
    for (int i = 1; i < n; i++) {
        int after_flip = qry(1, i + 1); // i(i+1)/2 - dist
        int before_flip = qry(1, i + 1); // dist
        int dist = (before_flip - after_flip + i * (i + 1) / 2) / 2;
        if (dist > 0) {
            qry(i - dist + 1, i + 1);
            qry(i - dist + 2, i + 1);
        }
    }
    return 0;
}
