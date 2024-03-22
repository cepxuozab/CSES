/**
* @brief Room Allocation
 * @link https://cses.fi/problemset/task/1164/
 * @date 21.01.2024
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

struct Client {
    int arrive{};
    int departure{};
    int id{};

    auto operator<=>(Client const &other) const = default;
};

auto main() -> int {
    int n;
    std::cin >> n;
    std::vector<Client> clients(n);
    int size = 0;
    for (auto &[arr, dep, id]: clients) {
        std::cin >> arr >> dep;
        id = size++;
    }
    std::ranges::sort(clients);
    std::priority_queue<Client, std::vector<Client>, std::greater<>> queue;
    std::vector<int> answer(n);
    int count = 0;
    for (auto const &client: clients) {
        int c = 0;
        if (queue.empty() || queue.top().arrive >= client.arrive) {
            c = ++count;
        } else {
            c = queue.top().departure;
            queue.pop();
        }
        queue.push({client.departure, c});
        answer[client.id] = c;
    }
    std::cout << count << '\n';
    for (int i: answer) {
        std::cout << i << ' ';
    }
    std::cout << '\n';


    return 0;
}

