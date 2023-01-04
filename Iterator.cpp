#include "Iterator.h"
#include <iostream>
using namespace std;

//Constructor
Iterator::Iterator()
{
	fIndex = 0;
	fIndexEnd = 5;
}
//Overloaded constructor
Iterator::Iterator(int aIndex, int aIndexEnd)
{
	fIndex = aIndex;
	fIndexEnd = aIndexEnd;
}
//Deference * operator, print the content of the pointer
int Iterator::operator*()
{
	return fIndex;
}
//postfix ++ operator, increase the fIndex
Iterator Iterator::operator++(int)
{
	//create a temporary iterator to store the current iterator
	Iterator temp = *this;
	if (fIndex < fIndexEnd)
		fIndex++;
	return temp;
}
//postfix -- operator, decrease the fIndex
Iterator Iterator::operator--(int)
{
	//create a temporary iterator to store the current iterator
	Iterator temp = *this;
	if (fIndex > 0)
		fIndex--;
	return temp;
}
//==operator, check the current fIndex matches the pointer iterator
bool Iterator::operator==(const Iterator& aOther)const
{
	return (fIndex == aOther.fIndex);
}
//!=operator, check the current fIndex not match the pointer iterator
bool Iterator::operator!=(const Iterator& aOther)const
{
	return !(*this == aOther);
}
//begin() function, return the start stage of iterator
Iterator Iterator::begin()
{
	return Iterator(0, fIndexEnd);
}
//end() function, return the end stage of iterator
Iterator Iterator::end() const
{
	return Iterator(fIndexEnd, fIndexEnd);
}