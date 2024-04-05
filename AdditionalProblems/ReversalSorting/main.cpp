#include <sstream>
#include <iostream>
#include <random>
#include <tuple>
#include <vector>

using namespace std;

struct Treap {
    mt19937 static rd;

    int pri, sz{1};
    int val, maximum;
    bool lazy{false};
    Treap *lc{nullptr}, *rc{nullptr};

    Treap(int val)
            : pri(rd()), val(val), maximum(val) {}

    void pull() {
        sz = 1;
        maximum = val;
        if (lc) {
            sz += lc->sz;
            maximum = max(maximum, lc->maximum);
        }
        if (rc) {
            sz += rc->sz;
            maximum = max(maximum, rc->maximum);
        }
    }

    void push() {
        if (!lazy) return;
        lazy = false;
        swap(lc, rc);
        if (lc) lc->lazy = !lc->lazy;
        if (rc) rc->lazy = !rc->lazy;
    }
};

mt19937 Treap::rd;

auto merge(Treap *a, Treap *b) -> Treap * {
    if (!a || !b) return a ? a : b;
    Treap *ret;
    if (a->pri < b->pri) {
        a->push();
        ret = a;
        ret->rc = merge(a->rc, b);
    } else {
        b->push();
        ret = b;
        ret->lc = merge(a, b->lc);
    }
    ret->pull();
    return ret;
}

auto splitK(Treap *root, int k) -> pair<Treap *, Treap *> {
    Treap *a = nullptr, *b = nullptr;
    if (!root) return {a, b};
    root->push();
    int left_size = 1 + (root->lc ? root->lc->sz : 0);
    if (left_size <= k) {
        a = root;
        tie(a->rc, b) = splitK(root->rc, k - left_size);
    } else {
        b = root;
        tie(a, b->lc) = splitK(root->lc, k);
    }
    root->pull();
    return {a, b};
}

auto split(Treap *root, int val) -> pair<Treap *, Treap *> {
    Treap *a = nullptr, *b = nullptr;
    if (!root) return {a, b};
    if (root->maximum != val) {
        a = root;
        return {a, b};
    }
    root->push();
    if (root->rc && root->rc->maximum == val) {
        a = root;
        tie(a->rc, b) = split(root->rc, val);
    } else {
        b = root;
        tie(a, b->lc) = split(root->lc, val);
    }
    root->pull();
    return {a, b};
}


void update(Treap *&root, int l, int r) {
    auto [a, b] = splitK(root, l);
    auto [c, d] = splitK(b, r - l + 1);
    c->lazy = !c->lazy;
    root = merge(a, merge(c, d));
}

auto query(Treap *&root, int val) -> int {
    auto [a, b] = split(root, val);
    int ret = a ? a->sz : 0;
    root = merge(a, b);
    return ret;
}

auto main() -> int {
    Treap::rd = mt19937(random_device()());

    int n;
    cin >> n;
    Treap *root = nullptr;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        root = merge(root, new Treap(x));
    }
    std::ostringstream out;
    int k = 0;
    for (int i = n; i >= 1; --i){
        int pos = query(root, i);
        if(pos+1!=i){
            out << pos + 1 << " " << i << "\n";
            k++;
        }
        update(root, pos, i - 1);
        Treap *temp;
        tie(root, temp) = splitK(root, i - 1);
        delete temp;
    }

    cout << k << "\n";
    std::cout<<out.str();
}