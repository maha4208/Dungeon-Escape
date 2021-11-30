// CSCI1300 Spring 2021
// Author: Greyson Dudley
// Recitation: 123 – Siddartha Shankar
// Project 3
// Partner - Mark Haley

#include <string>
using namespace std;


#ifndef MONSTER_H
#define MONSTER_H
// .h file for monster
// private members name and difficulty
class Monster
{
    private:
        string monsterName;
        int difficulty;
    public:
        Monster();
        Monster(int difficulty);
        string getMonster();
        void setMonster(int difficulty);
};
#endif