/**
* @brief Restaurant Customers
 * @link https://cses.fi/problemset/task/1619
 * @date 15.01.2023
*/

#include <iostream>
#include <algorithm>
#include <vector>

enum class Event : char8_t {
    IN, OUT
};

struct Customer {
    int time{};
    Event event;

    auto operator<=>(Customer const &) const = default;
};

auto ReadCustomers(unsigned n) -> std::vector<Customer>;

auto main() -> int {
    unsigned n;
    std::cin >> n;
    auto const customers = ReadCustomers(n);
    int answer = 0;
    int max = 0;
    for (auto const &[_, event]: customers) {
        max += (event == Event::IN ? 1 : -1);
        answer = answer > max ? answer : max;
    }
    std::cout << answer;
    return 0;
}

auto ReadCustomers(unsigned n) -> std::vector<Customer> {
    std::vector<Customer> customers;
    customers.reserve(n);
    for (unsigned i = 0; i < n; ++i) {
        int a;
        int b;
        std::cin >> a >> b;
        customers.push_back({a, Event::IN});
        customers.push_back({b, Event::OUT});
    }
    std::ranges::sort(customers);
    return customers;
}