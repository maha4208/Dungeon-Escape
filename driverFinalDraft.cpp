// Authors: Mark Haley
// To play, make sure you are on the correct directory in linux and enter the below commands:
// 1: g++ booty.cpp character.cpp cookware.cpp driverFinalDraft.cpp monster.cpp party.cpp weapon.cpp
// 2: ./a.out
//
// Follow the directions that are then output in the command terminal and have fun!
#include <iostream>
#include <iomanip>
#include <string>
# include <vector>
#include <cmath>
#include <fstream>
# include "weapon.h"
# include "cookware.h"
# include "character.h"
# include "party.h"
# include "monster.h"
# include "booty.h"

using namespace std;

// This function outputs the status of each player.
// Parameters: An object of class party, an integer for the wizards anger
// and an integer for the the current room.
// Return: number of characters still alive.
int statusUpdate(Party &party1, int anger, int room)
{   
    int i = 0;
    int numval = 5;
    Character character;
    Weapon weapon;
    cout << endl;
    cout << "End of turn. Everyone's hunger is dropping one point!" << endl;
    cout << endl;
    while (i < 5)
    {   
        character = party1.getCharacterAt(i);

        if(character.getName() != "")
        {
            if(character.getHunger() >= 0)
            {
                character.setHunger(character.getHunger() -1);
                party1.setCharactersAt(character, i);
                cout << character.getName() << "'s hunger is " << character.getHunger() << endl;
                cout << endl;
            }
            if(character.getHunger() <= 0)
            {
                cout << "Feed your team!!! " << character.getName() << " has died of hunger" << endl;
                
                character.setName("");
                character.setArmor(0);
                weapon = character.getWeapon();
                weapon.setName("");
                weapon.setHP(0);
                character.setWeapon(weapon);
                party1.setCharactersAt(character, i);
            }
        }
        i++;
    }

    for (int i = 0; i < 5; i++)
    {
        if (party1.getCharacterNameAt(i) == "")
        {
            numval--;
        }
    }
    cout << "Careful. The Sorcerers anger is now " << anger << endl;
    cout << endl;
    cout << "Number of teammates alive: " << numval << endl;
    cout << endl;
    cout << "Just so you know... You are in room " << room << endl;
    cout << endl; 
    cout << endl;
    return numval;
}


