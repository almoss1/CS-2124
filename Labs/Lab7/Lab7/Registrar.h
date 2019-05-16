//Registrar header file
#ifndef REGISTRAR_H
#define REGISTRAR_H
#include <iostream>
#include <vector>
#include <string>
//#include "Student.h"
//#include "Course.h"

class Student;
class Course;
class Registrar {
    friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const std::string& theCourse);
    bool addStudent(const std::string&);
    bool enrollStudentInCourse(const std::string& studentName,
                                const std::string& courseName);
    bool cancelCourse(const std::string& courseName);
    void purge();
    
private:
    size_t findStudent(const std::string&) const;
    size_t findCourse(const std::string&) const;
    
    std::vector<Course*> courses;
    std::vector<Student*> students;
};

#endif
