//
//  main.cpp
//  HW3
//
//  Created by Alex Mosseri on 2/20/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const bool D = false;

class warrior{
    friend ostream& operator<<(ostream& os, const warrior& W);
    class Weapon { //creates the weapon class
        
    public:
        Weapon(const string& weaponName, int weaponStrength): weaponName(weaponName), weaponStrength(weaponStrength){}
        void display() const{
            cout << "Weapon " << weaponName << ", "<< weaponStrength << endl;
        }
        
        //since weaponName and weaponStrength are private variables, functions below have been made to access and change them
        string getWeaponName() const {
            return weaponName;
        }
        int getWeaponStrength() const{
            return weaponStrength;
        }
        
        void changeWeaponStrength(int newStrength){
            weaponStrength = newStrength;
        }
        
        
        //define the variables for weaponName and weaponStrength in private
    private:
        string weaponName;
        int weaponStrength;
        
    };
    
public:
    //warrior constructor is created to initialize the warrior's name, his weapon's name and strength since only he can access his weapon
    warrior(const string& warriorName, const string& weaponName, int weaponStrength): warriorName(warriorName), sword(weaponName, weaponStrength){}
    
    
    string getWarriorName() const{
        return warriorName;
    }
    string getWeaponName() const{
        return sword.getWeaponName();
    }
    int getWeaponStrength() const {
        return sword.getWeaponStrength();
    }
    void changeWeaponStrength(int newStrength){
        sword.changeWeaponStrength(newStrength);
    }
    void battle(warrior& opponent){
        //        opponent.sword.getWeaponStrength();
        //        this->sword ===== (*this)
        //        this->sword.getWeaponStrength() == sword.getWeaponStrength();
        cout << warriorName << " battles " << opponent.getWarriorName()<<endl;
        if (sword.getWeaponStrength() == opponent.sword.getWeaponStrength() && (getWeaponStrength() != 0 && opponent.sword.getWeaponStrength() != 0)){
            cout <<"Mutual Annihilation: "<< warriorName << " and " << opponent.getWarriorName()
            <<" die at each other's hands " << endl;
            sword.changeWeaponStrength(0);
            opponent.sword.changeWeaponStrength(0);
        }
        else if (sword.getWeaponStrength() == 0 &&  opponent.sword.getWeaponStrength() == 0){
            cout <<"Oh, NO! They're both dead! Yuck!" << endl;
        }
        else if (sword.getWeaponStrength() > opponent.sword.getWeaponStrength() && (sword.getWeaponStrength() != 0 && opponent.sword.getWeaponStrength() != 0)){
            cout<< warriorName << " defeats " << opponent.getWarriorName() << endl;
            sword.changeWeaponStrength(getWeaponStrength() -  opponent.sword.getWeaponStrength());
            opponent.sword.changeWeaponStrength(0);
        }
        
        else if (sword.getWeaponStrength() < opponent.sword.getWeaponStrength() && sword.getWeaponStrength() != 0){
            cout << opponent.getWarriorName() << " defeats " << warriorName << endl;
            opponent.sword.changeWeaponStrength(opponent.sword.getWeaponStrength() - sword.getWeaponStrength());
            sword.changeWeaponStrength(0);
        }
        else if (sword.getWeaponStrength() == 0 && opponent.sword.getWeaponStrength() > 0){
            cout << "He's dead, " << opponent.getWarriorName() <<endl ;
        }
        
        else if(sword.getWeaponStrength() >0 && opponent.sword.getWeaponStrength() == 0){
            cout << "He's dead " << warriorName<< endl;
        }
        
        
    }
    
private:
    string warriorName;
    Weapon sword;
    
};

ostream& operator<<(ostream& os, const warrior& W){
    //    what do you want to ouput into the os;
    //    return os;
    os << "Warrior: " << W.warriorName<< ", "<< "Weapon: "<< W.getWeaponName() <<" "<< W.getWeaponStrength();
    return os;
}
void createWarriorandWeapon(const string& name, const string& weapon, int strength, vector<warrior>& theWarrior);
void battle(const string& name1, const string& name2, vector <warrior>& theWarrior);
void displaystatus(const vector<warrior>& theWarrior);
size_t find(const vector <warrior>& theWarrior, const string& name);

//the main function
int main(){
    
    ifstream textfile("warriors.txt");
    if (!textfile){
        cout<< "Could not open the file.\n";
        exit(1);
    }
    string linesoftext;
    vector <string> lines;
    while(getline(textfile, linesoftext)){
        lines.push_back(linesoftext);
        if(D) cout<< linesoftext << "\n";
    }
    
    vector <warrior> theWarriors;
    for(string line : lines)
    {// for loop for pulling the first word from each line of the input file stream
        if(D) cout << "looping; line = " << line << endl;
        string command;
        istringstream iss(line);
        iss >> command;
        
        if(D) cout << "Command = " << command << endl;
        //if the command is Warrior then it calls the createWarriorandWeapon function
        if (command == "Warrior"){
            int strength;
            string name;
            string weapon;
            iss >> name >> weapon >> strength;
            createWarriorandWeapon(name, weapon, strength, theWarriors);
            if(D){
                cout << "Handling warrior command with strength: "
                << strength << " and name " << name << endl;
            }
            
        }
        //if the command is Battle then it calls the battle function
        else if (command == "Battle"){
            string name1;
            string name2;
            iss >> name1 >>name2;
            size_t f = find(theWarriors,name1);
            size_t s = find(theWarriors,name2);
            theWarriors[f].battle(theWarriors[s]);
            if (D) cout <<"Handling battle command with name1 "<< name1
                << " and name2 " << name2 << endl;
            
        }
        //if the command is Status then it calls the displayStatus function
        else if (command == "Status"){
            displaystatus(theWarriors);
        }
    }
    
    textfile.close();
}



//create warrior function- takes in the input file stream and the vector by reference and name of the warrior and weapon and strength of the weapon
void createWarriorandWeapon(const string& name, const string& weapon, int strength,
                            vector<warrior>& theWarrior){
    
    warrior thewarrior(name,weapon,strength);
    cout << thewarrior << endl;
    theWarrior.push_back(thewarrior);
    
}








//find function -- taking in the vector by reference and a string name for warrior
size_t find(const vector <warrior>& theWarrior, const string& name){
    for (size_t x =0; x < theWarrior.size(); x++){
        if (theWarrior[x].getWarriorName() == name){
            return x;
        }
    }
    return theWarrior.size();
}






void displaystatus(const vector<warrior>& theWarrior){
    //displays the number of warriors and then calls the display function for each warrior
    cout<< "There are " << theWarrior.size() << " warriors\n";
    for (size_t i = 0; i < theWarrior.size(); ++i){
        cout << theWarrior[i] << endl;
    }
    
}



