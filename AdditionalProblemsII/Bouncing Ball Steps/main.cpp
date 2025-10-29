#include <iostream>
#include <numeric>
#include <cstdint>

auto main()->int{
    int t;std::cin>>t;
    for(int i =0; i < t; ++i){
        int64_t n,m,k;
        std::cin>>n>>m>>k;
        n--,m--;
        auto b1=k/n,b2=k/m;
        auto r1=k%n,r2=k%m;
        if(b1&1) r1=n-r1;
        if(b2&1) r2=m-r2;
        std::cout<<r1+1<<' '<<r2+1<<' '<<b1+b2-k/(std::lcm(n,m))<<'\n';
    }

}
