#include <iostream>
#include <vector>
#include <array>
#include <cstdint>


auto main() -> int {
    int n;
    std::cin >> n;
    std::array<std::vector<int>, 2> arr;
    arr.fill(std::vector<int>(n));

    for (int r = 0; r < 2; r++) {
        for (int i = 0; i < n; i++) {
            std::cin >> arr[r][i];
            arr[r][i]--;
        }
    }

    int64_t ans = 0;
    int top = 0, bot = 0;
    for (int i = 0; i < n; i++) {
        top += arr[0][i];
        bot += arr[1][i];

        if ((top < 0 && bot > 0) || (top > 0 && bot < 0)) {
            if (abs(top) < abs(bot)) {
                ans += abs(top);
                bot += top;
                top = 0;
            } else {
                ans += abs(bot);
                top += bot;
                bot = 0;
            }
        }

        ans += abs(top + bot);
    }
    std::cout << ans;
}