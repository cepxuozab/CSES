
#include <bits/stdc++.h>

using namespace std;
using ll = long long;


mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());



struct node {
    node *L, *R;
    int prio, sz, val;
    ll sum;
    bool rev;
    node (int _val = 0) {
        L = nullptr, R = nullptr, prio = rng(), sz = 1, val = sum = _val, rev = false;
    }
};

auto size(node *treap) -> int {
    if (!treap) return 0;
    return treap->sz;
}

auto sum(node *treap) -> ll {
    if (!treap) return 0ll;
    return treap->sum;
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
    treap->sum = sum(treap->L) + sum(treap->R) + treap->val;
}

void split(node *treap, node *&L, node *&R, int k) {
    if (!treap) {
        L = R = nullptr;
    }
    else {
        push(treap);
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
    if (!L) treap = R;
    else if (!R) treap = L;
    else {
        push(L), push(R);
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

auto query(node *treap, int k) -> ll {
    if (!treap) return 0;
    else {
        push(treap);
        if (size(treap->L) >= k) {
            return query(treap->L, k);
        }
        else {
            return sum(treap->L) + query(treap->R, k - size(treap->L) - 1) + treap->val;
        }
    }
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tipo, l, r;
    cin >> n >> m;
    node *root = 0;
    for (int i = 0; i < n; i++) {
        cin >> tipo;
        merge(root, root, new node(tipo));
    }
    for (int i = 0; i < m; i++) {
        node *a, *b, *c;
        cin >> tipo >> l >> r;
        if (tipo == 1) {
            split(root, a, b, l - 1);
            split(b, b, c, r - l + 1);
            b->rev ^= true;
            merge(root, a, b);
            merge(root, root, c);
        }
        else {
            cout << query(root, r) - query(root, l - 1) << '\n';
        }
    }
    return 0;
}