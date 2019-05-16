//
//  main.cpp
//  Lab13new
//
//  Created by Alex Mosseri on 5/3/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//


// rec13_test.cpp


#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
#include <iostream>
using namespace std;

//task 9
void display(const list<int>& nl){
    for (list<int>::const_iterator iter = nl.begin(); iter != nl.end(); iter++) {
        cout<< *iter<<" ";
    }
}
//task 10
void display_for_range(const list<int>& nl){
    for (int x: nl){
        cout<<x<<" ";
    }
}
void display_auto(const list<int>& nl){
    for(auto& item : nl){
        cout<<item<< " ";
    }
}

//Task 12
list<int>::const_iterator iter_find(const list<int>& nl, int numberToFind){
    //cout<<"In our find"<<endl;
    for (list<int>::const_iterator iter = nl.begin(); iter!= nl.end(); iter++) {
        if(*iter == numberToFind){
            return iter;
        }
    }
    return nl.end();
    
}
//Task 13
list<int>::const_iterator auto_iter_find(const list<int>& nl, int numberToFind){
    for(auto iter = nl.begin(); iter != nl.end(); iter++){
        if (*iter== numberToFind) {
            return iter;
        }
    }
    return nl.end();
}

void printVector(const vector<int> nv){
    for (int item : nv) {
        cout<<item<<" ";
    }
}
//Task 18
void printArray(int arr[], size_t length){
    for (size_t i = 0; i< length; i++) {
        cout<<arr[i]<<" ";
    }
}
//Task 19
list<int>::const_iterator ourFind(list<int>::iterator start,list<int>::iterator end, int numberToFind){
   // cout<<"It is working"<<endl;
    for(list<int>::const_iterator iter = start; iter!= end; iter++){
        if (*iter == numberToFind) {
            return iter;
        }
    }
    return end;
}

//Task 20
template <typename Alex, typename Moss>
Alex ourFindNew(Alex start, Alex end, Moss numberToFind){
    //cout<<"In the Template"<<endl;
    for(Alex iter = start; iter!= end; iter++){
        if (*iter == numberToFind) {
            return iter;
        }
    }
    return end;
}


template <typename SequenceContainer>
void print(const string name, const SequenceContainer& seq) {
    // cout << "\n_______" << endl;
    cout << name << ":\n";
    for(int item : seq) cout << item << " ";
    cout<<endl;
    //cout << "\n_______" << endl;
}

//Task 15
bool is_even(int n) {
    return (n % 2) == 0;
    
}


