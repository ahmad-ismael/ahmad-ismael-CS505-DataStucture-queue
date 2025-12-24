#include <iostream>
#include "QueueC.h"
using namespace std;

QueueC::QueueC(int nelements): front(0), rear(-1), count(0) {
    maxSize = nelements;
    queue = new int[maxSize];
}
QueueC::QueueC(const QueueC &q): front(q.front), rear(q.rear), count(q.count) {
    maxSize = q.maxSize;
    queue = new int[maxSize];

    for(int i=0; i < maxSize; i++) {
        queue[i] = q.queue[i];
    }
}
QueueC::~QueueC() {
    delete [] queue;
}

bool QueueC::queueIsEmpty() const{
    return (count == 0);
}
bool QueueC::queueIsFull() const{
    return (count == maxSize);
}
int QueueC::queueLength() const{
    return count;
}
void QueueC::queueFront(int &v) const{
    if(queueIsEmpty()) 
        cout << "queue is empty.. " << endl;
    else 
        v=queue[front];
}
    
void QueueC::enqueue(int v){
    if(queueIsFull())
        cout << "Queue is Full, try again later.."<<endl;
    else {
        rear = (rear+1) % maxSize; // circuler index (128 % 128 = 0)
        queue[rear] = v;
        count++;
    }
}
void QueueC::dequeue(int &v){
    if(queueIsEmpty()) 
        cout << "queue is empty.." << endl;
    else {
        v = queue[front];
        front = (front+1) % maxSize;
        count--;
    }
}