// This function displays the proper statements when the game ends
// Parameters: the most recent choice, wizards anger, number of characters, and current room.
// Return: N/A
void EndGameMenu(int choice, int anger, int numchars, int room)
{
    if (choice == 6)
    {
        cout << "I am so sorry to hear that you are a little quiter." << endl;
        cout << "Come and play again soon!!!" << endl;
    }
    else if(anger >= 100)
    {
        cout << "You are out of time! The Sorcerer became to angry." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~ YOU LOSE ~~~~~~~~~~~~~~~~~~~~" << endl;
    }
    else if(numchars == 0)
    {
        cout << "All of your players have died. The game is over." << endl;
        cout << "~~~~~~~~~~~~~~~~~~~ YOU LOSE ~~~~~~~~~~~~~~~~~~~" << endl;
    }
    else 
    {
        cout << "Congratualtions! You made it through all 5 rooms without dying!" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!~~~~~~~~YOU WIN~~~~~~~~!!!!!!!!!!!!!!!!!!!!" << endl;
    }
}
// This function plays at the end of every turn and determines whether to commit a misfortune and if so, whcih one.
// Parameters: an object of class party
// Return: N/A
void Misfortunes(Party &party1)
{
    bool broken = false;
    Character character;
    bool DeathMarker = false;
    string weaponName;
    Weapon weapon;
    int i = 0;
    int numAlive = 0;
    srand(time(NULL));
    int random = rand() % 5;
    if (random == 0 || random == 1)
    {
        random = rand() % 4;
        switch(random)
        {
            case 0:
                cout << "OH NO! Your team was robbed by dungeon bandits!You have no food/cookware/armor left!" << endl;
                party1.setIngredients(0);
                i = 0;
                while(i < 5)
                {
                    character = party1.getCharacterAt(i);
                    character.setArmor(0);
                    party1.setCharactersAt(character, i);
                    i++;
                }
                i = 0;
                while(i < party1.getCookwareSize())
                {
                    party1.breakCookwareAt(i);
                    i++;
                }
                break;

            case 1:
                cout << "OH NO! One of your weapons/armor broke!" << endl;
                i = 0;
                while(i < 5 && !broken)
                {
                    character = party1.getCharacterAt(i);
                    if(character.getArmor() > 0)
                    {
                        character.setArmor(0);
                        party1.setCharactersAt(character, i);
                        broken = true;
                    }
                    i++;
                }
                i = 0;
                while(i < 5 && !broken)
                {
                    character = party1.getCharacterAt(i);
                    weapon = character.getWeapon();
                    if(weapon.getName() != "")
                    {
                        weapon.setName("");
                        weapon.setHP(0);
                        character.setWeapon(weapon);
                        broken = true;
                    }
                    party1.setCharactersAt(character, i);
                    i++;
                }
                break;
            case 2:
                i = 5;
                while (i > 0 && !DeathMarker)
                {
                    character = party1.getCharacterAt(i-1);
                    if(character.getName() != "")
                    {
                        cout << "OH NO! " << character.getName() << " has died of hunger" << endl;
                        character.setName("");
                        character.setArmor(0);
                        weapon = character.getWeapon();
                        weaponName = "";
                        weapon.setName("");
                        weapon.setHP(0);
                        character.setWeapon(weapon);
                        party1.setCharactersAt(character, i - 1);
                        DeathMarker = true;
                    }
                    i--;
                }
                i = 0;
                while(i < 5)
                {
                    character = party1.getCharacterAt(i);
                    if(character.getName() != "")
                    numAlive++;
                    i++;
                }
                cout << "Number of teammates alive: " << numAlive << endl;
                break;
            
            case 3:
                i = 5;
                while (i > 0 && !DeathMarker)
                {
                    character = party1.getCharacterAt(i-1);
                    if(character.getName() != "")
                    {
                        cout << "OH NO!" << character.getName() << " has been trapped in the previous room, and is unable to get" << endl;
                        cout << "through. You must continue without him." << endl;
                        character.setName("");
                        character.setArmor(0);
                        weapon = character.getWeapon();
                        weaponName = "";
                        weapon.setName("");
                        weapon.setHP(0);
                        character.setWeapon(weapon);
                        party1.setCharactersAt(character, i - 1);
                        DeathMarker = true;
                    }
                    i--;
                }
                i = 0;
                while(i < 5)
                {
                    character = party1.getCharacterAt(i);
                    if(character.getName() != "")
                    numAlive++;
                    i++;
                }
                cout << "Number of teammates alive: " << numAlive;
                break;

            default:
                break;

        }
    }
}
// This function determines whether or not you can cook food, and if you can, increases each characters fullness.
// Parameters: An object of class Party
// Return: N/A
void cookAndEat(Party &party1)
{
    int hungPang;
    int kgUsed;
    int kgIn;
    int kgMax;
    int num;
    cout << "Enter the amount of ingredients you would like to cook." << endl;
    cout << "Excess food will be saved in sacrific for your fallen comrades." << endl;
    cin >> kgIn;
    if (party1.getCookwareSize() != 0 && party1.getIngredients() != 0)
    {
        kgMax = party1.getIngredients();
        if (kgIn < kgMax)
        {
            cout << "You are now going to cook " << kgIn << " kg of ingredients." << endl;
            kgUsed = kgIn;
            party1.setIngredients(party1.getIngredients() - kgIn);
        }
        else
        {
            cout << "You don't have that much food, we will use the maximum possible amount : " << kgMax << " kg." << endl;
            kgUsed = kgMax;
            party1.setIngredients(0);
        }
        hungPang = kgMax/5;
        srand(time(NULL));
        num = rand() % party1.getCookwareBreakabilityAt(0);
        if (num == 2)
        {
            party1.breakCookwareAt(0);
            cout << "Your cookware just broke, all ingredients and cookware lost." << endl;
        }
        else
        {
            for (int i = 0; i < hungPang; i++)
            {
                party1.incrementCharacterHungerAt(i % 5);
            }
            cout << "Your party has just been fed. Your fullness has increased by " << hungPang << " units."  << endl;
        }
    }
    else
    {
        cout << "You either don't have any cookware or ingredients." << endl;
    }   
}

