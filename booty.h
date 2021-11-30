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



#ifndef BOOTY_H
#define BOOTY_H

// .h file for class booty
// private elements name and value
class Booty
{
    private:
        string name;
        double value;
    public:
        Booty();
        Booty(string n1, int v1);
        void setBootyName(string n1);
        void setBootyVal(int v1);
        string getBootyName();
        double getBootyVal();
};
#endif