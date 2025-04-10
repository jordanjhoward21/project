// Project 1
// Jordan Howard
// 4-9-25

#include <iostream>
#include <cmath>
#include "Stack.h"
#include "Queue.h"

using namespace std;

// Function prototypes
void convertIntegerPart(int num, Stack& s);
void convertDecimalPart(double frac, Queue& q, int precision = 10);

int main() {
    double input;
    cout << "Please enter a decimal number >> ";
    cin >> input;

    int integerPart = static_cast<int>(input);
    double decimalPart = input - integerPart;

    Stack s;
    Queue q;

    convertIntegerPart(integerPart, s);
    convertDecimalPart(decimalPart, q);

    cout << "Binary representation >> ";

    // Integer part
    while (!s.isEmpty()) {
        cout << s.pop();
    }

    cout << ".";

    // Decimal part
    while (!q.isEmpty()) {
        cout << q.dequeue();
    }

    cout << endl;

    return 0;
}

// Converts integer part to binary using stack
void convertIntegerPart(int num, Stack& s) {
    if (num == 0) {
        s.push(0);
    }
    while (num > 0) {
        s.push(num % 2);
        num /= 2;
    }
}

// Converts decimal part to binary using queue
void convertDecimalPart(double frac, Queue& q, int precision) {
    int count = 0;
    while (frac > 0 && count < precision) {
        frac *= 2;
        int bit = static_cast<int>(frac);
        q.enqueue(bit);
        frac -= bit;
        ++count;
    }
}
