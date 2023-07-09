#ifndef MATRIX_H
#define MATRIX_H
#include "vec3.h"

class matrix{
    public:                                         //Public declaration
        double** matrix2;                           //Instantiation of matrix
        int n;                                      //size of the square matrix (nxn)
        int dim(){ return n; }                      //Method for getting the dimension of the matrix
        matrix(int dim) : n(dim){                   //Matrix constructor which takes in the dimension to dynamically allocate 
            matrix2 = new double*[n];               //Initialize an array of pointers of size n
            for(int i = 0; i < n; i++) {            //For each element in the pointers array,
                matrix2[i] = new double[n];         //set each of the elements in the array to a double array of size n
            }
        }

        matrix& operator=(const std::initializer_list<std::initializer_list<double>>& values) {         //Overloading the = operator to allow for an list of lists to initialize a matrix class
            if (values.size() != n) { throw std::invalid_argument("Invalid dimensions"); }              //Bounds check the matrix to ensure that the initializer matrix isn't too large
            for (int row = 0; row < n; row++) {                                                         //Iterate through all of the rows of the matrix
                if (values.begin()[row].size() != n){                                                   //
                    throw std::invalid_argument("Invalid dimensions"); 
                }
                for (int col = 0; col < n; col++){
                    matrix2[row][col] = values.begin()[row].begin()[col];
                }
            }
            return *this;
        }

        bool operator==(const matrix& m) const {
            for(int row = 0; row < n; row++){
                for(int col = 0; col < n; col++){
                    if(matrix2[row][col] != m.matrix2[row][col]){
                        return false;
                    }
                }
            }
            return true;
        }
        bool operator!=(const matrix& m) const { return !operator==(m); }
        matrix matrixMultiply(const matrix& A, const matrix& B) const {
            int dim = A.n;
            matrix C(dim);
            for(int row = 0; row < dim; row++){
                for(int col = 0; col < dim; col++){
                    C[row][col] = 
                    A.matrix2[0][col] + B.matrix2[0][col] +
                    A.matrix2[1][col] + B.matrix2[1][col] +
                    A.matrix2[2][col] + B.matrix2[2][col] +
                    A.matrix2[3][col] + B.matrix2[3][col];

                }
            }
            return C;
        }

        double* operator[](int index) {
            if (index < 0 || index >= n) { throw std::out_of_range("Invalid index"); }
                return matrix2[index];
        }
        


};

#endif