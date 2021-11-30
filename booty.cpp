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
# include "booty.h"

using namespace std;

// default constructer with no parameters.. sets name to empty string and value to 0
Booty::Booty()
{
    name = "";
    value = 0;
}
// paramaterized constructer that sets name and value to inputs
Booty::Booty(string n1, int v1)
{
    name = n1;
    value = v1;
}
//sets treasure name to an input
void Booty::setBootyName(string n1)
{
    name = n1;
}
// sets treasures value to an input
void Booty::setBootyVal(int v1)
{
    value = v1;
}
// gets booty's name and returns the name
string Booty::getBootyName()
{
    return name;
}
// gets treasure's value and returns it
double Booty::getBootyVal()
{
    return value;
}