#include <iostream>
#include <vector>
#include <cstdint>

class NextPrime {
    std::vector<int64_t> primes;

    void init() {
        const int sqrtN = 1e6 + 5;
        std::vector<bool> arr(sqrtN, true);
        for (int i = 2; i * i <= sqrtN; i++)
            if (arr[i])
                for (int j = 2 * i; j < sqrtN; j += i)
                    arr[j] = false;

        for (int i = 2; i < sqrtN; i++)
            if (arr[i])
                primes.push_back(i);

    }

    bool is_prime(int64_t n) const {
        for (size_t i = 0; i < primes.size() && primes[i] < n; i++)
            if (n % primes[i] == 0)
                return false;
        return true;
    }

public:
    NextPrime() { init(); }

    int64_t next_prime(int64_t n) const {
        n++;
        while (!is_prime(n))
            n++;
        return n;
    }
};

auto main() -> int {
    int test_cases;
    std::cin >> test_cases;
    NextPrime next_primes;
    for (int test = 0; test < test_cases; ++test) {
        int64_t n;
        std::cin >> n;
        std::cout << next_primes.next_prime(n) << '\n';
    }
}