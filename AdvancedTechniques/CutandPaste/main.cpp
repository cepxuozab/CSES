#include <bits/stdc++.h>
using namespace std;


mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());



struct node {
    node *L, *R;
    int prio, sz;
    char c;
    node (char _c) {
        L = nullptr, R = nullptr, prio =(int) rng(), sz = 1, c = _c;
    }
};

auto size(node *treap) -> int {
    if (treap == nullptr) return 0;
    return treap->sz;
}

void recalc(node *&treap) {
    if (treap == nullptr) return;
    treap->sz = size(treap->L) + size(treap->R) + 1;
}

void split(node *treap, node *&L, node *&R, int k) {
    if (treap == nullptr) {
        L = R = nullptr;
    }
    else {
        if (size(treap->L) >= k) {
            split(treap->L, L, treap->L, k);
            R = treap;
        }
        else {
            split(treap->R, treap->R, R, k - size(treap->L) - 1);
            L = treap;
        }
        recalc(treap);
    }
}

void merge(node *&treap, node *L, node *R) {
    if (L == nullptr) treap = R;
    else if (R == nullptr) treap = L;
    else {
        if (L->prio > R->prio) {
            merge(L->R, L->R, R);
            treap = L;
        }
        else {
            merge(R->L, L, R->L);
            treap = R;
        }
        recalc(treap);
    }
}

void print(node *treap) {
    if (treap == nullptr) return;
    print(treap->L);
    cout << treap->c;
    print(treap->R);
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l, r;
    string s;
    cin >> n >> m >> s;
    node *root = nullptr;
    for (int i = 0; i < n; i++) {
        merge(root, root, new node(s[i]));
    }
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        node *a, *b, *c, *d;
        split(root, a, b, l - 1);
        split(b, c, d, r - l + 1);
        merge(root, a, d);
        merge(root, root, c);
    }
    print(root);
    cout << '\n';
    return 0;
}