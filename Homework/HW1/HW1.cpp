//Alex Mosseri
//HW01
//Caesar Cypher


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char decrypter(char &letter, int shift){
    if (islower(letter)){
        letter -= shift;
        if (letter < 'a'){
            letter += 26;
        }
        return letter;
    }
    else{
        return letter;
    }

}

void decryptlines(string &linesofletter, int shift){
    for (size_t i = 0; i < linesofletter.size(); ++i){
        linesofletter[i] = decrypter(linesofletter[i], shift);
        
    }
}

int main(){
    ifstream changefile("/Users/AlexMosseri/Code/OOP/Homework/HW1/e.txt");
    if (!changefile){
        cerr << "Could not open the file.\n";
        exit(1);
 }

    string lineoftext; 
    vector<string> encryptedlines; 
    int shift; 
    while (getline(changefile, lineoftext)) {
        decryptlines(lineoftext, shift); 
        encryptedlines.push_back(lineoftext); 
        cout << lineoftext << endl;
    }

        
    reverse(encryptedlines.begin(), encryptedlines.end()); 
    
    for (size_t i =0; i < encryptedlines.size(); ++i){ 
        cout<< encryptedlines[i] << endl;
        
    }
    
    changefile.close();

    

}
 
 