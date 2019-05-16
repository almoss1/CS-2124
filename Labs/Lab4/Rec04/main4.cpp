//
//  main.cpp
//  Rec04
//
//  Created by Alex Mosseri on 2/22/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
// Learning Pointers


#include <iostream>
#include <vector>
using namespace std;


//task 16
struct Complex{
    double real;
    double img;
};

//task17
/*
class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int val )  { x = val; }
private:
    int x;
};*/


//task 18
class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int x )  { this->x = x; } // No confusion!
private:
    int x;
};

//task 28
class Colour {
public:
    Colour(const string& name, unsigned r, unsigned g, unsigned b)
    : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string name;      // what we call this colour
    unsigned r, g, b; // red/green/blue values for displaying
};

//task 29
class SpeakerSystem {
public:
    void vibrateSpeakerCones(unsigned signal) const {
        
        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
        
        
    }
};

class Amplifier {
public:
    void attachSpeakers(const SpeakerSystem& spkrs)
    {
        if(attachedSpeakers)
            cout << "already have speakers attached!\n";
        else
            attachedSpeakers = &spkrs;
    }
    
    void detachSpeakers() { // should there be an "error" message if not attached?
        attachedSpeakers = nullptr;
    }
    
    void playMusic( ) const {
        if (attachedSpeakers)
            attachedSpeakers -> vibrateSpeakerCones(440);
        else
            cout << "No speakers attached\n";
    }
private:
    //const int*  cant change the value
    //int* const 
   const SpeakerSystem* attachedSpeakers = nullptr;
    
};
    
//task 30
class Person {
public:
    Person(const string& name) : name(name) {}
    void movesInWith(Person& newRoomate) {
        if (newRoomate.roomie == nullptr){
            roomie = &newRoomate;        // now I have a new roomie
            newRoomate.roomie = this;    // and now they do too
        }
        else if (newRoomate.roomie != nullptr){
            cout<< newRoomate.roomie<< "has a roomate"<<endl;
        }
        else if(roomie != nullptr){
            cout << roomie <<"has a roomate"<<endl;
            
        }
        
    }
    const string& getName() const { return name; }
    // Don't need to use getName() below, just there for you to use in debugging.
    const string& getRoomiesName() const { return roomie->getName(); }
private:
    Person* roomie;
    string name;
};



int main() {
    //task 2
    int x;
    x = 10;
    cout <<"x = "<< x << endl;
    
    //task 8
    int* p;
    p = &x;
    cout << "p = " << p << endl;
    
    //task 10
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    
    //task 11
    *p = -2763;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    
    //task 12
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    
    //task 13
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    
    //task 14
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    cout<<"*pD contains"<<*pD<<endl;
    *pD = 73.2343;
    *p  = *pD;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *q  = *p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q now contains " << *q << endl;
    //pD  = p;
    //p  = pD;
    
    //task 15
    int joe = 24;
    const int sal = 19;
    int*  pI;
    pI = &joe;
    cout << "pI points to where " << *pI << " is stored\n";
    cout << "*pI now contains " << *pI << endl;
    *pI = 234;
    //pI = &sal;
    *pI = 7623;
    
    const int* pcI;
    pcI = &joe;
    cout << "pcI points to where " << *pcI << " is stored\n";
    cout << "*pcI now contains " << *pcI << endl;
    //*pcI = 234;
    pcI = &sal;
    cout << "pcI points to where " << *pcI << " is stored\n";
    cout << "*pcI now contains " << *pcI << endl;
    //*pcI = 7623;
    
    //int* const cpI;
    int* const cpI(&joe);
    //int* const cpI(&sal);
    //cpI = &joe;
    *cpI = 234;
    //cpI = &sal;
    *cpI = 7623;
    
    //const int* const cpcI;
    const int* const cpcI(&joe);
    //const int* const cpcI(&sal);
    //cpcI = &joe;
    //*cpcI = 234;
    //cpcI = &sal;
    //*cpcI = 7623;
    
    //task 16
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    
    //task17
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
   //task19
    int* pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    cout << "The " << *pDyn
    << " is stored at address " << pDyn
    << " which is in the heap\n";
    
    //task 20
    cout << pDyn << endl;
    delete pDyn;
    cout << pDyn << endl;
    cout << "The 17 might STILL be stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    
    //task21
    pDyn = nullptr;
    double* pDouble = nullptr;
    
    //task22
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    //task24
    double* pTest = new double(12);
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe
    
    //task25
    short* pShrt = new short(5);
    delete pShrt;
    //delete pShrt;
    
    //task 26
    long jumper = 12238743;
    //delete jumper;
    long* ptrTolong = &jumper;
    //delete ptrTolong;
    cout << "ptrTolong points to where " << *ptrTolong << " is stored\n";
    cout << "*ptrTolong now contains " << *ptrTolong << endl;
    Complex cmplx;
    //delete cmplx;
    
    
    //task 27
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        cout << "REAL "<<complV[ ndx ]->real << endl;
        cout << "IMG "<<complV[ ndx ]->img  << endl;
    }
    // release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        delete complV[ndx];
    }
    // clear the vector
    complV.clear();
    
    
    //
    //task 28
    vector<Colour*> colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    
    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
        colours.push_back(new Colour(inputName, inputR, inputG, inputB));
    }
    
    // display all the Colours in the vector:
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        colours[ndx]->display();
        cout << endl;
    }

    // release the heap space pointed at by the pointers in the vector
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
        delete colours[ndx];
    }
    
    colours.clear();
    
//task 30
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");
    
    // now model these two becoming roommates
    joeBob.movesInWith(billyJane);
    
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    joeBob.movesInWith(billyJane);
    
    const int a = 7;
    const int* one(&a);
    cout<< "ONE is equal to"<<*one<<endl;
    int* const two(&joe);
    cout<< "two is equal to"<< *two<<endl;
    
}

    
