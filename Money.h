#pragma once
#include "MoneyBase.h"

class Money : public MoneyBase {
public:
    Money();
    Money(long h, unsigned char k);
    Money(const Money& other);
    virtual ~Money() {}

    // Операції як методи класу (унарні та присвоєння)
    Money& operator=(const Money& other);
    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);

    // Бінарна арифметика та порівняння (зовнішні дружні функції)
    friend Money operator-(const Money& a, const Money& b);
    friend Money operator*(const Money& a, double factor);

    friend bool operator==(const Money& a, const Money& b);
    friend bool operator!=(const Money& a, const Money& b);
    friend bool operator<(const Money& a, const Money& b);
    friend bool operator>(const Money& a, const Money& b);
    friend bool operator<=(const Money& a, const Money& b);
    friend bool operator>=(const Money& a, const Money& b);
};