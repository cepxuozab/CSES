#include <iostream>
#include <string>
#include<bitset>

void GreyCode(int n) {
    // power of 2
    for (int i = 0; i < (1 << n); i++) {
        // Generating the decimal
        // values of gray code then using
        // bitset to convert them to binary form
        int val = (i ^ (i >> 1));

        // Using bitset
        std::bitset<32> r(val);

        // Converting to string
        std::string s = r.to_string();
        std::cout << s.substr(32 - n) << "\n";
    }
}


auto main() -> int {
    int n;
    std::cin >> n;
    GreyCode(n);
    return 0;
}