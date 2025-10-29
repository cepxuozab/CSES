#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        long long a, b, x;
        cin >> a >> b >> x;

        if (x > a) {
            cout << "NO\n";
        } else {
            long long g = gcd(a, b);
            if (x % g == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
