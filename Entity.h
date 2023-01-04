#pragma once
#include <iostream>
using namespace std;

//Represent a Entity object class
class Entity
{
private:
	string entityName; //The name of the entity
	int entityHP;	//The Hit points of entity

public:
	//Constructor
	Entity();
	Entity(string eName, int eHP);
	//Name getter and setter
	string getName();
	string setName(string eName);
	//Hit point getter and setter
	int getHP();
	int setHP(int eHP);
	//Set to virtual for derived class, do nothing
	virtual void showStats();
	virtual void attack();

	//Design Pattern Prototype
	//Allow derived class object to clone itself
	virtual Entity clone();

	//friend operator overloads
	friend ostream& operator << (ostream& aOstream, Entity& aEntity);
	friend istream& operator >> (istream& aIstream, Entity& aEntity);

	//Destructor
	~Entity();
};