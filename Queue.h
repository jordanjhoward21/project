#ifndef QUEUE_H
#define QUEUE_H

struct QueueNode {
    int data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue();                
    ~Queue();               

    void enqueue(int value); 
    int dequeue();           
    bool isEmpty() const;    
    void display() const;    
};

#endif
