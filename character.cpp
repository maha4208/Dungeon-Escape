// CSCI1300 Spring 2021
// Author: Greyson Dudley
// Recitation: 123 – Siddartha Shankar
// Project 3
// Partner - Mark Haley && Greyson Dudley
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
# include "character.h"
# include "weapon.h"
# include "cookware.h"

using namespace std;

// defualt constructor sets name hunger armor to null values
// and calls weapon class to set name and hp to null values
Character::Character()
{
    name = "";
    hunger = 0;
    armor = 0;
    weapon.setName("");
    weapon.setHP(0);
}

// parameterized constructor sets name hunger armor to input values
// and calls weapon class to set name and hp to input values
Character::Character(Weapon w1, string n1, int a1, int h1)
{
    name = n1;
    armor = a1;
    hunger = h1;
    weapon = w1;
}

// sets characters name to a string
void Character::setName(string n1)
{
    name = n1;
}

// sets characters armor
void Character::setArmor(int a1)
{
    armor = a1;
}

// sets characters hunger
void Character::setHunger(int h1)
{
    hunger = h1;
}

// sets characters weapon by calling weapon class function, setting name and hp
void Character::setWeapon(Weapon w1)
{
    weapon.setName(w1.getName());
    weapon.setHP(w1.getHP());
}

// gets characters name
string Character::getName()
{
    return name;
}

// gets characters armor value
int Character::getArmor()
{
    return armor;
}

// gets characters hunger value
int Character::getHunger()
{
    return hunger;
}

// gets characters weapon class
Weapon Character::getWeapon()
{
    return weapon;
}

// breaks characters weapon
void Character::breakWeapon()
{
    weapon.setName("");
    weapon.setHP(0);
}

// adds one to characters hunger
void Character::incrementHunger()
{
    hunger++;
}

// subtracts one from characters hunger
void Character::decrementHunger()
{
    hunger--;
}