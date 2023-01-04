#pragma once
#include <iostream>
using namespace std;

//Doubly linked list class
class WeaponBag
{
public:
	string weaponName; //the name of weapon
	int weaponDamage;	//the value of weapon damage
	WeaponBag* prev;	//pointer points to the previous address
	WeaponBag* next;	//pointer points to the next address

	//Constructor
	WeaponBag()
	{
		weaponName = "";
		weaponDamage = 0;
		prev = nullptr;
		next = nullptr;
	}

	WeaponBag(string wpName, int wpDamage)
	{
		weaponName = wpName;
		weaponDamage = wpDamage;
		prev = nullptr;
		next = nullptr;
	}

	WeaponBag(string wpName, int wpDamage, WeaponBag* wpPrevious, WeaponBag* wpNext)
	{
		weaponName = wpName;
		weaponDamage = wpDamage;
		prev = wpPrevious;
		next = wpNext;
	}

	//Allow player to append his weapon Bag
	void append(string wpName, int wpDamage, WeaponBag*& weaponBag)
	{
		//create a new weapon pointer to store the weapon
		WeaponBag* newWeapon = new WeaponBag(wpName, wpDamage);
		//the current bag next address is set to new weapon address
		weaponBag->next = newWeapon; 
		//the previous address of new weapon set to current weapon bag
		newWeapon->prev = weaponBag;
		//create a new pointer
		WeaponBag* Index;
		//Allow player to hold the newest weapon
		Index = weaponBag->next;
		weaponBag = Index;
		
	}
};