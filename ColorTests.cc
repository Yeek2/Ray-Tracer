//To make the test exe: g++ -std=c++17 ColorTests.cc -lgtest -lgtest_main -o b
//To run: ./a

#include <gtest/gtest.h>
#include <math.h>
#include "vec3.h"
#include "canvas.h"



TEST(ColorTests, BasicAssertions){
    std::cout << "Basic color assertions and types\n";
    color testColor(-0.5, 0.4, 1.7);
    EXPECT_EQ(testColor.red(), -0.5);
    EXPECT_EQ(testColor.green(), 0.4);
    EXPECT_EQ(testColor.blue(), 1.7);
    EXPECT_EQ(testColor.type(), "color");
}

color c1(0.9, 0.6, 0.75);
color c2(0.7, 0.1, 0.25);

TEST(ColorTests, ColorAddition){
    std::cout << "Adding colors\n";
    EXPECT_EQ(c1 + c2, color(1.6, 0.7, 1.0));
}

TEST(ColorTests, ColorSubtraction){
    std::cout << "Subtracting colors\n";
    EXPECT_EQ(c1 - c2, color(0.2, 0.5, 0.5));
}

TEST(ColorTests, ColorMultiplication){
    std::cout << "Multiplying colors by a scalar\n";
    EXPECT_EQ(color(0.2, 0.3, 0.4) * 2, color(0.4, 0.6, 0.8));
    std::cout << "Multiplying colors by one another\n";
    EXPECT_EQ(color(1, 0.2, 0.4) * color(0.9, 1, 0.1), color(0.9, 0.2, 0.04));
}

canvas c(10,20);
TEST(CanvasTests, BasicCanvasTests){
    std::cout << "Crating a canvas\n";
    EXPECT_EQ(c.width, 20);
    EXPECT_EQ(c.height, 10);

    std::cout << "Check all pixels are of color(0,0,0)\n";
    int counter = 0;
    for(int i = 0; i < c.height; i++){
        for(int j = 0; j < c.width; j++){
            counter++;
            EXPECT_EQ(c.screen[i][j], color(0,0,0));
        }
    }
    EXPECT_EQ(200, counter);
}

TEST(CanvasTests, WritingColors){
    color red(1,0,0);
    //c.writePixel(2, 3, red);
    std::cout << red << std::endl;
    for(int i = 0; i < c.height; i++){
        for(int j = 0; j < c.width; j++){
            std::cout << c.screen[i][j]*255 << "|";
        }
        std::cout << std::endl;
    }
    //std::cout << c.pixelAt(2,3) << std::endl;
    //EXPECT_EQ(c.pixelAt(2,3), red);
}

TEST(CanvasTests, CanvasOutput){
    canvas c(0,0);
    //c.screenToPPM();
    EXPECT_EQ(0,0);
}