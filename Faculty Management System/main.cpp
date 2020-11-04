//Abd Elhadi Omar ID: 20180373
#include <bits/stdc++.h>
#include "FCAIVector.h"
using namespace std;

template<class T>
FCAIVector<T> myVector;

void myMenu();

//function to returns the chosen list to be created
int menu(){
    cout<<"Insert type of vector you would like to create"<<endl
        <<"1. list of integer"<<endl
        <<"2. list of character"<<endl
        <<"3. list of string"<<endl
        <<"4. list of float"<<endl
        <<"5. list of students"<<endl
        <<"6. Exit"<<endl
        <<"your choice: ";
        int iChoice; cin>>iChoice;
        if (cin.fail()){
            system("CLS");
            cout << "You should enter correct value" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return menu();
        }
        system("CLS");
        return iChoice;
}
//function returns the chosen operation on the created list above
int operation(){
    cout<<"What kind of operation would you like to perform?"<<endl
        <<"1. Add element."<<endl
        <<"2. Remove last element."<<endl
        <<"3. Insert element at certain position."<<endl
        <<"4. Erase element from a certain position."<<endl
        <<"5. Clear."<<endl
        <<"6. Display first element."<<endl
        <<"7. Display last element."<<endl
        <<"8. Display element at certain position."<<endl
        <<"9. Display vector size."<<endl
        <<"10. Display vector capacity."<<endl
        <<"11. Is empty?"<<endl
        <<"your choice: ";
        int iChoice; cin>>iChoice;
        if (cin.fail()){
            system("CLS");
            cout << "You should enter correct value" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return operation();
        }
    return iChoice;
}

template<class T>
void administration(FCAIVector<T> &theVector){
    while(true){
        T newelement;
        T *ptr;
        int _index=0;
        int numberofelement;
        int oper = operation();//gets the required operation
        if (oper==1){
            system("CLS");
            Elemements:
            cout<<"How many elements you would like to add? ";
            cin>>numberofelement;
            if (cin.fail()){
                cout << "You should enter correct value" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                goto Elemements;
            }
            cin.ignore();
            cout<<"Enter elements"<<endl;
            for (int i=0; i<numberofelement; ++i){
                cout<<i+1<<"th element: ";
                cin>>newelement;
                myVector<T>.push(newelement);
            }
            cout<<"Size: "<<myVector<T>.Size()<<endl;
        }
        else if(oper==2){
            system("CLS");
            //check if the vector contains an element already or not
            if (myVector<T>.Size()>0){
                myVector<T>.pop();
                cout<<"Last element has been removed successfully"<<endl;
            }
            else
                cout<<"The container is empty"<<endl;
        }
        else if(oper==3){
            cout<<"enter index: "; cin>>_index;
            ptr = myVector<T>.Begin() + _index - 1;
            cout<<"Enter element"<<endl;
            cin>>newelement;
            myVector<T>.Insert(newelement,ptr);
            cout<<"The element has been inserted successfully"<<endl;
        }
        else if(oper==4){
            cout<<"enter the index: "; cin>>_index;
            ptr = myVector<T>.Begin() + _index - 1;
            if (ptr < myVector<T>.Begin() || ptr > myVector<T>.End()-1) cout<<"index out of range"<<endl;
            else if (myVector<T>.Size()>0){
                myVector<T>.Erase(ptr);
                cout<<"Element "<<*ptr<<" has been deleted"<<endl;
            }
            else cout<<"The container is empty"<<endl;
        }
        else if(oper==5){
            if (myVector<T>.Size()<1)
                cout<<"The vector is already empty"<<endl;
            else{
                myVector<T>.Clear();
                cout<<"Size: "<<myVector<T>.Size()<<endl;
            }
        }
        else if (oper==6){
            system("CLS");
            if (myVector<T>.Size()>0){
                cout<<"First element is: "<<myVector<T>[0]<<endl;
            }
            else cout<<"sorry. the container is empty"<<endl;
        }
        else if (oper==7){
            system("CLS");
            if (myVector<T>.Size()>0) cout<<"Last element is: "<<myVector<T>[myVector<T>.Size()-1]<<endl;
            else cout<<"sorry. the container is empty"<<endl;
        }
        else if (oper==8){
            cout<<"enter an index to show its corresponding element: "; int _index; cin>>_index;
            if (myVector<T>.Size()<1) cout<<"The container is empty"<<endl;
            else if (_index<=myVector<T>.Size()){
                for(int i=0; i<myVector<T>.Size();++i){
                    cout<<"Element "<<_index<<" is: "<<myVector<T>[_index-1]<<endl;
                    break;
                }
            }
            else cout<<"Index out of range"<<endl;
        }
        else if (oper==9){
            cout<<"Vector size: "<<myVector<T>.Size()<<endl;
        }
        else if (oper==10){
            cout<<"Vector capacity: "<<myVector<T>.getcapacity()<<endl;
        }
        else if (oper==11){
            bool isEmpty = myVector<T>.isEmpty();
            if (isEmpty) cout<<"The vector is empty"<<endl;
            else cout<<"The vector is not empty"<<endl;
        }
        cout<<"Would you like to perform other operations? (Y/N) ";
        char choice; cin>>choice;
        if (choice=='y'||choice=='Y'){
            system("CLS");
            int c = operation();
            system("PAUSE");
        }
        else if(choice=='n'||choice=='N'){
            int operand = menu();
            system("CLS");
            if (operand==6){
                cout<<"Program terminating"<<endl;
                exit(0);
            }
            else {
                myVector<T>.Clear();
                myMenu();
            }
        }
        system("CLS");
    }
}

void myMenu(){
    int listType = menu();
    if (listType==1){
        system("CLS");//clear the console
        myVector<int>;
        if (myVector<int>.Size()<1)
            cout<<"A vector of integers was created successfully"<<endl;
        administration(myVector<int>);
    }
    else if(listType==2){
        system("CLS");//clear the console
        myVector<char>;
        if (myVector<char>.Size()<1)
            cout<<"A vector of characters was created successfully"<<endl;
        administration(myVector<char>);
    }
    else if(listType==3){
        system("CLS");//clear the console
        myVector<string>;
        if (myVector<string>.Size()<1)
            cout<<"A vector of string was created successfully"<<endl;
        administration(myVector<string>);
    }
    else if(listType==4){
        system("CLS");//clear the console
        myVector<float>;
        if (myVector<string>.Size())
            cout<<"A vector of float was created successfully"<<endl;
        administration(myVector<float>);
    }
    else if(listType==5){
        system("CLS");//clear the console
        myVector<Student>;
        if (myVector<Student>.Size()<1)
            cout<<"A vector of students was created successfully"<<endl;
        administration(myVector<Student>);
    }
    else if (listType==6){
        cout<<"Program terminating"<<endl;
        exit(0);
    }
    else if (listType<1||listType>6){
        cout<<"invalid choice"<<endl;
        menu();
    }
}

int main()
{
    myMenu();
    return 0;
}
