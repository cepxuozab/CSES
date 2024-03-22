#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Point {
    int x{}, y{};
};

int main() {
#ifdef _DEBUG
    if (freopen("input.txt", "r", stdin) == nullptr) {
        puts("can't open input.txt");
        return 0;
    }
#endif // _DEBUG

    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> labirint(N);
    Point start;
    std::vector<std::vector<short>> visited(N, std::vector<short>(M, 0));
    std::queue<Point> queue;
    for (int i = 0; i < N; ++i) {
        std::cin >> labirint[i];
        for (int j = 0; j < M; ++j) {
            switch (auto const ch = labirint[i][j]; ch) {
                case '#':
                    visited[i][j] = 1;
                    break;
                case 'M':
                    visited[i][j] = 1;
                    queue.push({i, j});
                    break;
                case 'A':
                    start = {i, j};
                    break;
                default:
                    break;
            }
        }
    }
    auto const inbounds = [N, M](int x, int y) { return 0 <= x && x < N && 0 <= y && y < M; };
    std::vector<std::vector<int>> dist1(N, std::vector<int>(M, 0));

    int constexpr horiz[] = {1, -1, 0, 0};
    int constexpr vert[] = {0, 0, 1, -1};
    while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop();
        for (size_t i = 0; i < std::size(horiz); ++i) {
            auto const curr_x = x + horiz[i];
            auto const curr_y = y + vert[i];
            if (inbounds(curr_x, curr_y) && visited[curr_x][curr_y] == 0) {
                dist1[curr_x][curr_y] = dist1[x][y] + 1;
                visited[curr_x][curr_y] = 1;
                queue.push({curr_x, curr_y});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int constexpr INF = 0x3f3f3f3f;
            if (visited[i][j] == 0)
                dist1[i][j] = INF;
            visited[i][j] = (labirint[i][j] == '#');
        }
    }

    queue.push(start);
    visited[start.x][start.y] = 1;
    std::vector<std::string> path(N, std::string(M, ' '));
    std::vector<std::vector<int>> dist2(N, std::vector<int>(M, 0));

    while (!queue.empty()) {

        Point const P = queue.front();
        queue.pop();
        for (int i = 0; i < 4; i++) {

            int const x = P.x + horiz[i];
            int const y = P.y + vert[i];
            if (inbounds(x, y) && !visited[x][y] && dist2[P.x][P.y] + 1 < dist1[x][y]) {
                auto const direction = "DURL";
                path[x][y] = direction[i];
                dist2[x][y] = dist2[P.x][P.y] + 1;
                visited[x][y] = true;
                queue.push({x, y});
            }
        }
    }

    Point finish;
    bool isFinded = false;
    auto const Check = [&](int x, int y) {
        if (labirint[x][y] != '#' && labirint[x][y] != 'M' && visited[x][y] == 1) {
            finish = Point{x, y};
            isFinded = true;
        }
        return isFinded;
    };

    for (int i = 0; i < N; ++i) {
        if (Check(i, 0) || Check(i, M - 1)) {
            break;
        }
    }

    if (!isFinded) {
        for (int i = 0; i < M; i++) {
            if (Check(0, i) || Check(N - 1, i)) {
                break;
            }
        }
    }

    if (!isFinded) {
        puts("NO");
        return 0;
    }
    auto [x, y] = finish;
    int const SIZE = dist2[x][y];
    std::deque<char> answer;
    printf("YES\n%d\n", SIZE);
    for (int i = SIZE - 1; i >= 0; --i) {
        auto const curr = path[x][y];
        answer.push_front(curr);
        switch (curr) {
            case 'D':
                x--;
                break;
            case 'U':
                x++;
                break;
            case 'L':
                y++;
                break;
            case 'R':
                y--;
                break;
            default:
                break;
        }
    }
    for (char ch: answer) {
        printf("%c", ch);
    }
    printf("\n");
}
