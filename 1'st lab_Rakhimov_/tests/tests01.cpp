#include <gtest/gtest.h>
#include "../include/divisible.h"

TEST(FindMaxDivisibleTest, Example1) {
    EXPECT_EQ(findMaxDivisible(2, 7), 6);
}

TEST(FindMaxDivisibleTest, Example2) {
    EXPECT_EQ(findMaxDivisible(10, 50), 50);
}

// Граничные случаи
TEST(FindMaxDivisibleTest, DividerEqualsBound) {
    EXPECT_EQ(findMaxDivisible(5, 5), 5);
}

TEST(FindMaxDivisibleTest, DividerGreaterThanBound) {
    EXPECT_EQ(findMaxDivisible(10, 5), 0);
}

TEST(FindMaxDivisibleTest, BoundIsMultipleOfDivider) {
    EXPECT_EQ(findMaxDivisible(3, 15), 15);
}

TEST(FindMaxDivisibleTest, BoundNotMultipleOfDivider) {
    EXPECT_EQ(findMaxDivisible(3, 16), 15);
    EXPECT_EQ(findMaxDivisible(4, 13), 12);
}

// Тесты с единицей
TEST(FindMaxDivisibleTest, DividerIsOne) {
    EXPECT_EQ(findMaxDivisible(1, 10), 10);
    EXPECT_EQ(findMaxDivisible(1, 1), 1);
}

// Тесты с большими числами
TEST(FindMaxDivisibleTest, LargeNumbers) {
    EXPECT_EQ(findMaxDivisible(7, 100), 98); // 7 * 14 = 98
    EXPECT_EQ(findMaxDivisible(13, 200), 195); // 13 * 15 = 195
}

// Тесты для некорректных данных
TEST(FindMaxDivisibleTest, NegativeDivider) {
    EXPECT_EQ(findMaxDivisible(-5, 10), 0);
}

TEST(FindMaxDivisibleTest, NegativeBound) {
    EXPECT_EQ(findMaxDivisible(5, -10), 0);
}

TEST(FindMaxDivisibleTest, ZeroDivider) {
    EXPECT_EQ(findMaxDivisible(0, 10), 0);
}

TEST(FindMaxDivisibleTest, ZeroBound) {
    EXPECT_EQ(findMaxDivisible(5, 0), 0);
}

TEST(FindMaxDivisibleTest, BothZero) {
    EXPECT_EQ(findMaxDivisible(0, 0), 0);
}

TEST(FindMaxDivisibleTest, SmallNumbers) {
    EXPECT_EQ(findMaxDivisible(2, 1), 0); // 2 > 1
    EXPECT_EQ(findMaxDivisible(1, 2), 2);
    EXPECT_EQ(findMaxDivisible(2, 2), 2);
    EXPECT_EQ(findMaxDivisible(2, 3), 2);
    EXPECT_EQ(findMaxDivisible(3, 2), 0); // 3 > 2
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
