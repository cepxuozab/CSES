#include <iostream>
#include <string>
#include <array>
#include <string_view>

constexpr int side_length = 7;
constexpr int path_length = side_length * side_length - 1;

class Grid {
    enum class Direction : char {
        Up, Down, Left, Right, Any
    };

    using path = std::array<Direction, path_length>;
    using grid = std::array<std::array<bool, side_length>, side_length>;

    path pattern{};
    grid visited{};
    int total{};
public:
    Grid(std::string_view str) {
        visited[0][side_length - 1] = true;
        size_t i = 0;
        for (char ch: str) {
            switch (ch) {
                case 'D':
                    pattern[i] = Direction::Down;
                    break;
                case 'L':
                    pattern[i] = Direction::Left;
                    break;
                case 'U':
                    pattern[i] = Direction::Up;
                    break;
                case 'R':
                    pattern[i] = Direction::Right;
                    break;
                default:
                    pattern[i] = Direction::Any;
                    break;
            }
            i++;
        }
    }

    auto TotalNumberPaths() -> int {
        search(0, side_length - 1, 0);
        return total;
    }

private:
    auto left_valid(int x, int y) -> bool {
        return x > 0 && !visited[x - 1][y];
    }

    auto right_valid(int x, int y) -> bool {
        return x + 1 < side_length && !visited[x + 1][y];
    }

    auto down_valid(int x, int y) -> bool {
        return y > 0 && !visited[x][y - 1];
    }

    auto up_valid(int x, int y) -> bool {
        return y + 1 < side_length && !visited[x][y + 1];
    }

    auto split(int x, int y) -> bool {
        if (left_valid(x, y) && right_valid(x, y) && !up_valid(x, y) && !down_valid(x, y))
            return true;
        if (!left_valid(x, y) && !right_valid(x, y) && up_valid(x, y) && down_valid(x, y))
            return true;
        return false;
    }

    void search(int x, int y, int n) {
        if (n == path_length) { // finished
            total += 1;
            return;
        }
        if (x == 0 && y == 0) // visited endpoint early
            return;
        if (split(x, y))
            return;
        Direction next = pattern[n];
        // whether to try in each direction
        bool up = (next == Direction::Up || next == Direction::Any);
        bool down = (next == Direction::Down || next == Direction::Any);
        bool left = (next == Direction::Left || next == Direction::Any);
        bool right = (next == Direction::Right || next == Direction::Any);
        // search and sum each direction
        if (up && up_valid(x, y)) {
            visited[x][y + 1] = true;
            search(x, y + 1, n + 1);
            visited[x][y + 1] = false;
        }
        if (down && down_valid(x, y)) {
            visited[x][y - 1] = true;
            search(x, y - 1, n + 1);
            visited[x][y - 1] = false;
        }
        if (left && left_valid(x, y)) {
            visited[x - 1][y] = true;
            search(x - 1, y, n + 1);
            visited[x - 1][y] = false;
        }
        if (right && right_valid(x, y)) {
            visited[x + 1][y] = true;
            search(x + 1, y, n + 1);
            visited[x + 1][y] = false;
        }
    }

};


auto main() -> int {
    std::string str;
    std::cin >> str;
    auto grid = Grid(str);
    std::cout << grid.TotalNumberPaths() << '\n';
    return 0;
}