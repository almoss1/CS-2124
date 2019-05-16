//
//  main.cpp
//  Lab8
//
//  Created by Alex Mosseri on 3/29/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

/*
 testRational.cpp
 CS2124
 Implement the class Rational, so that the following program works.
 */

#include <iostream>

// If time allows use  separate compilation, otherwise just define the class below
//#include "Rational.h"

using namespace std;

// If time allows after implementing separate compilation, then wrap the class in a namespace.
//using namespace CS2124;


class Rational {
    friend ostream& operator<< (ostream& os, const Rational& rhs);
    friend istream& operator>> (istream& is, Rational& rhs);
    friend bool operator==(const Rational& lhs,const Rational& rhs);
    
public:
    Rational(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator){ normalize();}
    
    int greatestCommonDivisor(int x, int y) {
        while (y != 0) {
            int temp = x % y;
            x = y;
            y = temp;
        }
        return x;
    }
    
    void normalize() {
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int gcd = greatestCommonDivisor(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
    }
    
    
    Rational& operator +=(const Rational& rhs){
        numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);
        denominator = (denominator * rhs.denominator);
        normalize();
        return *this;
    }
    Rational& operator++(){
        *this += 1;
        return (*this);
    }
    
    //post increment
    Rational operator++(int){
        Rational temp(*this);
        *this+=1;
        return temp;
    }
    
    explicit operator bool() const{
        return (!(numerator == 0));
        
    }
    
private:
    int numerator;
    int denominator;
};


ostream& operator <<(ostream &os, const Rational& rhs){
    if (rhs.denominator == 0){
        os << "Sorry but this is undefined";
    }
    else if(rhs.denominator == 1){
        os << rhs.numerator;
    }
    else if(rhs.numerator == 0){
        os << "0";
    }
    else{
        os << rhs.numerator << "/" << rhs.denominator;
    }
    return os;
}

istream& operator >>(istream &is, Rational& rhs){
    char divide;
    is >> rhs.numerator >> divide >> rhs.denominator ;
    rhs.normalize();
    return is;
}


Rational operator +(const Rational& lhs, const  Rational& rhs){
    Rational result = lhs;
    result+= rhs;
    return result;
}

bool operator ==(const Rational& lhs , const Rational& rhs) {
    return ((lhs.numerator == rhs.numerator) && (lhs.denominator == rhs.denominator));
}

bool operator !=(const Rational& lhs,const Rational& rhs){
    return !(lhs == rhs);
}
//pre-decrement
Rational& operator--(Rational& rhs){
    rhs+=-1;
    return rhs;
}

//post decrement
Rational operator--(Rational& rhs, int){
    Rational tempRational(rhs);
    rhs+= -1;
    return tempRational;
}

bool operator<(const Rational& lhs,const Rational& rhs){
    return !(lhs==rhs) && (lhs < rhs);
}


bool operator >(const Rational& lhs, const Rational& rhs){
    if(!(lhs==rhs) && !(lhs < rhs)){
        return true;
    }
    else{
        return false;
    }
}

bool operator >=(const Rational& lhs, const Rational& rhs){
    if((lhs ==rhs) || (lhs > rhs)){
        return true;
    }
    else{
        return false;
       }
}

bool operator <=( const Rational& lhs,const Rational& rhs){
    if((lhs ==rhs) || (lhs <rhs)){
        return true;
    }
    else{
        return false;
    }
}






int main() {
    Rational twoThirds(2,3);
    cout << twoThirds << endl;
    
    Rational a, b;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "a: ";
    cin >> a;
    cout << "Input a rational number, e.g. 6/9.\n";
    cout << "b: ";
    cin >> b;
    const Rational one = 1;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;    // Implement as member
    cout << "a = " << a << endl;
    
    // Implement as non-member, but not a friend
    cout << "a + one: " << (a + one) << endl;
    cout << "a == one: " << boolalpha << (a == one) << endl;
    
    // How does this manage to work?
    // It does NOT require writing another == operator.
    cout << "1 == one: " << boolalpha << (1 == one) << endl;
    
    // Do not implement as friend.
    cout << "a != one: " << boolalpha << (a != one) << endl;
    
    
    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;
    cout << "a = " << a << endl;
    
    cout << "++ ++a = " << (++ ++a) << endl;
    cout << "a = " << a << endl;
    cout << "-- --a = " << (-- --a) << endl;
    cout << "a = " << a << endl;
    
    cout << "a++ ++ = " << (a++ ++) << endl;
    cout << "a = " << a << endl;
    
    // Even though the above example, (a++ ++), compiled, the
    // following shouldn't.
    // But some compiler vendors might let it...  Is your compiler
    // doing the right thing?
    //cout << "a-- -- = " << (a-- --) << endl;
    cout << "a = " << a << endl;
    
    
    // Should report that 1 is true
    if (Rational(1)) {
        cout << "1 is true" << endl;
    } else {
        cout << "1 is false" << endl;
    }
    
    // Should report that 0 is false
    if (Rational(0)) {
        cout << "0 is true" << endl;
    } else {
        cout << "0 is false" << endl;
    }
    
    
}

