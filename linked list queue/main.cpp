#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

void reverse (Queue &q) {
    Stack s;
    int el;
    while(!q.queueIsEmpty()) {
        q.dequeue(el);
        s.push(el);
    }
    while(!s.stackIsEmpty()) {
        s.pop(el);
        q.enqueue(el);
    }
}

void split(Queue &Q, Queue &Q1, Queue &Q2){
    Queue tmp(Q);
    int length = Q.queueLength();
    int el;

    while(!tmp.queueIsEmpty())
    {
        if(tmp.queueLength() > length/2) {
            tmp.dequeue(el);
            Q1.enqueue(el);
        }
        else {
            tmp.dequeue(el);
            Q2.enqueue(el);
        }
    }
}

void append(Queue &Q1, Queue &Q2) {
    int el;
    if(!Q2.queueIsEmpty()) {
        Q2.dequeue(el);
        Q1.enqueue(el);
        append(Q1,Q2);
    }
}

void traverse(Queue &Q) {
    Queue tmp(Q);
    int el;
    while(!tmp.queueIsEmpty()) {
        tmp.dequeue(el);
        cout << el << endl;
    }
}

void NthElement(Queue &Q, int n) {
    int el;
    int length = Q.queueLength();

    cout << "Number =" << n << endl;
    cout << "LENGTH =" << length << endl;
    
    if(n > length || n < 1) {
        cout << "Invalid position" << endl;
    }
    else {
        for(int i = 1; i<=length; i++) {
            Q.dequeue(el);
            if(i != n) {
                Q.enqueue(el);
            }
        }
    }
}

bool EqualQueues(Queue &Q1, Queue &Q2) {
    if(Q1.queueLength() != Q2.queueLength())
        return false;
    
    Queue tmp1(Q1), tmp2(Q2);
    int el1,el2;
    while(!tmp1.queueIsEmpty()) {
        tmp1.dequeue(el1);
        tmp2.dequeue(el2);
        if(el1 != el2)
            return false;
    }
    return true;
}

int min(Queue &Q) {
    Queue tmp(Q);
    int min, x;
    tmp.queueFront(min);
    while (!tmp.queueIsEmpty()) {
        tmp.dequeue(x);
        if(x < min)
            min = x;
    }
    return min;
}

int main () {
    Queue q, q1, q2;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    reverse(q);
    split(q, q1, q2);
    append(q1,q2);
    NthElement(q1,9);
    traverse(q1);

    Queue q3(q1);
    if(EqualQueues(q1,q3)) cout << "Equal" << endl;
    else cout << "Not Equal" << endl;

    cout << "MIN of q = " << min(q) << endl;
    cout << "MIN of q1 = " << min(q1) << endl;
    cout << "MIN of q2 = " << min(q2) << endl;
    cout << "MIN of q3 = " << min(q3) << endl;
    
    return 0;
}