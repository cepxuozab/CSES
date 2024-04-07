#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

#define Base 1000005

using namespace std;

struct Node {
    int tag = 0;
    int sum = 0;
};

long long n;
vector<Node> ST;

void init(int _n) {
    n = _n;
    ST.assign(n * 4, Node());
}

void pull(int l, int r, int d) {
    if (ST[d].tag > 0)
        ST[d].sum = r - l;
    else if (r - l <= 1)
        ST[d].sum = 0;
    else
        ST[d].sum = ST[d * 2].sum + ST[d * 2 + 1].sum;
}

void update(int ql, int qr, int val, int l = 0, int r = n, int d = 1) {
    if (r <= ql || qr <= l) return;
    if (ql <= l && r <= qr) {
        ST[d].tag += val;
    } else {
        int mid = l + (r - l) / 2;
        update(ql, qr, val, l, mid, d * 2);
        update(ql, qr, val, mid, r, d * 2 + 1);
    }
    pull(l, r, d);
}

struct Segment {
    int x, y1, y2, val;

    auto operator<(const Segment &other) const -> bool {
        if (x != other.x) return x < other.x;
        return val > other.val;
    }
};

auto main() -> int {


    int N;
    cin >> N;
    vector<Segment> Segs;
    int MaxY = 0;
    while (N--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += Base;
        x2 += Base;
        y1 += Base;
        y2 += Base;
        tie(y1, y2) = minmax(y1, y2);
        MaxY = max(MaxY, y2);
        Segs.emplace_back(Segment{x1, y1, y2, 1});
        Segs.emplace_back(Segment{x2, y1, y2, -1});
    }
    sort(Segs.begin(), Segs.end());

    init(Base * 2);
    long long previous_x = 0, ans = 0;
    for (auto &Seg: Segs) {
        ans += (Seg.x - previous_x) * ST[1].sum;
        update(Seg.y1, Seg.y2, Seg.val);
        previous_x = Seg.x;

    }
    cout << ans << '\n';
}
