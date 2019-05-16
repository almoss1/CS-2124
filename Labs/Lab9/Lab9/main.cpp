//
//  main.cpp
//  Lab9
//
//  Created by Alex Mosseri on 4/5/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class PrintedMaterial{
//    friend ostream& operator<<(ostream& os, const PrintedMaterial& p);
public:
    PrintedMaterial(unsigned numPages) : numberOfPages(numPages){}
    
    virtual void displayNumPages() const  = 0;
//        cout << numberOfPages<<endl;
//    }

     
    
protected:
   
private:
    unsigned numberOfPages;
};




void PrintedMaterial::displayNumPages() const {
    cout << numberOfPages << endl;
}


class Magazine : public PrintedMaterial{
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages){}
    // virtual - NOTE even without writing "virtual"
    // again, this overriden method IS virtual
    // viruality cannot be removed once installed
    // Also note that the = 0 has is not there
    void displayNumPages() const
    {
        cout << "Hi, I'm a Magazine object stored\n"
        << "(but I can't know that I am being\n"
        << "stored (by pointer) in a vector of\n"
        << "PrintedMaterial pointers!\n";
        PrintedMaterial::displayNumPages();
        cout << "(and I'm very glossy!\n";
    }
private:
    int price;
};





class Book : public PrintedMaterial{
public:
    Book(unsigned numPages) : PrintedMaterial(numPages){}

};


class Textbook : public Book{
public:
    Textbook(unsigned numPages, unsigned numIndxPgs) : Book(numPages), numOfIndexPages(numIndxPgs){}
    
    void displayNumPages() const override
    {
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout<< "Index Pages:";
        cout<<numOfIndexPages << endl;
        
    }

protected:
private:
    unsigned numOfIndexPages;
   
};

class Novel : public Book{
public:
    Novel(unsigned numPages) : Book(numPages){}
    
    void displayNumPages() const
    {
        cout << "\nThis is the story of a very\n"
        << " interesting programmer's quest\n"
        << "  understand inheritance.\n"
        << "   The journey is just beginning\n"
        << "    and already the journeyman\n"
        << "      hacker, no - not a hacker! -\n"
        << "         a programmer who reads, and\n"
        << "             studies and understands code\n"
        << "                 Hackers steal and don't even\n"
        << "                      try to understand what they stole\n"
        << "                           before using it.\n"
        << "\n       ...But I digress.\n"
        << "\nThis novel is quite long, there\n"
        << "being this number of pages:\n"
        << "=====================================\n"
        << "                 ";
        PrintedMaterial::displayNumPages();
        cout << "=====================================\n"
        << "Whew!\n"
        << " but there is an exciting\n"
        << "  programming adventure on every\n"
        << "   single one of them!\n"
        << "    And now, let's let the quest continue..."
        << endl << endl << endl;
    }
};


/*
ostream& operator<<(ostream& os, const PrintedMaterial& p){
    os<< p.numberOfPages<< endl;
    return os;
}
*/

// note that reference to PrintedMaterial is the parameter type
// now we can use the dot member operator
// if use the -> operator, thats not going to work (try it!)
void displayNumberOfPages( const PrintedMaterial& anyPM )
{
    anyPM.displayNumPages();
}

int main() {
    Textbook t(5430, 234);
    Novel n(213);
    Magazine m(6);
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
    
    //Magazine mm = pm;
    //cout << "\nA PrintedMaterial material object!\n";
    //PrintedMaterial pm(2345);
    //pm.displayNumPages();
    //PrintedMaterial pm = t;
    //cout << "\nA PrintedMaterial variable containing a TextBook value\n";
    //pm = t; // like putting a t into a vector of PrintedMaterials
    //pm.displayNumPages();
    
    cout << "Try using pointer to base type\n";
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    // instead of putting an actual PrintedMaterial
    // object into the vector, we put a pointer to
    // a PrintedMaterial object (t) into a vector
    // of pointers-to-PrintedMaterial
    // (that is, pointers to the Base class)
    // we'll be "managing" our objects by using
    // pointers to PrintedMaterial values.
    
    pmPtr->displayNumPages();
    
    // print some stuff by calling a generic function
    cout << "\nUse a generic function for printing\n";
    displayNumberOfPages(m);
    displayNumberOfPages(n);
    displayNumberOfPages(t);
    
    // Storing generic objects in a vector
    cout << "\n\nNow we'll use a container. Yea!!!\n\n";
    vector< PrintedMaterial* > allThemPrinties;
    allThemPrinties.push_back(&t);
    allThemPrinties.push_back(&n);
    allThemPrinties.push_back(&m);
    for( size_t ndx=0; ndx < allThemPrinties.size(); ++ ndx )
    {
        allThemPrinties[ndx]->displayNumPages();
        cout << endl;
    }

}
