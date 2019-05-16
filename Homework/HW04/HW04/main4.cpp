//
//  main.cpp
//  HW04
//
//  Created by Alex Mosseri on 2/26/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;




class Warrior{
public:
    Warrior(const string& warriorName, double warriorStrength) : warriorName(warriorName), warriorStrength(warriorStrength){}
    
    void display() const{
        cout <<  warriorName <<" : " << warriorStrength<<endl;
    }
    
    string getWarriorName() const{
        return warriorName;
    }
    double getWarriorStrength() const{
        return warriorStrength;
    }
    void changeWeaponStrength(double newStrength){
        warriorStrength = newStrength;
    }
    bool isHired() const {
        return hired;
    }
    void setHired(bool hire){
        hired = hire;
    }
    
    bool isDead() const{
        return warriorIsDead;
    }
    
private:
    bool hired;
    string warriorName;
    double warriorStrength;
    bool warriorIsDead;
};

class Noble{
public:
    Noble(const string& nobleName) : nobleName(nobleName), isDead(false){}

    
    void display() const {
        cout << nobleName <<" has an army of " <<theWarrior.size()<<endl;
        for( size_t i = 0; i < theWarrior.size(); i++){
            theWarrior[i]-> display();
        }
    }
    string getNobleName() const{
        return nobleName;
    }
    
    
    void hire(Warrior& employee){
        //check to see if warrior and noble is dead
        //if already hired
        if(this->isDead){
            
//            cout << employee.getWarriorName() << endl;
            cout << this->getNobleName()<<" is dead";
        }
        else if (employee.isDead()){
           cout<< employee.getWarriorName() <<" is dead";
        }
        else if(employee.isHired()){
           cout<< employee.getWarriorName() <<" is hired";
        }else{
            cout << "+1 " << endl;
           theWarrior.push_back(&employee);
            employee.setHired(true);
        }
    }
    void fire(Warrior& firedWarrior){
        
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
    
    double getArmyStrength(){
        double res = 0;
        for(size_t x =0; x < theWarrior.size(); x++){
            res += theWarrior[x]->getWarriorStrength();
        }
        return res;
    }
    
    void changeStrength(double ratioCount){
        
        cout << "in CHANGESTR" << "ratio: " << ratioCount << endl;
        for (size_t i =0; i < theWarrior.size(); i++){
            double newStrength = theWarrior[i]->getWarriorStrength() - ratioCount*theWarrior[i]->getWarriorStrength();
            cout<< "ratio: " << ratioCount ;
            theWarrior[i]->changeWeaponStrength(newStrength);
        }
    }
    void killArmy(){
        for(size_t i = 0; i <theWarrior.size();i++){
            theWarrior[i]->changeWeaponStrength(0);
        }
        isDead = true;
    }
    
    
    void battle(Noble& Challenger){
        cout << this->nobleName <<" battles "<< Challenger.nobleName <<endl;
        
        if( this->isDead && Challenger.isDead){
            cout <<"Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        else if( this->getArmyStrength() == Challenger.getArmyStrength()){
            cout<< "Str: "<< this->getArmyStrength() << endl;
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
            
            cout << "Our Army:" << getArmyStrength() << " , " << "Other:  " << Challenger.getArmyStrength() << endl;
            
            float ratioCount = Challenger.getArmyStrength() / this->getArmyStrength();
            
            cout << "RATIO COUNT IN BTTLE" << ratioCount << endl;
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
    
        
    
private:
    string nobleName;
    bool isDead;
    vector<Warrior*> theWarrior;
    
};

//the main function
int main() {
     Noble art("King Arthur");
     Noble lance("Lancelot du Lac");
     Noble jim("Jim");
     Noble linus("Linus Torvalds");
     Noble billie("Bill Gates");
     
     Warrior cheetah("Tarzan", 10);
     Warrior wizard("Merlin", 15);
     Warrior theGovernator("Conan", 12);
     Warrior nimoy("Spock", 15);
     Warrior lawless("Xena", 20);
     Warrior mrGreen("Hulk", 8);
     Warrior dylan("Hercules", 3);
     
     jim.hire(nimoy);
     lance.hire(theGovernator);
     art.hire(wizard);
     lance.hire(dylan);
     linus.hire(lawless);
     billie.hire(mrGreen);
     art.hire(cheetah);

     jim.display();
     lance.display();
     art.display();
     linus.display();
     billie.display();

     art.fire(cheetah);
     art.display();

     art.battle(lance);
     jim.battle(lance);
     linus.battle(billie);
     billie.battle(lance);
//
//
//     // NEW OUTPUT CODE
     cout << "==========\n"
     << "Status after all battles, etc.\n";
     jim.display();
     lance.display();
     art.display();
     linus.display();
     billie.display();
    
     }
     


    

