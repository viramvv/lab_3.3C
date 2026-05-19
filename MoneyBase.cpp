#include "MoneyBase.h"
#include <sstream>
#include <iomanip>

MoneyBase::MoneyBase() : Object(), hryvnia(0), kopecks(0) {}

MoneyBase::MoneyBase(long h, unsigned char k) : Object() {
    if (!Init(h, k)) {
        hryvnia = 0;
        kopecks = 0;
    }
}

MoneyBase::MoneyBase(const MoneyBase& other) : Object(other), hryvnia(other.hryvnia), kopecks(other.kopecks) {}

bool MoneyBase::Init(long h, long k) {
    if (h < 0 || k < 0 || k >= 100) return false;
    hryvnia = h;
    kopecks = static_cast<unsigned char>(k);
    return true;
}

bool MoneyBase::SetKopecks(unsigned char k) {
    if (k >= 100) return false;
    kopecks = k;
    return true;
}

void MoneyBase::Read() {
    long h, k;
    do {
        std::cout << "Введіть гривні: "; std::cin >> h;
        std::cout << "Введіть копійки (0-99): "; std::cin >> k;
    } while (!Init(h, k));
}

void MoneyBase::Display() const {
    std::cout << toString() << std::endl;
}

std::string MoneyBase::toString() const {
    std::stringstream ss;
    ss << hryvnia << "," << std::setw(2) << std::setfill('0') << static_cast<int>(kopecks);
    return ss.str();
}

std::ostream& operator<<(std::ostream& out, const MoneyBase& obj) {
    out << obj.toString();
    return out;
}

std::istream& operator>>(std::istream& in, MoneyBase& obj) {
    long h, k;
    in >> h >> k;
    if (!obj.Init(h, k)) {
        obj.Init(0, 0);
    }
    return in;
}