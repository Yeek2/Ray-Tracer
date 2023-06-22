//To make the test exe: g++ -std=c++17 MatrixTests.cc -lgtest -lgtest_main -o a
//To run: ./a
#include <gtest/gtest.h>
#include "vec3.h"
#include "matrix.h"

TEST(MatrixTests, MatrixInitialization){
    std::cout << "Initializing a 3x3 matrix of digits 1-9\n";
    matrix m(3);
    m = { {1,2,3}, {4,5,6}, {7,8,9} };
    std::cout << "Checking dimension is 3\n";
    EXPECT_EQ(m.dim(), 3);
    std::cout << "Checking indexing into matrix works properly\n";
    EXPECT_EQ(m[0][0], 1);
    EXPECT_EQ(m[0][1], 2);
    EXPECT_EQ(m[0][2], 3);
    EXPECT_EQ(m[1][2], 6);
}
TEST(MatrixTests, VariousMatrixSizes){
    std::cout << "Initializing a 2x2 matrix of digits 1-4\n";
    matrix m2(2);
    m2 = {{1,2}, {3,4}};
    std::cout << "Checking dimension is 2\n";
    EXPECT_EQ(m2.dim(), 2);
    std::cout << "Checking indexing into matrix works properly\n";
    EXPECT_EQ(m2[0][0], 1);
    EXPECT_EQ(4, m2[1][1]);
    std::cout << "Initializing a 4x4 matrix of all zeros\n";
    matrix m4(4);
    EXPECT_EQ(m4.dim(), 4);
    EXPECT_EQ(0, m4[3][3]);
}
TEST(MatrixTests, MatrixEquality){
    std::cout << "Initialize three 3x3 matrices\n";
    matrix A(3);
    matrix B(3);
    matrix C(3);
    A = { {1,2,3}, {4,5,6}, {7,8,9} };
    B = { {1,2,3}, {4,5,6}, {7,8,9} };
    C = { {1,2,3}, {4,5,7}, {7,8,9} };
    std::cout << "Check that A == B\n";
    EXPECT_EQ(A,B);
    std::cout << "Check that A != C\n";
    EXPECT_NE(A,C);
    std::cout << "Check that B != C\n";
    EXPECT_NE(B,C);
}
