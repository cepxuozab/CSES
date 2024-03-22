#include <iostream>
#include <unordered_set>
#include <vector>

[[maybe_unused]] static auto const _ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

auto find(std::vector<int> const &l, int x) -> int
{
    while (x != l[x])
    {
        x = l[x];
    }
    return x;
}

void unite(std::vector<int> &l, std::vector<int> &s, int a, int b)
{
    a = find(l, a);
    b = find(l, b);
    if (a == b)
    {
        return;
    }
    if (s[a] < s[b])
    {
        std::swap(a, b);
    }
    s[a] += s[b];
    l[b] = a;
}

auto main() -> int
{
    int n;
    int m;
    std::cin >> n >> m;
    std::vector<int> l(n * m, -1);
    std::vector<int> s(n * m, 1);
    std::vector<std::vector<bool>> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i].resize(m, false);
        for (int j = 0; j < m; j++)
        {
            char b;
            std::cin >> b;
            if (b == '.')
            {
                a[i][j] = true;
                l[i * m + j] = i * m + j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j < m - 1 && a[i][j] && a[i][j + 1])
            {
                unite(l, s, i * m + j, i * m + j + 1);
            }
            if (i < n - 1 && a[i][j] && a[i + 1][j])
            {
                unite(l, s, i * m + j, (i + 1) * m + j);
            }
        }
    }
    std::unordered_set<int> sets;
    for (int x : l)
    {
        if (x >= 0)
        {
            sets.insert(find(l, x));
        }
    }
    std::cout << sets.size() << std::endl;
}