//Task 16
class Functor{
public:
    bool operator()(int evenNumber){
        return (evenNumber % 2) == 0;
    }
};
int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> v ={1,2,5,3,7,29,0,4};
    for( int x : v){
        cout<< x <<" ";
    }
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> l(v.begin(), v.end());
    for (int y : l) {
        cout<< y <<" ";
    }
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    sort(v.begin(),v.end());
   // sort(l.begin(), l.end());
    //l.sort();
    print("Sorted Vector", v);
    print("Sorted List", l);
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (size_t i =0; i < v.size(); i+=2) {
        cout<< v[i] <<" ";
    }
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    for (size_t i =0; i < l.size(); i+=2) {
        // cout<<l[i];
    }
    //why cant this be done?????????
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for (vector<int>::iterator iter = v.begin(); iter!= v.end(); iter+=2) {
        cout<<*iter<<" ";
    }
    cout << "\n=======\n";
    
    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for (list<int>::iterator iter = l.begin(); iter != l.end(); iter++){
        cout << *iter << " ";
        iter++;
    }
    cout << endl;
    cout << "\n=======\n";
    
    // 8. Sorting a list
    cout << "Task 8:\n";
    l.sort();
    for (int sortedList : l) {
        cout << sortedList << " ";
    }
    cout << "\n=======\n";
    
    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    display(l);
    cout << endl;
    cout << "=======\n";
    
    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    display_for_range(l);
   // cout << endl;
    cout << "=======\n";
    
    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    display_auto(l);
    cout<<endl;
    cout << "=======\n";
    
    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator iter = iter_find(l, 1);
    list<int>::const_iterator iter2 = iter_find(l, 99);
    if (iter!= l.end()) { cout<<"found the number"<<endl;}
    if (iter2!= l.end()) { cout<<"found the number"<<endl;}
    else{cout<<"couldnt find the number"<<endl;}
    
    cout << "=======\n";
    
    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    list<int>::const_iterator iter3 = auto_iter_find(l, 1);
    list<int>::const_iterator iter4 = auto_iter_find(l, 99);
    if (iter3 != l.end()) { cout<<"found the number"<<endl;}
    else{cout<<"couldnt find the number"<<endl;}
    if (iter4!= l.end()) { cout<<"found the number"<<endl;}
    else{cout<<"couldnt find the number"<<endl;}
    cout << "=======\n";
    
    //
    // Generic Algorithms
    //
    
    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int>::iterator iter5= find(l.begin(), l.end(), 13);
    list<int>::iterator iter6= find(l.begin(), l.end(), 12);
    if (iter5 != l.end()) {cout<<"found";}
    else cout << "Could not find the number" << endl;
    if (iter6 != l.end()) {cout<<"found";}
    else cout << "Could not find the number" << endl;
    cout << "=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    list<int>::iterator if_iter1 = find_if(l.begin(), l.end(), is_even);
    cout << "First is_even() number in list is: " << *if_iter1 << endl;
    cout << "=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    Functor fun;
   // cout << fun(3) << endl;
    cout<<*find_if(l.begin(), l.end(), fun);///////////
    
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    [] (int a, int b) { cout << a + b << endl; } (4, 5);
    cout<<*find_if(l.begin(), l.end(), [] (int n) {return n%2==0;})<<endl;
    
    cout << "=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[v.size()];
    copy(v.begin(), v.end(), arr);
    printArray(arr, v.size());
    cout<<*find(arr,arr+v.size()-1,12); /////////////
    // call find on the arr
    cout<<endl;
    cout << "=======\n";
    
    //
    // Templated Functions
    //
    
    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int>::const_iterator ourIter = ourFind(l.begin(),l.end(), 13);  ////////////
    if (ourIter != l.end()) {cout<<"found";}
    else cout << "Could not find the number" << endl;
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    list<int>::const_iterator ourIter2 = ourFindNew(l.begin(),l.end(), 13);
    if (ourIter2 != l.end()) {cout<<"found";}
    else cout << "Could not find the number" << endl;
    cout << "=======\n";
    
    //
    // Associative collections
    //
    
    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    ifstream ifs("pooh-nopunc.txt");
    if (!ifs){
        cerr << "Can't open file" << endl;
    }
    vector<string> vs;
    string word;
    bool isWordThere;
    while (ifs>>word) {
        isWordThere = false;
        for (size_t i = 0; i< vs.size(); i++) {
            if (vs[i] == word) {
                isWordThere = true;
                break;
            }
        }
        if(isWordThere == false){
            vs.push_back(word);
        }
        
    }
    cout<<"size:"<<vs.size()<<endl;
    for (string y : vs) {
        cout<< y <<" ";
    }
    ifs.close();
    cout << "\n=======\n";
    
    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    ifstream newIfs("pooh-nopunc.txt");
    if (!newIfs){
        cerr << "Can't open file" << endl;
    }
    set<string> ss;
    string wordNew;
    while (newIfs >>wordNew) {
        //set<string>::iterator news = find(ss.begin(), ss.end(),wordNew);
        ss.insert(wordNew);
    }
    cout<<"size:"<<ss.size()<<endl;
    for (string x : ss) {
        cout<< x <<" ";
    }
    newIfs.close();
    
    cout << "=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    ifstream thePooh("pooh-nopunc.txt");
    if (!thePooh){
        cerr << "Can't open file" << endl;
    }
    string lastWords;
    map<string, vector<int>> wordMap;
    int position = 0;

    while (thePooh>> lastWords) {
        wordMap[lastWords].push_back(position);
        position++;
    }
    for (auto m : wordMap) {
        cout<<m.first<<":";
        
        for(size_t i = 0; i <m.second.size(); i++){
            cout<<m.second[i]<<endl;
        }
    }
    

    thePooh.close();
    cout << "=======\n";
}
