#include <iostream>

auto JosephusProblem(int n, int k) -> int {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
        return (2 * k > n) ? 2 * k % n : 2 * k;
    }
    int c = JosephusProblem(n >> 1, k - (n + 1) / 2);
    return (n & 1) ? 2 * c + 1 : 2 * c - 1;
}

auto main() -> int {
    int number_of_queries;
    std::cin >> number_of_queries;
    for (int i = 0; i < number_of_queries; ++i) {
        int number_of_children;
        int position_of_the_child;
        std::cin >> number_of_children >> position_of_the_child;
        std::cout << JosephusProblem(number_of_children, position_of_the_child) << '\n';
    }
}