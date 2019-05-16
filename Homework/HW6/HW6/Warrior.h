//
//  Warrior.h
//  HW6
//
//  Created by Alex Mosseri on 3/24/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#ifndef Warrior_h
#define Warrior_h
#include "Noble.h"
#include <iostream>
#include <vector>
#include <string>


namespace WarriorCraft {
    

class Noble;

class Warrior{
    friend std::ostream& operator<<(std::ostream& os, const Warrior& rhs);
public:
    Warrior(const std::string& warriorName, double warriorStrength);
    
    void display() const;
    
    std::string getWarriorName() const;
    
    double getWarriorStrength() const;
    
    void changeWeaponStrength(double newStrength);
    
    bool isHired() const;
    
    void setHired(bool hire);
    
    bool isDead() const;
    
    void runaway();
    
    void setBoss(Noble* employer);
    
private:
    bool hired;
    std::string warriorName;
    double warriorStrength;
    bool warriorIsDead;
    Noble* boss;
};
}

#endif /* Warrior_h */
