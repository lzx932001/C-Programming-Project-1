#pragma once
#include <iostream>
using namespace std;
#include "Enemy.h"

//Abstract Data Type Stack
class Stack
{
private:
	Enemy* fElements[5]; //store the pointer array of enemy
	int fStackPointer;	//the index of the pointer array
	int fStackSize; //the size of the stack
public:
	//Constructor
	Stack(int aSize);
	//Destructor
	~Stack();

	//check if the stack is empty
	bool isEmpty() const;
	//return the size of stack
	int size() const;
	//add the pointer to the stack
	void push(Enemy* aItem);
	//remove the pointer from the stack
	void pop();
	//show the top pointer of the stack
	Enemy* top() ;

};