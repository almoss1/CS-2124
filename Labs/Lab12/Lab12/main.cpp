//
//  main.cpp
//  Lab12
//
//  Created by Alex Mosseri on 4/28/19.
//  Copyright © 2019 Alex Mosseri. All rights reserved.
//

#include <iostream>
using namespace std;




class List {
    
    friend ostream& operator<<(ostream& os, const List& rhs){
        Node* index = rhs.header->next;
        
        while(index!= rhs.trailer){
            os<<index->data <<" ";
            index = index->next;
        }
        return os;
    }
    
public:
    
    List() : lst_size(0) { header = new Node(0); trailer = new Node(0);
        header->next = trailer;
        trailer->previous = header;
    }
    
    size_t size() const{
        return lst_size;
    }
    
    int front() const{
        return header->next->data;
    }
    
    int& front(){
        return header->next->data;
    }
    
    int back() const{
        return trailer->previous->data;
    }
    int& back() {
        return trailer->previous->data;
    }
    
    
    void push_back(int data){
        Node* addNode = new Node(data);
        Node* last = trailer->previous;
        addNode->next = trailer;
        addNode->previous = last;
        last->next= addNode;
        trailer->previous =addNode;
        lst_size+=1;
    }
    
    void pop_back(){
        Node* delete_node = trailer->previous;
        Node* last = delete_node->previous;
        last->next = trailer;
        trailer->previous = last;
        delete delete_node;
        delete_node = nullptr;
        lst_size -= 1;
    }
    
    void push_front(int data){
        Node* addNode = new Node(data);
        Node* first = header->next;
        addNode->previous = header;
        addNode->next = first;
        first->previous = addNode;
        header->next= addNode;
        lst_size+=1;
    }
    void pop_front(){
        Node* delete_node = header->next;
        Node* first = delete_node->next;
        header->next = first;
        first->previous =  header;
        delete delete_node;
        delete_node = nullptr;
        lst_size-=1;
    }
    
    void clear(){
        Node* index = header->next;
        while (index!= trailer) {
            Node* next =index->next;
            delete index;
            index = next;
        }
        header->next = trailer;
        trailer->previous = header;
        lst_size = 0;
    }
    
    
    int operator[](int index) const{
        Node* index_node = header->next;
        for (int i =0; i<index; i++) {
            index_node = index_node->next;
        }
        return index_node->data;
    }
    
    int& operator[](int index){
        Node* index_node = header->next;
        for (int i =0; i<index; i++) {
            index_node = index_node->next;
        }
        return index_node->data;
    }
    
    
    
private:
    //NODE
    struct Node{
        Node(int data =0, Node* next = nullptr) : data(data), next(next){}
        int data;
        Node* next;
        Node* previous;
    };
    
    Node* header;
    Node* trailer;
    int lst_size;
   
public:
    class iterator {
        friend bool operator!=(const iterator& rhs, const iterator& lhs) {
            return rhs.nodeptr != lhs.nodeptr;
        }
        friend bool operator==(const iterator& rhs, const iterator& lhs) {
            return rhs.nodeptr == lhs.nodeptr;
        }
        friend List;
    public:
        iterator(Node* head) : nodeptr(head) {}
        
        iterator& operator++() {
            nodeptr = nodeptr->next;
            return *this;
        }
        
        iterator& operator--() {
            nodeptr = nodeptr->previous;
            return *this;
        }
        
        int operator*() { return nodeptr->data; }
        
        iterator(const iterator& i) {
            nodeptr = new Node(*(i.nodeptr));
        }
        
    private:
        Node* nodeptr;
    };
    
    iterator begin() { return iterator(header->next); }
    
    iterator end() { return iterator(trailer); }
    
    iterator insert(const iterator& iter, int data) {
        Node* node = new Node(data);
        Node* before = iter.nodeptr->previous;
        Node* after = iter.nodeptr;
        node->next = after;
        node->previous = before;
        before->next = node;
        after->previous = node;
        lst_size += 1;
        return iterator(node);
    }
    
    iterator erase(const iterator& iter) {
        Node* node = iter.nodeptr;
        Node* before = node->previous;
        Node* after = node->next;
        before->next = after;
        after->previous = before;
        delete node;
        node = nullptr;
        lst_size -= 1;
        return iterator(after);
    }
    
};






// Task 1
void printListInfo(const List& myList) {
    cout << "size: " << myList.size()
    << ", front: " << myList.front()
    << ", back: " << myList.back()
    << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
// void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList){
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}
/*
// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}
*/
int main() {
    
    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    
    cout << "===================\n";
    
    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";
    
    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";
    
    
    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";
    
    
    
    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";
    
    
    
    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
    << "the data in the third item in the list\n"
    << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);
    
    
    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";
    
    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
    << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";
    
    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    /*
    // ***Need test for erase other than begin/end***
    cout << "===================\n";
    
    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);
    
    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
     */
}