// This function goes through the sequence that occurs when the player elects to attack a monster
// Parameters: the difficulty as determined by the room number, an object of class party
// Return: True or false depending on if you won or not.
bool Attack(int difficulty, Party &party1)
{
    Character character;
    Weapon weapon;
    int i = 0;
    int j = 0;
    int numClubs;
    int numSpears;
    int numCrossbows;
    int numBattleAxes;
    int numLongSwords;
    string weaponName;
    int totalHp = 0;
    int numWeapons = 0;
    int oneOfEach;
    double NumArmor = 0;
    double attackEquation;
    double random1;
    double random2;
    bool key = false;
    bool slain = false;

    while (i < 5)
    {
        character = party1.getCharacterAt(i);
        NumArmor = NumArmor + character.getArmor();
        weapon = character.getWeapon();
        weaponName = weapon.getName();
        if(weaponName != "")
        {
            if(weaponName != "Club")
            {
                numClubs++;
            }
            else if(weaponName != "Spears")
            {
                numSpears++;
            }
            else if(weaponName != "CrossBow")
            {
                numCrossbows++;
            }
            else if(weaponName != "Battle-Ax")
            {
                numBattleAxes++;
            }
            else if(weaponName != "Longsword")
            {
                numLongSwords++;
            }
            totalHp = totalHp + weapon.getHP();
            numWeapons++;
        }

        i++;
    }
    if(numBattleAxes == 1 && numCrossbows == 1 && numLongSwords == 1 && numSpears ==1 && numClubs == 1)
    {
        oneOfEach = 1;
    }

    srand(time(NULL));
    random1 = rand() % 6 + 1;
    random2 = rand() % 6 + 1;


    attackEquation = ((random1 * (numWeapons + totalHp) + oneOfEach)) - (random2 * difficulty * (1/NumArmor));
    
    if (attackEquation > 0)
    {
        random1 = rand() % 3;
        cout << "Congrats!!! You won!" << endl;
        cout << "You gained 50 gold pieces and 20kg of ingredients from the monster." << endl;
        if (random1 == 1)
        {
            cout << "You also gained a key!" << endl;
            key = true;
        }
        else
        {
            cout << "Unfortunately no key was gained" << endl;
        }
        party1.addPrice(50);
        party1.setIngredients(party1.getIngredients() + 20);
        cout << "You now have " << party1.getTreasure() << " coins and " << party1.getIngredients() << "kg of ingredients." << endl;

    }

    else
    {
        cout << "You lost" << endl;
        cout << "You lost a quarter of your coins and 30kg of ingredients" << endl;
        party1.removePrice(party1.getTreasure() * .25);
        party1.setIngredients(party1.getIngredients() - 30);
        cout << "You now have " << party1.getTreasure() << " coins and " << party1.getIngredients() << "kg of ingredients." << endl;
        while (j < 5)
        {
            character = party1.getCharacterAt(j);
            NumArmor = character.getArmor();
            if (NumArmor == 1)
            {
                random1 = rand() % 20;
                if(random1 == 1)
                {
                    cout << character.getName() << " has been slain." << endl;
                    character.setName("");
                    character.setArmor(0);
                    weapon = character.getWeapon();
                    weaponName = "";
                    weapon.setName("");
                    weapon.setHP(0);
                    character.setWeapon(weapon);
                    party1.setCharactersAt(character, i - 1);
                }
            }  

            else
            {
                random1 = rand() % 10;
                if(random1 == 1)
                {
                    cout << character.getName() << " has been slain." << endl;
                    character.setName("");
                    character.setArmor(0);
                    weapon = character.getWeapon();
                    weaponName = "";
                    weapon.setName("");
                    weapon.setHP(0);
                    character.setWeapon(weapon);
                    party1.setCharactersAt(character, i -1);
                }
            }  
            i++;     
        }
    }

    return key;
}

// This function goes through the process of surrendering to a monster
// Parameters: an object of class party
// Return: N/A
void Surrender(Party &party1)
{
    Character character;
    Weapon weapon;
    int i = 5;
    bool DeathMarker = false;
    string weaponName;
    cout << "One member from the traveling party was unable to escape the wrath of the monster." << endl;
    cout << "The party loses one member." << endl;
    while (i > 0 && !DeathMarker)
    {
        character = party1.getCharacterAt(i-1);
        if(character.getName() != "")
        {
            cout << character.getName() << " has been slain." << endl;
            character.setName("");
            character.setArmor(0);
            weapon = character.getWeapon();
            weaponName = "";
            weapon.setName("");
            weapon.setHP(0);
            character.setWeapon(weapon);
            party1.setCharactersAt(character, i - 1);
            DeathMarker = true;
        }
        i--;

    }

}

// This function fights the monster and determines whether or not to attack or surrender
// Parameters: The current room, an object of class party.
// Return: true or false depending on whether or not the key was dropped
bool Fight(int room, Party &party1)
{
    Character character;
    Weapon weapon;
    bool key;
    int choice;
    int difficulty = room;
    int i = 0;
    int NumArmor = 0;
    int numWeapon = 0;
    string weaponName;
    Monster monster = Monster(difficulty); 
    do{
        cout << "What is that?" << endl;
        cout << "OH NOOOOOO! " << monster.getMonster()  << " AHEAD! THEY LOOK HOSTILE!" << endl;
        cout << endl;
        cout << "What do you want to do?" << endl;
        cout << "1 : Fight it!!! (Enter 1)" << endl;
        cout << "2 : Surrender (Enter 2)" << endl;
        cin >> choice;
        i = 0;
        while(i < 5)
        {
            character = party1.getCharacterAt(i);
            NumArmor = NumArmor + character.getArmor();
            weapon = character.getWeapon();
            weaponName = weapon.getName();
            character.setHunger(character.getHunger() -1);
            party1.setCharactersAt(character, i);
            if(weaponName != "")
            {
                numWeapon++;
            }
            i++;
        }
        if (NumArmor != 0 && numWeapon != 0)
        {

        }
        else
        {
            cout << "Just kidding LOL. You either have no weapons or no armor." << endl;
            cout << "you have to surrender" << endl;
            choice = 2;
        }
        switch (choice)
        {
            case 1:
                key = Attack(room, party1);
                break;
            case 2:
                Surrender(party1);
                break;

            default:
                cout << "You silly little goose, that's not an option!" << endl;
                break;
        }
    }while(choice != 1 && choice != 2);

    cout << "Everyone's hunger dropped by one point from the Fight" << endl;

    return key;
}

