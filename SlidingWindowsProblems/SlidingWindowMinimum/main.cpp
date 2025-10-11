#include <cstdint>
#include <iostream>
#include <deque>


struct Window {
    std::deque<std::pair<int64_t, int>> dq;      // {value, index}
    int idx = 0;        // глобальный индекс следующего элемента
    int window_size{};    // фиксированный размер окна
    Window(int k) : window_size(k) {}

    void push(int64_t x) {
        // Поддерживаем монотонно возрастающую деку (минимум слева)
        while (!dq.empty() && dq.back().first >= x)
            dq.pop_back();
        dq.emplace_back(x, idx++);
    }

    auto get_min() -> int64_t {
        // Удаляем элементы, вышедшие за пределы текущего окна
        while (!dq.empty() && dq.front().second < idx - window_size)
            dq.pop_front();
        return dq.empty() ? -1 : dq.front().first;
    }
};

auto sliding_windows_minimum(int k, int n, int64_t x, int64_t a, int64_t b, int64_t c) -> int64_t {
    Window window(k);

    // Заполняем первое окно
    for (int i = 0; i < k; ++i) {
        window.push(x);
        x = (a * x + b) % c;
    }
    auto xum = window.get_min();
    for (int i = k; i < n; ++i) {
        window.push(x);
        xum ^= window.get_min();
        x = (a * x + b) % c;
    }
    return xum;
}

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    int64_t x, a, b, c;
    std::cin >> x >> a >> b >> c;

    std::cout << sliding_windows_minimum(k, n, x, a, b, c) << '\n';
}