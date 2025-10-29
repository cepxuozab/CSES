#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<long double> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        long long t;
        cin >> t;
        a[i] = t;
    }
    for (int i = 1; i <= n; ++i) {
        long long t;
        cin >> t;
        b[i] = t;
    }

    vector<long double> prefA(n + 1, 0.0L), prefB(n + 1, 0.0L);
    for (int i = 1; i <= n; ++i) {
        prefA[i] = prefA[i - 1] + a[i];
        prefB[i] = prefB[i - 1] + b[i];
    }

    // bounds for binary search
    long double lo = 0.0L;
    long double hi = 0.0L;
    for (int i = 1; i <= n; ++i) {
        hi = max(hi, prefA[i] / i);
        hi = max(hi, prefB[i] / i);
    }
    // store best pair found during successful checks
    int best_i = 1, best_j = 1;

    auto feasible = [&](long double t, bool store) -> bool {
        // find max over j of (prefB[j] - t*j)
        long double bestB = -1e300L;
        int bestBj = 1;
        for (int j = 1; j <= n; ++j) {
            long double val = prefB[j] - t * j;
            if (val > bestB) {
                bestB = val;
                bestBj = j;
            }
        }
        // check i
        for (int i = 1; i <= n; ++i) {
            long double val = (prefA[i] - t * i) + bestB;
            if (val >= 0.0L) {
                if (store) {
                    best_i = i;
                    best_j = bestBj;
                }
                return true;
            }
        }
        return false;
    };

    // binary search for maximum average
    for (int iter = 0; iter < 80; ++iter) {
        long double mid = (lo + hi) / 2.0L;
        if (feasible(mid, false)) lo = mid;
        else hi = mid;
    }
    // now store pair for lo (last feasible)
    feasible(lo, true);

    // best_i, best_j found. Output them.
    cout << best_i << " " << best_j << "\n";
    return 0;
}