#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;

    std::vector<long long> a(n);
    long long total_sum = 0;
    for (long long i = 0; i < n; ++i) {
        std::cin >> a[i];
        total_sum += a[i];
    }

    // Если сумма нечётная — невозможно
    if (total_sum % 2 != 0) {
        std::cout << "-1\n";
        return 0;
    }

    // Сортируем по убыванию
    std::sort(a.begin(), a.end(), std::greater<long long>());

    long long current_sum = 0;      // w
    long long pos = 0;              // p
    long long chosen_count = 0;     // l
    std::vector<long long> chosen;  // b

    const long long half = total_sum / 2;

    while (current_sum < half) {
        if (pos == n) {
            // Откат: убираем последний элемент из chosen
            current_sum -= a[chosen[chosen_count - 1]];
            while (chosen_count > 0 && chosen[chosen_count - 1] == pos - 1) {
                chosen.pop_back();
                chosen_count--;
                pos--;
                if (chosen_count == 0) break;
                current_sum -= a[chosen[chosen_count - 1]];
            }
            if (chosen_count == 0) {
                std::cout << "-1\n";
                return 0;
            }
            // Увеличиваем последний индекс
            chosen[chosen_count - 1]++;
            current_sum += a[chosen[chosen_count - 1]];
            pos = chosen[chosen_count - 1] + 1;
        } else {
            if (current_sum + a[pos] <= half) {
                current_sum += a[pos];
                chosen.push_back(pos);
                chosen_count++;
            }
            pos++;
        }
    }

    // Построение массива c — элементы, НЕ входящие в chosen
    std::vector<long long> complement; // c
    long long j = 0; // указатель в chosen
    for (long long i = 0; i < n; ++i) {
        if (j < chosen_count && a[i] == a[chosen[j]]) {
            j++;
        } else {
            complement.push_back(a[i]);
        }
    }

    // Симуляция вывода
    long long left_value = a[chosen[0]]; // w
    long long comp_index = 0;            // s
    long long chosen_index = 1;          // p
    long long has_left = 1;              // l (1 = камень слева, 0 = справа)

    for (long long i = 0; i < n - 1; ++i) {
        if (has_left) {
            std::cout << left_value << " " << complement[comp_index] << '\n';
            left_value -= complement[comp_index];
            comp_index++;
            if (left_value < 0) {
                left_value = -left_value;
                has_left = 0;
            }
        } else {
            std::cout << left_value << " " << a[chosen[chosen_index]] << '\n';
            left_value -= a[chosen[chosen_index]];
            chosen_index++;
            if (left_value < 0) {
                left_value = -left_value;
                has_left = 1;
            }
        }
    }

    return 0;
}