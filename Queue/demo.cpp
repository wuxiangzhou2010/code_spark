#include <iostream>
#include <stdlib.h>
#include "MyQueue.h"

int main(void)
{
	MyQueue *p = new MyQueue(4);
	p->EnQueue(10);
	p->EnQueue(12);
	p->QueueTraverse();
	delete p;
	p = NULL;

	return 0;
}