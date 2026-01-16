
// Linked List Queue Class implementation

#include <iostream>
#include"QueueL.h"
using namespace std;

// Class Constructor

QueueL::QueueL()
{
 	front = NULL; rear = NULL; count = 0;
}

// Class Destructor

QueueL::~QueueL()
{
	NodePointer cursor;
	while(front != NULL)
	{
		cursor = front;
		front = front->next;
		delete cursor;
	}
}


// Add a node with data (v) at the rear of the queue;
// the new node becomes the rear node.

void QueueL::enqueue(int v)
{
	NodePointer pnew = new node;
	pnew->e = v;  pnew->next = NULL;
	if(queueIsEmpty())
	{ front = pnew; rear = pnew;}
	else
	{ rear->next = pnew; rear = pnew; }
	count++;
}

void QueueL::enqueue(char v)
{
	NodePointer pnew = new node;
	pnew->e = v;  pnew->next = NULL;
	if(queueIsEmpty())
	{ front = pnew; rear = pnew;}
	else
	{ rear->next = pnew; rear = pnew; }
	count++;
}

// dequeue front node. Next node becomes front node.

void QueueL::dequeue(int &v)
{
	NodePointer cursor;
	if(queueIsEmpty()) cout << "Queue is Empty" << endl;
	else
	{
			v = front->e;
			cursor = front;
			front = front->next;
			delete cursor;  count--;
	}
}

void QueueL::dequeue(char &v)
{
	NodePointer cursor;
	if(queueIsEmpty()) cout << "Queue is Empty" << endl;
	else
	{
			v = front->e;
			cursor = front;
			front = front->next;
			delete cursor;  count--;
	}
}

// Retrieve front node without removing it

void QueueL::queueFront(int &v) const
{
	
	if(queueIsEmpty()) cout << "Queue is Empty" << endl;
	else { v = front->e; }
}

// return True if queue is empty

bool QueueL::queueIsEmpty() const
{
	return (count == 0);
}

// Queue Length

int QueueL::queueLength() const
{ return count; }



