#include "MyStack.h"
#include <iostream>
using namespace std;
int main(void)
{
	MyStack *p = new MyStack(5);

	cout << "stackLength" <<endl;
	cout << p->stackLength() <<endl;
	p->push('h');
	p->push('e');
	p->push('l');
	p->push('l');
	p->push('o');

	cout << "stackTraverse" <<endl;
	p->stackTraverse();

	cout << "pop" <<endl;
	char elem = 0;
	p->pop(elem);
	cout << elem <<endl;
	p->stackTraverse();
	cout << p->stackLength() <<endl;
	if(p->stackEmpty())
	{
		cout <<"Empty"<<endl;
	}
	if(p->stackFull())
	{
		cout<<"Full"<<endl;
	}
	
	delete p;
	p = NULL;
}