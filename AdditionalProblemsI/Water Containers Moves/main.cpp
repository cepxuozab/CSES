#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct MoveInfo {
    int fromA, fromB;
    string action;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, x;
    cin >> a >> b >> x;

    // Early impossible check
    if (x > a) {
        cout << -1 << "\n";
        return 0;
    }
    if (x % __gcd(a, b) != 0) {
        cout << -1 << "\n";
        return 0;
    }

    vector<vector<long long>> dist(a + 1, vector<long long>(b + 1, INF));
    vector<vector<MoveInfo>> parent(a + 1, vector<MoveInfo>(b + 1, {-1, -1, ""}));

    using State = tuple<long long, int, int>;
    priority_queue<State, vector<State>, greater<State>> pq;

    dist[0][0] = 0;
    pq.emplace(0, 0, 0);

    auto try_move = [&](int A, int B, int newA, int newB, long long cost, const string &act) {
        if (cost == 0) return; // no water moved
        if (newA < 0 || newA > a || newB < 0 || newB > b) return;
        if (dist[A][B] + cost < dist[newA][newB]) {
            dist[newA][newB] = dist[A][B] + cost;
            parent[newA][newB] = {A, B, act};
            pq.emplace(dist[newA][newB], newA, newB);
        }
    };

    while (!pq.empty()) {
        auto [d, A, B] = pq.top();
        pq.pop();
        if (d != dist[A][B]) continue;

        // 1. FILL A
        if (A < a) {
            long long cost = a - A;
            try_move(A, B, a, B, cost, "FILL A");
        }
        // 2. FILL B
        if (B < b) {
            long long cost = b - B;
            try_move(A, B, A, b, cost, "FILL B");
        }
        // 3. EMPTY A
        if (A > 0) {
            long long cost = A;
            try_move(A, B, 0, B, cost, "EMPTY A");
        }
        // 4. EMPTY B
        if (B > 0) {
            long long cost = B;
            try_move(A, B, A, 0, cost, "EMPTY B");
        }
        // 5. MOVE A -> B
        if (A > 0 && B < b) {
            int amount = min(A, b - B);
            if (amount > 0) {
                try_move(A, B, A - amount, B + amount, amount, "MOVE A B");
            }
        }
        // 6. MOVE B -> A
        if (B > 0 && A < a) {
            int amount = min(B, a - A);
            if (amount > 0) {
                try_move(A, B, A + amount, B - amount, amount, "MOVE B A");
            }
        }
    }

    // Find best state with A == x
    long long min_cost = INF;
    int bestB = -1;
    for (int B = 0; B <= b; B++) {
        if (dist[x][B] < min_cost) {
            min_cost = dist[x][B];
            bestB = B;
        }
    }

    if (min_cost == INF) {
        cout << -1 << "\n";
        return 0;
    }

    // Reconstruct path
    vector<string> moves;
    int curA = x, curB = bestB;
    while (curA != 0 || curB != 0) {
        auto [prevA, prevB, act] = parent[curA][curB];
        moves.push_back(act);
        curA = prevA;
        curB = prevB;
    }
    reverse(moves.begin(), moves.end());

    cout << moves.size() << " " << min_cost << "\n";
    for (const string &m: moves) {
        cout << m << "\n";
    }

    return 0;
}