//
//  Noble.cpp
//  HW6
//
//  Created by Alex Mosseri on 3/24/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Noble.h"
#include "Warrior.h"
using namespace std;
using namespace WarriorCraft;

namespace WarriorCraft {


Noble::Noble(const string& nobleName) : nobleName(nobleName), isDead(false) isHired(false){}
    
    
void Noble::display() const {
    cout << nobleName <<" has an army of " <<theWarrior.size()<<endl;
    for( size_t i = 0; i < theWarrior.size(); i++){
        theWarrior[i]-> display();
    }
}

string Noble::getNobleName() const {
    return nobleName;
}
    
    
void Noble::hire(Warrior& employee) {
    //check to see if warrior and noble is dead
    //if already hired
    if(this->isDead) {
            
    //            cout << employee.getWarriorName() << endl;
        cout << this->getNobleName()<<" is dead";
    }
    else if (employee.isDead()){
        cout<< employee.getWarriorName() <<" is dead";
    }
    else if(employee.isHired()){
        cout<< employee.getWarriorName() <<" is hired";
    }
    else{
        //cout << "+1 " << endl;
        theWarrior.push_back(&employee);
        employee.setHired(true);
        employee.setBoss(this);
    }
}
void Noble::fire(Warrior& firedWarrior){
        
    // look for the warrior by address instead if by name
    for( size_t i = 0; i < theWarrior.size(); ++i){
        if (theWarrior[i] == &firedWarrior){
            cout << theWarrior[i]->getWarriorName() << " ,you are fired, " <<
            this->nobleName<<endl;
            size_t index = i;
            for (size_t j = index; j <theWarrior.size() -1; j++){
                Warrior* temp = theWarrior[j];
                theWarrior[j] =theWarrior[j+1];
                theWarrior[j+1] =temp;
            }
            theWarrior.back()->setHired(false);
            cout << " ****** " << firedWarrior.getWarriorName() << endl;
            theWarrior.pop_back();
            break;
        }
    }
    
}
    
double Noble::getArmyStrength(){
    double res = 0;
    for(size_t x =0; x < theWarrior.size(); x++){
        res += theWarrior[x]->getWarriorStrength();
    }
    return res;
}
    
void Noble::changeStrength(double ratioCount){
    
    //cout << "in CHANGESTR" << "ratio: " << ratioCount << endl;
    for (size_t i =0; i < theWarrior.size(); i++){
        double newStrength = theWarrior[i]->getWarriorStrength() - ratioCount*theWarrior[i]->getWarriorStrength();
        //cout<< "ratio: " << ratioCount ;
        theWarrior[i]->changeWeaponStrength(newStrength);
    }
}


void Noble::killArmy(){
    for(size_t i = 0; i <theWarrior.size();i++){
        theWarrior[i]->changeWeaponStrength(0);
    }
    isDead = true;
}

void Noble::runaway(Warrior& runawayWarrior){
    //cout <<"+1";
    for( size_t i = 0; i < theWarrior.size(); ++i){
        //cout<<"in the loop";
        if (theWarrior[i] == &runawayWarrior){
            cout << theWarrior[i]->getWarriorName() << " flees in terror, abandoning his lord " << this->nobleName <<endl;
            size_t index = i;
            for (size_t j = index; j <theWarrior.size() -1; j++){
                Warrior* temp = theWarrior[j];
                theWarrior[j] =theWarrior[j+1];
                theWarrior[j+1] =temp;
            }
            theWarrior.back()->setHired(false);
            //cout << " ****** " << runawayWarrior.getWarriorName() << endl;
            theWarrior.pop_back();
            break;
        }
    }
    
}


void Noble::battle(Noble& Challenger){
    cout << this->nobleName <<" battles "<< Challenger.nobleName <<endl;
    
    if( this->isDead && Challenger.isDead){
        cout <<"Oh, NO! They're both dead! Yuck!" << endl;
    }
    
    else if( this->getArmyStrength() == Challenger.getArmyStrength()){
        //cout<< "Str: "<< this->getArmyStrength() << endl;
        this->killArmy();
        Challenger.killArmy();
        //cout << "MUTUAL";
        cout <<"Mutual Annihalation: "<< this->getNobleName() <<" and " << Challenger.getNobleName() << " die at each other's hands"<<endl;
    }
    
    else if(isDead && (!Challenger.isDead)){
        cout<< "He's dead, " << Challenger.getNobleName()<<endl;
        
    }
    
    
    else if((!isDead) && Challenger.isDead){
        cout<< "He's dead, " << this->getNobleName()<< endl;
    }
    
    
    else if((this->getArmyStrength() > Challenger.getArmyStrength())){
        
        //cout << "Our Army:" << getArmyStrength() << " , " << "Other:  " << Challenger.getArmyStrength() << endl;
        
        float ratioCount = Challenger.getArmyStrength() / this->getArmyStrength();
        
        //cout << "RATIO COUNT IN BTTLE" << ratioCount << endl;
        this->changeStrength(ratioCount);
        Challenger.killArmy();
        cout << this->nobleName << " defeats " << Challenger.getNobleName() <<endl;
        
    }
    
    else if(this->getArmyStrength() < Challenger.getArmyStrength()){
        
        double ratioCount = this->getArmyStrength() / Challenger.getArmyStrength();
        Challenger.changeStrength(ratioCount);
        this->killArmy();
        
        cout <<Challenger.getNobleName() << " defeats " <<this->getNobleName()<<endl;
        
    }
    
}
    
    ostream& operator<<(ostream& os, const Noble& rhs){
        os << rhs.nobleName << " has an army of "<< rhs.theWarrior.size()<<endl;
        for(size_t i = 0; i < rhs.theWarrior.size(); i++){
            os << "\t"<<*rhs.theWarrior[i];
        }
        
        
        return os;
        
    }
    
}
