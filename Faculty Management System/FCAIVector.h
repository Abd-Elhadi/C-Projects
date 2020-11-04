#include <bits/stdc++.h>
#ifndef FCAIVECTOR_H
#define FCAIVECTOR_H
using namespace std;
class Student;

template<class T>
class FCAIVector{
    public:
    //constructor to initialize the vector
        FCAIVector(){
            container = new T[1];
            Capacity = 1;
            current = 0;
        }
        //parametrized constructor with size to initialize the size and capacity of the vector
        FCAIVector(int Size){
            Capacity=Size;
            current = Size;
            container = new T[Size];
        }
        //parametrized constructor with size and initial value to initialize the size, capacity
        //and initial value to the element of the vector
        FCAIVector(int Size, const T& initialValue){
            Capacity = Size;
            current = Size;
            container = new T[Size];
            for (int i=0; i<Size; ++i){
                container[i] = initialValue;
            }
        }
        //operator overloading for = operator
        FCAIVector & operator = (const FCAIVector<T>& v)const{
            delete[] container;
            current = v.Size();
            Capacity = v.getcapacity();
            container = new T[current];
            for (int i=0; i<current; ++i)
                container[i] = v.container[i];
            return *this;
        }

        //create a type called iterator to be used as iterator for the vector
        typedef T* Iterator;
        //begin iterator like for the STL vector
        Iterator Begin(){
            return container;
        }
        //end iterator
        Iterator End(){
            return container+Size();
        }
        //pointer returns the value of the first element of the vector
        T& Front(){
            return container[0];
        }
        //pointer returns the value of the last element of the vector
        T& Back(){
            return container[current-1];
        }
        //function pushes an element at the last
        void push(T data){
        // if the number of elements is equal to the capacity
        // that means we don't have space
        // to accommodate more elements.
        // We need to double the capacity
            if (current==Capacity){
                T* temp = new T[2*Capacity];
                for(int i=0; i<Capacity; ++i){
                    temp[i] = container[i];
                }
                // deleting previous array
                delete[] container;
                Capacity *=2;
                container = temp;
            }
            // Inserting data
            container[current] = data;
            current++;
        }
        //pushes an element at any index
        void push(T &data, int index){
            // if index is equal to capacity then this
            // function is same as push defined above
            if (index==Capacity)
                push(data);
            else
                container[index] = data;
        }
        void Insert(T &data, T *pos){
            T* temp = new T[current];
            //copy elements to temp
            for (int i=0; i<current; ++i){
                temp[i] = container [i];
            }
            int dex=0,k=0;
            //this loop will fin out which index intended to insert the element of it
            for (FCAIVector<T>::Iterator it = Begin(); it!= &container[current]; it++){
                if (it == pos){
                    break;
                }
                dex++;
            }
            //increase size by 1
            current++;
            //multiply capacity by 2 to make sure the new element will fir into the vector
            Capacity*=2;
            //re-initialize the capacity of the vector
            container = new T[Capacity];
            //this loop will assign to the intended position the given value on the vector
            for (int j=0; j<current; j++){
                if (j != dex){
                    container[j] = temp[k];
                    k++;
                }
                else
                    container[j] = data;
            }
            delete[] temp;
        }
        //erase en element from the vector
        void Erase(T* position){
            //copy the elements to reservoir permanently
            T* reservoir = new T[Capacity];
            for (int x=0; x<current; x++){
                reservoir[x] = container [x];
            }
            int dex=0;
            //this loop will find out the intended position to be erased
            for (FCAIVector<T>::Iterator it = Begin(); it!=&container[current]; it++){
                if (it == position) break;
                else dex++;
            }
            current--;
            container = new T[Capacity];
            int y = 0;
            for (int k=0; k<current+1; ++k){
                if (k != dex){
                    container[y] = reservoir[k];
                    y++;
                }
            }
            delete[] reservoir;
        }
        //to get an element at index pos
        T get(int index){
            // if index is within the range
            if (index<current)
                return container[index];
        }
        //to delete last element
        void pop(){
            current--;
        }
        //to get size of the vector
        int Size()const {
            return current;
        }
        //to get capacity of the vector
        int getcapacity(){
            return Capacity;
        }
        //clear the created vector
        void Clear(){
            container=0;
            Capacity=0;
            current=0;
        }
        //checks if the vector is empty or not
        bool isEmpty(){
            if(current==0) return true;
            else return false;
        }
        //operator overloading for []
        T &operator [](int index){
            return container[index];
        }
        //destructor
        ~FCAIVector(){
            delete[] container;
        }

    private:
        T* container;//pointer point to the vector
        int Capacity;//total storage of the vector
        int current;//the number of current element on the vector
};

