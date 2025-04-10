#include "Queue.h"
#include <iostream>

using namespace std;


Queue::Queue() : front(nullptr), rear(nullptr) {}


Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}


void Queue::enqueue(int value) {
    QueueNode* newNode = new QueueNode{value, nullptr};

    if (rear)
        rear->next = newNode;
    else
        front = newNode;

    rear = newNode;
}


int Queue::dequeue() {
    if (isEmpty()) return -1;

    int value = front->data;
    QueueNode* temp = front;
    front = front->next;

    if (!front) rear = nullptr;

    delete temp;
    return value;
}


bool Queue::isEmpty() const {
    return front == nullptr;
}


void Queue::display() const {
    QueueNode* curr = front;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
