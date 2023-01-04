#include "Shop.h"
#include <iostream>
using namespace std;

//Constructor
Shop::Shop()
{
	//Initialize all the weapons and potions in Constructor
	sWeapon[0].weaponName = "Dagger  ";
	sWeapon[0].weaponDamage = 7;
	sWeapon[0].weaponCost = 5;
	
	sWeapon[1].weaponName = "Axe     ";
	sWeapon[1].weaponDamage = 10;
	sWeapon[1].weaponCost = 10;

	sWeapon[2].weaponName = "Sword   ";
	sWeapon[2].weaponDamage = 15;
	sWeapon[2].weaponCost = 18;

	sWeapon[3].weaponName = "Hammer  ";
	sWeapon[3].weaponDamage = 18;
	sWeapon[3].weaponCost = 23;

	sWeapon[4].weaponName = "DivineRapier";
	sWeapon[4].weaponDamage = 25;
	sWeapon[4].weaponCost = 32;

	sPotion[0].potName = "Small HP Potion";
	sPotion[0].regenValue = 10;
	sPotion[0].potCost = 8;

	sPotion[1].potName = "Medium HP Potion";
	sPotion[1].regenValue = 25;
	sPotion[1].potCost = 22;

	sPotion[2].potName = "Large HP Potion";
	sPotion[2].regenValue = 50;
	sPotion[2].potCost = 40;
}

//print out all the weapons in the shop
void Shop::showWeapon(Player *player)
{
	cout << endl;
	//print the weapons using for loop
	cout << "Weapon  " << "  Damage" << "  Cost" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << sWeapon[i].weaponName << "  " << sWeapon[i].weaponDamage << "       " << sWeapon[i].weaponCost << endl;
	}
	cout << endl;
	//Allow player to buy weapon
	cout << "If you want buy weapon, type buy'Weapon Name'. For example, buyDagger" << endl;
	string buyInput;
	cin >> buyInput;
	//check the input, if the input matches the certain weapon name, run certain if statement
	if (buyInput == "buyDagger")
	{
		//check the player's gold is higher than the weapon cost
		if (player->getGold() > sWeapon[0].weaponCost)
		{
			//append player's weapon bag
			player->wpBag->append(sWeapon[0].weaponName, sWeapon[0].weaponDamage,player->wpBag);
			//deduct the player's gold after bought the weapon
			player->setGold(player->getGold() - sWeapon[0].weaponCost);
			cout << "You bought a " << sWeapon[0].weaponName << endl;
			return;
		}
		else
		{
			//check if player's gold is lower than weapon cost
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else if (buyInput == "buyAxe")
	{
		if (player->getGold() > sWeapon[1].weaponCost)
		{
			player->wpBag->append(sWeapon[1].weaponName, sWeapon[1].weaponDamage, player->wpBag);
			player->setGold(player->getGold() - sWeapon[1].weaponCost);
			cout << "You bought a " << sWeapon[1].weaponName << endl;
			return;
		}
		else
		{
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else if (buyInput == "buySword")
	{
		if (player->getGold() > sWeapon[2].weaponCost)
		{
			player->wpBag->append(sWeapon[2].weaponName, sWeapon[2].weaponDamage, player->wpBag);
			player->setGold(player->getGold() - sWeapon[2].weaponCost);
			cout << "You bought a " << sWeapon[2].weaponName << endl;
			return;
		}
		else
		{
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else if (buyInput == "buyHammer")
	{
		if (player->getGold() > sWeapon[3].weaponCost)
		{
			player->wpBag->append(sWeapon[3].weaponName, sWeapon[3].weaponDamage, player->wpBag);
			player->setGold(player->getGold() - sWeapon[3].weaponCost);
			cout << "You bought a " << sWeapon[3].weaponName << endl;
			return;
		}
		else
		{
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else if (buyInput == "buyDivineRapier")
	{
		if (player->getGold() > sWeapon[4].weaponCost)
		{
			player->wpBag->append(sWeapon[4].weaponName, sWeapon[4].weaponDamage, player->wpBag);
			player->setGold(player->getGold() - sWeapon[4].weaponCost);
			cout << "You bought a " << sWeapon[4].weaponName << endl;
			return;
		}
		else
		{
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else
	{
		cout << "No such weapon available. Sorry :(" << endl;
	}

	
}
//print out all the potions in the shop
void Shop::showPotion(Player* player)
{
	cout << endl;
	//print all the potions
	cout << "Potion    " << "       Regen " << " Cost" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << sPotion[i].potName << "  " << sPotion[i].regenValue << "     " << sPotion[i].potCost << endl;
	}
	cout << endl;
	//Allow player to buy potion
	cout << "If you want buy potion, type buy'Small'. For example, buySmall" << endl;
	string buyInput;
	cin >> buyInput;
	//check the input, if the input matches the certain potion name, run certain if statement
	if (buyInput == "buySmall")
	{
		//check the player's gold is higher than the potion cost
		if (player->getGold() > sPotion[0].potCost)
		{
			//add the potion into the potion bag
			player->potBag->addPotion(sPotion[0].potName, sPotion[0].regenValue,player->potBag);
			//deduct the player's gold
			player->setGold(player->getGold() - sPotion[0].potCost);
			cout << "You bought a " << sPotion[0].potName << endl;
			return;
		}
		else
		{
			//if the player's gold lower than potion cost, print this statement
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else if (buyInput == "buyMedium")
	{
		if (player->getGold() > sPotion[1].potCost)
		{
			player->potBag->addPotion(sPotion[1].potName, sPotion[1].regenValue, player->potBag);
			player->setGold(player->getGold() - sPotion[1].potCost);
			cout << "You bought a " << sPotion[1].potName << endl;
			return;
		}
		else
		{
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else if (buyInput == "buyLarge")
	{
		if (player->getGold() > sPotion[2].potCost)
		{
			player->potBag->addPotion(sPotion[2].potName, sPotion[2].regenValue, player->potBag);
			player->setGold(player->getGold() - sPotion[2].potCost);
			cout << "You bought a " << sPotion[2].potName << endl;
			return;
		}
		else
		{
			cout << "Not enough gold to buy. Go kill some enemies!" << endl;
			return;
		}
	}
	else
	{
		cout << "No such potion available. Sorry :(" << endl;
	}
	
}

//Shop Destructor
Shop::~Shop()
{

}