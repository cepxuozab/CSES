/**
 * @brief Finding Periods
 * @link https://cses.fi/problemset/task/1733
 * @date 15.01.2024
 */

#include <string>
#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>
#include <cstdint>

[[maybe_unused]] static const auto FastIO = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

template<typename T>
auto operator<<(std::ostream &out, std::vector<T> const &arr) -> std::ostream & {
    for (auto &&elem: arr) {
        out << elem << ' ';
    }
    return out;
}

constexpr int POW = 37;
constexpr int MOD = 1000000007;

auto Pow(int n) -> std::vector<int64_t> {
    std::vector<int64_t> power(n);
    power[0] = 1;
    for (int i = 1; i < n; i++) {
        power[i] = (power[i - 1] * POW + MOD) % MOD;
    }
    return power;
}

auto Hash(std::string_view str) -> std::vector<int64_t> {
    size_t const size = str.length();
    std::vector<int64_t> hash(size + 1);
    for (size_t i = 1; i <= size; i++) {
        hash[i] = (hash[i - 1] * POW + (str[i-1] - 'a') + MOD) % MOD;
    }
    return hash;
}

auto Get_hash(int l, int r, std::vector<int64_t> const &hash, std::vector<int64_t> const &power) -> int64_t {
    long long int h;
    h = hash[r + 1] - (power[r - l + 1] * hash[l] % MOD) % MOD;
    return h < 0 ? h + MOD : h;
}

auto GetLengthPeriods(std::string_view str) -> std::vector<int> {
    int const n = static_cast<int>(str.length());
    std::vector<int> ans;
    auto const power = Pow(n);
    auto const hash = Hash(str);
    for (int i = 0; i < n; ++i) {
        int runIdx = 0;
        bool isGood = true;
        while (runIdx < n) {
            int len = std::min(i + 1, n - runIdx);
            isGood &= (Get_hash(0, len - 1, hash, power) == Get_hash(runIdx, runIdx + len - 1, hash, power));
            runIdx += len;
        }
        if (isGood) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

auto main() -> int {
    std::string str;
    std::cin >> str;
    std::cout << GetLengthPeriods(str);
}

