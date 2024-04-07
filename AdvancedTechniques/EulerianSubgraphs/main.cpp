#include <cstdint>
#include <iostream>
#include <vector>

constexpr int MOD = 1e9+7;
auto FastPow(int64_t b, int e) -> int64_t {
    if (e < 0) return 1;
    int64_t resp = 1;
    while (e) {
        if (e&1) resp = (resp * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return resp;
}


auto main() -> int {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    for (int i = 0, a, b; i < m; ++i) {
        std::cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    std::vector<bool> visited(n);
    auto Dfs=[&](auto&& self,int u)->void{
        visited[u]=true;
        for(int x:adj[u]){
            if(!visited[x]){
                self(self,x);
            }
        }
    };
    int cnt = 0;
    for(int v = 0; v<n;++v){
        if(!visited[v]){
            cnt++;
            Dfs(Dfs,v);
        }

    }
    std::cout << FastPow(2LL, m - n + cnt);
}