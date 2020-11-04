#include <bits/stdc++.h>
using namespace std;

template<class T>
class Queue {
public:
    Queue(){
        capacity = 1;
        _size = 0;
        _front = 0;
        container = new T[1];
    }
    Queue(int Size){
        capacity = Size;
        current = capacity - 1;
        _front = 0;
    }
	Queue(T value, int Size) {
        capacity = Size;
		_front = 0;
		container = new T[capacity];
		current = capacity - 1;
		for (int i = 0; i < Size; i++){
            container[i] = value;
		}

	}
	int Empty(){
		return _size == 0;
	}
	bool Full() {
		return _size == capacity;
	}
	void push(T Element) {
		if (Full()) {
            capacity *= 2;
            push(Element);
		}
		else {
			current = (current + 1) % capacity;
			container[current] = Element;
			_size++;
		}
	}
	void pop() {
		if (Empty()) {
			cout << "Empty Queue Can't Dequeue ...!";
		}
		else {
			_front = (_front + 1) % capacity;
			--_size;

		}
	}
	T& Front() {
		assert(!Empty());
		return container[_front];
	}

	int Size() {
		assert(!Empty());
		return container[current];
	}
	~Queue() {
		delete[] container;
	}
private:
    int current, _front, _size, capacity;
	T* container;
};

int main()
{
	Queue<double> q1;
	q1.push(1.5);
	q1.push(10.5);
	q1.push(100.5);
	q1.push(1000.5);
	q1.push(10000.5);
	while(!q1.Empty()){
        cout << "Element's value: " << q1.Front() << endl;
        q1.pop();
	}
}
