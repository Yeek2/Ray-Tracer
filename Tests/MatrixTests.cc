//To make the test exe: g++ -std=c++17 MatrixTests.cc -lgtest -lgtest_main -o MatrixTests
//To run: ./MatrixTests
#include <gtest/gtest.h>
#include "../doth/vec3.h"
#include "../doth/matrix.h"

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
    std::cout << "Initialize two 4x4 matrices\n";
    Matrix A = { {1,2,3,4}, {5,6,7,8}, {9,8,7,6}, {5,4,3,2} };
    Matrix B = { {-2,1,2,3}, {3,2,1,-1}, {4,3,6,5}, {1,2,7,8} };
    Matrix D = {{20,22,50,48},{44,54,114,108},{40,58,110,102},{16,26,46,42}};
    std::cout << "Multiply them together, expect equivalence to known multiplied matrix\n";
    Matrix C = matrixMultiply(A, B);

    EXPECT_EQ(C, D);
}
TEST(MatrixTests, MatrixMultiplicationTuple){
    std::cout << "Initialize one 4x4 matrix, one tuple\n";
    Matrix A = { {1,2,3,4}, {2,4,4,2}, {8,6,4,1}, {0,0,0,1} };
    std::vector<double> b = {1,2,3,1};

    std::vector<double> c = matrixMultiply(A, b);
    std::vector<double> d = {18,24,33,1};
    EXPECT_EQ(c, d);
}
TEST(MatrixTests, IdentityMatrix){
    std::cout << "Expect Identity Matrix to have a diagonal of zeros\n";
    Matrix I = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };
    EXPECT_EQ(I, Matrix::IDENTITY);
}
TEST(MatrixTests, MatrixTranspose){
    std::cout << "Expect matrix transpose to invert columns & rows\n";
    Matrix A = { {0,9,3,0}, {9,8,0,8}, {1,8,5,3}, {0,0,5,8} };
    Matrix B = { {0,9,1,0}, {9,8,8,0}, {3,0,5,5}, {0,8,3,8} };
    EXPECT_EQ(transpose(A), B);
}
TEST(MatrixTests, MatrixDeterminant2x2){
    std::cout << "Expect 2x2 matrix determinant to work\n";
    Matrix A = { {1,5}, {-3,2} };
    EXPECT_EQ(determinant2x2(A), 17);
}
TEST(MatrixTests, SubMatrix){
    std::cout << "Initialize a 3x3 Matrix & take the 0th row & 2nd column\n";
    Matrix A = { {1,5,0}, {-3,2,7}, {0,6,-3} };
    Matrix B = { {-3,2}, {0,6} };
    EXPECT_EQ(subMatrix(A, 0, 2), B);
    std::cout << "Initialize a 4x4 matrix & take the 2nd row and 1st column\n";
    Matrix C = { {-6,1,1,6},{-8,5,8,6},{-1,0,8,2},{-7,1,-1,1} };
    Matrix D = {{-6,1,6},{-8,8,6},{-7,-1,1}};
    EXPECT_EQ(subMatrix(C, 2, 1), D);
}
TEST(MatrixTests, Matrix3x3Minor){
    std::cout << "Initialize a 3x3 matrix & take the minor of it\n";
    Matrix A = { {3,5,0}, {2,-1,-7}, {6,-1,5} };
    Matrix B = subMatrix(A, 1, 0);
    EXPECT_EQ(minor3x3(A, 1, 0), determinant2x2(B));
}

