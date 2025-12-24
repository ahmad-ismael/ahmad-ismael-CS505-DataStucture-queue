#include <iostream>
#include "Queue.h"
using namespace std;

Queue :: Queue(): front(NULL), rear(NULL), count(0) {}

Queue :: Queue(const Queue &q): front(NULL), rear(NULL), count(0) {
    np curr = q.front;
    while (curr != NULL) {
        enqueue(curr->pid);
        curr = curr->next;
    }
}

Queue :: ~Queue(){
    while(!queueIsEmpty()) {
        np cursor;
        cursor = front;
        front = front->next;
        count--;
        delete cursor;
    }
}

bool Queue :: queueIsEmpty() const{
    return (count == 0);
}

int Queue :: queueLength() const{
    return count;
}

void Queue :: enqueue(int d){
    np p = new pcb;
    p->pid = d;
    p->next = NULL;  // CRITICAL FIX!
    
    if(!queueIsEmpty()) {
        rear->next = p;
        rear = p;
    } else {
        front = p;
        rear = p;
    }
    count++;
}

void Queue :: dequeue(int &d){
    if(queueIsEmpty()) {
        cout << "queue is empty" << endl;
    }
    else {
        d = front->pid;
        np p;
        p = front;
        front = front->next;
        count--;
        delete p;
    }
}

void Queue :: queueFront(int &d) const{
    if(queueIsEmpty()) {
        cout << "queue is empty" << endl;
    }
    else {
        d = front->pid;
    }
}