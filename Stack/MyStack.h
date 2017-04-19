#ifndef _MY_STACK_H_
#define _MY_STACK_H_

class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(char elem);
	bool pop(char &elem);
	void stackTraverse();

private:
	char * m_pBuffer;
	int m_iSize;
	int m_iTop;
};
#endif
