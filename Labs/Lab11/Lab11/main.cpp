//
//  main.cpp
//  Lab11
//
//  Created by Alex Mosseri on 4/19/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 functions for use with CS2124 rec11
 -jbs
 */

// Node to be used a part of linked list
struct Node {
    Node(int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

// listAddHead: adds a data item to the beginning of a [possibly empty] list
void listAddHead(Node*& headPtr, int entry) {
    headPtr = new Node(entry, headPtr);
}

// listClear: frees up all the nodes in a list
void listClear(Node*& headPtr) {
    while (headPtr) {
        Node* next = headPtr->next;
        delete headPtr;
        headPtr = next;
    }
}

// listBuild: constructs a list from a vector of data items. Note that
// you can use a curly-braced sequence.
// This may be useful for setting up test cases. Feel free to use it
// or not as you like.
// Example of using would be:
//    Node* myList = listBuild({1, 4, 9, 16}); // builds a list of: 1 4 9 16
Node* listBuild(const vector<int>& vals) {
    Node* result = nullptr;
    for (size_t index = vals.size(); index > 0; --index) {
        listAddHead(result, vals[index-1]);
    }
    return result;
}


Node* findEnd(Node* headptr){
    if (headptr == nullptr){
        return headptr;
    }
    Node* ptr = headptr;
    while(ptr->next != nullptr){
        ptr = ptr->next;
    }
    return ptr;
}

void splice(Node* newList, Node* target){
    Node* newListEnd = findEnd(newList);
    newListEnd->next = target->next;
    target->next = newList;
}

void listDisplay(Node* headptr){
    Node* ptr = headptr;
    while(ptr!= nullptr){
        cout<< ptr->data<< " ";
        ptr = ptr->next;
    }
    cout<<endl;
}


Node* isSubList(Node* listLookingFor, Node* originalList){
    cout<<"Target"<< endl;
    listDisplay(originalList);
    cout<<"Attempt Match"<<endl;
    listDisplay(listLookingFor);
    
    while (originalList != nullptr) {
        if(listLookingFor->data == originalList->data){
            Node* tempA = originalList->next;
            Node* tempB = listLookingFor->next;
            while (tempB != nullptr && tempA != nullptr && (tempB->data == tempA->data) ) {
                    tempB = tempB->next;
                    tempA= tempA->next;
                if(tempB == nullptr){
                    Node* nodesToReturn = originalList;
                    return nodesToReturn;
                    
                }
                
                }
            }
        originalList = originalList->next;
        
        }
    return nullptr;
        

}




int main(){
    cout << "Part One" << endl;
    cout <<"============================" << endl;
    
    Node* myList = listBuild({1,2,3,4});
    listDisplay(myList);
    
    Node* myList2 = listBuild({5,6,7,8});
    listDisplay(myList2);
    
    
    
    cout << "Target: "<<endl;
    listDisplay(myList);
    cout << "Splicing L2 at Target in L1" << endl;
    splice(myList2, myList->next);
    cout << "L1: ";
    listDisplay(myList);
    cout << "L2: ";
    listDisplay(myList2);
    cout<<endl;
    
    
    
    Node* result=isSubList(myList2, myList);
    if (result!= nullptr){
        listDisplay(result);
    }
    else{
        cout << "Failed to Match"<< endl;
    }
    
}
