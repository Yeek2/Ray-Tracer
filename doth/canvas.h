#ifndef CANVAS_H
#define CANVAS_H
#include "vec3.h"
#include <iostream>
#include <fstream>

class canvas{
    public:
    int width;                                      //Width of canvas
    int height;                                     //Height of canvas
    color** screen;                                 //Pointer to pointer of colors

    canvas(int h, int w) : width(w), height(h){     //Canvas constructor
        screen = new color*[height];                //Set the pointer to an array of pointers (2D array) to dynamically allocate a matrix
        for (int i = 0; i < height; i++) {          //Traverse through all of the rows (height) of the matrix 
            screen[i] = new color[width];           //Set each row to be of width width, or to have width columns
        }
    }

    ~canvas() {                                     //Canvas destructor
        for (int i = 0; i < height; i++){           //Iterate through the rows
            delete[] screen[i];                     //Delete each element
        }
        delete[] screen;                            //Delete the entire class
    }

    void writePixel(int x, int y, color c){         
        if (x >= 0 && x < width && y >= 0 && y < height){ screen[y][x] = c; }
    }

    color pixelAt(int x, int y) {
        if (x >= 0 && x < width && y >= 0 && y < height){ return screen[y][x]; }
        return color(0.0, 0.0, 0.0);
    }

    void screenToPPM(){                                                                 //Function to convert the screen/canvas to a PPM file
            std::ofstream outputFile("rendering.ppm");                                  //Output everything to a file called rendering
            outputFile << "P3" << std::endl;                                            //Some PPM formatting things, begin with P3
            outputFile << width << " " << height << std::endl;                          //Record the width and the height of the image
            outputFile << 255 << std::endl;                                             //255 = max color value
            for(int i = 0; i < height; i++){                                            //Begin double for loop to iterate through all elements of the 2D matrix, iterate through the rows of the matrix
                for(int j = 0; j < width; j++){                                         //Begin the second part of the double for loop to iterate through the columns of the matrix
                    outputFile << static_cast<int>(screen[i][j].red() * 255) << " ";
                    outputFile << static_cast<int>(screen[i][j].green() * 255) << " ";
                    outputFile << static_cast<int>(screen[i][j].blue() * 255) << " ";
                          //Output the value of the screen multiplied by 255
                }
                outputFile << std::endl;                                                //Create a newline/break for every single row of the matrix
            }
            outputFile << "\n";                                                         //End the PPM file with a newline character "\n"
    }      
};

#endif