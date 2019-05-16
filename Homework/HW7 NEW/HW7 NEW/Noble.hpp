//
//  Noble.hpp
//  HW7 NEW
//
//  Created by Alex Mosseri on 4/18/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Protector.hpp"


namespace warriorCraft{
    class Protectors;
//NOBLE
class Noble{
    
public:
    Noble(const std::string& name);
    
    std::string getNobleName()const;
    
    
    bool isDead() const;
    
    void setDead(bool dead);
    
    
    
    void kill();
    
    virtual double getStrength()const=0;
    
    virtual void changeStrength(double ratioCount) = 0;
    
    virtual void display();
    
    void battle(Noble& Challenger);
    
    
private:
    std::string name;
    bool nobleIsDead;
    bool hired;
    std::vector<Protectors*> theProtectors;
    
};

//LORD
class Lord : public Noble{
    
public:
    Lord(const std::string& name);
    
    
    double getStrength() const;
    
    virtual void changeStrength(double ratioCount);
    
    
    void hires(Protectors& employee);
    
    void fire(Protectors& firedProtector);
    void display();
    
    bool lostProtector(Protectors& loser);
    
private:
    
    std::string name;
    std::vector<Protectors*> theProtectors;
};




//PERSON WITH STRENGTH TO FIGHT
class PersonWithStrengthToFight : public Noble{
public:
    PersonWithStrengthToFight(const std::string& name, double strength);
    
    double getStrength() const;
    
    
    void changeStrength(double ratioCount);
    
    
private:
    double strength;
    
};

}
#endif /* Noble_hpp */
