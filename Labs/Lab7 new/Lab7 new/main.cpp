//
//  main.cpp
//  Lab7 new
//
//  Created by Alex Mosseri on 3/15/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

/*
 rec07
 Starter Code for required functionality
 Yes, you may add other methods.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student*);
    void removeStudentsFromCourse();
    size_t findStudent(const string& student) const;
    
private:
    string name;
    vector<Student*> students;
};

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);
    
    // Student method needed by Course
    void removedFromCourse(Course*);
    
    size_t findCourse(const string& course) const;
private:
    string name;
    vector<Course*> courses;
};

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string&);
    bool addStudent(const string&);
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();
    
private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;
    
    vector<Course*> courses;
    vector<Student*> students;
};




























//CPP


//course
ostream& operator<<(ostream& os, const Course& rhs){
    os<< rhs.name << ": ";
    if(rhs.students.size() == 0){
        os<<"No students"<<endl;
        return os;
    }
    for(size_t i =0; i <rhs.students.size();i++){
        os<< rhs.students[i]->getName()<< " ";
    }
    os << endl;
    return os;
}




    // Course methods needed by Registrar
Course::Course(const string& courseName) : name(courseName){}

const string& Course::getName() const{
    return name;
}
bool Course::addStudent(Student* studentPointer){
    for(size_t i =0; i < students.size(); i++){
        if(studentPointer == students[i]){
            return false;
        }
    }
    students.push_back(studentPointer);
    return true;
}

void Course::removeStudentsFromCourse(){
    for(size_t i =0; i <students.size(); i++){
        students[i]->removedFromCourse(this);
    }
    students.clear();
}









//student
ostream& operator<<(ostream& os, const Student& rhs){
    os << rhs.name << ": ";
    if(rhs.courses.size() ==0){
        os<<"No Courses";
    }
    for (size_t i =0; i <rhs.courses.size(); i++) {
        
        
        os<<rhs.courses[i]->getName()<<" ";
        
    }
    os << endl;
    return os;
}
    // Student methods needed by Registrar
Student::Student(const string& name) :name(name){
}
const string& Student::getName() const{
    return name;
}
bool Student::addCourse(Course* coursePointer){
    for(size_t i =0; i < courses.size(); i++){
        if(coursePointer == courses[i]){
            return false;
        }
    }
    courses.push_back(coursePointer);
    return true;
}
    
    // Student method needed by Course
void Student::removedFromCourse(Course* coursepointer){
    size_t currSize = courses.size();
    for(size_t i =0; i <currSize; i++){
        if(coursepointer == courses[i]){
            courses[i] = courses[currSize-1];
            courses.pop_back();
            return;
        }
        
    }
}
    











//class Registrar

ostream& operator<<(ostream& os, const Registrar& rhs){
    os<<"Courses:"<<endl;
    for(size_t i=0; i <rhs.courses.size();i++){
        os <<*rhs.courses[i];
    }
    os<<endl;
    os << "Students:"<<endl;
    for(size_t x=0; x <rhs.students.size(); x++){
        os<<*rhs.students[x];
    }
    return os;
    
}

Registrar::Registrar() {}
bool Registrar::addCourse(const string& theCourse){
    for (size_t i =0; i < courses.size(); i++) {
        if(courses[i]->getName() == theCourse){
            return false;
        }
    }
    Course* newCourse = new Course(theCourse);
    courses.push_back(newCourse);
    return true;
}

bool Registrar::addStudent(const string& name){
    for(size_t i = 0; i <students.size(); i++){
        if(students[i]->getName() == name){
            return false;
        }
    }
    Student* newName = new Student(name);
    students.push_back(newName);
    return true;
}

bool Registrar::enrollStudentInCourse(const string& studentName,
                                          const string& courseName){
    
    size_t course = findCourse(courseName);
    size_t student = findStudent(studentName);
    
    if (student != students.size() && course != courses.size()){
        return ( students[student]->addCourse(courses[course]) &&
                 courses[course]->addStudent(students[student]));
    }
    return false;
}
    



bool Registrar::cancelCourse(const string& courseName){
    size_t currSize = courses.size();
    for(size_t i =0; i <currSize; i++){
        if(courses[i]->getName() == courseName){
            courses[i]->removeStudentsFromCourse();
            delete courses[i];
            courses[i] = courses[currSize-1];
            courses.pop_back();
            return true;
        }
    }
    return false;
}

void Registrar::purge(){
    for(size_t i =0; i <students.size();i++){
        delete students[i];
    }
    for (size_t j =0; j < courses.size(); j++){
        delete courses[j];
    }
    students.clear();
    courses.clear();
}
    

size_t Registrar::findCourse(const string& course) const {
    for(size_t i =0; i < courses.size(); i++){
        if (courses[i]->getName() == course) {
            return i;
        }
    }
    return courses.size();
}

size_t Registrar::findStudent(const string& student) const {
    for(size_t i =0; i < students.size(); i++){
        if (students[i]->getName() == student) {
            return i;
        }
    }
    return students.size();
}




int main() {
    
    Registrar registrar;
    
    cout << "No courses or students added yet\n";
    cout << registrar << endl;
    
    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;
    
    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;
    
    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;
    
    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;
    
    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
    << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;
    
    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;
    
    /*
     // [OPTIONAL - do later if time]
     cout << "ChangeStudentName FritzTheCat MightyMouse\n";
     registrar.changeStudentName("FritzTheCat", "MightyMouse");
     cout << registrar << endl;
     
     cout << "DropStudentFromCourse MightyMouse CS101.001\n";
     registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
     cout << registrar << endl;
     
     cout << "RemoveStudent FritzTheCat\n";
     registrar.removeStudent("FritzTheCat");
     cout << registrar << endl;
     */
    
    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}

