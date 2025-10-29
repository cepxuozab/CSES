#include <iostream>
#include <vector>
#include <unordered_map>


auto main() -> int {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    const int MOD = 1000000007;
    int n;
    std::cin >> n;

    std::unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        int elem;
        std::cin >> elem;
        mpp[elem]++;
    }

    long long res = 1;
    for (auto &e: mpp) {
        res = (res * (e.second + 1)) % MOD;
    }

    res = (res - 1 + MOD) % MOD;
    std::cout << res;


}