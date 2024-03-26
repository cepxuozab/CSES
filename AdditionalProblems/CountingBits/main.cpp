#include <iostream>
#include <cstdint>

auto GetSetBitsFromOneToN(int64_t N) -> int64_t
{
    int64_t two = 2, ans = 0;
    int64_t n = N;
    while (n) {
        ans += (N / two) * (two >> 1);
        if ((N & (two - 1)) > (two >> 1) - 1)
            ans += (N & (two - 1)) - (two >> 1) + 1;
        two <<= 1;
        n >>= 1;
    }
    return ans;
}

auto main()->int{
    int64_t n;
    std::cin>>n;
    std::cout<<GetSetBitsFromOneToN(n);
}
