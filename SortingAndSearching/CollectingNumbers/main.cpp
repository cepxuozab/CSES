/**
* @brief Collecting Numbers
 * @link https://cses.fi/problemset/task/2216/
 * @author cepxuo(cepxuozab@gmail.com)
 * @date 13.01.2024
*/

#include <iostream>
#include <vector>
#include <span>

namespace {
    /**
     * @brief Read data , decrement it end form array
     * @param n size of array
     * @return array number from 0 to n-1
     */
    std::vector<int> ReadArray(int n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            int val;
            std::cin >> val;
            val--;
            arr[val] = i;
        }
        return arr;
    }
}//namespace

/**
 * @brief Count number of round collect number between 0..n in increasing order
 * @param arr numbers from 0 to n
 * @return number of round
 */
int NumberOfRoundToCollectNumbers(std::span<int> arr) {
    int num = 0;
    int cnt = 1;
    for (int a: arr) {
        cnt += static_cast<int>(num > a);
        num = a;
    }
    return cnt;
}

int main() {
    int n;
    std::cin >> n;
    auto arr = ReadArray(n);
    std::cout << NumberOfRoundToCollectNumbers(arr);
    return 0;
}
