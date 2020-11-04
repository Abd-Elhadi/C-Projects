#include "FCAIVector.h"

ostream & operator << (ostream &get, const Student &st){
	get << "Student name: " << st.sName << endl;
	get << "Student ID: " << st.sID << endl;
	get << "Student Department: " << st.sDepartment << endl;
	for (int i = 0; i <st.numberOFcourses; i++){
		st.printInfo();
	}
	return get;
}

istream & operator >> (istream &Set, Student &st){
    int numberOFCourses;
	cout << "Student name: ";
	Set >> st.sName;
	ID:
	cout << "Student ID: ";
	Set >> st.sID;
	if (Set.fail()){
        cout << "You should enter correct ID" << endl;
        Set.clear();
        Set.ignore(10000, '\n');
        goto ID;
	}
	cout << "Student Department: ";
	Set >> st.sDepartment;
	Courses:
	cout << "Number of Courses: ";
	Set >> numberOFCourses;
	if (Set.fail()){
        cout << "You should enter correct number for courses" << endl;
        Set.clear();
        Set.ignore(10000, '\n');
        goto Courses;
	}
	st.numberOFcourses = numberOFCourses;
	st.myCourses = new Courses[st.numberOFcourses];
	for (int i = 0; i < st.numberOFcourses; i++){
		cout<<i+1<<"th course name: ";
        string _courseName; Set>>_courseName;
        cout<<i+1<<"th course code: ";
        string _courseCode; Set>>_courseCode;
        Grade:
        cout<<i+1<<"th course grade: ";
        char _courseGrade; Set>>_courseGrade;
        if (Set.fail()){
            cout << "You should enter correct value for grade" << endl;
            Set.clear();
            Set.ignore(10000, '\n');
            goto Grade;
        }
        Point:
        cout<<i+1<<"th course point: ";
        double _coursePoint; Set>>_coursePoint;
        if (Set.fail()){
            cout << "You should enter correct value for course point" << endl;
            Set.clear();
            Set.ignore(10000, '\n');
            goto Point;
        }
        Year:
        cout<<i+1<<"th course year: ";
        int _courseYear; Set>>_courseYear;
        if (Set.fail()){
            cout << "You should enter correct value for course year" << endl;
            Set.clear();
            Set.ignore(10000, '\n');
            goto Year;
        }
        Semester:
        cout<<i+1<<"th course semester: ";
        int _courseSemester; Set>>_courseSemester;
        if (Set.fail()){
            cout << "You should enter correct value for course semester" << endl;
            Set.clear();
            Set.ignore(10000, '\n');
            goto Semester;
        }
        st.myCourses[i].setCourseName(_courseName);
        st.myCourses[i].setCoursCode(_courseCode);
        st.myCourses[i].setCourseGrade(_courseGrade);
        st.myCourses[i].setCoursePoint(_coursePoint);
        st.myCourses[i].setCourseYear(_courseYear);
        st.myCourses[i].setCourseSemester(_courseSemester);
        st.printInfo();
	}
	return Set;
}
