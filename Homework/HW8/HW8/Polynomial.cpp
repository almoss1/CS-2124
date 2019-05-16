//
//  Polynomial.cpp
//  HW8
//
//  Created by Alex Mosseri on 4/23/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include "Polynomial.hpp"


//constructor
Polynomial::Polynomial(std::vector<int> coefficients): degree(coefficients.size()-1){
    for (size_t i =0; i <coefficients.size(); i++) {
        Node* newNode = new Node(coefficients[i],head);
        head = newNode;
    }
}

//default constructor
Polynomial::Polynomial():degree(0), head(nullptr){}

//destructor
Polynomial::~Polynomial(){
    Node* headptr;
    while(head!=nullptr){
        headptr= head->next;
        delete head;
        head = headptr;
    }
}

//copy constructor
//Polynomial::Polynomial(const Polynomial& rhs){}

void Polynomial::display(std::ostream& os ,Node* currNode, int degree) const{
    if (currNode == nullptr) {
        std::cout<<" ";
    }
    else{
        display(os, currNode->next, degree++);
        if(currNode->coefficent != 0 ){
            if (degree == 0 || currNode->coefficent == 0) {
                std::cout<<currNode->coefficent<< " ";
            }
            else if  (degree == 1 || currNode->coefficent == 1) {
                std::cout<<currNode->coefficent<< "x^"<< degree<< "+";
            }
            else if (degree!= 0){
                std::cout<<currNode->coefficent<<"x^"<<degree<< "+";
            }
        }
    }
}

//evalutor function
//int Polynomial::evaluate(int xVal){}

//Assignment operator
//Polynomial& Polynomial::operator=(const Polynomial& rhs){}



//output operator
std::ostream& operator<<(std::ostream& os, const Polynomial& rhs){
    Node* headptr = rhs.head;
    if(headptr != nullptr){
        rhs.Polynomial::display(os, headptr, 0);
    }
    return os;
}



//operator +=
//Polynomial& Polynomial::operator+=(const Polynomial& rhs){}

//operator ==
//bool operator==(const Polynomial& lhs, const Polynomial& rhs){}

//doNothing function
void doNothing(Polynomial temp) {}

//operator !=
/*
bool operator!=(const Polynomial& lhs, const Polynomial& rhs){
    if(rhs ==lhs){
        return false;
    }
    return true;
}
*/
//operator +
//Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {}

//Power function
int raiseToPower(int base, int exponent){
    int product =1;
    for (int i =0; i <exponent+1; i++) {
        product*=base;
    }
    return product;
}