// This function determines whether or not you have enough money to complete a purchase, and if you can,
// subtracts the appropriate amount of money.
// Parameters: an object of class party, and the cash needed to complete the purchase
// Return: true or false depending on whether you have enough $ or not
bool CanYouBuy(Party &party1, double cashRemoved)
{
    double balance = party1.getTreasure();
    double possibleBallance = balance - cashRemoved;
    if (possibleBallance >= 0)
    {
        party1.removePrice(cashRemoved);
        return true;
    }
    else
    {
        cout << "Cannot proceed with purchase, you would have negative treasure." << endl;
        return false;
    }
}
// This function calls in the merchant, and adds objects to your inventory, subtracting the appropriate amount of $
// it also allows you to sell booty that you've found.
// Parameters: the current room, and an object of class party
void Merchant(int room, Party &party1)
{
    ifstream in_file;
    string line;
    in_file.open("merchant_info.txt");
    int numkg;
    int numArmor;
    double price;
    bool canBuy;
    int i;
    int numClubs;
    int index;
    int numSpears;
    int numCrossbows;
    int numBattleAxes;
    int numLongSwords;
    int numCauldrons;
    int numCastIron;
    int numCeramic;
    int choice;
    Weapon possibleWeapons[5];
    possibleWeapons[0] = Weapon("Club", 1);
    possibleWeapons[1] = Weapon("Spear", 1);
    possibleWeapons[2] = Weapon("Crossbow", 2);
    possibleWeapons[3] = Weapon("Battle-Ax", 2);
    possibleWeapons[4] = Weapon("Longsword", 2);
    Cookware possibleCookwares[3];
    possibleCookwares[0] = Cookware(50, "Cauldron");
    possibleCookwares[1] = Cookware(10, "Cast-Iron Pan");
    possibleCookwares[2] = Cookware(4, "Ceramic Pot");
    while(getline(in_file, line))
    {
        cout << line << endl;
    }
    do
    {
        cout << "What order guide do you want to see?" << endl;
        cout << "1 : Food (Enter 1)" << endl;
        cout << "2 : Weapons (Enter 2)" << endl;
        cout << "3 : Armor (Enter 3)" << endl;
        cout << "4 : Cookware (Enter 4)" << endl;
        cout << "5 : Leave Merchant Area (Enter 5)" << endl;

        cin >> choice;
        
        switch(choice) 
        {
            case 1:
                price = 1 *(1+ 0.25 * (room -1));
                cout << "How many kilograms of food do you want at " <<
                price <<  " gold piece per kg, homeboy. " << endl;
                cout << "I recomend at least 10 kg per person, but what do I know... " << endl;

                cin >> numkg;

                canBuy = CanYouBuy(party1, numkg * price);
                if (canBuy == true)
                {
                    party1.setIngredients(party1.getIngredients()+numkg);
                }

                cout << "Remaining balance: " << party1.getTreasure() << " coins" << endl;

                break;
            
            case 2:
                cout << "You need weapons to be able to beat off monsters, otherwise, you can only run!" << endl;
                cout << "Equipping your team with the maximum number of weapons(1 weapon per person)" << endl;
                cout << "and buying upgraded weapons that are worth 5 gold pieces will maximize your" << endl;
                cout << "chances of survival during an attack. You can have amaximum of 5weapons. These" << endl;
                cout << "are the different types of weapons:" << endl;
                cout << "i.A club costs " << 2 *(1+ 0.25 * (room -1)) << " gold pieces." << endl;
                cout << "ii.A spear costs " << 2 *(1+ 0.25 * (room -1)) << " gold pieces." << endl;
                cout << "iii.A crossbow costs " << 5 *(1+ 0.25 * (room -1)) << " gold pieces." << endl;
                cout << "iv.A battle-axe costs " << 5 *(1+ 0.25 * (room -1))<< " gold pieces." << endl;
                cout << "v.A longsword costs " << 5 *(1+ 0.25 * (room -1)) <<  " gold pieces." << endl;
                cout << "Warning: Most recent purchases will be kept, buying more than the max will result in wasted gold." << endl;
                i = 0;
                cout << "How many clubs do you want?" << endl;
                cin >> numClubs;
                canBuy = CanYouBuy(party1, numClubs *  (2 *(1+ 0.25 * (room -1))));
                if (canBuy == true)
                {
                    while (i < numClubs)
                    {
                        index = i % 5;
                        party1.addCharacterWeapon(possibleWeapons[0],index);
                        i++;
                    }
                }
                cout << "How many spears do you want?" << endl;
                cin >> numSpears;
                canBuy = CanYouBuy(party1, numSpears *  (2 *(1+ 0.25 * (room -1))));
                if (canBuy == true)
                {
                    while (i < numClubs+numSpears)
                    {
                        index = i % 5;
                        party1.addCharacterWeapon(possibleWeapons[1],index);
                        i++;
                    }
                }
                cout << "How many crossbows do you want?" << endl;
                cin >> numCrossbows;
                canBuy = CanYouBuy(party1, numCrossbows *  (5 *(1+ 0.25 * (room -1))));
                if (canBuy == true)
                {
                    while (i < numClubs+numSpears+ numCrossbows)
                    {
                        index = i % 5;
                        party1.addCharacterWeapon(possibleWeapons[2],index);
                        i++;
                    }
                }
                cout << "How many battle-axes do you want?" << endl;
                cin >> numBattleAxes;
                canBuy = CanYouBuy(party1, numBattleAxes *  (5 *(1+ 0.25 * (room -1))));
                if (canBuy == true)
                {
                    while (i < numClubs+numSpears+ numCrossbows+numBattleAxes)
                    {
                        index = i % 5;
                        party1.addCharacterWeapon(possibleWeapons[3],index);
                        i++;
                    }
                }
                cout << "How many longswords do you want?" << endl;
                cin >> numLongSwords;
                canBuy = CanYouBuy(party1, numLongSwords *  (5 *(1+ 0.25 * (room -1))));
                if (canBuy == true)
                {
                    while (i < numClubs+numSpears+ numCrossbows+numBattleAxes+numLongSwords)
                    {
                        index = i % 5;
                        party1.addCharacterWeapon(possibleWeapons[4],index);
                        i++;
                    }
                }

                cout << "Remaining balance: " << party1.getTreasure() << " coins" << endl;
            break;

            case 3:
                cout << "A set of armor costs " << 5 * (1+ 0.25 * (room -1)) << " gold coins. Armor protects you from monsters." << endl;
                cout << "Equipping your team with the maximum amount of armor (1 armor per person)" << endl;
                cout << "will maximize your chances of survival during an attack. Adding more armor" << endl;
                cout << "on top of the maximum amount will not increase your chances further."<< endl;
                cout << "How many sets of armor do you want?" << endl;
                cin >> numArmor;

                canBuy = CanYouBuy(party1, numArmor *  (5 *(1+ 0.25 * (room -1))));
                int in2;
                for (int p = 0; p < numArmor; p++)
                {
                    in2 = p % 6;
                    party1.addCharacterArmor(in2);
                }


                cout << "Remaining balance: " << party1.getTreasure() << " coins" << endl;
                break;

            case 4: 
                cout << "A cauldron costs " << 20 *(1+ 0.25 * (room -1)) << " gold pieces. You can use a cauldron to stew and boil"   << endl;
                cout << "ingredients. It is made of thick sturdy metal, so it only has a 2% chance of" << endl;
                cout << "breaking each time you use it." << endl;
                cout << "A castiron pan costs " << 10 *(1+ 0.25 * (room -1)) << " gold pieces. You can use a frying pan to sizzle ingredients." << endl;
                cout << "It is not as sturdy as a cauldron, with a 10% chance of breaking each time you use it" << endl;
                cout << "A ceramic pot costs " << 5 *(1+ 0.25 * (room -1)) << " gold pieces. You can use a ceramic pot to stew and boil" << endl;
                cout << "ingredients. It is made from weaker material, so it has a 25% chance of breaking" << endl; 
                cout << "each time you use it." << endl;

                cout << "How many cauldrons do you want?" << endl;
                cin >> numCauldrons;
                canBuy = CanYouBuy(party1, numCauldrons *  (20 *(1+ 0.25 * (room -1))));
                if (canBuy == true && numCauldrons != 0)
                {
                    for (int p = 0; p <numCauldrons; p++)
                    {
                        party1.setCookware(possibleCookwares[0]);
                    }
                }

                cout << "How many cast iron pans do you want?" << endl;
                cin >> numCastIron;
                canBuy = CanYouBuy(party1, numCastIron *  (10 *(1+ 0.25 * (room -1))));
                if (canBuy == true && numCastIron != 0)
                {
                    for (int p = 0; p <numCastIron; p++)
                    {
                        party1.setCookware(possibleCookwares[1]);
                    }
                }
                cout << "How many ceramic pots do you want?" << endl;
                cin >> numCeramic;
                canBuy = CanYouBuy(party1, numCeramic *  (5 *(1+ 0.25 * (room -1))));
                if (canBuy == true && numCeramic != 0)
                {
                    for (int p = 0; p <numCeramic; p++)
                    {
                        party1.setCookware(possibleCookwares[2]);
                    }
                }
                cout << "Remaining balance: " << party1.getTreasure() << " coins" << endl;
                break;

            case 5:
                choice = 5;
                break;
            
            default:
                cout << "Hey you silly goose, enter a valid input. Try Again" << endl;
                break;
        }
    } while(choice != 5);
    int bootyChoice;
    int bootyPrice;
    if (party1.getBootySize() != 0)
    {
        do
        {
            cout << "You have booty to sell. Enter '1' to sell or '2' to leave the Market" << endl;
            cin >> bootyChoice;
            if (bootyChoice == 1)
            {
                cout << "You just sold your " << party1.getBootyNameAt(0) << " for " << party1.getBootyValAt(0) << "." <<
                " You now have " << party1.getTreasure() << " gold coins." <<  endl;
                bootyPrice = party1.getBootyValAt(0);
                party1.addPrice(bootyPrice);
                party1.popBootyBack();
            }
            else if (bootyChoice == 2)
            {
                cout << "You are now leaving the market." << endl;
            }
            else
            {
                cout << "DumbAss, Enter a value '1' or '2' please." << endl;
            }
        } while (bootyChoice != 2 && party1.getBootySize() != 0);
        // This do...while loop allows you to sell booty if you have it
        
    }
}
// This function adds treasure to your inventory if you've found some.
// Parameters: the current room, and an object of class party.
// Return: N/A
void BootyChest(Party &party1, int room)
{
    // This 2 dimensional array lists all non-gold-coin treasures that can be sold later on.
    Booty possibleBooties[5][2];
    possibleBooties[0][0] = Booty("Quartz",10);
    possibleBooties[0][1] = Booty("Embroidered Silk Handerchief",10);
    possibleBooties[1][0] = Booty("Pearl",20);
    possibleBooties[1][1] = Booty("Bronze Crown",20);
    possibleBooties[2][0] = Booty("Topaz",30);
    possibleBooties[2][1] = Booty("Golden Dragon Comb",30);
    possibleBooties[3][0] = Booty("Emerald",40);
    possibleBooties[3][1] = Booty("Old Masterpiece Painting",40);
    possibleBooties[4][0] = Booty("Diamond",50);
    possibleBooties[4][1] = Booty("Golden Sarcophagus",50);
    srand(time(NULL));
    int num1 = rand() % 3;
    srand(time(NULL));
    int num2 = rand() % 2;
    if (num1 == 1)
    {
        if (room == 1)
        {
            party1.addPrice(50);
        }
        else if (room == 2)
        {
            party1.addPrice(100);
        }
        else if (room == 3)
        {
            party1.addPrice(500);
        }
        else if (room == 4)
        {
            party1.addPrice(1000);
        }
        else if (room == 5)
        {
            party1.addPrice(2000);
        }
    }
    // The above if statement is for when the gold-coins are found
    else
    {
        cout << "You just found a " << possibleBooties[room][num2].getBootyName() << ". This is worth " <<
        possibleBooties[room][num2].getBootyVal() << " gold pieces." << endl;
        party1.addBooty(possibleBooties[room][num2]);
    }
    // The above else statement is for when a treasure is found.
}

