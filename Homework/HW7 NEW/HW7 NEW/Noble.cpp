//
//  Noble.cpp
//  HW7 NEW
//
//  Created by Alex Mosseri on 4/18/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>
#include "Noble.hpp"
using namespace std;



//NOBLE
namespace warriorCraft{
    
Noble::Noble(const string& name): name(name), nobleIsDead(false), hired(false) {}
    
    string Noble::getNobleName() const{
        return name;
    }
    
    
    bool Noble::isDead() const{
        return nobleIsDead;
    }
    
    void Noble::setDead(bool dead){
        nobleIsDead =dead;
    }
    
    
    
    void Noble::kill(){
        for (size_t i =0 ; i <theProtectors.size(); i++) {
            theProtectors[i]->changeProtectorStrength(0);
        }
        
    }
    

    void Noble::display(){}
    
    void Noble::battle(Noble& Challenger){
        cout << this->getNobleName() <<" battles "<< Challenger.getNobleName() <<endl;
        
        if( this->nobleIsDead && Challenger.nobleIsDead){
            cout <<"Oh, NO! They're both dead! Yuck!" << endl;
        }
        else if(this->nobleIsDead && (!Challenger.nobleIsDead)){
            cout<< "He's dead, " << Challenger.getNobleName()<<endl;
        }
        
        
        else if((!this->nobleIsDead) && Challenger.nobleIsDead){
            cout<< "He's dead, " << this->getNobleName()<< endl;
            
        }
        
        else if( this->getStrength() == Challenger.getStrength()){
            cout<< "Str: "<< this->getStrength() << endl;
            cout<< "Str: "<< Challenger.getStrength() << endl;
            this->kill();
            Challenger.kill();
            //cout << "MUTUAL";
            cout <<"Mutual Annihalation: "<< this->getNobleName() <<" and " << Challenger.getNobleName() << " die at each other's hands"<<endl;
        }
        
        
        
        
        else if((this->getStrength() > Challenger.getStrength())){
            
            //cout << "Our Army:" << getArmyStrength() << " , " << "Other:  " << Challenger.getArmyStrength() << endl;
            
            float ratioCount = Challenger.getStrength() / this->getStrength();
            
            //cout << "RATIO COUNT IN BTTLE" << ratioCount << endl;
            this->changeStrength(ratioCount);
            Challenger.kill();
            Challenger.setDead(true);
            this->display();
            Challenger.display();
            cout << this->getNobleName() << " defeats " << Challenger.getNobleName() <<endl;
            
        }
        
        else if(this->getStrength() < Challenger.getStrength()){
            
            double ratioCount = this->getStrength() / Challenger.getStrength();
            Challenger.changeStrength(ratioCount);
            this->kill();
            this->setDead(true);
            this->display();
            Challenger.display();
            
            cout <<Challenger.getNobleName() << " defeats " <<this->getNobleName()<<endl;
            
        }
        
    }
    


//LORD
    

    Lord::Lord(const string& name) : Noble(name){}
    
    
    double Lord::getStrength()const{
        double res = 0;
        for(size_t x =0; x < theProtectors.size(); x++){
            res += theProtectors[x]->getStrength();
        }
        return res;
    }
    
    void Lord::changeStrength(double ratioCount){
        for (size_t i= 0; i <theProtectors.size(); i++) {
            double newStrength = theProtectors[i]->getStrength() - ratioCount*theProtectors[i]->getStrength();
            theProtectors[i]->changeProtectorStrength(newStrength);
        }
    }
    
    
    void Lord::hires(Protectors& employee){
        if(this->isDead()){
            cout << this->getNobleName()<<" is dead"<<endl;
        }
        else if(employee.isDead()){
            cout<< employee.getName() << " is dead"<<endl;
        }
        else if(employee.isHired()){
            cout<<employee.getName()<<" is hired"<<endl;
        }
        else{
            theProtectors.push_back(&employee);
            employee.setHired(true, this);
        }
    }
    
    void Lord::fire(Protectors& firedProtector){
        
        // look for the warrior by address instead if by name
        for( size_t i = 0; i < theProtectors.size(); ++i){
            if (theProtectors[i] == &firedProtector){
                cout << theProtectors[i]->getName() << " ,you are fired, " <<
                this->getNobleName()<<endl;
                size_t index = i;
                for (size_t j = index; j <theProtectors.size() -1; j++){
                    Protectors* temp = theProtectors[j];
                    theProtectors[j] =theProtectors[j+1];
                    theProtectors[j+1] =temp;
                }
                theProtectors.back()->setHired(false,nullptr);
                cout << " ****** " << firedProtector.getName()<< endl;
                theProtectors.pop_back();
                break;
            }
        }
        
    }
    bool Lord::lostProtector(Protectors& loser ) {
        if ( !isDead() ) {
            for (size_t i = 0; i < theProtectors.size(); i++) {
                if (theProtectors[i]->getName() == loser.getName()) {
                    changeStrength(this->getStrength() - loser.getStrength());
                    swap(theProtectors[i], theProtectors.back());
                    theProtectors.pop_back();
                    return true;
                }
            }
        }
        return false;
    }
    
    void Lord::display(){
        for (size_t i = 0; i < theProtectors.size(); i++) {
            theProtectors[i]->display();
        }
    }
    





//PERSON WITH STRENGTH TO FIGHT


    PersonWithStrengthToFight::PersonWithStrengthToFight(const string& name, double strength) : Noble(name), strength(strength) {}
    
    double PersonWithStrengthToFight::getStrength()const{
        return strength;
    }
    
    
    void PersonWithStrengthToFight::changeStrength(double ratioCount){
        strength*=(1-ratioCount);
    }
    
}
    

