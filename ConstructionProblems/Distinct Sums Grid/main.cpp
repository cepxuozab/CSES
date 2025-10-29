#include <iostream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;

    if (n < 4) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }

    if (n == 4) {
        std::cout << "1 1 3 2\n"
                     "2 1 2 4\n"
                     "3 3 3 4\n"
                     "2 1 4 4\n";
        return 0;
    }

    // Выводим первые (n - 2) строки
    for (long long i = 0; i < n - 2; ++i) {
        for (long long j = 0; j < n - 2; ++j) {
            std::cout << 2 + (i + j) % (n - 2) << ' ';
        }
        std::cout << "1 " << i + 2 << '\n';
    }

    // Предпоследняя строка
    for (long long i = 1; i < n; ++i) {
        std::cout << n - i << ' ';
    }
    std::cout << "1\n";

    // Последняя строка
    for (long long i = 0; i < n; ++i) {
        std::cout << n << ' ';
    }

    return 0;
}
