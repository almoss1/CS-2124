//
//  main.cpp
//  Lab14
//
//  Created by Alex Mosseri on 5/10/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
#include <exception>
using namespace std;

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};
struct Node{
    Node(int data = 0, Node* next = nullptr) : data(data), next(next){}
    int data;
    Node* next;
    
};

//task 1
bool evenNumberBinary(int n){
    bool result; // does a bool automaticallyset as true or false?
    if (n == 1) {
        return false;
    }
    if (n == 0) {
        return true;
    }
    
    result = evenNumberBinary(n/2);
    if (n % 2) {
        return !result;
    }
    return result;
}

// task 2
Node* addLists(Node* first, Node* second){
    Node* nextptr;
    Node* headptr;
    if (first == nullptr && second == nullptr) {
        return nullptr;
    }
    else if (first == nullptr){
        nextptr = addLists(first, second->next);
        headptr = new Node(second->data, nextptr);
    }
    else if (second == nullptr){
        nextptr = addLists(first->next, second);
        headptr = new Node(first->data, nextptr);
    }
    else{
        nextptr = addLists(first->next, second->next);
        headptr = new Node(first->data + second->data, nextptr);
    }
    return headptr;
}

//task 3
int max(TNode* root) {
    if (root == nullptr) throw invalid_argument("Empty tree");
    int largest = root->data;
    int right = root->data;
    
    if (root->left)  largest = max(root->left);
    if (root->right) right = max(root->right);
    
    if (largest < right) {
        largest = right;
    }
    if(largest < root->data){
        largest = root->data;
    }
    else{
        largest = largest;
    }
    return largest;
}

// task 4
bool palindrome(char array[], int size){
    if (size <= 1) {
        return true;
    }
    if (array[0] == array[size - 1]) {
        return palindrome(array + 1, size -2);
    }
    return false;
}

//task 5
int towers(int n, int start = 0, int target = 1, int spare = 2) {
    
    if (n == 1){
        return 1;
    }
    return (towers(n - 1, start, spare, target)+ towers(n - 1, spare, target, start) +1);
    //cout << "Moving disk " << n << " to peg " << target << endl;
    //total_moves += 1;
    //return total_moves;
}



//task 6
void mystery(int n) {
    if (n > 1) {
        cout << 'a';
        mystery(n/2);
        cout << 'b';
        mystery(n/2);
    }
    cout << 'c';
}


/*
 0: c
 1: c
 2: a, c, b, c
 3:a, c, b, c
 4: aacbccbacbccc
 5:aacbccbacbccc
 6:aacbccbacbccc
 7:aacbccbacbccc
 8:aaacbccbacbcccbaacbccbacbcccc
 9:aaacbccbacbcccbaacbccbacbcccc
 10:aaacbccbacbcccbaacbccbacbcccc
 */

int main() {
    
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    try{
    cout << max(&f) << endl;
    }
    catch(exception& e){
        cout<<"Exception caught "<<e.what()<<endl;
    }
    cout<<evenNumberBinary(2)<<endl;
    cout<<towers(3, 0,  1,  2)<<endl;
    mystery(14);
    cout<<endl;
    
}

