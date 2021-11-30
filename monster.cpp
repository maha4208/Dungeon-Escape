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
#include <stdio.h>     
#include <cstdlib>    
#include <ctime> 
#include "monster.h"

using namespace std;

// calls split function
// parmeters: string, char, string array, and int
// return num values stored
int split(string str, char separator, string array[], int sizeArray)
{
    int strLength = str.length();
    string newStr = "";
    int index = 0;
    int totalStrings;
    // checks if the string is empty, returns 0
    if (strLength == 0)
    {
        return 0;
    }
    // loops through entire string and checks if each character is the separator
    // if it is the separator, then it adds the new string to an index of an array
    for(int i = 0; i < strLength; i++)
    {
        if (str[i] == separator)
        {   
            array[index] = newStr;
            index++;
            newStr = "";
        }
        else
        {
            newStr += str[i];
        }
    }
    // returns -1 if the total strings is greater than size of array because that is an error
    array[index] = newStr;
    totalStrings = index + 1;
    if (totalStrings > sizeArray)
    {
        return -1;
    }

    return totalStrings;
}

// default constructor for monster sets monsters name to ""
Monster::Monster()
{
    monsterName = "";
}

// parameterized constructor which reads in a file and outputs a monster based on difficulty
Monster::Monster(int difficulty)
{
    // read file in 

    ifstream in_file;
    string line;
    in_file.open("monsters.txt");
    string arr[2];
    string arrayMonsters[4];
    int i = 0;
    int random;
    split(line, ',', arr, 2);
    // go through each line in the file and split it using split function
    // send it to an array 
    // set monster based on the difficulty which is labeled on index 2 of the array
    while(getline(in_file, line))
        {
            if (difficulty == 1)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 1)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 2)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 2)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 3)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 3)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 4)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 4)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 5)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 5)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else
            {
                cout << "invalid input" << endl;
            }   
        }
    srand(time(NULL));
    random = rand() % 4;
    monsterName = arrayMonsters[random];
    in_file.close();
}

// sets monster which reads in a file and outputs a monster based on difficulty
void Monster::setMonster(int difficulty)
{
    //read in file
    ifstream in_file;
    string line;
    in_file.open("monsters.txt");
    string arr[2];
    string arrayMonsters[4];
    int i = 0;
    int random;
    split(line, ',', arr, 2);
    // go through each line in the file and split it using split function
    // send it to an array 
    // set monster based on the difficulty which is labeled on index 2 of the array
    while(getline(in_file, line))
        {
            if (difficulty == 1)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 1)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 2)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 2)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 3)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 3)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 4)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 4)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else if(difficulty == 5)
            {
                split(line, ',', arr, 2);
                if (stoi(arr[1]) == 5)
                {
                    arrayMonsters[i] = arr[0];
                    i++;
                }
            }

            else
            {
                cout << "invalid input" << endl;
            }   
        }
    srand(time(NULL));
    random = rand() % 4;
    monsterName = arrayMonsters[random];
    in_file.close();
}

// get monster returning name
string Monster::getMonster()
{
    return monsterName;
}