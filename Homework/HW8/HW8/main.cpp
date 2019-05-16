//
//  main.cpp
//  HW8
//
//  Created by Alex Mosseri on 4/22/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//


#include "Polynomial.hpp"
#include <iostream>
#include <vector>
using namespace std;

void doNothing(Polynomial temp) {}

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
//    cout << "p2 + p3: " << (p2+p3) << endl;
//    cout << "p2 + p4: " << (p2+p4) << endl;
//    cout << "p4 + p2: " << (p4+p2) << endl;
    
    
    //test copy constructor - the statement below uses the copy constructor
    //to initialize poly3 with the same values as poly4
    Polynomial p5(p4);
//    p5 += p3;
    cout << "Polynomial p5(p4);\n"
    << "p5 += p3;\n";
    
    cout << "p4: " << p4 << endl;
    cout << "p5: " << p5 << endl;
    
    cout << "Calling doNothing(p5)\n";
    doNothing(p5);
    cout << "p5: " << p5 << endl;
    
    //tests the assignment operator
    Polynomial p6;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;  // Causes bools true and false to be printed that way.
//    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    p6 = p4;
    cout << "p6: " << p6 << endl;
    cout << boolalpha;
//    cout << "(p4 == p6) is " << (p4 == p6) << endl;
    
    //test the evaluaton
//    int x = 5;
//    cout << "Evaluating p1 at " << x << " yields: " << p1.evaluate(5) << endl;
//    cout << "Evaluating p2 at " << x << " yields: " << p2.evaluate(5) << endl;
    
    Polynomial p7({3, 2, 1});           // 3x^2 + 2x + 1
    cout << "p7: " << p7 << endl;
//    cout << "Evaluating p7 at " << x << " yields: " << p7.evaluate(5) << endl;
    
    cout << boolalpha;
//    cout << "(p1 == p2) is " << (p1 == p2) << endl;
//    cout << "(p1 != p2) is " << (p1 != p2) << endl;
    
    /*=================================================================
     NEW TEST CODE - test if cleaning the leading 0s
     ===================================================================*/
    
    Polynomial p8({ 1, 1 });
    Polynomial p9({ -1, 1 });
    Polynomial p10({ 0, 0, 2 });
    //p8 + p9 tests if += does the cleanup()
    //p10 tests if constructor does the cleanup()
//    cout << "((p8 + p9) == p10) is " << ((p8 + p9) == p10) << endl;
    
    
}


/*
 p1: 17
 p2: x + 2
 p3: -1x + 5
 p4: 5x^4 + 4x^3 + 3x^2 + 2x + 1
 has_a_zero: 4x^3 + x + 7
 p2 + p3: 7
 p2 + p4: 5x^4 + 4x^3 + 3x^2 + 3x + 3
 p4 + p2: 5x^4 + 4x^3 + 3x^2 + 3x + 3
 Polynomial p5(p4);
 p5 += p3;
 p4: 5x^4 + 4x^3 + 3x^2 + 2x + 1
 p5: 5x^4 + 4x^3 + 3x^2 + x + 6
 Calling doNothing(p5)
 p5: 5x^4 + 4x^3 + 3x^2 + x + 6
 p6: 0
 (p4 == p6) is false
 p6: 5x^4 + 4x^3 + 3x^2 + 2x + 1
 (p4 == p6) is true
 Evaluating p1 at 5 yields: 17
 Evaluating p2 at 5 yields: 7
 p7: 3x^2 + 2x + 1
 Evaluating p7 at 5 yields: 86
 (p1 == p2) is false
 (p1 != p2) is true
 ((p8 + p9) == p10) is true
 */

