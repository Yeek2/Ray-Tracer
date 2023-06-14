//To make the test exe: g++ -std=c++17 hello_test.cc -lgtest -lgtest_main -o a
//To run: ./a
#include <gtest/gtest.h>
#include "vec3.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

vec3 test1(5,5,5);
vec3 test2(2,2,2);
vec3 test4(-2,-2,-2);
vec3 test5(9,9,9);

point3 ptest1(1,1,1);
point3 ptest2(3,3,3);
point3 ptest6(-1,-1,-1);

TEST(VectorOperations, VectorPointAddition){
  std::cout << "Adding a point with a vector should yield a point\n";
  EXPECT_EQ(point3(5,5,5), vec3(2,2,2) + point3(3,3,3));
}

TEST(VectorOperations, PointSubtractPointEqualsVector){
  std::cout << "Subtracting a point from a point yields a vector\n";
  EXPECT_EQ(point3(4,4,4) - point3(1,1,1), vec3(3,3,3));
}

TEST(VectorOperations, PointMinusVectorYieldsVector){
  std::cout << "Subtracting a vector from a point yields a vector\n";
  EXPECT_EQ(point3(4,4,4) - vec3(2,2,2), point3(2,2,2));
}
TEST(VectorOperations, VectorMinusVectorYieldsVector){
  std::cout << "Subtracting a vector from a vector yields a vector\n";
  EXPECT_EQ(vec3(5,5,5) - vec3(2,2,2), vec3(3,3,3));
}

TEST(VectorOperations, Negations){
  std::cout << "Negations of vectors/points should yield the inverse\n";
  EXPECT_EQ(ptest1, -ptest6);
  EXPECT_EQ(test2, -test4);
}

TEST(VectorOperations, Multiplication){
  std::cout << "Multiplying vectors & points by fractional and decimal numbers\n";
  EXPECT_EQ(point3(3,3,3)*1.5, point3(4.5,4.5,4.5));
  EXPECT_EQ(test2*1.5, vec3(3,3,3));
}

TEST(VectorOperations, Division){
  std::cout << "Dividing vectors & points\n";
  EXPECT_EQ(point3(4,4,4)/2, point3(2,2,2));
  EXPECT_EQ(test5/3, vec3(3,3,3));
}

TEST(VectorOperations, Magnitude){
  std::cout << "Testing magnitude function\n";
  EXPECT_EQ(point3(1,0,0).magnitude(), 1);
  EXPECT_EQ(vec3(1,2,3).magnitude(), sqrt(14));
  EXPECT_EQ(point3(-1,-2,3).magnitude(), sqrt(14));
}

TEST(VectorOperations, Normalization){
  std::cout << "Testing normalization function\n";
  EXPECT_EQ(point3(4,0,0).normalize(), point3(1,0,0));
  EXPECT_EQ(vec3(1,2,3).normalize(), vec3(1/sqrt(14), 2/sqrt(14), 3/sqrt(14)));
  std::cout << "Expect that a normalized vector has a magnitude of 1\n";
  EXPECT_EQ(vec3(1,2,3).normalize().magnitude(), 1);
}

TEST(VectorOperations, DotProduct){
  std::cout << "Testing the dot product operator/function\n";
  EXPECT_EQ(vec3::dot(vec3(1,2,3), vec3(2,3,4)), 20);
}

TEST(VectorOperations, CrossProduct){
  std::cout << "Testing the cross product operator/function\n";
  EXPECT_EQ(vec3::cross(vec3(1,2,3), vec3(2,3,4)), vec3(-1,2,-1));
  EXPECT_EQ(vec3::cross(vec3(2,3,4), vec3(1,2,3)), vec3(1,-2,1));
}


TEST(VectorOperations, TypeAssertions){
  std::cout << "Testing that points add properly\n";
  std::cout << "Assert that ptest1 is of type point3\n";
  EXPECT_EQ("point3", point3(1,1,1).type());
  std::cout << "Assert that test1 is of type vec3\n";
  EXPECT_EQ("vec3", test1.type());

  std::cout << "Adding test1 and ptest1 together\n";
  point3 something = ptest1 + test1;
  std::cout << "Test that they keep their types of vec3 and point3\n";
  EXPECT_EQ("point3", ptest1.type());
  EXPECT_EQ("vec3", test1.type());
}