#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    std::set<int> mex;
    std::unordered_map<int, int> mp;

    for (int i = 0; i <= k; i++) mex.insert(i);

    for (int i = 0; i < k; i++) {
        mp[arr[i]]++;
        mex.erase(arr[i]);
    }
    std::vector<int> result;
    result.push_back(*mex.begin());


    int i = 0;
    for (int j = k; j < n; j++) {
        // remove i
        int const prev_value = arr[i];
        mp[prev_value]--;
        if (mp[prev_value] == 0) {
            mp.erase(prev_value);
            mex.insert(prev_value);
        }
        // add j
        int const curr_value = arr[j];
        mp[curr_value]++;
        mex.erase(curr_value);
        result.push_back(*mex.begin());
        i++;
    }

    for (int elem: result)std::cout << elem << ' ';
    return 0;
}