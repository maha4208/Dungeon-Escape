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
#include "cookware.h"

using namespace std;

// default constructor which sets name and breakability to null values
Cookware::Cookware()
{
    name = "";
    breakability = 0;
}

// parameterized constructor that sets name and breakabiltity to input values
Cookware::Cookware(int b1, string n1)
{
    name = b1;
    breakability = b1;
}

// sets breakability to the parameter
void Cookware::setBreakability(int b1)
{
    breakability = b1;
}

// sets name to the parameter
void Cookware::setName(string n1)
{
    name = n1;
}

// returns breakability
int Cookware::getBreakability()
{
    return breakability;
}

// returns name
string Cookware::getName()
{
    return name;
}