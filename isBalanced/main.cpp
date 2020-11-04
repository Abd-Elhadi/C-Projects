#include <bits/stdc++.h>
using namespace std;

bool Pair(char open, char close){
    if (open == '(' && close == ')') return true;
    else if (open == '{' && close == '}') return true;
    else if (open == '[' && close == ']') return true;
    return false;
}

bool isBalanced(string str){
    stack<char> s;
    int n = str.size();
    for (int i = 0; i < n; i++){
        if (str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if (s.empty() || !Pair(s.top(), str[i])) return false;
            else s.pop();
        }
    }
    return s.empty();
}

int main() {
    cout << "your input: "; string s; cin >> s;
    if (isBalanced(s)) cout << "Balanced" << endl;
    else cout << "Not Balanced" << endl;
}
