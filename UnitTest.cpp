#include <gtest/gtest.h>
#include "Money.h"

// Тест глобального лічильника живих об'єктів
TEST(ObjectSystemTest, GlobalCounter) {
    int start = Object::GetCount();
    {
        Money t1, t2;
        EXPECT_EQ(Object::GetCount(), start + 2);
    }
    EXPECT_EQ(Object::GetCount(), start);
}

// Тест фінансової валідації полів
TEST(MoneyBaseTest, Validation) {
    Money m1(10, 50);
    EXPECT_EQ(m1.GetHryvnia(), 10);
    EXPECT_EQ(m1.GetKopecks(), 50);

    Money m2(10, 105); // Некоректні копійки
    EXPECT_EQ(m2.GetHryvnia(), 0);
    EXPECT_EQ(m2.GetKopecks(), 0);
}

// Тест унарних методів (інкременти)
TEST(MoneyOperatorTest, UnaryClassMethods) {
    Money m(4, 99);
    ++m;
    EXPECT_EQ(m.GetHryvnia(), 5);
    EXPECT_EQ(m.GetKopecks(), 0);

    m--;
    EXPECT_EQ(m.GetHryvnia(), 4);
    EXPECT_EQ(m.GetKopecks(), 99);
}

// Тест дружніх бінарних операцій
TEST(MoneyOperatorTest, BinaryFriendFunctions) {
    Money m1(20, 50);
    Money m2(10, 70);

    Money diff = m1 - m2; // 20.50 - 10.70 = 9.80
    EXPECT_EQ(diff.GetHryvnia(), 9);
    EXPECT_EQ(diff.GetKopecks(), 80);

    EXPECT_TRUE(m1 > m2);
    EXPECT_TRUE(m2 < m1);
    EXPECT_FALSE(m1 == m2);
}