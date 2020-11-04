#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
//template<auto, class T = decay_t<decltype(*object)>>
template <class T>
class Matrix {
public:
    Matrix(){
        row=0;
        column=0;
    }
    Matrix(int row,int column){
        this->row=row;
        this->column=column;
        container = new T*[row];
        for(int i=0; i<row; i++)
            container[i] = new T[column]();
    }
    T* operator [] (int index) {
        return container[index];
    }
    friend istream& operator >>(istream& input, Matrix& another);
    friend ostream& operator <<(ostream& output, Matrix& another);

    ///copy constructor
    Matrix(const Matrix& m){
        this->row=m.row;
        this->column=m.column;
        container=new T*[row];
        for(int i=0;i<row;i++) container[i]=new T[column];
            for(int i=0;i<row;i++)
                for(int j=0;j<column;j++)
                    container[i][j]=m.container[i][j];
    }
    ///initialize matrix's row and column
    void initializeMatrix(int _row, int _column){
        this-> row = _row;
        this-> column = _column;
        container = new T*[row];
        for(int i=0; i < _row; i++)
            container[i] = new T[_column];
    }
    ///adding two matrices
    Matrix add(Matrix& mat1, Matrix& mat2){
        Matrix<T> _another;
        if (mat1.column == mat2.column && mat1.row == mat2.row){
            _another.initializeMatrix(mat1.row, mat1.column);
            for(int i = 0; i < mat1.row;i ++){
                for(int j=0; j < mat2.column; j++){
                    _another.container[i][j] = 0; ///base
                    _another.container[i][j] = mat1.container[i][j] + mat2.container[i][j];
                }
            }
            return _another;
        }
        else {
            cout<<"The two matrices should have the same dimensions"<<endl
                <<"First matrix will be printed"<<endl;
            return mat1;
        }
    }
    ///subtraction two matrices
    Matrix subtract(Matrix& mat1, Matrix& mat2){
        Matrix<T> _another;
        if (mat1.column == mat2.column && mat1.row == mat2.row){
            _another.initializeMatrix(mat1.row,mat1.column);
            for(int i = 0; i < mat1.row;i ++){
                for(int j=0; j < mat2.column; j++){
                    //_another.container[i][j] = 0;
                    _another.container[i][j] = mat1.container[i][j] - mat2.container[i][j];
                }
            }
            return _another;
        }
        else {
            cout<<"The two matrices should have the same dimensions"<<endl
                <<"First matrix will be printed"<<endl;
            return mat1;
        }
    }
    ///Multiply two matrices
    Matrix Multiply (Matrix& mat1, Matrix& mat2){
        if(mat1.column != mat2.row) {
            cout<<"No matching for matrix multiplication"<<endl
                <<"First matrix will be printed instead"<<endl;
            return mat1;
        }
        else {
            //mat1 row = a
            //mat1 col = b
            //mat2 row = c
            //mat2 col = d
            Matrix _another;
            _another.initializeMatrix(mat1.row, mat2.column);
            for(int i = 0; i < mat1.row; i++){
                for(int j = 0; j < mat2.column; j++){
                    for(int k = 0; k < mat2.row; k++){
                        //_another.container[i][j] = 0;
                        _another.container[i][j] += mat1.container[i][k] * mat2.container[k][j];

                    }
                }
            }
            return _another;
        }
    }
    /*
    ///add two matrices
    Matrix addition(Matrix& another){
        if (column==another.column || row==another.row){
            Matrix<T> _another;
            _another.initializeMatrix(row,column);
            for(int i=0;i<row;i++){
                for(int j=0;j<column;j++){
                    _another.container[i][j]=0; ///base
                    _another.container[i][j] = container[i][j] + another.container[i][j];
                }
            }
            return _another;
        }
        else{
            std::cout<<"No matching for matrix addition"<<std::endl;
            return another; ///should return something i need to stop this
        }
    }
    ///subtract two matrices
    Matrix subtraction(Matrix& another) {
        if (column==another.column || row==another.row){
            Matrix<T> _another;
            _another.initializeMatrix(row,column);
            for(int i=0;i<row;i++){
                for(int j=0;j<column;j++){
                    _another.container[i][j]=0;
                    _another.container[i][j]=container[i][j]-another.container[i][j];
                }
            }
        return _another;
        }
        else{
            std::cout<<"No matching for matrix subtraction"<<std::endl;
            return another;
        }
    }
    ///Multiply two matrices
    Matrix Multiplication (Matrix& another){
        if(column!=another.row) {
            std::cout<<"No matching for matrix multiplication"<<std::endl;
            return another;
        }
        else{
            Matrix _another;
            _another.initializeMatrix(row,column);
            for(int i=0;i<row;i++){
                for(int j=0;j<another.column;j++){
                    _another.container[i][j]=0;
                    for(int k=0; k<column; k++)
                        _another.container[i][j]+=container[i][k]*another.container[k][j];
                }
            }
            return _another;
        }
    }
    */
    ///transpose matrix
    Matrix transpose (){
        Matrix<T> another;
        another.initializeMatrix(row,column);
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                another.container[i][j]=container[j][i];
            }
        }
        return another;
    }
    ///print matrix data
    void PrintMatrix(){
        for(int i=0; i<this->row; i++){
            for(int j=0; j<this->column; j++)
            std::cout<<this->container[i][j]<<" ";
            std::cout<<std::endl;
        }
    }
    ///destructor to free the allocated memory
    ~Matrix(){
        for(int i=0;i<row;i++)
            delete[] container[i];
        delete[] container;
    }
    private:
    T** container;
    int row, column;
};

template<class T>
istream& operator >>(istream& input, Matrix<T>& another){
    for (int i=0; i<another.row; ++i){
        Matrix<T> newMatrix;
        input>>newMatrix;
        another.container[i] = newMatrix;
    }
    return input;
}
template<class T>
ostream& operator <<(ostream& output, Matrix<T>& another){
    for (int i=0; i<another.row; ++i){
        for (int j=0; j<another.column; j++){
            output<<another.container[i][j]<<" ";
        }
        output<<endl;
    }
}
/*
for(int i=0;i<row;i++){
    for(int j=0;j<column;j++)
        std::cin>>container[i][j];
}
*/
#endif // MATRIX_H
