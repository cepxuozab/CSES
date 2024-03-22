#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

class Node {
    std::unique_ptr<Node> left{}, right{};
    int tL{}, tR{};
    int64_t sum = 0, pushL = 0, pushR = 0;

public:
    Node(int tL, int tR)
        : tL(tL)
        , tR(tR) {
    }
    void Add(int qL, int qR, int64_t addL, int64_t addR);
    auto Query(int qL, int qR) -> int64_t;

private:
    void Push();
};

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n);
    for (auto& x : nums) std::cin >> x;
    auto node = std::make_unique<Node>(0, n - 1);
    for (int i = 0; i < n; ++i) {
        node->Add(i, i, nums[i], nums[i]);
    }
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        --b;
        --c;
        if (a == 1) {
            node->Add(b, c, 1, c - b + 1);
        } else {
            std::cout << node->Query(b, c) << '\n';
        }
    }
}

void Node::Add(int qL, int qR, int64_t addL, int64_t addR) {
    if (qL > qR) return;
    if (tL == tR) {
        sum += addL;
        return;
    }

    if (qL == tL && qR == tR) {
        pushL += addL;
        pushR += addR;
        sum += (addL + addR) * (tR - tL + 1) / 2;
        return;
    }

    Push();

    int64_t step = qR == qL ? 0 : ((addR - addL) / (qR - qL));
    int m = tL + (tR - tL) / 2;
    int split = std::min(m, qR);
    if (m >= qR) {
        left->Add(qL, qR, addL, addR);
    } else if (m < qL) {
        right->Add(qL, qR, addL, addR);
    } else {
        int64_t splitVal = addL + (split - qL) * step;  // a_k = a_0 + k * step
        left->Add(qL, std::min(m, qR), addL, splitVal);
        right->Add(std::max(m + 1, qL), qR, splitVal + step, addR);
    }

    sum = left->sum + right->sum;
}

void Node::Push() {
    int m = tL + (tR - tL) / 2;
    if (!left) left = std::make_unique<Node>(tL, m);
    if (!right) right = std::make_unique<Node>(m + 1, tR);

    int64_t step = (pushR - pushL) / (tR - tL);
    int64_t addM = pushL + (m - tL) * step;  // a_k = a_0 + step * (k)
    if (pushL > 0) {
        left->Add(tL, m, pushL, addM);
        right->Add(m + 1, tR, addM + step, pushR);
        pushL = 0;
        pushR = 0;
    }
    sum = left->sum + right->sum;
}

auto Node::Query(int qL, int qR) -> int64_t {
    if (qL > qR) return 0;
    if (qL == tL && qR == tR) return sum;

    Push();
    int m = tL + (tR - tL) / 2;

    return left->Query(qL, std::min(qR, m)) + right->Query(std::max(qL, m + 1), qR);
}