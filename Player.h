#pragma once
#include <iostream>
#include "Entity.h"
#include "Enemy.h"
#include "PotionBag.h"
#include "WeaponBag.h"

//Allow Player class to access Enemy class
class Enemy;

//A derived class from Entity class
class Player : public Entity
{
private:
	//show the number of gold that player currently has
	int gold;
public:
	//A Singly linked list Pointer, store the potion in the singly linked list
	PotionBag* potBag;
	//A Doubly linked list Pointer, store the weapon in the doubly linked list
	WeaponBag* wpBag;

	//Constructor
	Player();
	//WeaponBag getter, return the name of the weapon
	string getWeapon();
	//WeaponBag setter, set the weaponName and weaponDamage player currently holding
	WeaponBag setWeapon(string wpName, int wpDamage);
	//Gold getter, return the number of gold
	int getGold();
	//Gold setter, change the number of gold if player kill an enemy
	int setGold(int pGold);
	//print the player's current stats
	void showStats();
	//Allow player to attack enemey
	void attack(Enemy*& enemy);
	//Allow player to heal himself
	void heal(Player* player);
	
	//Design Pattern Prototype
	//Allow player to clone himself
	Entity clone() override;

	//Destructor
	~Player();
};