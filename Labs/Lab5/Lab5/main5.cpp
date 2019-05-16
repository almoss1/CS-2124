//
//  main.cpp
//  Lab5
//
//  Created by Alex Mosseri on 3/1/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//section
class Section{
    
friend ostream& operator<<(ostream& os, const Section& sec);
    
    
    
    //timeslot
    class TimeSlot{
        friend ostream& operator<<(ostream& os, const TimeSlot& Timesl){
            if (Timesl.Time > 12){
                cout << Timesl.Day << ", " << Timesl.Time - 12 << " PM"<< endl;
            }
            else{
                cout << Timesl.Day << ", " << Timesl.Time << " AM" << endl;
            }
            return os;
        }
        
    public:
        TimeSlot(const string& Day, const int Time) : Day(Day),Time(Time){}
        
           
    private:
        string Day;
        int Time;
    };
    
    
    
    //student record
    class StudentRecord{
        
        friend ostream& operator<<(ostream& os, const StudentRecord& sr){
            os << "Student: " << sr.name << " Grades: ";
            for (size_t i = 0; i <sr.grades.size(); ++i){
                cout << sr.grades[i] <<" ";
            }
            return os;
        }
        
    public:
        
        
        
        StudentRecord(const string& name) : name(name), grades(14,-1) {}
        
        void display(){
            cout<< "Student:"<<name<<"Grades:";
            for(size_t i = 0; i < grades.size(); ++i){
                cout << grades[i] << " ";
            }
        }
        
        string getStudentName() const{
            return name;
        }
        
        void changeGrade(int newGrade, int week){
            for( size_t i = 0; i <grades.size(); i++){
                if(i == week){
                    grades[i] = newGrade;
                    break;
                }
            }
        }
        
        
    private:
        string name;
        vector<int> grades;
        
    };
    
    
    //section
public:
    Section(const string& TAsection,const string& day, const int& timesl) : TAsection(TAsection), Timesl(day,timesl)  {};
    
    void addStudent(const string& student){
        StudentRecord* newStudent = new StudentRecord(student);
        students.push_back(newStudent);
        
    }
    string getSectionName() const {
        return TAsection;
    }
    
    void addGrade(string studentName, int grade, int week){
        for (size_t i = 0; i < students.size(); i++){
            if( students[i] ->getStudentName()== studentName){
                students[i] -> changeGrade(grade,week);
            }
        }
    }
    
    void reset(){
        for(size_t i = 0; i < students.size(); i++){
            cout << "deleting "<< *students[i]<<endl;
            delete students[i];
        }
        students.clear();
    }
    
    ~Section(){
        reset();
    }
    
    Section(const Section& sect) : TAsection(sect.TAsection), Timesl(sect.Timesl){
        for (size_t y =0; y < sect.students.size(); y++){
            students.push_back(new StudentRecord(*sect.students[y]));
            
        }
    }
    
private:
    string TAsection;
    TimeSlot Timesl;
    vector<StudentRecord*> students;
    
    
    
    
};




//Labworker
class LabWorker{
    friend ostream& operator<<(ostream& os, const LabWorker& lw );
public:
    
    LabWorker(const string& LabWorkerName): LabWorkerName(LabWorkerName){}
    
    void addSection(Section& theSection){
        theSectionptr = &theSection;
    }
    
    void addGrade(const string& name, int grade, int week){
        if (theSectionptr != nullptr){
            theSectionptr->addGrade(name, grade,week);
        }
        else{
            cerr << "theSectionptr is nullptr";
        }
    }
private:
    string LabWorkerName;
    Section* theSectionptr = nullptr;
    
};
ostream& operator<<(ostream& os, const LabWorker& lw){
    if(!lw.theSectionptr){
        os << lw.LabWorkerName << " doesn't have a section";
        return os;
    }
    else{
        os << lw.LabWorkerName <<" has section " << *lw.theSectionptr;
        return os;
    }
}

ostream& operator<<(ostream& os, const Section& sec){
    os << "Section: " << sec.TAsection<< " TimeSlot :" <<sec.Timesl;
    for (size_t i= 0; i <sec.students.size(); i++) {
        os<< *sec.students[i]<<endl;
        
    }
    return os;
}






// Test code
void doNothing(Section sec) {
    cout << sec << endl;
}

int main() {
    
    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;
    
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;
    
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe("Moe");
    cout << moe << endl;
    
    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection(secA2);
    cout << moe << endl;
    
    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection(secB3);
    cout << jane << endl;
    
    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;
    
    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;
    
    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
    << "those students (or rather their records?)\n";
    
    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
    << "then make sure the following call works properly, i.e. no memory leaks\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";
    
} // main


