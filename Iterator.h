#pragma once
#include <iostream>
using namespace std;

//Iterator class
class Iterator
{
private:
	int fIndex; //the start of the iterator
	int fIndexEnd; //the end of the iterator

public:
	//Constructor
	Iterator();
	Iterator(int aIndex, int aIndexEnd);
	//Deference * operator, print the content of the pointer
	int operator*();
	//postfix ++ operator, increase the fIndex
	Iterator operator++(int);
	//postfix -- operator, decrease the fIndex
	Iterator operator--(int);
	bool operator==(const Iterator& aOther)const; //==operator, check the current fIndex matches the pointer iterator
	bool operator!=(const Iterator& aOther)const; //!=operator, check the current fIndex not match the pointer iterator
	Iterator begin(); //begin() function
	Iterator end()const; //end() function
};