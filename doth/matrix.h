#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include "vec3.h"



class Matrix{
    public:                                         //Public declaration
        double** matrixx;                           //Instantiation of matrix pointer to pointer
        int n;                                      //size of the square matrix (n x n)
        int dim() const { return n; }               //Method for getting the dimension of the matrix
        Matrix(int dim) : n(dim){                   //Matrix constructor which takes in the dimension to dynamically allocate 
            matrixx = new double*[n];               //Initialize an array of pointers of size n
            for(int i = 0; i < n; i++) {            //For each element in the pointers array,
                matrixx[i] = new double[n];         //set each of the elements in the array to a double array of size n
            }
        }

        static const Matrix IDENTITY;

    Matrix(const std::initializer_list<std::initializer_list<double>>& values) {
        n = static_cast<int>(values.size());    //Get the number of rows from the initializer list
        matrixx = new double*[n];               //Allocate memory for the matrix based on the size 'n'
        for(int i = 0; i < n; i++) { matrixx[i] = new double[n]; }
        
        if (values.size() != n) { throw std::invalid_argument("Invalid dimensions, too many rows"); } //Bounds check the matrix to ensure that the initializer matrix isn't too large

        // Populate the matrix with values from the initializer list
        int row = 0;
        for (const auto& r : values) {
            if (r.size() != n) { throw std::invalid_argument("Invalid dimensions, too many columns"); }
            int col = 0;
            for (const auto& val : r) {
                matrixx[row][col] = val;
                col++;
            }
            row++;
        }
    }



        //Overloading the equals or assignment operator. This operator can take an initalizer list of initializer lists to assign a matrix inline, like so:
        // A = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };
        Matrix& operator=(const std::initializer_list<std::initializer_list<double>>& values) {         //Overloading the = operator to allow for an list of lists to initialize a matrix class
            if (values.size() != n) {throw std::invalid_argument("Invalid dimensions, too many rows");} //Bounds check the matrix to ensure that the initializer matrix isn't too large
            for (int row = 0; row < n; row++) {                                                         //Iterate through all of the rows of the matrix
                if (values.begin()[row].size() != n)                                                    //Check how many columns (how many elements in each row there are)
                    throw std::invalid_argument("Invalid dimensions, too many columns");                //Throw error
                for (int col = 0; col < n; col++){                                                      //For loop to iterate through all columns
                    matrixx[row][col] = values.begin()[row].begin()[col];                               //Assign them properly 
                }
            }
            return *this;                                                                               //Return the instantiated matrix
        }

        bool operator==(const Matrix& m) const {                                                        //Equality operator overload
            for(int row = 0; row < n; row++){                                                           //Iterate through rows
                for(int col = 0; col < n; col++){                                                       //Iterate through columns
                    if(matrixx[row][col] != m.matrixx[row][col]){                                       //Check if they're not equal
                        return false;                                                                   //Return false if they aren't
                    }
                }
            }
            return true;                                                                                //If they made it here, return true
        }
        bool operator!=(const Matrix& m) const { return !operator==(m); }                               //Not equal operator, run the equal operator and invert it

        

        double* operator[](int index) {
            if (index < 0 || index >= n) { throw std::out_of_range("Invalid index"); }
                return matrixx[index];
        }
        double* operator[](int index) const{
            if (index < 0 || index >= n) { throw std::out_of_range("Invalid index"); }
                return matrixx[index];
        }
};

Matrix matrixMultiply(const Matrix& A, const Matrix& B) {                                               //Operation to element-wise multiply matrices together
            int dim = A.n;                                                                              //Set the dimension of the new matrix to be the same as one of the input matrices
            if (dim != 4) {throw std::invalid_argument("Matrix must be 4 x 4");}                        //Ensure matrix is of dim(4)
            Matrix C(dim);                                                                              //Create a new matrix with the same dimension
            for(int row = 0; row < dim; row++){                                                         //Iterate through rows
                for(int col = 0; col < dim; col++){                                                     //Iterate through columns
                    C[row][col] =                                                                       //Set each element of the C matrix
                    A.matrixx[row][0] * B.matrixx[0][col] +                                             //
                    A.matrixx[row][1] * B.matrixx[1][col] +
                    A.matrixx[row][2] * B.matrixx[2][col] +
                    A.matrixx[row][3] * B.matrixx[3][col];

                }
            }
            return C;
}

const Matrix Matrix::IDENTITY = { 
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
};

std::vector<double> matrixMultiply(const Matrix& A, std::vector<double> b) {
    int dim = A.n;
    
    if (dim != 4) throw std::invalid_argument("Matrix must be 4 x 4");
    std::vector<double> c(dim, 0.0);
    
    for (int row = 0; row < dim; row++) {
        c[row] =
            A.matrixx[row][0] * b[0] +
            A.matrixx[row][1] * b[1] +
            A.matrixx[row][2] * b[2] +
            A.matrixx[row][3] * b[3];
    }
    
    return c;
}

Matrix transpose(Matrix& m){
    int n = m.dim();
    Matrix c = Matrix(n);
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            c[col][row] = m[row][col];
        }
    }
    return c;
}

int determinant2x2(const Matrix& m){
    int n = m.n;
    if(n != 2) throw std::invalid_argument("Function only works on 2x2 matrices");
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
}

Matrix subMatrix(const Matrix& m, int rowDelete, int colDelete){
    int n = m.dim();
    Matrix subM(n - 1);
    int subRow = 0;
    for(int row = 0; row < n; row++){
        if(row == rowDelete) continue;
        int subCol = 0;
        for(int col = 0; col < n; col++){
            if(col == colDelete) continue;
            subM[subRow][subCol] = m[row][col];
            subCol++;
        }
        subRow++;
    }
    return subM;
}

int minor3x3(const Matrix& m, int rowDelete, int colDelete){
    Matrix minor = subMatrix(m, rowDelete, colDelete);
    return determinant2x2(minor);
}

#endif