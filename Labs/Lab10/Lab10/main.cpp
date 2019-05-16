//
//  main.cpp
//  Lab10
//
//  Created by Alex Mosseri on 4/14/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//


#include <iostream>
#include <vector>

using namespace std;

class Instrument {
public:
    virtual void makeSound() const =0;
    virtual void play() const=0;
private:
    
};

void Instrument::makeSound() const { //giving a body to the pure virtual method!
    cout<<"To make a sound.... ";
}



class Brass: public Instrument {
public:
    Brass(unsigned pitch) : pitch(pitch) {}
    
    void makeSound() const {
        Instrument::makeSound();
        cout<<"blow on mouthpiece of size " << pitch<<endl;
    }
    
private:
    unsigned pitch;
    
};

class Trumpet: public Brass{
public:
    using Brass::Brass;
    
    void play() const {
        cout<<"Toot ";
    }
private:
    
};

class Trombone: public Brass {
public:
    using Brass::Brass;
    
    void play() const {
        cout<<" Blat ";
    }
private:
    
};

class String: public Instrument {
public:
    String(unsigned pitch) : pitch(pitch) {}
    
    void makeSound() const {
        Instrument::makeSound();
        cout<<"blow on mouthpiece of size " << pitch<<endl;
    }
    
private:
    unsigned pitch;
};

class Violin: public String {
public:
    using String::String;
    void play() const {
        cout<<" Screech ";
    }
private:
    
};

class Cello: public String {
public:
    using String::String;
    void play() const {
        cout<<" Sqwuack ";
    }
private:
    
};

class Percussion: public Instrument {
public:
    void makeSound() const {
        Instrument::makeSound();
        cout<<"hit me!! " <<endl;
    }
private:
    
};

class Drum: public Percussion {
public:
    using Percussion::Percussion;
    void play() const {
        cout<<" Boom  ";
    }
private:
};

class Cymbal: public Percussion {
public:
    using Percussion::Percussion;
    void play() const {
        cout<<" Crash ";
    }
private:
    
};



class MILL {
public:
    void receiveInstr(Instrument& instrument) {
        instrument.makeSound();
        for ( size_t i=0; i <instrumentBin.size(); i++){
            if (instrumentBin[i]==nullptr) {
                instrumentBin[i]= &instrument;
                return;
            }
        }
        instrumentBin.push_back(&instrument);
        return;
    }
    
    Instrument* loanOut(){
        for ( size_t i=0; i <instrumentBin.size(); i++){
            if (instrumentBin[i]!=nullptr) {
                Instrument* temp = instrumentBin[i];
                instrumentBin[i]=nullptr;
                return temp;
            }
        }
        return nullptr;
        
    }
    
    void dailyTestPlay() {
        for ( size_t i=0; i <instrumentBin.size(); i++) {
            if (instrumentBin[i]!=nullptr) {
                instrumentBin[i]->makeSound();
            }
        }
    }
    
private:
    vector<Instrument*> instrumentBin;
    
};


class Musician {
public:
    Musician() : instr(nullptr) {}
    
    void acceptInstr(Instrument* instPtr) {
        instr = instPtr;
        
    }
    
    Instrument* giveBackInstr() {
        Instrument* result(instr);
        instr = nullptr;
        return result;
    }
    
    void testPlay() const {
        if (instr) instr->makeSound();
        else cerr << "have no instr\n";
    }
    
    void play() {
        if (instr) instr->play();
    }
    
private:
    Instrument* instr;
};

class Orch {
public:
    
    void play() const {
        //check if musciaans have instruments
        for (Musician* currMuse: Band){
            currMuse->play();
            cout<<endl;
        }
    }
    
    void addPlayer(Musician& newMuse){
        Band.push_back(&newMuse);
    }
private:
    vector<Musician*> Band;
};

// PART ONE
int main() {
    
    cout << "Define some instruments ------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;
    
    cout << "Define the MILL --------------------------------------------\n";
    MILL mill;
    
    cout << "Put the instruments into the MILL --------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    
    cout << "Daily test -------------------------------------------------\n";
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
    
    cout << "Define some Musicians---------------------------------------\n";
    Musician harpo;
    Musician groucho;
    
    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    groucho.testPlay();
    cout << endl;
    groucho.acceptInstr(mill.loanOut());
    cout << endl;
    groucho.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    
    cout << endl << endl;
    
    groucho.testPlay();
    cout << endl;
    mill.receiveInstr(*groucho.giveBackInstr());
    harpo.acceptInstr(mill.loanOut());
    groucho.acceptInstr(mill.loanOut());
    cout << endl;
    groucho.testPlay();
    cout << endl;
    harpo.testPlay();
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    
    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
    
    mill.receiveInstr(*groucho.giveBackInstr());
    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
    mill.receiveInstr(*harpo.giveBackInstr());
    
    
    cout << endl;
    cout << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
    
    cout << endl;
    
    
    //PART TWO
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;
    
    Orch orch;
    
    // THE SCENARIO
    
    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);
    
    //The orchestra performs
    cout << "orch performs\n";
    orch.play();
    
    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);
    
    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());
    
    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);
    
    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());
    
    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);
    
    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());
    
    //ORCHESTRA PERFORM
    cout << "orch performs\n";
    orch.play();
    
    //Ralph joins the orchestra.
    orch.addPlayer(ralph);
    
    //ORCHESTRA PERFORM
    cout << "orch performs\n";
    orch.play();
    
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());
    
    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
    
    //Morgan joins the orchestra.
    orch.addPlayer(morgan);
    
    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
}


