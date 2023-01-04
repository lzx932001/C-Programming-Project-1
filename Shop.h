#pragma once
#include <iostream>
#include "Player.h"
using namespace std;

//struct data structure
//store the weapon attributes
struct shopWeapon {
	string weaponName;
	int weaponDamage;
	int weaponCost;
};
//store the potion attributes
struct shopPotion {
	string potName;
	int regenValue;
	int potCost;
};
//Shop class
class Shop
{
private:
	shopWeapon sWeapon[5];	//struct array to store all the weapons
	shopPotion sPotion[3];	//struct array to store all the potions

public:
	//Constructor
	Shop();
	//print out all the weapons available in the shop
	void showWeapon(Player* player);
	//print out all the potions available in the shop
	void showPotion(Player* player);
	//Destructor
	~Shop();
};