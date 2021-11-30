// CSCI1300 Spring 2021
// Author: Greyson Dudley
// Recitation: 123 – Siddartha Shankar
// Project 3
// Partner - Mark Haley && Greyson Dudley

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

using namespace std;

// default constructor which sets each value in the characters array to the default 
// character constructor
// sets ingredients and treasure to 0 too
Party::Party()
{
    for (int i = 0; i < 5; i++)
    {
        characters[i] = Character();
    }
    ingredients = 0;
    treasure = 0;
}
// parameterized constructor which sets each value in the characters array to the 
// the character array parameter
// sets ingredients and treasure to the parameter too
Party::Party(Character ch1[], vector<Cookware> c1, int in1, double t1, vector<Booty> b1)
{
    for (int i = 0; i < 5; i++)
    {
        characters[i] = ch1[i];
    }
    for (int i = 0; i < c1.size(); i++)
    {
        cookware[i] = c1[i];
    }
    ingredients = in1;
    treasure = t1;
}

// sets character at a specific index
void Party::setCharactersAt(Character c1, int i1)
{
    characters[i1] = c1;
}

// sets cookware
void Party::setCookware(Cookware c1)
{
    cookware.push_back(c1);
}

// sets ingredients
void Party::setIngredients(int i1)
{
    ingredients = i1;
}

// sets treasure
void Party::setTreasure(double i1)
{
    treasure = i1;
}

// returns character class at a certain index
Character Party::getCharacterAt(int i1)
{
    return characters[i1];
}

// gets cookware name  by calling cookware class function get name and returns it
string Party::getCookwareNameAt(int i1)
{
    return cookware[i1].getName();
}

// gets cookware breakability by calling cookware class function get breakability and returns it
int Party::getCookwareBreakabilityAt(int i1)
{
    return cookware[i1].getBreakability();
}

// returns ingredients
int Party::getIngredients()
{
    return ingredients;
}

// returns treasure
int Party::getTreasure()
{
    return treasure;
}

// removes price from treasure
void Party::removePrice(double price)
{
    treasure = treasure - price;
}

// adds price to treasure
void Party::addPrice(double price)
{
    treasure += price;
}

// erases a member of cookware vector
void Party::breakCookwareAt(int i1)
{
    cookware.erase(cookware.begin() + i1);
}

// adds a weapon by calling character function set weapon
void Party::addCharacterWeapon(Weapon w1, int CharI)
{
    characters[CharI].setWeapon(w1);
}

// adds armor by calling character class function set armor
void Party::addCharacterArmor(int CharI)
{
    characters[CharI].setArmor(1);
}

// returns size of cookware vector
int Party::getCookwareSize()
{
    return cookware.size();
}

// adds hunget for a given character
void Party::incrementCharacterHungerAt(int i1)
{
    characters[i1].incrementHunger();
}

// removes hunger for a given character
void Party::decrementCharacterHungerAt(int i1)
{
    characters[i1].decrementHunger();
}

// returns a characters name at a given index
string Party::getCharacterNameAt(int i1)
{
    return characters[i1].getName();
}

// add treasure
void Party::addBooty(Booty b1)
{
    booty.push_back(b1);
}

// removes booty from vector 
void Party::popBootyBack()
{
    booty.pop_back();
}

// returns size of booty vector
int Party::getBootySize()
{
    return booty.size();
}

// gets bootys name at a given index
string Party::getBootyNameAt(int i1)
{
    return booty[i1].getBootyName();
}

// gets bootys value at a given index
double Party::getBootyValAt(int i1)
{
    return booty[i1].getBootyVal();
}