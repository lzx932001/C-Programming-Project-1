#include <iostream>
#include "Entity.h"
using namespace std;

//Constructor
Entity::Entity()
{
	entityName = "";
	entityHP = 100;
}
//Overloaded Constructor
Entity::Entity(string eName, int eHP)
{
	entityName = eName;
	entityHP = eHP;
}
//Name getter
string Entity::getName()
{
	return entityName;
}
//Name setter
string Entity::setName(string eName)
{
	entityName = eName;
	return entityName;
}
//Hit points getter
int Entity::getHP()
{
	return entityHP;
}
//Hit points setter
int Entity::setHP(int eHP)
{
	entityHP = eHP;
	return entityHP;
}
//Set to virtual for derived class, do nothing
void Entity::showStats()
{

}
//Set to virtual for derived class, do nothing
void Entity::attack()
{

}
//Design pattern Prototype
//Allow derived class object to clone itself
Entity Entity::clone()
{
	return *this;
}

//friend operator overloads
istream& operator >> (istream& aIstream, Entity& aEntity)
{
	//Allow player to enter the playerName
	aIstream >> aEntity.entityName;
	return aIstream;
}

//friend operator overloads
ostream& operator << (ostream& aOstream, Entity& aEntity)
{
	//print the player name and HP
	aOstream << "Name: " << aEntity.entityName << endl;
	aOstream << "HP: " << aEntity.entityHP << endl;

	return aOstream;
}
//Destructor
Entity::~Entity()
{

}