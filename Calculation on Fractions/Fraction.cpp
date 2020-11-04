#include "Fraction.h"
#include <bits/stdc++.h>
#include <sstream>
using namespace std;


Fraction::Fraction(){
    nominator = 0;
    denominator = 1;
}
Fraction::Fraction(int _nominator, int _denominator){
    this->nominator = _nominator;
    this->denominator = _denominator;
}
int Fraction::fractionReducer(int fnumber, int snumber){
    fnumber = abs(fnumber);
    snumber = abs(snumber);
    if (fnumber==0) return 0;
    if(snumber==0) return 0;
    if (fnumber ==  snumber) return snumber;
    if (fnumber > snumber) return fractionReducer(fnumber - snumber, snumber);
    return fractionReducer(fnumber, snumber - fnumber);
}

Fraction Fraction::addition(Fraction &another){
    Fraction newObj;
    newObj.nominator = (this->nominator*another.denominator)+(this->denominator*another.nominator);
    newObj.denominator = (this->denominator*another.denominator);
    int gcd = fractionReducer(newObj.nominator,newObj.denominator);
    newObj.nominator/=gcd;
    newObj.denominator/=gcd;
    return newObj;
}

Fraction Fraction::subraction(Fraction &another){
    Fraction newObj;
    newObj.nominator = this->nominator*another.denominator-this->denominator*another.nominator;
    newObj.denominator = this->denominator*another.denominator;
    int gcd = fractionReducer(newObj.nominator,newObj.denominator);
    newObj.nominator/=gcd;
    newObj.denominator/=gcd;
    return newObj;
    return newObj ;
}

Fraction Fraction::multiplication(Fraction &another){
    Fraction newObj;
    newObj.nominator = this->nominator*another.nominator;
    newObj.denominator = this->denominator*another.denominator;
    int gcd = fractionReducer(newObj.nominator,newObj.denominator);
    newObj.nominator/=gcd;
    newObj.denominator/=gcd;
    return newObj;
}

Fraction Fraction::division(Fraction &another){
    Fraction newObj;
    newObj.nominator = this->nominator*another.denominator;
    newObj.denominator = this->denominator*another.nominator;
    int gcd = fractionReducer(newObj.nominator,newObj.denominator);
    newObj.nominator/=gcd;
    newObj.denominator/=gcd;
    return newObj;
}

bool Fraction::operator>(Fraction &another){
    if (this->nominator>another.nominator)
        return true;
    else if (this->nominator==another.nominator){
        if (this->denominator<another.denominator)
            return true;
        else return false;
    }
    else return false;
}

bool Fraction::operator<(Fraction &another){
    if (this->nominator<another.nominator)
        return true;
    else if (this->nominator==another.nominator){
        if (this->denominator>another.denominator)
            return true;
        else return false;
    }
    else return false;
}

bool Fraction::operator==(Fraction& another){
    if (this->nominator==another.nominator&&this->denominator==another.denominator) return true;
    else return false;
}

bool Fraction::operator>=(Fraction &another){
    if (this->nominator>another.nominator)
        return true;
    else if (this->nominator==another.nominator){
        if (this->denominator<another.denominator)
            return true;
        else return false;
    }
    else if
        (this->nominator==another.nominator&&this->denominator==another.denominator) return true;
    else return false;
}

bool Fraction::operator<=(Fraction &another){
    if (this->nominator<another.nominator)
        return true;
    else if (this->nominator==another.nominator){
        if (this->denominator>another.denominator)
            return true;
        else return false;
    }
    else if
        (this->nominator==another.nominator&&this->denominator==another.denominator) return true;
    else return false;
}

istream& operator >>(istream& input, Fraction& another){
    string str = "", _nominator = "", _denominator = "";

    do {
        input >> str;
        if (str[2] == '0'){
            cout<<"Denominator cannot be zero"<<endl
            <<"Re-enter again: ";
        }
        _nominator = str[0];
        _denominator = str[2];
    }while(_denominator == "0");

    another.nominator = stoi(_nominator);
    another.denominator = stoi(_denominator);
    return input;
}

ostream& operator <<(ostream& output, const Fraction& another){
    output<<another.nominator<<"/"<<another.denominator<<endl;
    return output;
}
