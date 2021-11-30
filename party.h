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
# include "booty.h"

using namespace std;

// .h file for class party
// private members array characters, vector cookware, ingredients, treasure, and vector booty
#ifndef PARTY_H
#define PARTY_H
class Party
{
    private:
        Character characters[5];
        vector<Cookware> cookware;
        int ingredients;
        int treasure;
        vector<Booty> booty;
    public:
        Party();
        Party(Character ch1[], vector<Cookware> c1, int in1, double t1, vector<Booty> b1);
        void setCharactersAt(Character c1, int i1);
        void setCookware(Cookware c1);
        void setIngredients(int i1);
        void setTreasure(double i1);
        Character getCharacterAt(int i1);
        string getCookwareNameAt(int i1);
        string getCharacterNameAt(int i1);
        int getCookwareBreakabilityAt(int i1);
        int getIngredients();
        int getTreasure();
        void removePrice(double price);
        void addPrice(double price);
        void breakCookwareAt(int i1);
        void addCharacterWeapon(Weapon w1, int CharI);
        void addCharacterArmor(int CharI);
        int getCookwareSize();
        void incrementCharacterHungerAt(int i1);
        void decrementCharacterHungerAt(int i1);
        void addBooty(Booty b1);
        void popBootyBack();
        int getBootySize();
        string getBootyNameAt(int i1);
        double getBootyValAt(int i1);
};

#endif