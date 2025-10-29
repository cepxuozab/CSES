#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdint>

class BigInt {
private:
    // база 1e9, хранение младшей цифры в digits[0]
    static const uint32_t BASE = 1000000000u;
    std::vector<uint32_t> digits;
    bool neg;

    void trim() {
        while (!digits.empty() && digits.back() == 0) digits.pop_back();
        if (digits.empty()) neg = false;
    }

    static int cmpAbs(const BigInt &a, const BigInt &b) {
        if (a.digits.size() != b.digits.size())
            return (a.digits.size() < b.digits.size()) ? -1 : 1;
        for (size_t i = a.digits.size(); i-- > 0;) {
            if (a.digits[i] != b.digits[i]) return a.digits[i] < b.digits[i] ? -1 : 1;
        }
        return 0;
    }

public:
    BigInt(): digits(), neg(false) {}

    // from signed 64-bit
    static BigInt fromInt64(int64_t v) {
        BigInt r;
        uint64_t uv;
        if (v < 0) { r.neg = true; uv = (uint64_t)(-v); }
        else { r.neg = false; uv = (uint64_t)v; }
        while (uv > 0) {
            r.digits.push_back((uint32_t)(uv % BASE));
            uv /= BASE;
        }
        return r;
    }

    // add absolute b to a (assumes a and b non-negative, modifies *this)
    void addAbs(const BigInt &b) {
        uint64_t carry = 0;
        size_t n = std::max(digits.size(), b.digits.size());
        digits.resize(n, 0u);
        for (size_t i = 0; i < n; ++i) {
            uint64_t ai = digits[i];
            uint64_t bi = (i < b.digits.size() ? b.digits[i] : 0u);
            uint64_t sum = ai + bi + carry;
            digits[i] = (uint32_t)(sum % BASE);
            carry = sum / BASE;
        }
        if (carry) digits.push_back((uint32_t)carry);
    }

    // subtract absolute b from a: assumes |a| >= |b|
    void subAbs(const BigInt &b) {
        int64_t carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            int64_t ai = (int64_t)digits[i];
            int64_t bi = (int64_t)(i < b.digits.size() ? b.digits[i] : 0);
            int64_t cur = ai - bi - carry;
            if (cur < 0) { cur += BASE; carry = 1; }
            else carry = 0;
            digits[i] = (uint32_t)cur;
        }
        trim();
    }

    BigInt operator+(const BigInt &other) const {
        BigInt res = *this;
        if (res.neg == other.neg) {
            res.addAbs(other);
        } else {
            int cmp = cmpAbs(res, other);
            if (cmp >= 0) { // |res| >= |other|
                res.subAbs(other);
            } else {
                BigInt tmp = other;
                tmp.subAbs(res);
                res = tmp;
            }
        }
        return res;
    }

    BigInt operator-(const BigInt &other) const {
        BigInt a = *this;
        BigInt b = other;
        // a - b = a + (-b)
        b.neg = !b.neg;
        return a + b;
    }

    BigInt& operator+=(const BigInt &o) { *this = *this + o; return *this; }
    BigInt& operator-=(const BigInt &o) { *this = *this - o; return *this; }

    // multiply by small non-negative integer (fits in int but could be up to like 2e5)
    void mulInt(uint32_t m) {
        if (m == 0 || digits.empty()) { digits.clear(); neg = false; return; }
        uint64_t carry = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            uint64_t prod = (uint64_t)digits[i] * m + carry;
            digits[i] = (uint32_t)(prod % BASE);
            carry = prod / BASE;
        }
        while (carry) {
            digits.push_back((uint32_t)(carry % BASE));
            carry /= BASE;
        }
    }

    // multiply BigInt (absolute) by a signed 64-bit value, returning result (handles sign)
    static BigInt mulByInt64AsBig(int64_t val, uint32_t mulCount) {
        // Build BigInt from absolute val then multiply by mulCount (small)
        BigInt base = BigInt::fromInt64(val);
        if (base.digits.empty()) return BigInt(); // zero
        base.mulInt(mulCount);
        // sign handled by fromInt64 and mulInt doesn't change sign
        return base;
    }

    std::string toString() const {
        if (digits.empty()) return "0";
        std::string s;
        if (neg) s.push_back('-');
        // most significant
        size_t i = digits.size() - 1;
        s += std::to_string(digits[i]);
        // other digits with leading zeros to width 9
        for (size_t k = i; k-- > 0;) {
            std::string part = std::to_string(digits[k]);
            // pad
            s += std::string(9 - part.size(), '0') + part;
        }
        return s;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }

    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());

    BigInt ans; // initialized zero

    // For each x[i], we add lb * x[i] and subtract (n - ub) * x[i]
    for (int i = 0; i < n; ++i) {
        int lb = static_cast<int>(std::lower_bound(x.begin(), x.end(), x[i]) - x.begin());
        if (lb != 0) {
            BigInt addTerm = BigInt::mulByInt64AsBig(x[i], (uint32_t)lb);
            ans += addTerm;
        }
        int ub = static_cast<int>(std::upper_bound(x.begin(), x.end(), x[i]) - x.begin());
        int cnt = n - ub;
        if (cnt != 0) {
            BigInt subTerm = BigInt::mulByInt64AsBig(x[i], (uint32_t)cnt);
            ans -= subTerm;
        }
    }

    for (int i = 0; i < n; ++i) {
        int lb = static_cast<int>(std::lower_bound(y.begin(), y.end(), y[i]) - y.begin());
        if (lb != 0) {
            BigInt addTerm = BigInt::mulByInt64AsBig(y[i], (uint32_t)lb);
            ans += addTerm;
        }
        int ub = static_cast<int>(std::upper_bound(y.begin(), y.end(), y[i]) - y.begin());
        int cnt = n - ub;
        if (cnt != 0) {
            BigInt subTerm = BigInt::mulByInt64AsBig(y[i], (uint32_t)cnt);
            ans -= subTerm;
        }
    }

    std::cout << ans.toString() << "\n";
    return 0;
}