class Courses{
    public:
        //empty constructor to initialize course parameters
        Courses(){
            courseName = "OOP";
            courseCode = "CS213";
            courseGrade = 'A';
            coursePoint = 92.5;
            courseYear = 2;
            courseSemester = 1;
        }
        //set course name
        void setCourseName(string _name){
            courseName = _name;
        }
        //set course code
        void setCoursCode(string _code){
            courseCode = _code;
        }
        //set course grade
        void setCourseGrade(char _grade){
            courseGrade = _grade;
        }
        //set course point
        void setCoursePoint(double _points){
            coursePoint = _points;
        }
        //set course year
        void setCourseYear(int _year){
            courseYear = _year;
        }
        //set course semester
        void setCourseSemester(int _semester){
            courseSemester = _semester;
        }
        //set all attributes for the course
        void setALL(){
            cout<<"Course name: "; cin>>courseName;
            cout<<"Course code: "; cin>>courseCode;
            cout<<"Course grade: "; cin>>courseGrade;
            cout<<"Course point: "; cin>>coursePoint;
            cout<<"Course year: "; cin>>courseYear;
            cout<<"Course semester: "; cin>>courseSemester;
        }
        //print course info
        void printCourseInfo(){
            cout<<"Course name: "<<courseName<<endl
                <<"Course code: "<<courseCode<<endl
                <<"Course grade: "<<courseGrade<<endl
                <<"Course point: "<<coursePoint<<endl
                <<"Course year: "<<courseYear<<endl
                <<"Course semester: "<<courseSemester<<endl;
        }
        //get the name of the course
        string getCourseName(){
            return courseName;
        }
        //get the code of the course
        string getCoursCode(){
            return courseCode;
        }
        //get the grade of the course
        char getCourseGrade(){
            return courseGrade;
        }
        //get the point of the course
        double getCoursePoint(){
            return coursePoint;
        }
        //get the year of the course
        int getCourseYear(){
            return courseYear;
        }
        //get the semester of the course
        int getCourseSemester(){
            return courseSemester;
        }
    private:
        string courseName;
        string courseCode;
        char courseGrade;
        double coursePoint;
        int courseYear;
        int courseSemester;
};

class Student{
    public:
        static int stdid;
        //empty constructor to initialize the Student
        Student(){
            sName = "noName";
            sDepartment = "noDepartment";
            sID = 0;
        }
        //parametrized constructor to initialize student's name, id and department
        Student(string _sName, string _sDepartment, int _sID){
            sName = _sName;
            sDepartment = _sDepartment;
            sID =  _sID;
        }
        //set student's name
        void setName(string _sName){
            sName = _sName;
        }
        void setNumberOFCourses(int n){
            numberOFcourses = n;
        }
        //set student's department
        void setDepartment(string _sDepartment){
            sDepartment = _sDepartment;
        }
        //set student's ID
        void setID(int _sID){
            sID = _sID;
        }
        //get student's name
        string getName(){
            return sName;
        }
        //get student's department
        string getDepartment(){
            return sDepartment;
        }
        //get student's ID
        int getID(){
            return sID;
        }
        int getNumberOFCourses(){
            return numberOFcourses;
        }
        //set courses of the student
        void setCourses(int numofCourses){
            for (int i=0; i<numofCourses; ++i){
                Courses newCourse;
                newCourse.getCourseName();
                newCourse.getCoursCode();
                newCourse.getCourseGrade();
                newCourse.getCoursePoint();
                newCourse.getCourseYear();
                newCourse.getCourseSemester();
                myCourses[i]=newCourse;
            }
        }
        //print info of the student
        void printInfo() const
        {
            int n = numberOFcourses;
            cout<<"name: "<<sName<<endl
                <<"ID: "<<sID<<endl
                <<"Department: "<<sDepartment<<endl;
            for (int i=0; i<n; ++i){
                cout<<"Course name: "<<myCourses[i].getCourseName()<<endl
                    <<"Course code: "<<myCourses[i].getCoursCode()<<endl
                    <<"Course grade: "<<myCourses[i].getCourseGrade()<<endl
                    <<"Course point: "<<myCourses[i].getCoursePoint()<<endl
                    <<"Course year: "<<myCourses[i].getCourseYear()<<endl
                    <<"Course semester: "<<myCourses[i].getCourseSemester()<<endl;
            }
        }
        friend ostream & operator << (ostream &get, const Student &st);
        friend istream & operator >> (istream &Set, Student &st);
    private:
        string sName, sDepartment;
        int sID, numberOFcourses=0;
        Courses* myCourses;
};
#endif // FCAIVECTOR_H
