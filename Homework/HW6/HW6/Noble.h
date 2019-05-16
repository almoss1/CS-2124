//
//  Noble.h
//  HW6
//
//  Created by Alex Mosseri on 3/24/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#ifndef Noble_h
#define Noble_h
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>

namespace WarriorCraft {
    

class Noble{
    friend std::ostream& operator<<(std::ostream& os, const Noble& rhs);
public:
    
    Noble(const std::string& nobleName);
    
    
    void display() const;
    
    std::string getNobleName() const;
    
    
    void hire(Warrior& employee);
    
    void fire(Warrior& firedWarrior);
    
    double getArmyStrength();
    
    void changeStrength(double ratioCount);
    
    void killArmy();
    
    void runaway(Warrior& runawayWarrior);
    
    void battle(Noble& Challenger);
    
    
    
private:
    std::string nobleName;
    bool isDead;
    std::vector<Warrior*> theWarrior;
    
};
}

#endif /* Noble_h */
