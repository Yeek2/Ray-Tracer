#ifndef CANVAS_H
#define CANVAS_H
#include "vec3.h"
#include <iostream>
#include <fstream>

class canvas{
    public:
        static const int MAX_HEIGHT = 2160;
        static const int MAX_WIDTH = 3840;
        int width;
        int height;
        color screen[MAX_HEIGHT][MAX_WIDTH];
        canvas(int h, int w) : height(h), width(w) { color screen[height][width]; };
        void writePixel(int x, int y, color c){ screen[y][x] = c; }
        color pixelAt(int x, int y){ return screen[y][x]; }

        void screenToPPM(){
            std::ofstream outputFile("rendering.ppm");
            outputFile << "P3" << std::endl;
            outputFile << width << " " << height << std::endl;
            outputFile << 255 << std::endl;
            for(int i = 0; i < height; i++){
                for(int j = 0; j < width; j++){
                    outputFile << (screen[i][j] * 255) << " ";
                }
                outputFile << std::endl;
            }
            outputFile << "\n";
        }

};

#endif