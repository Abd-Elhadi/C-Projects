#include <bits/stdc++.h>
#include "Fraction.h"
#include "FractionCalculator.h"
using namespace std;

int correctChoice(){
    int _choice;
    cout<<"Enter your choice: ";
    cin>>_choice;
    if (cin.fail()){
        cout<<"Invalid choice!"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        return correctChoice();
    }
    else return _choice;
}

void menu(){
    cout<<"Welcome to FCI Fraction Calculator"<<endl<<"----------------------------------"<<endl
        <<"1- Perform Fraction Addition"<<endl
        <<"2- Perform Fraction Subtraction"<<endl
        <<"3- Perform Fraction Multiplication"<<endl
        <<"4- Perform Fraction division"<<endl
        <<"5- Exit"<<endl;
    int ch = correctChoice();
    FractionCalculator newObj;
    newObj.calculator(ch);
}

int main(){
    while (true){
        menu();
        system("PAUSE");
        system("CLS");
    }
}
