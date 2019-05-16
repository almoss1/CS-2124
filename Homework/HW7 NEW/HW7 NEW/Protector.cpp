//
//  Protector.cpp
//  HW7 NEW
//
//  Created by Alex Mosseri on 4/18/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//
#include <iostream>
#include <vector>
#include <string>
#include "Protector.hpp"
#include "Noble.hpp"
using namespace std;


namespace warriorCraft {
   
//PROTECTORS

    Protectors::Protectors(const string& name, int strength)  :  name(name), strength(strength),hired(false),protectorIsDead(false) {}
    
    void Protectors::display() const{
        cout<<" says: Take that in the name of my lord, "<<getBossName();
    }
    
    string Protectors::getName() const{
        return name;
    }
    
    bool Protectors::isHired() const {
        return hired;
    }
    void Protectors::setHired(bool hire, Lord* thelord ){
        hired = hire;
        boss = thelord;
    }
    
    bool Protectors::isDead() const{
        return protectorIsDead;
    }
    
    void Protectors::changeProtectorStrength(double newStrength){
        strength = newStrength;
    }
    
    double Protectors::getStrength(){
        return strength;
    }
    
    std::string Protectors::getBossName()const{
        return boss->getNobleName();
    }
    
    bool Protectors::hireBoss(Lord& theBoss){
        boss = &theBoss;
        return true;
    }

    bool Protectors::quit() {
        if (!isDead()) {
            cout<< "flees in terror, abandoning his Lord, " ;
            cout<< getBossName() << endl;
            
            //lets the boss know he/she lost a noble
            boss->lostProtector(*this);
            boss = nullptr;
            return true;
        }
        return false;
    }

//Archer
    Archer::Archer(const string& name, int strength) : Protectors(name, strength)  {}
    
    void Archer::display() const{
        cout<<"TWANG!";
        cout<<Protectors::getName();
        Protectors::display();
        cout<<endl;
    }



//ARCHERS

    Swordsman::Swordsman(const string& name, int strength) : Protectors(name, strength){}
    
    void Swordsman::display() const {
        cout<< "CLANG!";
        cout<<Protectors::getName();
        Protectors::display();
        cout<<endl;
    }
    


//WIZARDS

    Wizard::Wizard(const string& name, int strength) : Protectors(name, strength){}
    
    void Wizard::display() const {
        cout<< "POOF. It is such a hard job to control the strength expended with magic!"<<endl;
    }
    

}
