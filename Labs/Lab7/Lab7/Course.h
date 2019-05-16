#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <vector>
//#include "Student.h"
//#include "Registrar.h"

class Student;
class Registrar;


class Course {
    friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const std::string& courseName);
    const std::string& getName() const;
    bool addStudent(Student* studentPointer);
    void removeStudentsFromCourse();
    
private:
    std::string name;
    std::vector<Student*> students;
};

#endif



