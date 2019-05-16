//
//  main.cpp
//  HW5
//
//  Created by Alex Mosseri on 3/6/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;



class Warrior{
public:
    friend ostream& operator<<(ostream& os, const Warrior& W );
    
    Warrior(const string& name, double strength) : name(name),  warriorStrength(strength), hired(false){}
    
    string getWarriorName() const{
        return name;
    }
    double getWarriorStrength() const{
        return warriorStrength;
    }
    void changeWarriorStrength(double changeStrength){
        warriorStrength = changeStrength;
    }
    bool isHired() const{
        return hired;
    }
    void setHired(bool hire){
        hired =hire;
    }
    bool isDead() const{
        return warriorIsDead;
    }
    
    
private:
    bool warriorIsDead;
    bool hired;
    string name;
    double warriorStrength;
    
    
    
};

class Noble{
public:
    friend ostream& operator<<(ostream& os, const Noble& N);
    
    Noble(const string& nobleName) : nobleName(nobleName), isDead(false) {}
    
    string getNobleName() const{
        return nobleName;
    }
    double getArmyStrength(){
        double sumOfStrength = 0;
        for(size_t i = 0; i <theWarrior.size();i++){
            sumOfStrength+=theWarrior[i]->getWarriorStrength();
        }
        return sumOfStrength;
    }
    void changeStrength(double ratioCount){
        for(size_t i = 0; i <theWarrior.size() ; i++){
            double newStrength = theWarrior[i]->getWarriorStrength() - ratioCount*theWarrior[i]->getWarriorStrength();
            theWarrior[i]->changeWarriorStrength(newStrength);
        }
    }
 
    void hired(Warrior* employee){
        if(this->isDead){
            cout << this->getNobleName() <<"is dead";
        }
        else if(employee->isDead()){
            cout << employee->getWarriorName()<< "is dead";
        }
        else if(employee->isHired()){
            cout <<employee->getWarriorName()<< "is hired"<<endl;
        }
        else{
            theWarrior.push_back(employee);
            employee->setHired(true);
        }
        
    }
    void fired(Warrior* firedWarrior){
        for( size_t i = 0; i < theWarrior.size(); ++i){
            if (theWarrior[i] == firedWarrior){
                cout << "You don't work for me anymore " <<theWarrior[i]->getWarriorName() <<" -- "<< this->getNobleName()<<endl;
                size_t index = i;
                for (size_t j = index; j <theWarrior.size() -1; j++){
                    Warrior* temp = theWarrior[j];
                    theWarrior[j] =theWarrior[j+1];
                    theWarrior[j+1] =temp;
                }
                theWarrior.back()->setHired(false);
                //cout << " ****** " << firedWarrior->getWarriorName() << endl;
                theWarrior.pop_back();
                break;
    
            }
        }
    }
    
