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
# include "weapon.h"
# include "cookware.h"

using namespace std;
#ifndef CHARACTER_H
#define CHARACTER_H

// .h file for class booty
// private elements weapon of class Weapon, name , armor, and hunger
class Character
{
    private:
    Weapon weapon;
    string name;
    int armor;
    int hunger;
    public:
    Character();
    Character(Weapon w1, string n1, int a1, int h1);
    void setArmor(int a1);
    void setName(string n1);
    void setHunger(int h1);
    void setWeapon(Weapon w1);
    Weapon getWeaponAt(int i1);
    string getName();
    int getArmor();
    int getHunger();
    void breakWeapon();
    void decrementHunger();
    void incrementHunger(); 
    Weapon getWeapon();
};
#endif