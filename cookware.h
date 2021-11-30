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

#ifndef COOKWARE_H
#define COOKWARE_H
// .h file for class cookware
// private elements breakability and name
class Cookware
{
    public:
    Cookware();
    Cookware(int b1, string n1);
    void setBreakability(int b1);
    void setName(string s1);
    int getBreakability();
    string getName();
    private:
    int breakability;
    string name;
};
#endif