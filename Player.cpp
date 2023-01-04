#include "Player.h"
#include <iostream>
using namespace std;

//Player Constructor
Player::Player()
{
	gold = 0; //Default gold is set to 0
	potBag = new PotionBag(); //Create a new Singly linked list Pointer
	wpBag = new WeaponBag("Hoe", 5); //Create a new Doubly linked list Pointer, set default weapon name and damage
}

//Weapon getter, return the name of the weapon
string Player::getWeapon()
{
	return wpBag->weaponName;
}
//Weapon setter, set the weapon name and damage
WeaponBag Player::setWeapon(string wpName, int wpDamage)
{
	wpBag->weaponName = wpName;
	wpBag->weaponDamage = wpDamage;
	return *wpBag;
}

//Gold getter, return the number of gold
int Player::getGold()
{
	return gold;
}

//Gold setter, set the number of gold if gold increase
int Player::setGold(int pGold)
{
	gold = pGold;
	return gold;
}

//Print out the player's current stats
void Player::showStats()
{
	cout << "CurrentHP: " << getHP() << endl;
	cout << "Weapon: " << wpBag->weaponName << endl;
	cout << "Gold: " << gold << endl;
	cout << endl;
}
//Allow player to attack enemy
void Player::attack(Enemy *&enemy)
{
	int remainHP;
	cout << endl;
	cout << "Deals " << wpBag->weaponDamage << " damages to " << enemy->getName() << endl;
	//calculate the remaining HP of enemy after player attack
	remainHP = enemy->getHP() - wpBag->weaponDamage;
	if (remainHP < 0)
	{
		remainHP = 0;
	}
	//set enemy HP to remaining HP
	enemy->setHP(remainHP);
	cout << "Enemy remain HP: " << remainHP << endl;
	cout << endl;
	
}

//Allow player to heal himself
void Player::heal(Player *player)
{
	cout << endl;
	string healInput;
	cout << "Use heal'Name' to heal yourself. For example, healSmall." << endl;
	cin >> healInput;
	//check the input, player want to use which potion
	if (healInput == "healSmall")
	{
		//check if the potion bag exists small potion, return true
		if (player->potBag->checkPotion("Small", player->potBag) == true)
		{
			//heal the player
			player->setHP(player->getHP() + 10);
			//if player HP over 100 after healed, set to 100 Max HP
			if (player->getHP() > 100)
			{
				player->setHP(100);
			}
			cout << "Player HP: " << player->getHP() << endl;
		}
	}
	//check the input, player want to use which potion
	else if (healInput == "healMedium")
	{
		//check if the potion bag exists medium potion, return true
		if (player->potBag->checkPotion("Medium", player->potBag) == true)
		{
			player->setHP(player->getHP() + 25);
			//if player HP over 100 after healed, set to 100 Max HP
			if (player->getHP() > 100)
			{
				player->setHP(100);
			}
			cout << "Player HP: " << player->getHP() << endl;
		}
	}
	//check the input, player want to use which potion
	else if (healInput == "healLarge")
	{
		//check if the potion bag exists large potion, return true
		if (player->potBag->checkPotion("Large", player->potBag) == true)
		{
			player->setHP(player->getHP() + 50);
			//if player HP over 100 after healed, set to 100 Max HP
			if (player->getHP() > 100)
			{
				player->setHP(100);
			}
			cout << "Player HP: " << player->getHP() << endl;
		}
	}
	else
	{
		//print the statement if the player do not have specific potion
		cout << "Do not have the potion in your potion bag. Go buy one!" << endl;
	}
}

//Design Pattern Prototype
//Allow player to clone himself
Entity Player::clone()
{
	return Player(*this);
}

//Player Destructor
Player::~Player()
{
	delete potBag; //delete the potionBag pointer
	delete wpBag;	//delete the weaponBag pointer
}