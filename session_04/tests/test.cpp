//
// Created by Jonathan Gerber on 10/31/16.
//

#include "gtest/gtest.h"
#include "../src/Vector.hpp"

TEST(Vector, default_constructor) {
    Vector v{};
    EXPECT_DOUBLE_EQ(0.0, v.x);
    EXPECT_DOUBLE_EQ(0.0, v.y);
    EXPECT_DOUBLE_EQ(1.0, v.z);
}

TEST(Vector, double_constructor) {
    Vector v{1.2, 3.4, 7};
    EXPECT_DOUBLE_EQ(1.2, v.x);
    EXPECT_DOUBLE_EQ(3.4, v.y);
    EXPECT_DOUBLE_EQ(7.0, v.z);
}

TEST(Vector, operator_plus) {
    Vector v1{1.2, 3.4, 7};
    Vector v2{2, -4.5, 7.2};

    auto result = v1 + v2;

    EXPECT_DOUBLE_EQ( 3.2, result.x);
    EXPECT_DOUBLE_EQ(-1.1, result.y);
    EXPECT_DOUBLE_EQ(14.2, result.z);
}


TEST(Vector, operator_plus_eq) {
    Vector result{1.2, 3.4, 7};
    Vector v2{2, -4.5, 7.2};

    result += v2;

    EXPECT_DOUBLE_EQ( 3.2, result.x);
    EXPECT_DOUBLE_EQ(-1.1, result.y);
    EXPECT_DOUBLE_EQ(14.2, result.z);
}

TEST(Vector, operator_minus) {
    Vector v1{1.2, 3.4, 14};
    Vector v2{3, -4.5, 7.2};

    auto result = v1 - v2;

    EXPECT_DOUBLE_EQ(-1.8, result.x);
    EXPECT_DOUBLE_EQ( 7.9, result.y);
    EXPECT_DOUBLE_EQ( 6.8, result.z);
}

TEST(Vector, operator_minus_eq) {
    Vector result{1.2, 3.4, 14};
    Vector v2{3, -4.5, 7.2};

    result -= v2;

    EXPECT_DOUBLE_EQ(-1.8, result.x);
    EXPECT_DOUBLE_EQ( 7.9, result.y);
    EXPECT_DOUBLE_EQ( 6.8, result.z);
}

TEST(Vector, times_double) {
    Vector v1{2, 4, -6};
    double d{2};

    auto result = v1 * d;

    EXPECT_DOUBLE_EQ(4,   result.x);
    EXPECT_DOUBLE_EQ(8,   result.y);
    EXPECT_DOUBLE_EQ(-12, result.z);
}

TEST(Vector, equality) {
    Vector v1{2, 4, -6};
    Vector v2{2, 4, -6};

   EXPECT_TRUE(v1 == v2);
}

TEST(Vector, equality_2) {
    Vector v1{2, 4, -6};
    Vector v2{2, 4, 6};

    EXPECT_FALSE(v1 == v2);
}

TEST(Vector, dot_product) {

    Vector v1{2, 3, 4};
    Vector v2{6, 3, 8};
    auto result = v1 * v2;
    auto expect = (2 * 6) + (3 * 3) + (4 * 8);
    EXPECT_DOUBLE_EQ(expect, result);
}

TEST(Vector, cross_product) {
    Vector v1{2, 3, 4};
    Vector v2{3,8,-2};
    auto result = v1.cross(v2);

    Vector expect {v1.y * v2.z - v1.z * v2.y,
                   v1.z * v2.x - v1.x * v2.z,
                   v1.x * v2.y - v1.y * v2.x };

    EXPECT_DOUBLE_EQ(expect.x, result.x);
    EXPECT_DOUBLE_EQ(expect.y, result.y);
    EXPECT_DOUBLE_EQ(expect.z, result.z);
}

TEST(Vector, length) {
    Vector v1{2.0, 3.0, 4.0};
    auto len = v1.length();
    // sqrt (29)
    auto expect = 5.385164807134504;
    EXPECT_DOUBLE_EQ(expect, len);
}

TEST(Vector, normalize) {
    Vector v1{2.0, 3.0, -4.0};
     v1.normalize();
    // sqrt (29)
    auto expect = 5.385164807134504;

    EXPECT_DOUBLE_EQ(2.0 / expect, v1.x);
    EXPECT_DOUBLE_EQ(3.0 / expect, v1.y);
    EXPECT_DOUBLE_EQ(-4.0 / expect, v1.z);
}