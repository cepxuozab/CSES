/**
* @brief Apartments
 * @link https://cses.fi/problemset/task/1084
 * @date 15.01.2023
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <span>

std::vector<int> ReadAndSortData(unsigned n);

int DistributeApartments(int diff, std::span<int> applicants, std::span<int> appartments);

int main() {
    unsigned applicantsSize = 0;
    unsigned appartmentsSize = 0;
    int diff = 0;
    std::cin >> applicantsSize >> appartmentsSize >> diff;
    auto applicants = ReadAndSortData(applicantsSize);
    auto appartments = ReadAndSortData(appartmentsSize);
    std::cout << DistributeApartments(diff, applicants, appartments);
    return 0;

}

int DistributeApartments(int diff, std::span<int> applicants, std::span<int> appartments) {
    int answer = 0;
    int const applicantsSize = static_cast<int>(applicants.size());
    int const appartmentsSize = static_cast<int>(appartments.size());
    int i = 0;
    int j = 0;
    while (i < applicantsSize && j < appartmentsSize) {
        if (applicants[i] + diff < appartments[j]) {
            i++;
        } else if (applicants[i] - diff > appartments[j]) {
            j++;
        } else {
            i++;
            j++;
            answer++;
        }
    }
    return answer;
}

std::vector<int> ReadAndSortData(unsigned n) {
    std::vector<int> arr;
    arr.resize(n);
    for (int &data: arr) {
        std::cin >> data;
    }
    std::ranges::sort(arr);
    return arr;
}