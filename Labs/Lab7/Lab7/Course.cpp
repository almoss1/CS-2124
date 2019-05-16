
#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"




std::ostream& operator<<(std::ostream& os, const Course& rhs){
    os<< rhs.name << ": ";
    if(rhs.students.size() == 0){
        os<<"No students"<<std::endl;
        return os;
    }
    for(size_t i =0; i <rhs.students.size();i++){
        os<< rhs.students[i]->getName()<< " ";
    }
    os << std::endl;
    return os;
}

// Course methods needed by Registrar
Course::Course(const std::string& courseName) : name(courseName){}

const std::string& Course::getName() const{
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

