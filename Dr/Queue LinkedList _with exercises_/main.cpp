#include<iostream>
#include<conio.h>
#include"QueueL.h"
using namespace std;

int main()
{
	QueueL x;
	int out;
	x.enqueue(4);
	x.enqueue(1);
	x.enqueue(3);
	x.enqueue(2);
	x.dequeue(out);
	cout<<"output ="<<out<<endl;

	return 0;
}
