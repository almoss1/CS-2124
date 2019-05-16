//
//  Polynomial.hpp
//  HW8
//
//  Created by Alex Mosseri on 4/23/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#ifndef Polynomial_hpp
#define Polynomial_hpp

#include <stdio.h>
#include <iostream>
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
    
    //destructor
    ~Polynomial();
    
    //copy constructor
//    Polynomial(const Polynomial& rhs);
    
    void display(std::ostream& os, Node* currNode, int degree)const;
    
    //evaluator function
//    int evaluate(int xVal);
    
    //Assignment operator
//    Polynomial& operator=(const Polynomial& rhs);
    
    
    
    //operator +=
//    Polynomial& operator+=(const Polynomial& rhs);
    
    //operator ==
//    friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
    
private:
    //defines degree variable and pointer to Node list
    int degree;
    Node* head;
    
};


//doNothing function
void doNothing(Polynomial temp);

//operator !=
//bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

//operator +
//Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);

//Power function
int raiseToPower(int base, int exponent);





#endif /* Polynomial_hpp */
