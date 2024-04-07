#include <bits/stdc++.h>

using namespace std;


mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());


struct node {
    node *L= nullptr, *R= nullptr;
    int prio, sz=1;
    char c;
    bool rev=false;

    node(char _c):prio(static_cast<int>(rng())),c(_c) {

    }
};

auto size(node *treap) -> int {
    if (!treap) return 0;
    return treap->sz;
}

void push(node *treap) {
    if (treap && treap->rev) {
        treap->rev = false;
        swap(treap->L, treap->R);
        if (treap->L) treap->L->rev ^= true;
        if (treap->R) treap->R->rev ^= true;
    }
}

void recalc(node *&treap) {
    if (!treap) return;
    treap->sz = size(treap->L) + size(treap->R) + 1;
}

void split(node *treap, node *&L, node *&R, int k) {
    if (!treap) {
        L = R = nullptr;
    } else {
        push(treap);
        if (size(treap->L) >= k) {
            split(treap->L, L, treap->L, k);
            R = treap;
        } else {
            split(treap->R, treap->R, R, k - size(treap->L) - 1);
            L = treap;
        }
        recalc(treap);
    }
}

void merge(node *&treap, node *L, node *R) {
    if (!L) treap = R;
    else if (!R) treap = L;
    else {
        push(L), push(R);
        if (L->prio > R->prio) {
            merge(L->R, L->R, R);
            treap = L;
        } else {
            merge(R->L, L, R->L);
            treap = R;
        }
        recalc(treap);
    }
}

void print(node *treap) {
    if (!treap) return;
    push(treap);
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
        node *a, *b, *c;
        split(root, a, b, l - 1);
        split(b, b, c, r - l + 1);
        b->rev ^= true;
        merge(root, a, b);
        merge(root, root, c);
    }
    print(root);
}