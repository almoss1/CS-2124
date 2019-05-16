//Alex Mosseri
//rec02
//order 

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;



struct hydroCarbons{
    vector<string> Name;
    int numberofCarbons;
    int numberofHydrogens;
};

size_t checkforduplicates(const hydroCarbons& Carbon, const vector<hydroCarbons>& molecules){
    for (size_t i=0; i<molecules.size(); ++i){
        if (Carbon.numberofCarbons==molecules[i].numberofCarbons && Carbon.numberofHydrogens==molecules[i].numberofHydrogens){
           return i;
        }
    }
            return molecules.size();
}
        
int main(){


vector<hydroCarbons> molecules;

    ifstream ifs ("/Users/AlexMosseri/Code/OOP/Labs/Lab2/chemical.txt");
    if (!ifs){
        cerr << "file could not be found.\n";
        exit(1);
    }
    string name;
    char carbon;
    int numberofcarbons;
    char hydrogen;
    int numberofhydrogens;
    while (ifs >> name >> carbon >> numberofcarbons >> hydrogen >> numberofhydrogens){
        hydroCarbons Carbon;
        Carbon.Name.push_back(name);
        Carbon.numberofCarbons=numberofcarbons;
        Carbon.numberofHydrogens=numberofhydrogens;
        size_t result=checkforduplicates(Carbon, molecules);
        if (result!=molecules.size()){
            molecules[result].Name.push_back(name);
        }
        else{
            molecules.push_back(Carbon);
        }
    }
   
    for (int n=0; n<97; ++n){
        for (size_t i=0;i<molecules.size(); i++){
            if (n==molecules[i].numberofCarbons){
                for (size_t j=0; j<molecules[i].Name.size(); j++){
                    cout << molecules[i].Name[j]<<" ";
                }
                cout << ' ' << 'C' << molecules[i].numberofCarbons << 'H' << molecules[i].numberofHydrogens << endl;
            }
    }
    
    }
    
}
