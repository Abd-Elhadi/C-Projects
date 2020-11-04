#include <bits/stdc++.h>
using namespace std;

template<class T>
class Stack{
public:
    Stack(){
        container = new T[1];
        Size = 0;
        _top = -1;
    }
    Stack(T value, int _size){
        Size = _size;
        container = new T[_size];
        for (int i = 0; i < _size; i++){
            container[i] = value;
        }
    }
    ~Stack(){
        delete[] container;
    }

    void push(T newElement){
        container[++_top] = newElement;
    }
    bool isEmpty (){
        return _top == -1;
    }

    T& top(){
        return container[_top];
    }

    void pop(){
        if (isEmpty()) cout << "Stack is empty" << endl;
        else {
            T temp = container[_top];
            container[_top] = container[--_top];
        }
    }
private:
    T* container;
    int _top;
    int Size;
};


int main() {
    Stack<double> s;
    s.push(1.5);
    s.push(2.5);
    s.push(3.5);
    s.push(4.5);
    s.push(5.5);

    while(!s.isEmpty()){
        cout << "Element's Value: " << s.top() << endl;
        s.pop();
    }
    cout << endl;
}
