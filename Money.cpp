#include "Money.h"
#include <cmath>

Money::Money() : MoneyBase() {}

Money::Money(long h, unsigned char k) : MoneyBase(h, k) {}

Money::Money(const Money& other) : MoneyBase(other) {}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        SetHryvnia(other.GetHryvnia());
        SetKopecks(other.GetKopecks());
    }
    return *this;
}

Money& Money::operator++() {
    long h = GetHryvnia();
    int k = GetKopecks() + 1;
    if (k >= 100) { k = 0; h++; }
    Init(h, k);
    return *this;
}

Money Money::operator++(int) {
    Money temp(*this);
    ++(*this);
    return temp;
}

Money& Money::operator--() {
    long h = GetHryvnia();
    int k = GetKopecks();
    if (k == 0) {
        if (h > 0) { h--; k = 99; }
    } else {
        k--;
    }
    Init(h, k);
    return *this;
}

Money Money::operator--(int) {
    Money temp(*this);
    --(*this);
    return temp;
}

Money operator-(const Money& a, const Money& b) {
    long total_k1 = a.GetHryvnia() * 100 + a.GetKopecks();
    long total_k2 = b.GetHryvnia() * 100 + b.GetKopecks();
    long diff = total_k1 - total_k2;
    if (diff < 0) diff = 0;
    return Money(diff / 100, diff % 100);
}

Money operator*(const Money& a, double factor) {
    long total_k = a.GetHryvnia() * 100 + a.GetKopecks();
    long res = static_cast<long>(std::round(total_k * factor));
    if (res < 0) res = 0;
    return Money(res / 100, res % 100);
}

bool operator==(const Money& a, const Money& b) {
    return (a.GetHryvnia() == b.GetHryvnia() && a.GetKopecks() == b.GetKopecks());
}

bool operator!=(const Money& a, const Money& b) { return !(a == b); }

bool operator<(const Money& a, const Money& b) {
    if (a.GetHryvnia() != b.GetHryvnia()) return a.GetHryvnia() < b.GetHryvnia();
    return a.GetKopecks() < b.GetKopecks();
}

bool operator>(const Money& a, const Money& b) { return b < a; }
bool operator<=(const Money& a, const Money& b) { return !(a > b); }
bool operator>=(const Money& a, const Money& b) { return !(a < b); }