#include <bits/stdc++.h>
#include "BigDecimalInt.h"
using namespace std;

///to keep track the number of operations performed so far
int counter = 0;

///to get a correct choice for an operation
int choice(){
    cout<<"Enter your choice: ";
    int _choice; cin>>_choice;
    if (cin.fail()){
        cout<<"Invalid input!"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        return choice();
    }
    else return _choice;
}
///menu function that perform requires operation
void menu(){
    cout<<"Welcome to FCI Calculator"<<endl
        <<"-------------------------"<<endl
        <<"1- Perform Addition"<<endl
        <<"2- Perform Subtraction"<<endl
        <<"3- Exit"<<endl;
        int ch = choice();
        string fnumber, snumber;
        BigDecimalInt obj;///to perform the operation on it
        if (ch == 1){
            cout<<"Enter first number: ";cin>>fnumber;
            cout<<"Num1: "<<fnumber<<endl;
            cout<<"Enter second number: "; cin>>snumber;
            cout<<"Num2: "<<snumber<<endl;
            BigDecimalInt obj1(fnumber), obj2(snumber), obj3;
            ///before proceeding further we want to make sure both numbers are positive
            if (fnumber[0] != '-' && snumber[0] != '-')
                //cout<<"The result of the operation is: "<<obj1 + obj<<endl;
                cout<<"The result of the operation is: "<<obj.addTwoBigInt(fnumber,snumber)<<endl;
            ///if both numbers are negative we will perform addition on them
            ///and add negative sign on the result
            else if (fnumber[0] == '-' && snumber[0] == '-'){
                fnumber.erase(fnumber.begin());
                snumber.erase(snumber.begin());
                string res = obj.addTwoBigInt(fnumber,snumber);
                reverse(res.begin(), res.end());///revers it to add negative sign at the end
                res.push_back('-');///add negative sign at the end of result
                reverse(res.begin(), res.end());///reverse it back
                cout<<"The result of the operation is: "<<res<<endl;
            }
            ///if the first number its first char is '-'
            ///then we will just subtract the second number from the fist one
            else if (fnumber[0] == '-'){
                fnumber.erase(fnumber.begin());
                cout<<"The result of the operation is: "<<obj.subtractTwoBigInt(snumber,fnumber)<<endl;
            }
            ///if the second number its first char is '-'
            ///then we will just subtract the first number from the second one
            else if (snumber[0] == '-'){
                snumber.erase(snumber.begin());
                cout<<"The result of the operation is: "<<obj.subtractTwoBigInt(fnumber,snumber)<<endl;
            }
            counter++;
        }
        ///subtract the second number from the first number
        else if (ch == 2){
            cout<<"Enter first number: ";cin>>fnumber;
            cout<<"Num1: "<<fnumber<<endl;
            cout<<"Enter second number: "; cin>>snumber;
            cout<<"Num2: "<<snumber<<endl;
            ///before proceeding further we want to make sure both numbers are positive
            if (fnumber[0] != '-' && snumber[0] != '-')
                cout<<"The result of the operation is: "<<obj.subtractTwoBigInt(fnumber,snumber)<<endl;
            else if (fnumber[0] == '-' && snumber[0] == '-'){
                fnumber.erase(fnumber.begin());
                snumber.erase(snumber.begin());
                string res = obj.addTwoBigInt(fnumber,snumber);
                reverse(res.begin(), res.end());///revers it to add negative sign at the end
                res.push_back('-');///add negative sign at the end of result
                reverse(res.begin(), res.end());///reverse it back
                cout<<"The result of the operation is: "<<res<<endl;
            }
            else if (fnumber[0] == '-'){
                fnumber.erase(fnumber.begin());
                cout<<"The result of the operation is: "<<obj.subtractTwoBigInt(snumber,fnumber)<<endl;
            }
            ///if the second number its first char is '-'
            ///then we will just subtract the first number from the second one
            else if (snumber[0] == '-'){
                snumber.erase(snumber.begin());
                cout<<"The result of the operation is: "<<obj.subtractTwoBigInt(fnumber,snumber)<<endl;
            }
            counter++;
        }
        ///exit the program
        else if (ch == 3){
            if (counter>0){
                system("CLS");
                cout<<"Thank you for using our calculator."<<endl
                    <<"You had performed: "<<counter<<", operations with it."<<endl;
            }
            system("PAUSE");
            exit(0);
        }
        else cout<<"Invalid choice"<<endl;
}

int main(){
    while (true){
        menu();
        system("PAUSE");
        system("CLS");
    }
}
