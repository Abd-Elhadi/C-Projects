#include <iostream>
#include "Matrix.h"
#include "MatrixCalculator.h"
using namespace std;

template<class T>
void menu();


int correctChoice(){
    cout<<"Enter your choice: ";
    int choice; cin>>choice;
    if (cin.fail()){
        cout<<"Invalid input!"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        return correctChoice();
    }
    return choice;
}
void menu(){
    cout<<"Welcome to FCI Matrix Calculator"<<endl
        <<"------------------------------"<<endl
        <<"1- Perform Matrix Addition"<<endl
        <<"2- Perform Matrix Subtraction"<<endl
        <<"3- Perform Matrix Multiplication"<<endl
        <<"4- Matrix Transpose"<<endl
        <<"5- To exit"<<endl;
    int ch = correctChoice();
    if (ch == 5) {
        system("PAUSE");
        exit(0);
    }
    MatrixCalculator<int> newObj;
    newObj.matrixCalculator(ch);
}
int main(){
    while (true){
        menu();
    }
    /*
    int row1,row2,col1,col2;
    Matrix<int> b(row2,col2);
    Matrix<int> a(row1,col1);
    Matrix<int> d=a.addition(b);
    d.PrintMatrix();
    Matrix<int> f=a.subtraction(b);
    f.PrintMatrix();
    Matrix<int> c=a.Multiplication(b);
    c.PrintMatrix();

    int tran;
    cout<<"any matrix (transpose)"<<endl;
    cin>>tran;
    if(tran==1){
        Matrix<int> k=a.transpose();
        k.PrintMatrix();
    }
    else if(tran==2){
        Matrix<int> k=b.transpose();
        k.PrintMatrix();
    }
    */
}

