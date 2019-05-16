//
//  Polynomial.cpp
//  HW8 NEW
//
//  Created by Alex Mosseri on 5/2/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include "Polynomial.hpp"
#include <iostream>
#include <vector>




    //constructor
Polynomial::Polynomial(std::vector<int> coefficients): degree(coefficients.size()-1), head(nullptr){
        for (size_t i =0; i <coefficients.size(); i++) {
            Node* newNode = new Node(coefficients[i],head);
            head = newNode;
        }
    }
    
    //default constructor
Polynomial::Polynomial():degree(0), head(nullptr){}
    
    //GOOD
    //destructor
Polynomial::~Polynomial(){
        Node* headptr;
        while(head!=nullptr){
            headptr= head->next;
            delete head;
            head = headptr;
        }
    }


    //GOOD
    //copy constructor
Polynomial::Polynomial(const Polynomial& rhs){
        head = nullptr;
        degree =rhs.degree;
        Node* ptr = rhs.head;
        while(ptr != nullptr){
            Node* temp = new Node(ptr->coefficent);
            if (head == nullptr) {
                head = temp;
            }
            else{
                Node* last = head;
                while (last->next) {
                    last = last->next;
                }
                last->next = temp;
            }
            ptr = ptr->next;
        }
    }
    
    
    //GOOD
    //display
void Polynomial::display(std::ostream& os ,Node* currNode, int degree) const{
        
        if (currNode == nullptr) {
            
            std::cout<<" ";
        }
        else{
            
            display(os, currNode->next, degree+1);
            if(currNode->coefficent != 0){
                if (degree == 0) {
                    std::cout<<currNode->coefficent<< " ";
                }
                else if  (degree == 1)  {
                    if(currNode->coefficent ==1){
                        std::cout<<"x + ";
                    }
                    else{
                        std::cout<<currNode->coefficent<< "x +";
                    }
                }
                else{
                    if(currNode->coefficent ==1){
                        std::cout<<"x^"<<degree <<"+";
                    }
                    else{
                        std::cout<<currNode->coefficent<<"x^"<<degree<< "+";
                    }
                }
            }
        }
    }
    
    //evalutor function
int Polynomial::evaluate(int xVal){
        int sum=0;
        int degreeCounter=0;
        Polynomial first= *this;
        while (first.head !=nullptr){
            int product = raiseToPower(xVal, degreeCounter);
            sum+=(first.head->coefficent)*(product);
            ++degreeCounter;
            first.head=first.head->next;
        }
        return sum;
    }
    
    
    //Power function
int Polynomial::raiseToPower(int base, int exponent){
        int product=1;
        for (size_t i=1; i<exponent+1; i++){
            product*=base;
        }
        return product;
    }
    
    //GOOD
    //Assignment operator
    
Polynomial& Polynomial::operator=( Polynomial& rhs){
        if( this != &rhs){
            Node* tempDel;
            // delete everything in rhs
            while(head!=nullptr){
                tempDel= head->next;
                delete head;
                head = tempDel;
            }
            //tempDel=nullptr;
            
            head = new Node(rhs.head->coefficent);
            // assign everything from self to rhs
            Node* lhptr = head;
            Node* rhptr = rhs.head->next;
            while(rhptr!=nullptr){
                lhptr->next = new Node(rhptr->coefficent);
                rhptr = rhptr->next;
                lhptr = lhptr->next;
            }
            
            degree=rhs.degree;
            
        }
        return *this;
    }
    
    
    
    
    
    
    //GOOD
    //operator +=
Polynomial& Polynomial::operator+=(const Polynomial& rhs){
        Node* right = rhs.head;
        Node* left = head;
        Node* newRight = rhs.head;
        Node* newLeft = head;
        
        
    int difference = abs(rhs.degree- degree);
        
        /* make the right && left point to the rightmost node;  */
        while(right!=nullptr){
            right = right->next;
            
        }
        for(int i=0; i <difference;i++){
            if (degree > rhs.degree){
                right = new Node(0);
            }
            else if(degree < rhs.degree){
                left->next =new Node(0);
            }
        }
        while(newRight!= nullptr){
            newLeft->coefficent+= newRight->coefficent;
            newLeft= newLeft->next;
            newRight = newRight->next;
        }
        
        return *this;
    }
    
    
    
    
    
    
    //GOOD
    //operator ==
bool Polynomial::operator==(const Polynomial& rhs){
        Node* right = rhs.head;
        Node* left = head;
        if(rhs.head != head){
            return false;
        }
        else{
            while (right != nullptr && left != nullptr) {
                if(right->coefficent != left->coefficent){
                    return false;
                }
                right =right->next;
                left =left->next;
            }
            return true;
        }
        
    }
    
    
    ///GOOD
    //operator !=
    
bool Polynomial::operator!=(const Polynomial& rhs){
        return !(*this == rhs);
    }
    
int Polynomial::getDegree()const{
        return degree;
    }


//GOOD
//output operator
std::ostream& operator<<(std::ostream& os, const Polynomial& rhs){
    Node* headptr = rhs.head;
    if(rhs.degree == 0){
        if(rhs.head != nullptr){
            os<< headptr->coefficent;
        }
    }
    else if(headptr != nullptr){
        rhs.display(os, headptr, 0);
    }
    return os;
}


//doNothing function
void doNothing(Polynomial temp) {}


//operator +
Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs) {
    if(lhs.getDegree() > rhs.getDegree()){
        Polynomial result(lhs);
        result += rhs;
        return result;
    }else{
        Polynomial result(rhs);
        result += lhs;
        return result;
    }
}





