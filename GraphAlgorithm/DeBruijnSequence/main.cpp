#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>

[[maybe_unused]] static const auto FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto main() -> int {
    int n;
    std::cin >> n;
    std::unordered_set<std::string> visited;
    std::string answer;
    std::function<void(std::string)> dfs = [&](std::string const &s) {
        for (char i: {'0', '1'}) {
            std::string tmp = s + i;
            if (visited.insert(tmp).second) {
                dfs(tmp.substr(1));
                answer += i;
            }
        }
    };
    std::string str(n - 1, '0');
    dfs(str);
    answer += str;
    std::cout << answer << '\n';
    return 0;
}