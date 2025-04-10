#include "Stack.h"
#include <iostream>

using namespace std;


Stack::Stack() : top(nullptr) {}


Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}


void Stack::push(int value) {
    StackNode* newNode = new StackNode{value, top};
    top = newNode;
}


int Stack::pop() {
    if (isEmpty()) return -1;
    
    int value = top->data;
    StackNode* temp = top;
    top = top->next;
    delete temp;
    return value;
}


bool Stack::isEmpty() const {
    return top == nullptr;
}


void Stack::display() const {
    StackNode* curr = top;
    while (curr) {
        cout << curr->data;
        curr = curr->next;
    }
    cout << endl;
}
