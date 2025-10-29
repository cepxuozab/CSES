#include <iostream>
#include <string>
#include <numeric>

bool qry_red(int i) {
    std::cout << "? " << i << std::endl;
    std::string res;
    std::cin >> res;
    return res == "R";
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    // just binary search lol
    int n;
    std::cin >> n;
    bool first_red = qry_red(1);
    int l = 1, r = n;
    while (l < r) {
        int mid = std::midpoint(l, r + 1);
        if (first_red ^ qry_red(mid) ^ (mid % 2 == 1))
            l = mid;
        else
            r = mid - 1;
    }
    std::cout << "! " << l << std::endl;
    return 0;
}
