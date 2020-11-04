#ifndef MATRIXCALCULATOR_H
#define MATRIXCALCULATOR_H
#include "Matrix.h"
template<class T>
class MatrixCalculator{
public:
    void matrixCalculator(int choice){
        if (choice == 4){
            cout<<"Enter a matrix to get its transpose"<<endl
                <<"enter matrix row and column: ";
            int r,c; cin>>r>>c;
            Matrix<T> _thirdMatrix(r,c);
            for (int i=0; i<r; ++i){
                for (int j=0; j<c; ++j)
                    cin>>_thirdMatrix[i][j];
            }
            _thirdMatrix = _thirdMatrix.transpose();
            cout<<"Transpose matrix"<<endl;
            for (int i=0; i<r; ++i){
                for (int j=0; j<c; ++j){
                    cout<<_thirdMatrix[i][j]<<" ";
                }
            cout<<endl;
            }
        }
        else {
            Matrix<T> thirdMatrix;
            int row1,row2,column1,column2;
            cout<<"your first matrix row and col: ";
            cin>>row1>>column1;
            Matrix<T> firstMatrix(row1,column1);
            cout<<"Enter the matrix"<<endl;

            for (int i=0; i<row1; i++){
                for (int j=0; j<column1; j++){
                    cin>>firstMatrix[i][j];
                }
            }
            cout<<"your second matrix row and col: ";
            cin>>row2>>column2;
            Matrix<T> secondMatrix(row2,column2);
            cout<<"Enter the matrix"<<endl;

            for (int i=0; i<row2; i++){
                for (int j=0; j<column2; j++){
                    cin>>secondMatrix[i][j];
                }
            }
            if (choice == 1){
                thirdMatrix = thirdMatrix.add(firstMatrix, secondMatrix);
                //thirdMatrix = firstMatrix.addition(secondMatrix);
                cout<<"The resulted matrix"<<endl;
                for (int i=0; i<row1; ++i){
                    for (int j=0; j<column1; ++j){
                        cout<<thirdMatrix[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else if (choice == 2){
                thirdMatrix = thirdMatrix.subtract(firstMatrix, secondMatrix);
                //thirdMatrix = firstMatrix.subtraction(secondMatrix);
                cout<<"The resulted matrix"<<endl;
                for (int i=0; i<row1; ++i){
                    for (int j=0; j<column1; ++j){
                        cout<<thirdMatrix[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else if (choice == 3){
                thirdMatrix = thirdMatrix.Multiply(firstMatrix, secondMatrix);
                //thirdMatrix = firstMatrix.Multiplication(secondMatrix);
                cout<<"The resulted matrix"<<endl;
                for (int i=0; i<row1; ++i){
                    for (int j=0; j<column1; ++j){
                        cout<<thirdMatrix[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
            else if (choice == 5){
                exit(0);
                system("PAUSE");
            }
            else cout<<"Invalid choice"<<endl;
        }
    }
    private:
};

#endif // MATRIXCALCULATOR_H