// This function calls various puzzles 
// Parameters: N/A
// Return: true or false depending on whether puzzle was answered correctly or not.
bool Puzzles()
{
    bool Win;
    srand(time(NULL));
    int random = rand() % 4;
    int choice;
    // This switch statement determines which puzzle is to be solved.
    switch(random)
    {  
        case 0:
            cout << "What month of the year has 28 days?" << endl;
            cout << "1 : February" << endl;
            cout << "2 : March" << endl;
            cout << "3 : all of them" << endl;
            cin >> choice;
            if(choice == 3)
            {
                Win = true;
            }
            else
            {
                Win = false;
            }
            break;
        
        case 1:
            cout << "At what X value do these lines intersect:" << endl;
            cout << "y = 3x - 4" << endl;
            cout << "y = 2x" << endl;
            cin >> choice;
            if (choice == 4)
            {
                Win = true;
            }
            else
            {
                Win = false;
            }
            break;

        case 2:
            cout << "What is 129 / 3?" << endl;
            cin >> choice;
            if (choice == 43)
            {
                Win = true;
            }
            else
            {
                Win = false;
            }
            break;

        case 3:
            cout << "What is 234 - 56?" << endl;
            cin >> choice;
            if (choice == 178)
            {
                Win = true;
            }
            else
            {
                Win = false;
            }
            break;

        default:
            Win = true;
            break;



    }
    return Win;
}
// This function goes through a mock rock-paper-scissors game whenever one tries to open the door
// Parameters: an object of class party
// Return: true or false depending on who won the game of rock paper scissors
bool DoorPuzzle(Party &party1)
{
    bool DeathMarker = false;
    Character character;
    Weapon weapon;
    bool Win;
    int choice;
    string RPS1;
    string RPS2;
    srand(time(NULL));
    int random;
    random = (rand() % 3) +1;
    do{
        cout << "MUHAHAHA, I am the door, and the only way you get past me is if you beat" << endl;
        cout << "me in a grueling game of rock, paper, sissors." << endl;
        cout << "What is your pick???" << endl;
        cout << "1 : Rock (enter 1)" << endl;
        cout << "2 : Paper (enter 2)" << endl;
        cout << "3 : Sissors (enter 3)" << endl;
        cin >> choice;
        if(choice == 1)
        {
            RPS1 = "Rock";
        }
        else if(choice == 2)
        {
            RPS1 = "Paper";
        }
        else
        {
            RPS1 = "Sissors";
        }
        if(random == 1)
        {
            RPS2 = "Rock";
        }
        else if(random == 2)
        {
            RPS2 = "Paper";
        }
        else
        {
            RPS2 = "Sissors";
        }
        if(choice != 1 && choice != 2 && choice != 3)
        {
            cout << "COME ON... Enter a valid number." << endl;
        }
        else if (choice == random)
        {
            cout << "Oh no! It's a tie. We both picked " << RPS1 << endl;
        }
    }while ((choice != 1 && choice != 2 && choice != 3) || choice == random);

    if(RPS1 == "Rock" && RPS2 == "Paper")
    {
        cout << "I win... Paper beats rock" << endl;
        Win = false;
    }
    else if(RPS1 == "Paper" && RPS2 == "Sissors")
    {
        cout << "I win... Sissors beats Paper" << endl;
        Win = false;
    }
    else if(RPS1 == "Sissors" && RPS2 == "Rock")
    {
        cout << "I win... Rock beats Sissors" << endl;
        Win = false;
    }
    else if(RPS2 == "Rock" && RPS1 == "Paper")
    {
        cout << "You win... Paper beats rock" << endl;
        Win = true;
        
    }
    else if(RPS2 == "Paper" && RPS1 == "Sissors")
    {
        cout << "You win... Sissors beats Paper" << endl;
        Win = true;
        
    }
    else if(RPS2 == "Sissors" && RPS1 == "Rock")
    {
        cout << "You win... Rock beats Sissors" << endl;
        Win = true;
        
    }  

    if (!Win)
    {
        int i = 5;
        while (i > 0 && !DeathMarker)
        {
            character = party1.getCharacterAt(i-1);
            if(character.getName() != "")
            {
                cout << character.getName() << " has been slain." << endl;
                character.setName("");
                character.setArmor(0);
                weapon = character.getWeapon();
                weapon.setName("");
                weapon.setHP(0);
                character.setWeapon(weapon);
                party1.setCharactersAt(character, i - 1);
                DeathMarker = true;
            }
            i--;
        }
        Win = true;
    }
    return Win;
}

