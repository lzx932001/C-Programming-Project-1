#include "Enemy.h"
#include <iostream>
using namespace std;

//Enemy Constructor
Enemy::Enemy()
{
	enemySkill = "";	//Default name of enemy attack
	enemyDamage = 0;	//Default value of enemy attack
}
//Overloaded Constructor
Enemy::Enemy(string enemyName, int enemyHP, string eSkill, int eDamage) : Entity(enemyName, enemyHP)
{
	enemySkill = eSkill;
	enemyDamage = eDamage;
}
//Skill getter, return the name of enemy skill
string Enemy::getSkill()
{
	return enemySkill;
}
//Skill setter, set the name of enemy skill
string Enemy::setSkill(string eSkill)
{
	enemySkill = eSkill;
	return enemySkill;
}
//Damage getter, return the value of enemy damage
int Enemy::getDamage()
{
	return enemyDamage;
}
//Damage setter, set the value of enemy damage
int Enemy::setDamage(int eDamage)
{
	enemyDamage = eDamage;
	return enemyDamage;
}
//print out the enemy's current stats
void Enemy::showStats()
{
	cout << "Enemy Stats:" << endl;
	cout << "MonsterName " << "HP " << " Skill  " <<"  Damage" << endl;
	cout << getName() << "       " << getHP() << "  " << getSkill() << "     " <<getDamage()<< endl;
}
//Allow enemy to attack player
void Enemy::attack(Player *&player)
{
	int remainHP;
	cout << getName() << " deals " << getDamage() << " damages to " << player->getName() << endl;
	//set the player's remaining HP after player get hit
	remainHP = player->getHP() - getDamage();

	if (remainHP < 0)
	{
		remainHP = 0;
	}
	player->setHP(remainHP);
	cout << "Player remain HP: " << player->getHP() << endl;
	cout << endl;
	
}
//Design Pattern Prototype
//Allow enemy to clone itself
Entity Enemy::clone()
{
	return Enemy(*this);
}
//Enemy Destructor
Enemy::~Enemy()
{

}