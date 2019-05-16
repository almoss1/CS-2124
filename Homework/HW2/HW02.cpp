//Alex Mosseri
//HW02
//This is a medieval times wehre there are battles going on with
 //new warriors. Warriors are created and battle to keep their existance 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

const bool D = false ;


struct warrior { //creates the warrior struct to be used later
    string name;
    int strength;

};

void createWarrior(const string& name, int strength, vector<warrior>& theWarrior);
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

    vector<warrior> theWarriors;
    for(string line : lines)
    {// for loop for pulling the first word from each line of the input file stream
        if(D) cout << "looping; line = " << line << endl;
        string command;
        istringstream iss(line);
        iss >> command;

        if(D) cout << "Command = " << command << endl;

        if (command == "Warrior"){
            int strength;
            string name;
            iss >> name >> strength;
            if(D) cout << "Handling warrior command with strength: "
                        << strength << " and name " << name << endl;
            createWarrior(name, strength, theWarriors);
        }
        else if (command == "Battle"){
            string name1;
            string name2;
            iss >> name1 >>name2;
            if (D) cout <<"Handling battle command with name1 "<< name1
                            << " and name2 " << name2 << endl;
                battle(name1, name2, theWarriors);
        }
        else if (command == "Status"){
            displaystatus(theWarriors);
        }
    }
    textfile.close();
}


//create warrior function- takes in the input file stream and the vector by reference
void createWarrior(const string& name, int strength,
                   vector<warrior>& theWarrior ){
    
    warrior thewarrior; //creates a Warrior struct
    // create string stream like we did to get command
    
     thewarrior.name = name; //assigns the warrior name
     thewarrior.strength = strength; //assigns the warrior strength
     theWarrior.push_back(thewarrior); //adds the warrior struct to the vector
}





//find function -- takaing in the vector by referent and a string name for warrior
size_t find(const vector <warrior>& theWarrior, const string& name){
    for (size_t x =0; x < theWarrior.size(); x++){
        if (theWarrior[x].name == name){
            return x;
        }
    }
    return theWarrior.size();
}







//battle function- takes in the input file stream and the vector by reference
void battle(const string& name1, const string& name2, vector <warrior>& theWarrior){
    
    //textfile >> name1>> name2;
    size_t index1 = find(theWarrior,name1); // finds where the first warrior is 
    size_t index2 = find(theWarrior,name2);// finds where the second warrior is 

    cout << "In battle!" << endl;

    cout<< theWarrior[index1].name << " battles " << theWarrior[index2].name<<endl;
    
    
    if ((theWarrior[index1].strength == theWarrior[index2].strength) && (theWarrior[index1].strength != 0) && (theWarrior[index2].strength != 0)) {
        
        cout <<"Mutual Annihilation: "<< theWarrior[index1].name << " and " << theWarrior[index2].name
        <<" die at each other's hands " << endl;
        theWarrior[index1].strength = 0;
        theWarrior[index2].strength =0;
        //if both warriors have the same strength but arent both dead, then there is a mutual annihilation and both
        //strengths are set to zero
    }

    else if (theWarrior[index1].strength ==0 && theWarrior[index2].strength == 0){
        cout <<"Oh, NO! They're both dead! Yuck!" << endl;
    }
    // if both warriors are already dead, then it prints that they are both already dead

    else if (theWarrior[index1].strength > theWarrior[index2].strength && theWarrior[index2].strength != 0){
        
        cout << theWarrior[index1].name << " defeats " << theWarrior[index2].name << endl;
        theWarrior[index1].strength = theWarrior[index1].strength- theWarrior[index2].strength;
        theWarrior[index2].strength=0;
    }
    // if one warrior is stronger than the other and the weaker warrior isn't dead, than one warrior defeats the other. The weaker warrior's strength is
        // set to zero and the stronger warrior loses the amount of strength the weaker warrior had
    

    else if (theWarrior[index1].strength < theWarrior[index2].strength && theWarrior[index1].strength != 0){
        
        cout << theWarrior[index2].name << " defeats " << theWarrior[index1].name << endl;
        theWarrior[index2].strength = theWarrior[index2].strength - theWarrior[index1].strength;
        theWarrior[index1].strength=0; 
    }
     // if one warrior is stronger than the other and the weaker warrior isn't dead, than one warrior defeats the other. The weaker warrior's strength is
        // set to zero and the stronger warrior loses the amount of strength the weaker warrior had.
        // does the same but switches it around

    else if (theWarrior[index1].strength == 0 && theWarrior[index2].strength > 0){
        cout << "He's dead, " << theWarrior[index2].name << endl;
        // if one warrior is alive and the other is dead, it prints that he is already dead
    }

    else if (theWarrior[index1].strength>0 && theWarrior[index2].strength == 0){
        
        cout << "He's dead, " << theWarrior[index1].name << endl;
        // if one warrior is alive and the other is dead, it prints that he is already dead
        // does the same but switches it around
    }

    
}

void displaystatus(const vector<warrior>& theWarrior){
    cout<< "There are " << theWarrior.size() << " warriors\n";
    for (size_t i = 0; i < theWarrior.size(); ++i){
        cout<< "Warrior:"<< theWarrior[i].name<< ", Strength:"<<theWarrior[i].strength<<endl;
    }

}



