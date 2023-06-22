#ifndef MATRIX_H
#define MATRIX_H
#include "vec3.h"

class matrix{
    public:                     //Public declaration
        double** matrix2;
        int n;
        int dim(){ return n; }
        matrix(int dim) : n(dim){
            matrix2 = new double*[n];
            for(int i = 0; i < n; i++) {
                matrix2[i] = new double[n];
            }
        }

        matrix& operator=(const std::initializer_list<std::initializer_list<double>>& values) {
            if (values.size() != n) { throw std::invalid_argument("Invalid dimensions"); }
            for (int row = 0; row < n; row++) {
                if (values.begin()[row].size() != n){ 
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