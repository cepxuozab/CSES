#include <iostream>
#include <numeric>

const int INF = 1'000'000'007;

int qry(bool finnish, int i) {
    std::cout << (finnish ? 'F' : 'S') << ' ' << i << std::endl;
    int res; std::cin >> res;
    return res;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);
    int n, k; std::cin >> n >> k;
    auto better_qry = [n](bool finnish, int i) -> int {
        if (i <= 0)
            return INF;
        if (i > n)
            return -INF;
        return qry(finnish, i);
    };
    // out of all configurations of i finnish and k-i swedish,
    // find the right one using binary search
    int l = std::max(0, k - n), r = std::min(n, k) + 1;
    while (l < r) {
        int mid = std::midpoint(l, r);
        if (better_qry(true, mid) - better_qry(false, k - mid) > 0)
            l = mid + 1;
        else
            r = mid;
    }
    // l is the first position where F[l] - S[k-l] < 0
    int ans = std::max(better_qry(true, l), better_qry(false, k - l + 1));
    std::cout << "! " << ans << std::endl;
    return 0;
}
