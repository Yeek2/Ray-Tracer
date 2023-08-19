//To make the test exe: g++ -std=c++17 MatrixTests.cc -lgtest -lgtest_main -o a
//To run: ./a
#include <gtest/gtest.h>
#include "vec3.h"
#include "matrix.h"

TEST(MatrixTests, MatrixInitialization){
    std::cout << "Initializing a 3x3 matrix of digits 1-9\n";
    Matrix m(3);
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
    Matrix m2(2);
    m2 = {{1,2}, {3,4}};
    std::cout << "Checking dimension is 2\n";
    EXPECT_EQ(m2.dim(), 2);
    std::cout << "Checking indexing into matrix works properly\n";
    EXPECT_EQ(m2[0][0], 1);
    EXPECT_EQ(4, m2[1][1]);
    std::cout << "Initializing a 4x4 matrix of all zeros\n";
    Matrix m4(4);
    EXPECT_EQ(m4.dim(), 4);
    EXPECT_EQ(0, m4[3][3]);
}
TEST(MatrixTests, MatrixEquality){
    std::cout << "Initialize three 4x4 matrices\n";
    Matrix A(4);
    Matrix B(4);
    Matrix C(4);
    A = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    B = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    C = { {1,2,3,5}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
    std::cout << "Check that A == B\n";
    EXPECT_EQ(A,B);
    std::cout << "Check that A != C\n";
    EXPECT_NE(A,C);
    std::cout << "Check that B != C\n";
    EXPECT_NE(B,C);
}
TEST(MatrixTests, MatrixMultiplication){
    std::cout<< "Initialize two 4x4 matrices\n";
    Matrix A(4);
    Matrix B(4);
    Matrix C(4);
    Matrix D(4);
    A = { {1,2,3,4}, {5,6,7,8}, {9,8,7,6}, {5,4,3,2} };
    B = { {-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8} };
    C = matrixMultiply(A, B);

    D = {{20,22,50,48},{44,54,114,108},{40,58,110,102},{16,26,46,42}};

    EXPECT_EQ(C, D);
}
TEST(MatrixTests, MatrixMultiplicationTuple){
    std::cout<< "Initialize one 4x4 matrix, one tuple\n";
    Matrix A(4);
    std::vector<double> b = {1,2,3,1};
    A = { {1,2,3,4}, {2,4,4,2}, {8,6,4,1}, {0,0,0,1} };
    std::vector<double> c = matrixMultiply(A, b);
    std::vector<double> d = {18,24,33,1};
    EXPECT_EQ(c, d);
}