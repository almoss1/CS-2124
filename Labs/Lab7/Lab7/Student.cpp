
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Registrar.h"





std::ostream& operator<<(std::ostream& os, const Student& rhs){
    os << rhs.name << ": ";
    if(rhs.courses.size() ==0){
        os<<"No Courses";
    }
    for (size_t i =0; i <rhs.courses.size(); i++) {
        os<<rhs.courses[i]->getName()<<" ";
    }
        os << std::endl;
    return os;
}

// Student methods needed by Registrar
Student::Student(const std::string& name) :name(name) {}
const std::string& Student::getName() const{
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


