#include <iostream>
#include <vector>

void solution(int n, int a, int b) {
    if ((a + b) > n || ((a == 0 || b == 0) && !(a == 0 && b == 0))) {
        std::cout << "NO" << '\n';
        return;
    }

    int rem = n - a - b;
    std::vector<int> v1, v2;


    while (rem) {
        v1.push_back(rem);
        v2.push_back(rem);
        rem--;
    }

    int c1 = n - a - b + 1;
    int c2 = n - b + 1;

    for (int i = 0; i < b; i++) {
        v1.push_back(c1);
        c1++;
        v2.push_back(c2);
        c2++;
    }

    int c3 = n - a + 1;
    int c4 = n - a - b + 1;
    for (int i = 0; i < a; i++) {
        v1.push_back(c3);
        c3++;
        v2.push_back(c4);
        c4++;
    }

    std::cout << "YES" << '\n';
    for (auto &elem: v1) std::cout << elem << " ";
    std::cout << '\n';
    for (auto &elem: v2) std::cout << elem << " ";
    std::cout << '\n';
}

auto main() -> int {
    int T;
    std::cin >> T;

    while (T--) {
        int n, a, b;
        std::cin >> n >> a >> b;
        solution(n, a, b);
    }
}