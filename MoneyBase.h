#pragma once
#include "Object.h"
#include <iostream>
#include <string>

class MoneyBase : public Object {
private:
    long hryvnia;
    unsigned char kopecks;
public:
    MoneyBase();
    MoneyBase(long h, unsigned char k);
    MoneyBase(const MoneyBase& other);
    virtual ~MoneyBase() {}

    bool Init(long h, long k);
    void Read();
    void Display() const;
    std::string toString() const;

    long GetHryvnia() const { return hryvnia; }
    unsigned char GetKopecks() const { return kopecks; }
    void SetHryvnia(long h) { hryvnia = h; }
    bool SetKopecks(unsigned char k);

    friend std::ostream& operator<<(std::ostream& out, const MoneyBase& obj);
    friend std::istream& operator>>(std::istream& in, MoneyBase& obj);
};