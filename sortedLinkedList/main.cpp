#include <iostream>
using namespace std;
class StudentList;

class student {
public:
    student () {}
    student (string _name, int _ID, double GPA) : name(_name), ID(_ID), gpa(GPA) {}
    int getID(){
        return ID;
    }
    friend ostream & operator << (ostream &out, const student &another);
    friend istream & operator >> (istream &input,  student &another);
    friend StudentList;

private:
    int ID;
    double gpa;
    string name;
    student* next;
};

ostream & operator << (ostream &out, const student &another) {
    out << "Student name: " << another.name << ", GPA: " <<another.gpa << ", ID: " << another.ID ;
    return out;
}

istream & operator >> (istream &in,  student &another) {
    cout << "Student name: ";
    in >> another.name;
    cout << "Student GPA: ";
    in >> another.gpa;
    cout << "Student ID: ";
    in >> another.ID;
    return in;
}

class StudentList{
public:
    StudentList() {
        head = NULL;
    }
    ~StudentList() {};
    void addStudent(student val);
    void reverseList();
    void display();
    void printList();
    void Insert(student new_node);
    void deleteStudent(int givenID);
    student* Serach(int key);
private:
    student* head;
};

void StudentList::Insert(student new_node){
    student* current;
    if (head == nullptr || head->ID >= new_node.ID) {
        new_node.next = head;
        head = &new_node;
    }
    else {
        current = head;
        while (current->next != nullptr && current->next->ID < new_node.ID) {
            current = current->next;
        }
        new_node.next = current->next;
        current->next = &new_node;
    }
}

void StudentList::reverseList() {
    student* temp = head;
    student* nextnode = NULL;
    student* revnode = NULL;
    while (temp != NULL) {
        head = temp;
        nextnode = temp->next;
        temp->next = revnode;
        revnode = temp;
        temp = nextnode;
    }
}

void StudentList::display(){
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        student* temp = head;
        while (temp != NULL) {
            cout << *temp << endl;
            temp = temp->next;
        }
        cout << endl;
    }
}
void StudentList::printList(){
    student *temp = head;
    while(temp != nullptr) {
        cout << *temp << endl;
        temp = temp->next;
    }
}

void StudentList::deleteStudent(int key){
    student* temp = head;
    student* prev;
    if (temp != NULL && temp->getID() == key) {
        head = temp->next;
        cout << "The Student with the ID: " << temp->getID() << ", deleted successfully." << endl;
        free(temp);
        return;
    }
    while (temp != NULL && temp->getID() != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;

    cout << "The Student with the ID: " << temp->getID() << ", deleted successfully." << endl;
    prev->next = temp->next;
    free(temp);
}

student* StudentList::Serach(int key){
    student* temp = head;
    student* prev;
    if (temp != NULL && temp->getID() == key) {
        cout << *temp << ", was found on the list." << endl;
        return temp;
    }
    while (temp != NULL && temp->getID() != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "The given key is not found on the list." << endl;
        system("PAUSE");
        exit(0);
    }
    cout << *temp << ", was found on the list." << endl;
    return temp;
}

int main() {

    StudentList* list = new StudentList();
    student s1, s2, s3, s4, s5;
    cin >> s1 >> s2 >> s3 >> s4 >> s5;
    list->Insert(s1);
    list->Insert(s2);
    list->Insert(s3);
    list->Insert(s4);
    list->Insert(s5);

    list->printList();
    cout << "Enter an ID to print its corresponding value: " << endl;
    int n; cin >> n;
    list->Serach(n);
    cout << "Linked List data" << endl;
    list->printList();
    cout << "Enter an ID to delete its corresponding value: " << endl;
    cin >> n;
    list->deleteStudent(n);
    cout << "Linked List data" << endl;
    list->printList();
    delete list;
    return 0;
}
