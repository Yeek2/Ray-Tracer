//To compile, do: g++ -std=c++17 vec3.h   
#ifndef VEC3_H              //Declare header file
#define VEC3_H              //Define header file
#include <iostream>         //The classic, include iostream for some basic functionality

class vec3{
    public:
        /* VARIABLES SECTION */
        double v[4];                                                    //Array to hold three points
        constexpr static double EPSILON = 0.00001;                      //Declare a constant to compare floating point numbers
        /* END VARIABLES SECTION */
    private:
        static bool equals(double a,double b){ return (abs(a - b) < EPSILON) ?  true : false; }     //Function to check equality with a margin of error
        vec3(double e0, double e1, double e2, double e3) : v{e0, e1, e2, e3} {};                    //Private constructor to set all values of the array rather than only the first three                   
    public:
        
        /* FUNCTIONS SECTION */
        vec3() : v{0, 0, 0, 0} {}                                       //Default constructor
        vec3(double e0, double e1, double e2) : v{e0, e1, e2, 0} {}     //Parameterized constructor
        
        double x() const { return v[0]; }                               //Get the first element of the array
        double y() const { return v[1]; }                               //Get the second element of the array
        double z() const { return v[2]; }                               //Get the third element of the array
        double w() const { return v[3]; }                               //Get the fourth element of the array

        std::string type() const {                                      //Function to determine the type of the object
            switch(int(v[3])){                                          //Instantiate a switch statement which casts the fourth element of the array to an integer for comparison
                case 0:                                                 //Zero corresponds to a vector
                    return "vec3";                                      //Return type "vec3"
                break;                                                  //Escape the switch statement
                case 1:                                                 //One corresponds to a point
                    return "point3";                                    //Return type "point3"
                break;                                                  //Escape switch statement
                default:                                                //Fall through case, for example if a point is added to another point and the fourth element becomes two
                    return "unknown";                                   //Type is unknown, return "Unknown"
            }                                                           //End switch statement
            return "unknown";                                           //If it somehow got here, return the type as unknown
        }

