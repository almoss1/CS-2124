//
//  main.cpp
//  HW8 NEW
//
//  Created by Alex Mosseri on 5/2/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Polynomial.hpp"
using namespace std;

/*
struct Node {
    Node(int coefficent = 0, Node* next = nullptr) : coefficent(coefficent), next(next) {}
    int coefficent;
    Node* next;
};

//class Polynomial
class Polynomial{
    //output operator
    friend ostream& operator<<(ostream& os, const Polynomial& rhs);
    
public:
    
    //constructor
    Polynomial(std::vector<int> coefficients): degree(coefficients.size()-1), head(nullptr){
        for (size_t i =0; i <coefficients.size(); i++) {
            Node* newNode = new Node(coefficients[i],head);
            head = newNode;
        }
    }

    //default constructor
    Polynomial():degree(0), head(nullptr){}

    //GOOD
    //destructor
    ~Polynomial(){
        Node* headptr;
        while(head!=nullptr){
            headptr= head->next;
            delete head;
            head = headptr;
        }
    }
//GOOD
    //copy constructor
    Polynomial(const Polynomial& rhs){
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
    void display(std::ostream& os ,Node* currNode, int degree) const{

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
    int evaluate(int xVal){
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
    int raiseToPower(int base, int exponent){
        int product=1;
        for (size_t i=1; i<exponent+1; i++){
            product*=base;
        }
        return product;
    }

    //GOOD
    //Assignment operator
    
    Polynomial& operator=( Polynomial& rhs){
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
    Polynomial& operator+=(const Polynomial& rhs){
        Node* right = rhs.head;
        Node* left = head;
        Node* newRight = rhs.head;
        Node* newLeft = head;
        
        
        int difference = abs(rhs.degree- degree);
        
 
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
    bool operator==(const Polynomial& rhs){
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
    
    bool operator!=(const Polynomial& rhs){
        return !(*this == rhs);
    }
    
    int getDegree()const{
        return degree;
    }


private:
    //defines degree variable and pointer to Node list
    int degree;
    Node* head;
    
};

//GOOD
//output operator
ostream& operator<<(ostream& os, const Polynomial& rhs){
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

*/





int main() {
   
    //test constructor
    Polynomial p1({17});                 // 17
    Polynomial p2({1, 2});               // x + 2
    Polynomial p3({-1, 5});              // -1x + 5
    Polynomial p4({5, 4, 3, 2, 1});      // 5x^4 + 4x^3 + 3x^2 + 2x + 1
    Polynomial has_a_zero({4, 0, 1, 7}); // 4x^3 + x + 7
    
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;
    cout << "p4: " << p4 << endl;
    cout << "has_a_zero: " << has_a_zero << endl;
    cout << "p2 + p3: " << (p2+p3) << endl;
    cout << "p2 + p4: " << (p2+p4) << endl;
    cout << "p4 + p2: " << (p4+p2) << endl;
    
    
    //test copy constructor - the statement below uses the copy constructor
    //to initialize poly3 with the same values as poly4
    Polynomial p5(p4);
//    cout << "p5 copy:" << p5 << endl;
    
//    cout << "p3 :" << p3 << endl;
//    cout << "p5: " << p5 << endl;
    p5 += p3;
    cout << "Polynomial p5(p4);\n"
    << "p5 += p3;\n";
    
    cout << "p4: " << p4 << endl;
    cout << "p5: " << p5 << endl;
    
    cout << "Calling doNothing(p5)\n";
    doNothing(p5);
    cout << "p5: " << p5 << endl;
//
    //tests the assignment operator
    Polynomial p6;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;  // Causes bools true and false to be printed that way.
    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    p6 = p4;
    cout << "p6: " << p6 << endl;
    cout << "p4: " << p4 << endl;
    cout << boolalpha;
    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    
    //test the evaluaton
        int x = 5;
        cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
        cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;
    
    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
    cout << "p7: " << p7 << endl;
        cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;
    
    cout << boolalpha;
    cout << "(p1 == p2) is " << (p1 == p2) << endl;
    cout << "(p1 != p2) is " << (p1 != p2) << endl;
    
    /*=================================================================
     NEW TEST CODE - test if cleaning the leading 0s
     ===================================================================*/

    Polynomial p8({ 1, 1 });
    Polynomial p9({ -1, 1 });
    Polynomial p10({ 0, 0, 2 });
    //p8 + p9 tests if += does the cleanup()
    //p10 tests if constructor does the cleanup()
    cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;
    
}
