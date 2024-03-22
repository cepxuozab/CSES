#include <iostream>
#include <vector>
#include <cstdint>

auto MinimumNumberMoves(std::vector<int> const &arr) -> int64_t {
    int64_t answer = 0;
    int64_t max = arr.front();
    for (int elem: arr) {
        max = max > elem ? max : elem;
        answer += (max - elem);
    }
    return answer;
}

auto Read(int n) {
    std::vector<int> arr(n);
    for (int &elem: arr) {
        std::cin >> elem;
    }
    return arr;
}

auto main() -> int {
    int n;
    std::cin >> n;
    std::cout << MinimumNumberMoves(Read(n)) << '\n';
    return 0;
}