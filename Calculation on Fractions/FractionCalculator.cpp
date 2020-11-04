#include "FractionCalculator.h"
void FractionCalculator::calculator(int choice){
    if (choice == 1){
        cout<<"Enter the first fraction: ";
        Fraction f1; cin>>f1;
        cout<<"Enter the second fraction: ";
        Fraction f2; cin>>f2;
        cout<<"Fraction result: "
            <<f1.addition(f2)<<endl;
    }
    else if (choice == 2){
        cout<<"Enter the first fraction: ";
        Fraction f1; cin>>f1;
        cout<<"Enter the second fraction: ";
        Fraction f2; cin>>f2;
        cout<<"Fraction result: "
            <<f1.subraction(f2)<<endl;
    }
    else if (choice == 3){
        cout<<"Enter the first fraction: ";
        Fraction f1; cin>>f1;
        cout<<"Enter the second fraction: ";
        Fraction f2; cin>>f2;
        cout<<"Fraction result: "
            <<f1.multiplication(f2)<<endl;
    }
    else if (choice == 4){
        cout<<"Enter the first fraction: ";
        Fraction f1; cin>>f1;
        cout<<"Enter the second fraction: ";
        Fraction f2; cin>>f2;
        cout<<"Fraction result: "
            <<f1.division(f2)<<endl;
    }
    else if (choice == 5){
        system("PAUSE");
        exit(0);
    }
    else cout<<"Invalid choice"<<endl;
}
