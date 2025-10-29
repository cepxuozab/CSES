#include <iostream>
#include <set>
#include <vector>
#include <cstdlib>

void backtrack(int n, std::vector<int>& res, std::set<int>& available) {
    if (static_cast<int>(res.size()) == n) {
        for (size_t i = 0; i < res.size(); ++i) {
            std::cout << res[i];
            if (i + 1 == res.size()) std::cout << '\n';
            else std::cout << ' ';
        }
        std::exit(0);
    }

    for (int x : available) {
        if (res.empty() || std::abs(res.back() - x) > 1) {
            res.push_back(x);
            available.erase(x);
            backtrack(n, res, available);
            available.insert(x);
            res.pop_back();
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n == 2 || n == 3) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    std::vector<int> res;
    std::set<int> available;
    for (int i = 1; i <= n; ++i) {
        available.insert(i);
    }

    backtrack(n, res, available);

    // На случай, если решение не найдено (хотя для n=1,4+ оно есть)
    std::cout << "NO SOLUTION\n";
    return 0;
}