#include <iostream>
#include <vector>
#include <string>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1, 0), b(n + 1, 0), c(n + 1, 0);
    std::vector<std::string> g(n);
    for (auto &s: g) {
        std::cin >> s;
    }

    int w = (1 << k) - 1;
    long long ans = 0;

    for (int j = 0; j < n; ++j) {
        std::vector<int> v(n, 0);
        for (int j2 = j; j2 < n; ++j2) {
            for (int i = 0; i < n; ++i) {
                v[i] |= 1 << (g[i][j2] - 'A');
            }

            int l = 0, r = 0, res = 0;
            for (int i = 0; i < n; ++i) {
                c[++l] = v[i];
                a[l] = c[l] | a[l - 1];

                while ((a[l] | b[r]) == w) {
                    if (r == 0) {
                        for (int jj = l, ii = 1; jj >= 1; --jj, ++ii) {
                            b[ii] = b[ii - 1] | c[jj];
                        }
                        r = l;
                        l = 0;
                    }
                    --r;
                    ++res;
                }

                ans += res;
            }
        }
    }

    std::cout << ans << '\n';
    return 0;
}
