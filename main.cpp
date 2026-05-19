#include <iostream>
#include "Money.h"

#pragma pack(push, 1)
struct PackedMoney {
    long h;
    unsigned char k;
};
#pragma pack(pop)

int main() {
    using namespace std;

    cout << "=== ЛІЧИЛЬНИК ОБ'ЄКТІВ (Object) ===" << endl;
    cout << "Початкова кількість: " << Object::GetCount() << endl;

    Money m1(50, 75);
    Money m2(20, 80);
    cout << "Кількість після створення m1 та m2: " << Object::GetCount() << endl;

    cout << "\n=== ВВЕДЕННЯ / ВИВЕДЕННЯ ===" << endl;
    cout << "m1: " << m1 << endl; // Автоматично підтягує оператор з MoneyBase

    Money m3;
    cout << "Введіть гривні та копійки для m3 через пробіл: ";
    cin >> m3;
    cout << "m3: " << m3 << endl;

    cout << "\n=== АРИФМЕТИКА ТА ПОРІВНЯННЯ ===" << endl;
    Money diff = m1 - m2;
    cout << "Різниця (m1 - m2): " << diff << endl;
    cout << "Множення (m1 * 2.5): " << (m1 * 2.5) << endl;
    cout << "m1 > m2: " << (m1 > m2 ? "Так" : "Ні") << endl;

    cout << "\n=== ІНКРЕМЕНТИ ===" << endl;
    cout << "Префіксний ++m1: " << ++m1 << endl;
    cout << "Постфіксний m1++: " << m1++ << " | Після кроку: " << m1 << endl;

    cout << "\n=== ДИНАМІЧНІ МАСИВИ ===" << endl;
    const int size = 3;
    Money* wallet = new Money[size]{ Money(10, 0), Money(5, 50), Money(100, 99) };
    cout << "Кількість разом з масивом: " << Object::GetCount() << endl;

    delete[] wallet;
    cout << "Кількість після видалення масиву: " << Object::GetCount() << endl;

    cout << "\n=== РОЗМІР ПАМ'ЯТІ ===" << endl;
    cout << "sizeof(Money) з урахуванням vptr: " << sizeof(Money) << " байт" << endl;
    cout << "sizeof(PackedMoney) з #pragma pack(1): " << sizeof(PackedMoney) << " байт" << endl;

    return 0;
}