
#include <iostream>
#include <vector>
#include <string>
#include "Registrar.h"
#include "Course.h"
#include "Student.h"
using namespace std;



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