// This function speaks to an NPC and either allows you to purchase inventory, get a key, or fight a monster
// Parameters: the room you're currently in, an object of class party
// Return: True or false depending on whether or not a key was dropped.

bool speakToNPC(int room, Party &party1)
{
    bool key = false;
    srand(time(NULL));
    int random = rand() % 3;
    bool win = Puzzles();
    if(random == 0 && win)
    {
        cout << "The NPC was friendly" << endl;
        Merchant(room, party1);
    }
    else if (random == 0 && !win)
    {
        cout << "The NPC was friendly, but the Puzzle was answered incorrecly, so you get nothing" << endl;
    }
    else if (random == 1 && win)
    {
        cout << "The NPC was neutral, so you get nothing" << endl;
    }
    else if (random == 1 && !win)
    {
        cout << "The NPC was neutral, so you get nothing" << endl;
    }
    else if (random == 2)
    {
        cout << "The NPC was Evil, so you must fight a monster" << endl;
        key = Fight(room, party1);
    }
    return key;
}

// This function opens the door 
// Parameters: an object of class party, the room you're currently in, and a bool for whether or not the key was found
// Return: the room you'll be in when the function is through running.

int OpenDoor(Party &party1, int room, bool key)
{
    bool answer = false;
    if(!key)
    {
        while (!answer)
        {
            cout << "You have fallen into a trap because you do not have a key. Answer a riddle to get out" << endl;
            answer = Puzzles();
        }
        cout << "You are still in room " << room << endl;
    }
    else if(key)
    {
        room++;
        cout << "Congratualations you are moving on to room " << room << endl;
    }
    return room;
}
// This is the main function that puts it all together
int main()
{
    Character character = Character();
    Weapon weapon = Weapon();
    int room = 1;
    int anger = 0;
    bool key = false; // This boolean variable determines whether or not a key has been found for the next room.
    int numchars = 5;
    int numval;
    int num12;
    int numFight = 0;
    cout << "Welcome to Dungeon Escape: The Game" << endl;
    string dummyName[5];
    cout << "Enter a name: This is the name of your team leader" << endl;
    getline(cin,dummyName[0]);
    cout << "You will now enter in the names of the rest of your party" << endl;
    for (int i = 1; i < 5; i++)
    {
        cout << "Enter in player " << i + 1 << "." << endl;
        getline(cin,dummyName[i]);
    }
    // Below is the beginning of the necessary sorting algorithm
    cout << "Here is list of all names sorted by length." << endl;
    string temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < (4-i); j++)
        {
            if (dummyName[j].length() > dummyName[j+1].length())
            {
                temp = dummyName[j];
                dummyName[j] = dummyName[j+1];
                dummyName[j+1] = temp;
            }
        }
    }
    cout << dummyName[0] << ", " << dummyName[1] << ", " << dummyName[2] << ", " <<
    dummyName[3] << ", " << dummyName[4] << "." << endl;
    // This ends the sorting algorithm
    Party gameplayParty = Party();
    for (int i = 0; i < 5; i++)
    {
        gameplayParty.setCharactersAt(Character(Weapon(),dummyName[i],0,10),i);
    }
    gameplayParty.setTreasure(100.00);
    cout << "Below you can make your initial purchases: You are beginning with 100 peices of gold." << endl;
    Merchant(room,gameplayParty);
    int choice7;
    do
    {
        cout << "You are currently in room: " << room << endl;
        cout << "Select what you would like to do from the list below." << endl;
        cout << "1. Fight A Monster!" << endl;
        cout << "2. Talk to a Non-Player Character!" << endl;
        cout << "3. Cook and Eat!" << endl;
        cout << "4. Explore the Room!" << endl;
        cout << "5. Open the Door!" << endl;
        cout << "6. Quit the Game!" << endl;
        cin >> choice7;
        // This switch statement picks which action is taken
        switch (choice7)
        {
            case 1:
                if(numFight < 5)
                {
                    if(key)
                    {
                        Fight(room, gameplayParty);
                        numFight++;
                    }
                    else
                    {
                        key = Fight(room, gameplayParty);
                        numFight++;
                    }
                }
                else
                {
                    cout << endl;
                    cout << "You can only fight a max of 4 times per level" << endl;
                    cout << "Fight limit exceeded" << endl;
                    cout << endl;
                }
                choice7 = 1;
                break;
            case 2:
                if(key)
                {
                    speakToNPC(room, gameplayParty);
                }
                else
                {
                    key = speakToNPC(room, gameplayParty);
                }
                break;
            case 3:
                cookAndEat(gameplayParty);
                break;
            case 4:
                srand(time(NULL));
                num12 = rand() % 5;
                if (num12 == 1)
                {
                    cout << "Congratulations! You found a key!" << endl;
                    key = true;
                    choice7 = 4;
                }
                else if (num12 == 2)
                {
                    cout << "EGAD! Looks like you uncovered a monster" << endl;
                    if(key)
                    {
                        Fight(room, gameplayParty);
                    }
                    else
                    {
                        key = Fight(room, gameplayParty);
                    }
                    choice7 = 4;
                }
                else if (num12 == 3)
                {
                    BootyChest(gameplayParty, room);
                    choice7 = 4;
                }
                else
                {
                    cout << "Looks like nothing happened, dumb move tbh!" << endl;
                    choice7 = 4;
                }
                break;
            case 5:
                DoorPuzzle(gameplayParty);
                room = OpenDoor(gameplayParty, room, key);
                key = false;
                choice7 = 5;
                break;
            case 6:
                break;
            default:
                cout << "Dang, that's a wrong entry, pick an integer 1-6!" << endl;
                break;
        }
        Misfortunes(gameplayParty);
        anger += 2;
        numchars = statusUpdate(gameplayParty, anger, room);
    }while (choice7 != 6 && numchars > 0 && anger < 100 && room < 6);
    // This do...while loop keeps running until the game is over
    EndGameMenu(choice7, anger, numchars, room);

    return 0;
}