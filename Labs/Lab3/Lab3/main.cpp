//
//  main.cpp
//  Lab3
//
//  Created by Alex Mosseri on 2/27/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;



struct Account{
    string account;
    int accountNumber;
};


int main() {
    ifstream ifs("account.txt");
    if (!ifs){
        cerr<< "could not open the file\n";
        exit(1);
    }
    
    string linesoftext;
    vector <string> theLines;
    while(getline(ifs, theLines)){
        theLines.push_back(linesoftext);
        cout<< linesoftext <<endl;
        
    }
    
    
    
}
