#include <SFML/Audio.hpp>
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "Shop.h"
#include <time.h>
#include "Iterator.h"
#include "Stack.h"
#include <stdlib.h>

//show all the input in combat stage
void battleInput(string input, Player* player, Enemy *&enemy)
{
    string commands[3] = { "attack", "showStats", "heal" };
    //if input == help, show all the available command
    if (input == "help")
    {
        cout << endl;
        cout << "Available commands:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << commands[i] << endl;
        }
        cout << endl;
    }
    //allow player attack enemy, and enemy will auto attack player
    else if (input == "attack")
    {
        player->attack(*&enemy);
        enemy->attack(*&player);
    }
    //heal player command
    else if (input == "heal")
    {
        player->heal(player);
    }
    //show the player stats command
    else if (input == "showStats")
    {
        player->showStats();
    }
}
//show the available command in the shop
void accessShop(Shop shop, Player* player)
{
    string shopCommand;
    
    do 
    {
        cout << "Available commands in SHOP" << endl;
        cout << "showWeapon" << endl;
        cout << "showPotion" << endl;
        cout << "exitShop" << endl;
        cout << endl;
        cin >> shopCommand;
        //if command is showWeapon, print all the weapon
        if (shopCommand == "showWeapon")
        {
            shop.showWeapon(player);
            cout << endl;
        }
        //if command is showPotion, print all the potion
        else if (shopCommand == "showPotion")
        {
            shop.showPotion(player);
            cout << endl;
        }
        //exit the shop
        else if (shopCommand == "exitShop")
        {
            cout << "Exit the SHOP. Have a nice day!" << endl;
            cout << endl;
        }
        else
        {
            //if the command is not included in the command list
            cout << "Command not found :(" << endl;
            cout << endl;
        }
    } while (shopCommand != "exitShop");
}

int main()
{
    
    sf::SoundBuffer buffer;     //soundbuffer variable
    if (!buffer.loadFromFile("101 You're a Treasure.wav")) //load the music from file
        return -1;
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play(); //play the music
    

    //Initialize the stack
    Stack enemyStack(5);
    //Initialize all the enemy
    Enemy* e1 = new Enemy("Slime", 20, "Spit", 3);
    Enemy* e2 = new Enemy("Goblin", 35, "Enrage", 7);
    Enemy* e3 = new Enemy("Zombie", 42, "Bite", 10);
    Enemy* e4 = new Enemy("Skeleton", 50, "Scratch", 15);
    Enemy* e5 = new Enemy("Dark Knight", 65, "Dark Ascension", 20);
    //push all the enemies to the stack
    enemyStack.push(e5);
    enemyStack.push(e4);
    enemyStack.push(e3);
    enemyStack.push(e2);
    enemyStack.push(e1);
    //show the Design Pattern Prototype
    //Demo
    
    cout << "Demo" << endl;
    Entity e6 = e5->clone();
    cout << e6;
    cout << endl;
    
    //Initialize the player pointer
    Player* p1;
    p1 = new Player();
    //The name of the game
    cout << "Welcome to The Adventure" << endl;
    //require player to enter character name
    cout << "Enter your character name : " << endl;
    string playerName;
    //Here using the friend operator overload
    cin >> playerName;
    p1->setName(playerName);
    cout << endl;
    cout << "This is your Player Stats: " << endl;
    //show the player start stats
    cout << *p1;
    cout << endl;
    //help generate random number
    srand((unsigned)time(0));
    
    //Initialize a enemy pointer to store the current enemy
    Enemy* currentEnemy;
    currentEnemy = new Enemy();
    
    //Initialize the shop object
    Shop shop;
    
    //Initialize the GameState iterator pointer
    Iterator* GameState = new Iterator(0, 5);
    //loop the iterator
    for (; (*GameState) != (*GameState).end();)
    {
        cout <<"Stage " << *(*GameState)+1 << endl;
        cout << "You meet an enemy, fight it" << endl;
        cout << endl;
        
        //set the top of the stack to current enemy
        currentEnemy = enemyStack.top();
        //print out the enemy stats
        currentEnemy->showStats();
        //remove it from the stack
        enemyStack.pop();
        
        cout << endl;
        string input;
        do 
        {
            //require player input combat command
            cout << "Type 'help' if you want to show all the commands" << endl;
            cin >> input;
            //send the input, player himself, and the current enemy to the function
            battleInput(input, p1, currentEnemy);
            //if the current enemy HP is 0, print statement
            if (currentEnemy->getHP() == 0)
            {
                cout << "Congratulations! You defeated the enemy!" << endl;
            }
            //if the player HP is 0, print statement
            if (p1->getHP() == 0)
            {
                cout << "You died. Try a new Game." << endl;
                //End the game, exit from the program
                return 0;
            }
        } while (currentEnemy->getHP() > 0 || p1->getHP() < 0);
        //Initialize randNum to store random number
        int randNum = (rand() % 60) + 1;
        cout << endl;
        cout << "Enemy drops " << randNum <<" golds" << endl;
        //and store it into player
        p1->setGold(randNum);
        cout << endl;
        string normalInput;
        do
        {
            //available command after combat stage
            cout << "Choose your next action:" << endl;
            cout << "shop  " << "  Enter the SHOP" << endl;
            cout << "move  " << "  move to next stage" << endl;
            cout << endl;

            cin >> normalInput;
            cout << endl;
            //if input is shop, access the shop
            if (normalInput == "shop")
            {
                accessShop(shop, p1);
            }
            //if input is move, move to next stage
            else if (normalInput == "move")
            {
                (*GameState)++;
            }
        } while (normalInput != "move");
           
    }
    //print this after player defeated the final boss
    cout << "Congratulations!You defeated the final enemy!" << endl;
    //delete player and iterator pointers
    delete p1;
    delete GameState;
    return 0;
}