//To compile, do g++ -std=c++17 driver.cpp
//to run, do ./a.out

#include <iostream>
#include "vec3.h"
#include "canvas.h"
using namespace std;

int main(){
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