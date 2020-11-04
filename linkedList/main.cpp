#include <bits/stdc++.h>
using namespace std;

template <class T>
class List {
public:
    class node {
    public:
        T data;
        node *next;
        node *prev;

        node() : next(nullptr), prev(nullptr) {}
        node(const T& item, node *ptr = nullptr) :
        data(item), next(ptr), prev(ptr) {}
    };
    List(node* newNode) : head(newNode) {}
    List (T value, int initialSize){
        head = NULL;
        tail = NULL;
        temp = NULL;
        _size = 0;
        for (int i = 0; i < initialSize; i++){
            InsertBack(value);
        }
    }
    void InsertFront(T newElement){
        temp = new node;
        temp->data = newElement;
        tail = head;
        temp->next = head;
        temp->prev = NULL;
        if (head != NULL){
            head->prev = temp;
        }
        head = temp;
        ++_size;
    }
    /*
    List& operator = (List another) {
        swap(*this, another);
        return *this;
    }
    */

    List& operator =(const List &another ) {
        if (&another == this)
            return (*this);
        node* nodePtr = nullptr;
        node* nodePtr2 = nullptr;
        if (another.head == NULL){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = new node;
            //head->next = new List(head->next);
            nodePtr = head;
            nodePtr2 = another.head->next;
        }
        while(nodePtr2){
            nodePtr -> next = new node;
            nodePtr = nodePtr -> next;
            //nodePtr->next = new List((nodePtr2->next));
            nodePtr2 = nodePtr2->next;
        }
        nodePtr -> next = NULL;
        tail = nodePtr;
        delete nodePtr;
        delete nodePtr2;
        return *this;
    }

    void InserAt(T newElement, node* pos){
        temp = new node;
        tail = head;
        temp->prev = pos->prev;
        pos->prev = temp;
        temp->next = pos;
        if (temp->prev != NULL) temp->prev->next = temp;
        else head = temp;
    }

    void Delete(T delData){
        node* delPtr = NULL;
        temp = head;
        tail = head;
        while (tail != NULL && tail->data != delData){
            temp = tail;
            tail = tail->next;
        }
        if (tail == NULL){
            cout << delData << " was not Found" << endl;
            delete delPtr;
        }
        else {
            delPtr = tail;
            tail = tail->next;
            temp->next = tail;
            delete delPtr;
            cout << "The value " << delData << " was deleted" << endl;
        }
        --_size;
    }
    void print(){
        tail = head;
        cout << "The are " << _size << " elements in the list." << endl
             << "Forward printing" << endl;
        while (tail != nullptr){
            cout << tail->data << " ";
            temp = tail;
            tail = tail->next;
        }
        cout << endl << "Backward printing" << endl;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    List() {
      head = tail = temp = new node();
      _size = 0;
    }
    List(const List<T>& other) = delete;
    List(List<T>& other) = delete;
    ~List() {
      while (head->next != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
      }
      delete head;
    }

    //List<T>& operator = (const List<T>& other) = delete;
    //List<T>& operator = (List<T>&& other) = delete;

    void InsertBack(T newElement){
        temp = new node;
        tail = head;
        temp->data = newElement;
        temp->next = NULL;
        if (head == NULL){
            temp->prev = NULL;
            head = temp;
            ++_size;
            return;
        }
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = temp;
        temp->prev = tail;
        ++_size;
    }

    // Inner class Iterator
    class Iterator {
    friend class List;
    private:
        node *nodePtr;
        // The constructor is private, so only our friends
        // can create instances of Iterators.
        Iterator(node *newPtr) : nodePtr(newPtr) {}
    public:
        Iterator() : nodePtr(nullptr) {}

        // Overload for the comparison operator !=
        bool operator!=(const Iterator& itr) const {
            return nodePtr != itr.nodePtr;
        }

        // Overload for the dereference operator *
        T& operator*() const {
            return nodePtr->next->data;
        }

        // Overload for the postincrement operator ++
        Iterator operator ++ (int) {
            Iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
        }

        Iterator operator ++ () {
            Iterator temp = *this;
            nodePtr = nodePtr->next;
            return temp;
        }

        Iterator operator -- (int) {
            Iterator temp = *this;
            nodePtr = nodePtr->prev;
            return temp;
        }

        Iterator operator -- () {
            Iterator temp = *this;
            nodePtr = nodePtr->prev;
            return temp;
        }
    }; // End of inner class Iterator

    Iterator Begin() const {
        return Iterator(head);
    }

    Iterator End() const {
        return Iterator(tail->next);
    }

    Iterator Insert(Iterator position, const T& value) {
        node* newNode = new node;
        newNode->next = position.nodePtr->next;
        newNode->prev = position.nodePtr->prev;
        newNode->data = value;
        if (position.nodePtr == tail) tail = newNode;
        position.nodePtr->next = newNode;
        _size++;
        return position;
    }

    Iterator Erase(Iterator position) {
        node *toDelete = position.nodePtr->next;
        position.nodePtr->next = position.nodePtr->next->next;
        if (toDelete == tail) tail = position.nodePtr;
        delete toDelete;
        return position;
    }
private:
    node* head;
    node* tail;
    node* temp;
    int _size;
};

int main()
{
    List<int> lis, anotherList;
    lis.InsertBack(1);
    lis.InsertBack(3);
    lis.InsertBack(5);
    lis.InsertBack(7);
    lis.InsertBack(9);
    lis.InsertBack(11);

    List<int>::Iterator it = lis.Begin();
    lis.Insert(it, 4);
    lis.Insert(it, 100);
    lis.Erase(it);
    lis.InsertBack(100);
    lis.Insert(it, 150);
    List<int>::Iterator ite = lis.Begin();
    while (ite != lis.End()){
        cout << *ite << " ";
        ite++;
    }
    cout << endl;

    //anotherList = lis;
    //anotherList.print();
}
