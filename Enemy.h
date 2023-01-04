#pragma once
#include <iostream>
#include "Entity.h"
#include "Player.h"

//Allow Enemy class can access Player class
class Player;

//Derived class from Entity class
class Enemy : public Entity
{
private:
	string enemySkill;	//the name of enemy skill
	int enemyDamage;	//the damage of enemy attack
public:
	//Constructor
	Enemy();
	Enemy(string enemyName, int enemyHP, string eSkill, int eDamage);
	//Skill getter, return the name of the skill
	string getSkill();
	//Skill setter, set the name of the skill
	string setSkill(string eSkill);
	//Damage getter, return the value of enemy attack
	int getDamage();
	//Damage setter, set the value of enemy attack
	int setDamage(int eDamage);
	//Allow enemy to print its stats
	void showStats();
	//Allow enemy to attack player
	void attack(Player*& player);

	//Design Pattern Prototype
	//Allow enemy to clone itself

	Entity clone() override;
	//Destructor
	~Enemy();
};