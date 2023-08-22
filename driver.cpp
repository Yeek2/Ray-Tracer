//To compile, do g++ -std=c++17 driver.cpp -o driver
//to run, do ./driver

#include <iostream>
#include "doth/vec3.h"
#include "doth/canvas.h"
#include <math.h>
using namespace std;

int main(){

     canvas c(80,20);
    //c.screenToPPM();

    //cout << "Hello world";
    point3 something(1,1,1);
    point3 something1(1,1,2);
    vec3 somethingg(1,1,1);
    
    point3 something3 = somethingg + something1;
cout << "Hello" << somethingg.w() << endl;
    

    cout << something1.x() << endl;
    cout << something1.y() << endl;
    cout << something1.z() << endl;
    cout << something1.w() << endl;

    cout << something3.x() << endl;
    cout << something3.y() << endl;
    cout << something3.z() << endl;
    cout << something3.w() << endl;

    cout << something3.type() << endl;
    cout << somethingg.w() << endl;
}