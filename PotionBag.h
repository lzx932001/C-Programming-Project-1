#pragma once
#include <iostream>
using namespace std;

//Singly Linked List class
class PotionBag
{
	
public:
	string potionName; //name of the potion
	int potionValue;	//the regeneration value of the potion
	PotionBag* next;	//point to the next potion address
	//Constructor
	PotionBag()
	{
		//Default do not have potion
		potionName = "";	
		potionValue = 0;
		next = nullptr;
	}
	PotionBag(string potName, int potValue)
	{
		potionName = potName;
		potionValue = potValue;
		next = nullptr;
	}

	PotionBag(string potName, int potValue, PotionBag* ptr)
	{
		potionName = potName;
		potionValue = potValue;
		next = ptr;
	}

	//Allow player to buy potion and add it to potion bag
	void addPotion(string potName, int regenValue, PotionBag*& top)
	{
		//create a new potion bag pointer
		PotionBag* newPotion = new PotionBag(potName, regenValue, top);
		//change the top of the list to new potion
		top = newPotion;
	}
	//After player healed himself, remove the potion from potion bag
	void removePotion(PotionBag*& top, PotionBag* potion)
	{
		//change the top of the list to the next potion address of current potion
		top = potion->next;
		//remove the potion
		delete potion;
	}
	//check the potion is in the potion Bag
	bool checkPotion(string potName, PotionBag* potionBag)
	{
		//create a Index pointer to store the potionBag
		PotionBag* Index;
		Index = potionBag;
		//if the potion name is Small, run loop to search small potion name
		if (potName == "Small")
		{
			while (Index->potionName != "Small HP Potion")
			{
				Index = Index->next;
			}
			//if small potion name is found, remove the potion
			removePotion(potionBag, potionBag);
			return true;
			
		}
		// if the potion name is Medium, run loop to search medium potion name
		else if (potName == "Medium")
		{
			while (Index->potionName != "Medium HP Potion")
			{
				Index = Index->next;
			}
			//if medium potion name is found, remove the potion
			removePotion(potionBag, potionBag);
			return true;
			
		}
		// if the potion name is Large, run loop to search large potion name
		else if (potName == "Large")
		{
			while (Index->potionName != "Large HP Potion")
			{
				Index = Index->next;
			}
			//if large potion name is found, remove the potion
			removePotion(potionBag, potionBag);
			return true;
			
		}
		else
		{
			return false;
		}
	}
};