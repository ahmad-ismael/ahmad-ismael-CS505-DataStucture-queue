#include <iostream>
#include "Stack.h"
using namespace std;

Stack::Stack()
{
    top = NULL;
    count = 0;
}

Stack::Stack(const Stack &s)
{
    // 
}

Stack::~Stack(){
    ptr p;
    while(top != NULL) {
        p = top;
        top = top->next;
        delete p;
    }
}

bool Stack::stackIsEmpty(){
    return (top == NULL);
}

void Stack::push(int n){
    ptr p = new node;
    p->e = n;
    p->next = top;
    top = p;
    count++;
} 

void Stack::pop(int &x){
    if(stackIsEmpty()) cout << "Stack underflow" << endl;
    else {
        ptr p;
        x = top->e;
        p = top;
        top = top->next;
        delete p;
        count--;
    }
}

void Stack::stackTop(int &x){
    if(stackIsEmpty()) cout << "Stack underflow" << endl;
    else {
        x = top->e;
    }
}

int Stack::stackSize(){
    return count;
}
