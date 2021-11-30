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
#include "weapon.h"

using namespace std;
// default constructor which sets name and hp to null values
Weapon::Weapon()
{
    name = "";
    hp = 0;
}

// parameterized constructor which sets name and hp to parameter values
Weapon::Weapon(string n1, int h1)
{
    name = n1;
    hp = h1;
}

// sets hp for a weapon
void Weapon::setHP(int h1)
{
    hp =h1;
}

// sets name for a weapon
void Weapon::setName(string n1)
{
    name = n1;
}

// gets name of weapon
string Weapon::getName()
{
    return name;
}

// gets hp of a weapon
int Weapon::getHP()
{
    return hp;
}