    void killArmy(){
        for(size_t i = 0; i < theWarrior.size(); i++){
            theWarrior[i]->changeWarriorStrength(0);
        }
        isDead =true;
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
    void clear(){
        //go through a for loop and delete the warrior and nobles on the heap and then the vector still has open pointers so needs to clear it also using the Vector.clear
        
        for (size_t i = 0; i <theWarrior.size(); i++){
            delete theWarrior[i];
        }
        
        
    }

    

    
    
private:
    string nobleName;
    vector<Warrior*> theWarrior;
    bool isDead;
   
    
};


ostream& operator<<(ostream& os, const Noble& N){
    os << N.nobleName << " has an army of "<< N.theWarrior.size()<<endl;
    for(size_t i = 0; i < N.theWarrior.size(); i++){
        os << "\t"<<*N.theWarrior[i];
    }
   
    
    return os;

}
ostream& operator<<(ostream& os, const Warrior& W){
    os<< W.name<<": "<< W.warriorStrength<< endl;
    return os;
}



//find warrrior
size_t findWarrior(const vector<Warrior*> theWarriors, const string& warriorName){
    for(size_t i =0; i < theWarriors.size(); i++){
        if(theWarriors[i]->getWarriorName() == warriorName){
            return i;
        }
    }
    return theWarriors.size();
}
size_t findNoble(const vector<Noble*> theNobles, const string& nobleName){
    for(size_t i =0; i < theNobles.size(); i++){
        if(theNobles[i]->getNobleName() == nobleName){
            return i;
        }
    }
    return theNobles.size();
}


int main() {
    
    ifstream textfile("nobleWarriors.txt");
        if(!textfile){
            cerr << "Could not open file\n";
            exit(1);
        }
    
//    string linesoftext;
//    vector<string> lines;
//    while (getline(textfile, linesoftext)){
//        lines.push_back(linesoftext);
//    }
//
    vector<Warrior*> theWarrior;
    vector<Noble*> theNobles;
    
    string command;
    while(textfile >> command){
        if (command == "Noble"){
            string nobleName;
            textfile >> nobleName;
            if (findNoble(theNobles, nobleName) == theNobles.size()) {
                theNobles.push_back(new Noble(nobleName));
            }
            else{
                cerr << "The noble " << nobleName<< " already exists";
                
            }
//            cout << "succ" << endl;
            
        }
        
        
        else if(command == "Warrior"){
            double strength;
            string warriorName;
             textfile>> warriorName >> strength;
            
            if(findWarrior(theWarrior, warriorName) == theWarrior.size()){
                theWarrior.push_back(new Warrior(warriorName,strength));
            }
            else{
                cerr << "The warrior " << warriorName<< " already exists";
            }
           
          
        }
        
        
        else if(command == "Hire"){
            string warriorName;
            string noble;
            textfile >> noble >>warriorName;
            
            // If a Noble tries to hire a Warrior and either of them do not exist.
            
            size_t nobleIndex = findNoble(theNobles, noble);
            size_t warriorIndex = findWarrior(theWarrior, warriorName);
            
            if(nobleIndex == theNobles.size()){
                cerr<< "The noble "<< noble<<" doesn't exists";
            }
            else{
                if(warriorIndex == theWarrior.size()){
                    cerr<<"The warrior" <<warriorName<<"doesnt exist";
                }
                else{
                    theNobles[nobleIndex]->hired(theWarrior[warriorIndex]);
                }
            }
        }
           
        
        else if(command == "Fire"){
            string noble;
            string warriorName;
            textfile >> noble >>warriorName;
//             If a Noble tries to fire a Warrior and either the Noble does not exist or does   not have the Warrior by that name in this army.
            
            size_t nobleIndex = findNoble(theNobles, noble);
            size_t warriorIndex = findWarrior(theWarrior, warriorName);
            
            if(nobleIndex == theNobles.size()){
                cerr<< "The noble "<< noble<<" doesn't exists";
            }
            else{
                if(warriorIndex == theWarrior.size()){
                    cerr<<"The warrior" <<warriorName<<"doesnt exist";
                }
                else{
                    theNobles[nobleIndex]->fired(theWarrior[warriorIndex]);
                }
            }
        }
        
        
        
        else if(command == "Battle"){
            string nobleOne;
            string nobleTwo;
            textfile >>nobleOne >>nobleTwo;
            // If a Noble initiates a battle with another Noble, but one or the other does not exist.
            
            size_t n1 =  findNoble(theNobles, nobleOne);
            size_t n2 = findNoble(theNobles, nobleTwo);
            
            
            if(n1 == theNobles.size() || n2 == theNobles.size()){
                cerr<<"The noble does not exist" << endl;
            }
            
            theNobles[n1]->battle(*theNobles[n2]);
            
        }
        else if(command == "Status"){
            cout<<"Status\n" <<"======"<<endl;
            cout<<"Nobles: "<<endl;
            if(theNobles.empty()){
                cout<<"NONE\n";
            }
            else{
                for(size_t i = 0; i <theNobles.size(); i++){
                    cout<< *theNobles[i] << endl;
                }
            }
            cout<<"Unemployed Warriors:\n";
            
            
                for(size_t i = 0; i <theWarrior.size(); i++){
                    if(!theWarrior[i]->isHired()){
                        cout<< *theWarrior[i]<<endl;
                }
            }
            
        }
        
        
        else if(command == "Clear"){
            for (size_t i =0; i<theWarrior.size(); i++) {
                if(!theWarrior[i]->isHired()){
                    delete theWarrior[i];
                }
            }
            for (size_t i = 0; i <theNobles.size(); i++) {
                theNobles[i]->clear();
            }
            
            theNobles.clear();
            theWarrior.clear();
        }
        
        
        
        
    
    
    
    }
    textfile.close()

}
