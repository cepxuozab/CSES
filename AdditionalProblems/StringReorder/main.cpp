#include <algorithm>
#include <array>
#include <iostream>
#include <string>

auto main() -> int {
    std::string str;
    std::cin >> str;
    constexpr int ALPHABET = 26;
    std::array<int, ALPHABET> freq{};
    int n = static_cast<int>(str.length());
    for (char ch : str) {
        int idx = static_cast<int>(static_cast<unsigned char>(ch) - 'A');
        if (++freq[idx] > (n + 1) / 2) {
            std::cout << "-1";
            exit(0);
        }
    }
    std::string ans;
    int las = -1;
    for (int i = 0; i < n; i++) {
        int v = 0;
        int target = (n - i + 2) / 2;
        if (auto it = std::ranges::find(freq, target); it != freq.end()) {
            v = std::ranges::distance(freq.begin(), it);
        } else {
            while (freq[v] == 0 || v == las) {
                v++;
            }
        }
        freq[v]--;
        las = v;
        ans.push_back(static_cast<char>(v + 'A'));
    }
    std::cout << ans;
}