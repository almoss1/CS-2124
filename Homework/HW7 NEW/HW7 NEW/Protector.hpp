//
//  Protector.hpp
//  HW7 NEW
//
//  Created by Alex Mosseri on 4/18/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#ifndef Protector_hpp
#define Protector_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Noble.hpp"


namespace warriorCraft {
    class Lord;
//PROTECTORS
class Protectors{
public:
    Protectors(const std::string& name, int strength);
    
    virtual void display() const;
    
    std::string getName() const;
    
    bool isHired() const;
    void setHired(bool hire, Lord* thelord);
    
    bool isDead() const;
    
    void changeProtectorStrength(double newStrength);
    
    double getStrength();
    
    std::string getBossName()const;
    
    bool hireBoss(Lord& theBoss);
    bool quit();
private:
    std::string name;
    int strength;
    bool hired;
    bool protectorIsDead;
    Lord* boss =nullptr;
};



//Archer
class Archer : public Protectors{
public:
    Archer(const std::string& name, int strength);
    
    void display() const;
private:
    
};



//ARCHERS
class Swordsman : public Protectors{
public:
    Swordsman(const std::string& name, int strength);
    
    void display() const;
    
private:
    
};

//WIZARDS
class Wizard : public Protectors{
public:
    Wizard(const std::string& name, int strength);
    
    void display() const;
    
private:
    
};
}
#endif /* Protector_hpp */
