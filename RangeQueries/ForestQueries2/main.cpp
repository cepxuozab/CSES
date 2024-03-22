
#include <iostream>
#include <vector>

[[maybe_unused]] auto const FastIo = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class BIT_2D {
private:
    int n, m;
    std::vector<std::vector<int>> tree;

public:
    explicit BIT_2D(std::vector<std::vector<int>> const &mat) :
        n(static_cast<int>(mat.size())), m(static_cast<int>(mat.front().size())), tree(n, std::vector<int>(m, 0)) {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                bit_update(i, j, mat[i][j]);
            }
        }
    }

    [[nodiscard]] int query(int x1, int y1, int x2, int y2) const {
        return bit_query(x2, y2) - bit_query(x1 - 1, y2) - bit_query(x2, y1 - 1) + bit_query(x1 - 1, y1 - 1);
    }

    void bit_update(int x, int y, int delta) {
        for (int i = x; i < n; i += low(i)) {
            for (int j = y; j < m; j += low(j)) {
                tree[i][j] += delta;
            }
        }
    }

private:
    // Returns an integer which constains only the least significant bit.
    static int low(int i) { return i & (-i); }

    [[nodiscard]] int bit_query(int x, int y) const {
        int ans = 0;
        for (int i = x; i > 0; i -= low(i)) {
            for (int j = y; j > 0; j -= low(j)) {
                ans += tree[i][j];
            }
        }

        return ans;
    }
};

signed main() {
    int n;
    int q;
    std::cin >> n >> q;
    std::vector<std::vector<int>> mat(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            std::cin >> x;
            mat[i][j] = static_cast<int>(x == '*');
        }
    }

    BIT_2D bit(mat);
    while ((q--) != 0) {
        int t;
        std::cin >> t;
        if (t == 2) {
            int x1;
            int y1;
            int x2;
            int y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << bit.query(x1, y1, x2, y2) << std::endl;
        } else {
            int y;
            int x;
            std::cin >> x >> y;
            int const d = (mat[x][y] != 0 ? -1 : 1);
            bit.bit_update(x, y, d);
            mat[x][y] = static_cast<int>(mat[x][y]) == 0;
        }
    }
}
