//
//  main.cpp
//  Lab6
//
//  Created by Alex Mosseri on 3/8/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

/*
 Recitation 06
 CS2124
 
 Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary): title(aTitle), salary(aSalary) {}
    const string& getTitle() const {
        return title;
    }
    double getSalary() const {
        return salary;
        
    }
    void changeSalaryTo(double d) {
        salary = d;
        
    }
private:
    string title;
    double salary;
}; // class Position




class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << " " << rhs.room
        << " " << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
    : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const {
        return name;
        
    }
    unsigned getPhone() const {
        return phone;
        
    }
    
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry




class Directory {
    friend ostream& operator<<(ostream& os, const Directory& Dir){
        //loop through each array and print out the entry
        for(size_t i = 0; i < Dir.size ; i++){
            os <<*Dir.entries[i];
        }
        return os;
    }
        
    
public:
    Directory():size(0), capacity(1), entries(new Entry*[1]){}
    
    unsigned operator[](const string& str) {
        for(size_t i = 0; i <size; i++){
            if(str == entries[i]->getName()){
                return entries[i]->getPhone();
            }
        }
        return 9999999;
    }
        

    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity) {
            //cout<<"Increasing capacity\n";
            Entry** oldEntries = entries;
            entries = new Entry*[capacity * 2];
            for(size_t i =0; i< size; i++){
                entries[i] = oldEntries[i];
            }
            capacity *= 2;
            delete [] oldEntries;
        }// if
        
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
    
//destructor
    
    ~Directory(){
        //loop
        cout<<"Going into the destructor"<<endl;
        for( size_t i =0; i< size; ++i){
            delete entries[i];
        }
        delete [] entries;
    }
    
    
    //copy constructor
    Directory(const Directory& d2){
        cout<< "Going into the copy constuctor"<<endl;
        size = d2.size;
        capacity = d2.capacity;
        entries = new Entry*[capacity];
        for (int i = 0; i < size; i++) {
            entries[i] = new Entry(*d2.entries[i]);
        }
    }
    
    


//assignment operator
Directory& operator=(const Directory& d2) {
    cout<<"Going into the assignment operator"<<endl;
    if (&d2 != this) {
        for( size_t i =0; i< size; ++i){
            delete entries[i];
        }
        delete [] entries;
        size = d2.size;
        capacity =d2.capacity;
        entries = new Entry*[capacity];
        for (int i = 0; i < size; i++) {
            entries[i] = new Entry(*d2.entries[i]);
        }
    }
    return *this;
}

private:
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory



void doNothing(Directory dir) {
    cout << dir << endl;
    
}

int main() {
    
    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;
    
    Directory d2 = d;    // What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout <<" d "<< d << endl;
    
    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";
    
    Directory d3;
    d3 = d2;
    
    // Should display 1592
    cout << d2["Carmack"] << endl;
    
} // main
