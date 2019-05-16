//
//  Polynomial.hpp
//  HW8 NEW
//
//  Created by Alex Mosseri on 5/2/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
#include <vector>



struct Node {
    Node(int coefficent = 0, Node* next = nullptr) : coefficent(coefficent), next(next) {}
    int coefficent;
    Node* next;
};

//class Polynomial
class Polynomial{
    //output operator
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);
    
public:
    
    //constructor
    Polynomial(std::vector<int> coefficients);
    
    //default constructor
    Polynomial();
    
    //GOOD
    //destructor
    ~Polynomial();
    
    
    //GOOD
    //copy constructor
    Polynomial(const Polynomial& rhs);
    
    
    //GOOD
    //display
    void display(std::ostream& os ,Node* currNode, int degree) const;
        
    
    //evalutor function
    int evaluate(int xVal);
    
    
    //Power function
    int raiseToPower(int base, int exponent);
    
    //GOOD
    //Assignment operator
    
    Polynomial& operator=( Polynomial& rhs);
    
    
    
    
    
    
    //GOOD
    //operator +=
    Polynomial& operator+=(const Polynomial& rhs);
    
    
    //GOOD
    //operator ==
    bool operator==(const Polynomial& rhs);
    
    
    ///GOOD
    //operator !=
    
    bool operator!=(const Polynomial& rhs);
    
    int getDegree()const;
    
    
private:
    //defines degree variable and pointer to Node list
    int degree;
    Node* head;
    
};

//GOOD
//output operator
    std::ostream& operator<<(std::ostream& os, const Polynomial& rhs);


//doNothing function
    void doNothing(Polynomial temp);


//operator +
    Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);






#endif /* Polynomial_hpp */
