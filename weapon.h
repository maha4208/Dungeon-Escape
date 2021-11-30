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

using namespace std;

// .h file for class weapon
// private members name and hp
#ifndef WEAPON_H
#define WEAPON_H
class Weapon
{
    public:
    Weapon();
    Weapon(string n1, int h1);
    void setName(string s1);
    void setHP(int h1);
    string getName();
    int getHP();
    private:
    string name;
    int hp;
};

#endif