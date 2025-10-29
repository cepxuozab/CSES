#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<long long> dp(n + 1, 0);
    vector<long long> pref(n + 1, 0);

    dp[0] = 1;
    pref[0] = 1;

    unordered_map<long long, int> last;
    int left = 0;

    for (int i = 1; i <= n; ++i) {
        long long val = x[i - 1];

        // Если значение уже встречалось в текущем окне — сдвигаем левую границу
        if (last.count(val) && last[val] >= left) {
            left = last[val] + 1;
        }

        last[val] = i - 1;

        // dp[i] = сумма dp[j] для j от left до i-1
        long long sum = pref[i - 1];
        if (left > 0) {
            sum = (sum - pref[left - 1] + MOD) % MOD;
        }

        dp[i] = sum;
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] % MOD << '\n';
    return 0;
}