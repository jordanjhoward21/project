#ifndef STACK_H
#define STACK_H

struct StackNode {
    int data;
    StackNode* next;
};

class Stack {
private:
    StackNode* top;

public:
    Stack();               
    ~Stack();             

    void push(int value);  
    int pop();             
    bool isEmpty() const;  
    void display() const;  
};

#endif
