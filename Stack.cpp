#include "Stack.h"
#include <iostream>
using namespace std;

//Constructor
Stack::Stack(int aSize)
{
	if (aSize <= 0)
		throw invalid_argument("Illegal stack size.");
	else
	{
		//create 5 fElements pointer to store the Enemy pointer
		fElements[0] = new Enemy();
		fElements[1] = new Enemy();
		fElements[2] = new Enemy();
		fElements[3] = new Enemy();
		fElements[4] = new Enemy();
		fStackPointer = 0;
		fStackSize = aSize;
	}
}
//Destructor
Stack::~Stack()
{
	//Delete all the fElements pointer
	delete fElements[0];
	delete fElements[1];
	delete fElements[2];
	delete fElements[3];
	delete fElements[4];
}
//check the size of stack is 0
bool Stack::isEmpty() const
{
	return fStackPointer == 0;
}
//check the size of stack
int Stack::size() const
{
	return fStackPointer;
}
//add a Enemy pointer into stack
void Stack::push(Enemy* aItem)
{
	if (fStackPointer < fStackSize)
		fElements[fStackPointer++] = aItem;
	else
		throw overflow_error("Stack full.");
}
//remove enemy pointer from the stack
void Stack::pop()
{
	if (!isEmpty())
		fStackPointer--;
	else
		throw underflow_error("Stack empty.");
}
//return the top of the enemy pointer
Enemy* Stack::top()
{
	if (!isEmpty())
		return fElements[fStackPointer-1];
	else
		throw underflow_error("Stack empty.");
}