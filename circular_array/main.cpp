#include <iostream>
#include "QueueC.h"
using namespace std;

int main () {
    QueueC q(5);
    int v = 0;

    for(int i = 0; i < 10; i++) {
        q.enqueue(i%5);
        q.queueFront(v);
        cout << v << "\t";
    }

    return 0;
}