        vec3    operator+(const vec3& ve)   const { return vec3(v[0] + ve.v[0], v[1] + ve.v[1], v[2] + ve.v[2], v[3] + ve.v[3]); }                              //Overload "+" operator to element-wise add each element of the array together, returning a new vector in the process so that point3s & vec3s aren't cast into one another
        vec3    operator-(const vec3& ve)   const { return vec3(v[0] - ve.v[0], v[1] - ve.v[1], v[2] - ve.v[2], v[3] - ve.v[3]); }                              //Overload "-" operator to element-wise subtract each element of the array together, returning a new vector in the process so that point3s & vec3s aren't cast into one another and type is maintained
        vec3    operator*(const vec3& ve)   const { return vec3(v[0] * ve.v[0], v[1] * ve.v[1], v[2] * ve.v[2], v[3]); }                                        //Overload "*" operator to element-wise multiply each element of the array together (schur product) returning a new vector in the process so that point3s & vec3 aren't cast into one another
        vec3    operator*(const double ve)  const { return vec3(v[0] * ve, v[1] * ve, v[2] * ve, v[3]); }                                                       //Overload "*" operator to multiply the entire array by a constant scalar value
        vec3    operator/(const double ve)  const { return vec3(v[0] / ve, v[1] / ve, v[2] / ve, v[3]); }                                                       //Overload "/" operator to divide the entire array by a constant scalar value
        bool    operator==(const vec3& ve)  const { return equals(v[0], ve.v[0]) && equals(v[1], ve.v[1]) && equals(v[2], ve.v[2]) && equals(v[3], ve.v[3]); }  //Overload "==" operator to compare element-wise each element of the array by calling the equals function, which allows for a slight epsilon delta for rounding floating point numbers
        vec3&   operator=(const vec3& ve)         { v[0] = ve.v[0]; v[1] = ve.v[1]; v[2] = ve.v[2];    return *this; }                                          //Overload "=" operator to element-wise set all of the elements of one point3/vec3 to another
        friend std::ostream& operator<<(std::ostream& out, const vec3& ve) { return out << ve.v[0] << ' ' << ve.v[1] << ' ' << ve.v[2]; }                       //Overload "<<" operator to element-wise print out the entire array
        inline vec3& operator-(){ v[0] = -v[0]; v[1] = -v[1]; v[2] = -v[2]; return *this; }                                                                     //Overload "-" operator to element-wise negate the elements in the array
        vec3&   operator+=(const vec3& ve){       //Overload += opereator 
            v[0] += ve.v[0];                      //Add element 0 to this
            v[1] += ve.v[1];                      //Add element 1 to this
            v[2] += ve.v[2];                      //Add element 2 to this
            return *this;                         //Return *this, a modified version rather than a new instance of the class
        }
         vec3&   operator-=(const vec3& ve){      //Overload -= operator
            v[0] -= ve.v[0];                      //Subtract element 0 to this
            v[1] -= ve.v[1];                      //Subtract element 1 to this
            v[2] -= ve.v[2];                      //Subtract element 2 to this
            return *this;                         //Return *this, a modified version rather than a new instance of the class
        }
        vec3&   operator*=(const vec3& ve){       //Overload *= operator when multiplied by another vec3 object
            v[0] *= ve.v[0];                      //Multiply element 0 to this
            v[1] *= ve.v[1];                      //Multiply element 1 to this
            v[2] *= ve.v[2];                      //Multiply element 2 to this
            return *this;                         //Return *this, a modified version rather than a new instance of the class
        }
        vec3&   operator*=(const double ve){      //Overload *= operator when multiplied by a scalar
            v[0] *= ve;                           //Multiply ve to first element 
            v[1] *= ve;                           //Multiply ve to second element
            v[2] *= ve;                           //Multiply ve to third element
            return *this;                         //Return *this, a modified version rather than a new instance of the class
        }
        vec3&   operator/=(const double ve){      //Overload /= operator when divided by a scalar
            v[0] /= ve;                           //Divide first element by ve
            v[1] /= ve;                           //Divide second element by ve
            v[2] /= ve;                           //Divide third element by ve
            return *this;                         //Return *this, a modified version rather than a new instance of the class
        }
        vec3& normalize(){                        //Function to nomalize vectors
            double normal = 1/sqrt(v[0] * v[0] +  //Set the normal, square the first element
                                   v[1] * v[1] +  //Square the second element
                                   v[2] * v[2]);  //Square the third element
            v[0] *= normal;                       //Multiply the first element by the normal
            v[1] *= normal;                       //Multiply the second element by the normal
            v[2] *= normal;                       //Multiply the third element by the normal
            return *this;
        }
        double magnitude() const{ return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]); }                                       //Take the magnitude of the vector and return it
        inline static double dot(const vec3& a, const vec3& b){ return a.v[0] * b.v[0] + a.v[1] * b.v[1] + a.v[2] * b.v[2]; }   //Take the dot product of two vectors and return the scalar
        inline static vec3 cross(const vec3& a, const vec3& b){                                                                 //Take the cross product of two vectors
            return vec3(a.v[1] * b.v[2] - a.v[2] * b.v[1],                                                                      //First part of the r3 cross product
                        a.v[2] * b.v[0] - a.v[0] * b.v[2],                                                                      //Second
                        a.v[0] * b.v[1] - a.v[1] * b.v[0]);                                                                     //& third
        }

        
};

class point3 : public vec3{                                                              //point3 is a child of vec3                   
    public:                                                                              //Public methods/constructors
        point3() : vec3() { v[3] = 1; }                                                  //Default constructor, overload the fourth element in the array to be 1
        point3(double e0, double e1, double e2) : vec3(e0, e1, e2) { v[3] = 1; }         //Parameterized constructor, overload the fourth element in the array to be 1
        point3(const vec3 other) : vec3(other.v[0], other.v[1], other.v[2]) { v[3] = 1; }//Typecasting a vector to a point, return a new vector such that the fourth element in the array is 1
};                                                                                       //End class declaration

class color : public vec3{                                                      //class color is a child of vec3
    public:                                                                     //Public methods/constructors of color
        color() : vec3() {}                                                     //An empty instantiation of color is the same as an empty instantiation of a vec3 object                                                                          
        color(double e0, double e1, double e2) : vec3(e0, e1, e2) {}            //Parameterized constructor, same as the vec3 class
        color(const vec3 other) : vec3(other.v[0], other.v[1], other.v[2]) {}   //Typecast a color to a vec3 obejct for comparison and such
        double red()    const { return v[0]; }                                  //Method alias for the first value in the array
        double green()  const { return v[1]; }                                  //Method alias for the second value in the array
        double blue()   const { return v[2]; }                                  //Method alias for the third value in the array
        std::string type(){ return "color"; }                                   //Overload type to be of type "color"
        color hadamardProduct(const color& c1, const color& c2) const { return color(c1.v[0] * c2.v[0], c1.v[1] * c2.v[1], c1.v[2] * c2.v[2]); }//Hadamard product, element-wise multiply the array with the other array
        color schurProduct(const color& c1, const color& c2) const { return hadamardProduct(c1, c2); }                                          //Schur product, another name for the Hadamard product, in case one forgets the name of Hadamard Product
};                                                                              //End class declaration

#endif                                                                          //Endif