#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <string>
#include <bitset>

auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        arr[i].first = stoi(str, nullptr, 2);
    }
    int resp = k + 1;
    arr[0].second = resp;
    for (int i = 1; i < n; i++) {
        auto tmp = std::bitset<32>(arr[0].first ^ arr[i].first);
        arr[i].second = static_cast<int>(tmp.count());
        resp = std::min(resp, arr[i].second);
    }
    auto compare = [](auto const &lhs, auto const &rhs) { return lhs.second < rhs.second; };
    std::ranges::sort(arr, compare);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j].second < arr[i].second + resp) {
                auto tmp = std::bitset<32>(arr[j].first ^ arr[i].first);
                resp = std::min(resp, static_cast<int>(tmp.count()));
            } else break;
        }
    }
    std::cout << resp << '\n';
}