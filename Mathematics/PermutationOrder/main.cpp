#include <iostream>
#include <numeric>
#include <vector>



auto main() -> int{
    int t;
    std::cin>>t;
    while(t--){
        int e,n;
        long long k=0;
        std::cin>>e;
        std::cin>>n;
        std::vector<int> v(n);
        std::vector<int> p(n);
        std::iota(p.begin(),p.end(),1);

        if(e==1){
            std::cin>>k;
            k --;
            std::vector<long long> sol;
            std::vector<int> remaining(n);
            for(int i = 0;i<n;i++){
                remaining[i] = i+1;
            }
            int n_tag = n;
            while(n > 0){
                long long fact = 1;
                int N = n - 1;
                while(N > 1){
                    fact *= N;
                    N--;
                }
                long long idx = (k) / fact ;
                for(int i = 0;i<n_tag;i++){
                    if(idx == 0 && remaining[i] != -1){
                        sol.push_back(remaining[i]);
                        remaining[i] = -1;
                        break;
                    }
                    if(remaining[i] != -1){
                        idx--;
                    }
                }
                k = (k) % fact;
                n --;
            }
            for(long long &x : sol){
                std::cout<<x<<" ";
            }
            std::cout<<"\n";
        }else{
            for(int &x:v){
                std::cin>>x;
            }
            long long f = 1;
            for(int i = 2;i<n;i++){
                f*=i;
            }
            std::vector<int> place(n);
            for(int i = 0;i<n;i++){
                place[i] = i + 1;
            }
            for(int i = 0;i<n;i++){
                int pos = 0;
                for(int j = 0;j<n;j++){
                    if(v[i] == place[j]){
                        place[j] = -1;
                        break;
                    }
                    if(place[j] != -1){
                        pos ++;
                    }
                }
                k += f * (pos);
                if(i == n-1){
                    continue;
                }
                f /= (n - i - 1);
            }
            std::cout<<k + 1<<"\n";
        }
    }
}