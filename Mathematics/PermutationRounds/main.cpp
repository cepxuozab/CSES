#include <iostream>
#include <map>
#include <vector>

const long long MOD = 1e9 + 7;

auto power(long long base, long long exp) -> long long {
    long long result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}


auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i];
    std::vector<bool> vis(n + 1, false);
    long long ans = 1;
    std::map<int, int> prime_power;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cur = i;
            int len = 0;
            while (!vis[cur]) {
                vis[cur] = true;
                cur = p[cur];
                len++;
            }
            int temp = len;
            for (int idx = 2; idx * idx <= temp; idx++) {
                int cnt = 0;
                while (temp % idx == 0) {
                    cnt++;
                    temp /= idx;
                }
                prime_power[idx] = std::max(prime_power[idx], cnt);
            }
            if (temp > 1) {
                prime_power[temp] = std::max(prime_power[temp], 1);
            }
        }
    }
    for (auto const &[prime, cnt]: prime_power) {
        ans = (ans * power(prime, cnt)) % MOD;
    }
    std::cout << ans << '\n';

}