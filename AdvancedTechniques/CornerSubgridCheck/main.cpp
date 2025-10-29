#include <bits/stdc++.h>
using namespace std;

auto has_valid_subgrid(const vector<string>& grid, int n, char target_char) -> bool {
    // Для каждой пары столбцов (c1, c2), где c1 < c2
    // будем запоминать, встречалась ли уже эта буква в этих столбцах
    vector<vector<bool>> seen_pair(n, vector<bool>(n, false));

    for (int r = 0; r < n; r++) {
        // Найдем все столбцы в текущей строке, где стоит нужная буква
        vector<int> cols_with_char;
        for (int j = 0; j < n; j++) {
            if (grid[r][j] == target_char) {
                cols_with_char.push_back(j);
            }
        }

        // Для каждой пары столбцов в этой строке
        for (size_t i1 = 0; i1 < cols_with_char.size(); i1++) {
            for (size_t i2 = i1 + 1; i2 < cols_with_char.size(); i2++) {
                int c1 = cols_with_char[i1];
                int c2 = cols_with_char[i2];

                if (seen_pair[c1][c2]) {
                    return true;
                }

                seen_pair[c1][c2] = true;
            }
        }
    }

    return false;
}

auto main() -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int letter = 0; letter < k; letter++) {
        char target_char = static_cast<char>('A' + letter);
        bool exists = has_valid_subgrid(grid, n, target_char);
        cout << (exists ? "YES" : "NO") << "\n";
    }

    return 0;
}