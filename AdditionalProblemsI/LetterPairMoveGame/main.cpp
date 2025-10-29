#include <iostream>
#include <vector>
#include <string>
#include <set>

void domove(std::vector<std::string> &moves, std::string &s, int i, int &empty) {
    std::set<int> diff{i, i + 1, empty, empty + 1};
    if (diff.size() != 4) {
        std::cout << "-1\n";
        exit(0);
    }
    std::swap(s[i], s[empty]);
    std::swap(s[i + 1], s[empty + 1]);
    moves.push_back(s);
    empty = i;
}

auto main() -> int {
    std::vector<std::string> moves;
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    if (n == 1) {
        std::cout << 0;
        exit(0);
    }

    int empty = s.find_first_of('.') != std::string::npos ? static_cast<int>(s.find_first_of('.')) : -1;
    int end = s.find_last_not_of('B') != std::string::npos ? static_cast<int>(s.find_last_not_of('B')) : 2 * n;
    int begin = s.find_first_of('B') != std::string::npos ? static_cast<int>(s.find_first_of('B')) : -1;
    while (begin < end) {
        if (empty != end - 1) {
            if (empty == end - 2) {
                domove(moves, s, 0, empty);
            }
            domove(moves, s, end - 1, empty);
        }
        begin = s.find_first_of('B') != std::string::npos ? static_cast<int>(s.find_first_of('B')) : -1;
        if (begin == 0) {
            if (end - begin <= 4) {
                std::cout << "-1\n";
                exit(0);
            } else {
                domove(moves, s, begin + 2, empty);
                domove(moves, s, begin, empty);
                domove(moves, s, end - 1, empty);
            }
            begin += 2;
        }
        domove(moves, s, begin - 1, empty);
        end = s.find_last_not_of('B') != std::string::npos ? static_cast<int>(s.find_last_not_of('B')) : 2 * n;
        begin = s.find_first_of('B') != std::string::npos ? static_cast<int>(s.find_first_of('B')) : -1;
    }
    std::cout << moves.size() << "\n";
    for (auto &m: moves) {
        std::cout << m << "\n";
    }


}

