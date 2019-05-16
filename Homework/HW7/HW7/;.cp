//
//  main.cpp
//  HW7
//
//  Created by Alex Mosseri on 4/3/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//class Protectors;


//PROTECTORS
class Protectors{
public:
    Protectors(const string& name, int strength)  :  name(name), strength(strength),hired(false),protectorIsDead(false) {}
    
    virtual void display() const{
        cout<<"says: Take that in the name of my lord, "<< name;
    }
    
    string getName() const{
        return name;
    }
    
    bool isHired() const {
        return hired;
    }
    void setHired(bool hire){
        hired = hire;
    }
    
    bool isDead() const{
        return protectorIsDead;
    }
    
    void changeProtectorStrength(double newStrength){
        strength = newStrength;
    }
    
    double getStrength(){
        return strength;
    }
    
private:
    string name;
    int strength;
    bool hired;
    bool protectorIsDead;
};



//Archer
class Archer : public Protectors{
public:
    Archer(const string& name, int strength) : Protectors(name, strength)  {}
    
    void display() const{
        cout<<"TWANG!";
        Protectors::getName();
        Protectors::display();
        
        
    }
private:
    
};



//ARCHERS
class Swordsman : public Protectors{
public:
    Swordsman(const string& name, int strength) : Protectors(name, strength){}
    
    void display() const {
        cout<< "CLANG!";
        Protectors::getName();
        Protectors::display();
    }
    
private:
    
};

//WIZARDS
class Wizard : public Protectors{
public:
    Wizard(const string& name, int strength) : Protectors(name, strength){}
    
    void display() const {
        cout<< "POOF. It is such a hard job to control the strength expended with magic!";
    }
    
private:
    
};



//NOBLE
class Noble{
    
public:
    Noble(const string& name): name(name), nobleIsDead(false), hired(false) {}
    
    string getNobleName(){
        return name;
    }
    
    
    bool isDead() const{
        return nobleIsDead;
    }
    
    void setDead(bool dead){
        nobleIsDead =dead;
    }
    
        
    
    void kill(){
        for (size_t i =0 ; i <theProtectors.size(); i++) {
            theProtectors[i]->changeProtectorStrength(0);
        }
        
    }
    
    virtual double getStrength() = 0;
    
    virtual void changeStrength(double ratioCount) = 0;
    
    
    
    void battle(Noble& Challenger){
        cout << this->getNobleName() <<" battles "<< Challenger.getNobleName() <<endl;
        
        if( this->nobleIsDead && Challenger.nobleIsDead){
            cout <<"Oh, NO! They're both dead! Yuck!" << endl;
        }
        
        else if( this->getStrength() == Challenger.getStrength()){
            cout<< "Str: "<< this->getStrength() << endl;
             cout<< "Str: "<< Challenger.getStrength() << endl;
            this->kill();
            Challenger.kill();
            //cout << "MUTUAL";
            cout <<"Mutual Annihalation: "<< this->getNobleName() <<" and " << Challenger.getNobleName() << " die at each other's hands"<<endl;
        }
        
        else if(this->nobleIsDead && (!Challenger.nobleIsDead)){
            cout<< "He's dead, " << Challenger.getNobleName()<<endl;
        }
        
        
        else if((!this->nobleIsDead) && Challenger.nobleIsDead){
            cout<< "He's dead, " << this->getNobleName()<< endl;
            
        }
        
        
        else if((this->getStrength() > Challenger.getStrength())){
            
            //cout << "Our Army:" << getArmyStrength() << " , " << "Other:  " << Challenger.getArmyStrength() << endl;
            
            float ratioCount = Challenger.getStrength() / this->getStrength();
            
            //cout << "RATIO COUNT IN BTTLE" << ratioCount << endl;
            this->changeStrength(ratioCount);
            Challenger.kill();
            //this->dispaly()
            cout << this->getNobleName() << " defeats " << Challenger.getNobleName() <<endl;
            
        }
        
        else if(this->getStrength() < Challenger.getStrength()){
            
            double ratioCount = this->getStrength() / Challenger.getStrength();
            Challenger.changeStrength(ratioCount);
            this->kill();
            //Challenger.display();
            cout <<Challenger.getNobleName() << " defeats " <<this->getNobleName()<<endl;
            
        }
        
    }
    

private:
    string name;
    bool nobleIsDead;
    bool hired;
    vector<Protectors*> theProtectors;


    

};

//LORD
class Lord : public Noble{
    
public:
    Lord(const string& name) : Noble(name){}
    
    
     double getStrength(){
        double res = 0;
        for(size_t x =0; x < theProtectors.size(); x++){
            res += theProtectors[x]->getStrength();
        }
        return res;
    }
    
    virtual void changeStrength(double ratioCount){
        for (size_t i= 0; i <theProtectors.size(); i++) {
            double newStrength = theProtectors[i]->getStrength() - ratioCount*theProtectors[i]->getStrength();
            theProtectors[i]->changeProtectorStrength(newStrength);
        }
    }
    
    
    void hires(Protectors& employee){
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
            employee.setHired(true);
        }
    }
    
    void fire(Protectors& firedProtector){
        
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
                theProtectors.back()->setHired(false);
                cout << " ****** " << firedProtector.getName()<< endl;
                theProtectors.pop_back();
                break;
            }
        }
        
    }
    
   
private:
    
    string name;
    vector<Protectors*> theProtectors;
};




//PERSON WITH STRENGTH TO FIGHT
class PersonWithStrengthToFight : public Noble{
public:
    PersonWithStrengthToFight(const string& name, double strength) : Noble(name), strength(strength) {}
    
     double getStrength(){
        return strength;
    }
    

    void changeStrength(double ratioCount){
        strength*=(1-ratioCount);
        
    }
    
    
private:
    double strength;
   
};



int main() {
    Lord sam("Sam");
    Archer samantha("Samantha", 200);
    sam.hires(samantha);
    Lord joe("Joe");
    PersonWithStrengthToFight randy("Randolf the Elder", 250);
    joe.battle(randy);
    joe.battle(sam);
    Lord janet("Janet");
    Swordsman hardy("TuckTuckTheHardy", 100);
    Swordsman stout("TuckTuckTheStout", 80);
    janet.hires(hardy);
    janet.hires(stout);
    PersonWithStrengthToFight barclay("Barclay the Bold", 300);
    janet.battle(barclay);
    janet.hires(samantha);
    Archer pethora("Pethora", 50);
    Archer thora("Thorapleth", 60);
    Wizard merlin("Merlin", 150);
    janet.hires(pethora);
    janet.hires(thora);
    sam.hires(merlin);
    janet.battle(barclay);
    sam.battle(barclay);
    joe.battle(barclay);
}












/*
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
*/
