//
//  Warrior.cpp
//  HW6
//
//  Created by Alex Mosseri on 3/24/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <stdio.h>
#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


namespace WarriorCraft {

Warrior::Warrior(const string& warriorName, double warriorStrength) : warriorName(warriorName), warriorStrength(warriorStrength){}

void Warrior::display() const{
    cout <<  warriorName <<" : " << warriorStrength<<endl;
}

string Warrior::getWarriorName() const{
    return warriorName;
}
double Warrior::getWarriorStrength() const{
    return warriorStrength;
}
void Warrior::changeWeaponStrength(double newStrength){
    warriorStrength = newStrength;
}
bool Warrior::isHired() const {
    return hired;
}
void Warrior::setHired(bool hire){
    hired = hire;
}

bool Warrior::isDead() const{
    return warriorIsDead;
}
void Warrior::runaway(){
    //cout<<"+2";
    boss->runaway(*this);
    boss = nullptr;
    
}
void Warrior::setBoss(Noble* employer){
    boss = employer;
    
}
    ostream& operator<<(ostream& os, const Warrior& rhs){
        os<< rhs.warriorName<<": "<< rhs.warriorStrength<< endl;
        return os;
    }
    


}
