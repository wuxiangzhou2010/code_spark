
#include "MyStack.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
MyStack::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new char[size];
	m_iTop = 0;
}
MyStack::~MyStack()
{
	delete []m_pBuffer;
}
bool MyStack::stackEmpty()
{
	if(0 == m_iTop)
		return true;
	return false;
}
bool MyStack::stackFull()
{
	if(m_iTop == m_iSize)
	{
		return true;
	}
	return false;
}
void MyStack::clearStack()
{
	m_iTop = 0;
}
int MyStack::stackLength()
{
	return m_iTop;
}
bool MyStack::push(char elem)
{
	if(stackFull())
		return false;
	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}
bool MyStack::pop(char &elem)
{
	if(stackEmpty())
		return false;
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}

void MyStack::stackTraverse()
{
	for(int i = 0; i <m_iTop; i++)
	{
		cout << m_pBuffer[i] <<endl;
	}
}
