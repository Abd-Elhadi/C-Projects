#pragma once
#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt {
public:
    BigDecimalInt (){}
	BigDecimalInt(std::string _decStr) {
		this->decStr = _decStr;
	}
	BigDecimalInt(int _decInt) {
		this->decInt = _decInt;
	}

	BigDecimalInt &operator = (const BigDecimalInt& anotherDec) {
		return *this;
	}

	BigDecimalInt operator + (BigDecimalInt const& anotherDec) {
		BigDecimalInt newBigInt;
		newBigInt.decInt = (decInt + anotherDec.decInt);
		newBigInt.decStr = addTwoBigInt(this->decStr, anotherDec.decStr);
		return newBigInt;
	}
    bool isLesser(string str1, string str2){
        if (str1.size() < str2.size()){
            return true;
        }
        if (str1.size() > str2.size()){
            return false;
        }
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] < str2[i]){
                return true;
            }
            else if (str2[i] < str1[i]){
                return false;
            }
        }
        return false;
    }

	string addTwoBigInt(std::string str1, std::string str2) {
        string result = "" ;
        int Size1, Size2, carry;
        Size1 = str1.size();
        Size2 = str2.size();
        carry = 0;
        if (Size1>Size2){
            for (int i = Size2 - 1; i>=0; --i){
                int a = (str1[i + Size1 - Size2] - 48) + (str2[i] - 48) + carry;
                result.push_back(a%10 + 48);
                if (a>=10) carry = 1;
                else carry = 0;
            }
            for (int i = Size1 - Size2 - 1; i>=0; --i){
                int a = str1[i] - 48 + carry;
                result.push_back(a % 10 + 48);
                if (a>=10) carry = 1;
                else carry = 0;
            }
        }
        else if (Size2 > Size1){
            for (int i = Size1 - 1; i>=0; --i){
                int a = (str1[i] - 48) + (str2[i + Size2 - Size1] - 48) + carry;
                result.push_back(a%10 + 48);
                if (a>=10) carry = 1;
                else carry = 0;
            }
            for (int i = Size2 - Size1 - 1; i>=0; --i){
                int a = str2[i] - 48 + carry;
                result.push_back(a % 10 + 48);
                if (a>=10) carry = 1;
                else carry = 0;
            }
        }
        else{
            for (int i = Size1-1; i>=0; --i){
                int a = (str1[i] - 48) + (str2[i] - 48) + carry;
                result.push_back(a%10 + 48);
                if (a>=10) carry = 1;
                else carry = 0;
            }
        }
        if (carry) result.push_back(carry + 48);
        reverse(result.begin(), result.end());
        if (result[0] == '0')
            result.erase(result.begin());
        return result;
    }
    string subtractTwoBigInt (std::string str1, std::string str2){
        string result = "";
        bool flag = false;
        int Size1, Size2, carry;
        carry = 0;
        if (isLesser(str1, str2)){
            flag = true;
            swap(str1, str2);
        }
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        for (int i = 0; i < str2.size(); i++){
            int res = ((str1[i] - 48) - (str2[i] - 48) - carry);
            if (res < 0){
                res += 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            result.push_back(res + 48);
        }
        for (int i = str2.size(); i < str1.size(); i++){
            int res = ((str1[i] - 48) - carry);
            if (res < 0){
                res += 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
            result.push_back(res + 48);
        }
        if (flag){result += '-';}
        reverse (result.begin(), result.end());
        if (flag && result[1] == '0'){result.erase(result.begin() + 1);}
        else if (result[0] == '0'){result.erase(result.begin());}
        return result;
    }
	friend std::ostream& operator << (std::ostream& out, BigDecimalInt b);
	~BigDecimalInt() {

    }

private:
	std::string decStr = "";
	int decInt = 0;
};




