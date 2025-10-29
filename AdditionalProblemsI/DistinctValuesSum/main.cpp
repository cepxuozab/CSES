#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    unordered_map<long long, int> last_pos; // последняя позиция каждого значения
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int prev = last_pos.count(x[i]) ? last_pos[x[i]] : -1;
        long long left = i - prev;      // сколько вариантов для начала подмассива
        long long right = n - i;        // сколько вариантов для конца
        ans += left * right;
        last_pos[x[i]] = i;
    }

    cout << ans << '\n';
    return 0;
}