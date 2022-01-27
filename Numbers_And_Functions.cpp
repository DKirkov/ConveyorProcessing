/**
*
* Solution to course project # 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Dimitar Kirkov
* @idnumber 4MI0600002
* @compiler VC
*
* <file with functions to get the numbers and functions from the files>
*
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getNumberOfNumbers()
{
    int i = 0, j;
    ifstream file;
    file.open("numbers.txt");
    if (!file) cout << "Cannot open file" << endl;
    else
    {
        while (!file.eof())
        {
            file >> j;
            i++;
        }
    }
    file.close();
    return i;
}

int getNumberOfFunctions()
{
    int i = 0;
    string j;
    ifstream file;
    file.open("functions.txt");
    if (!file) cout << "Cannot open file" << endl;
    else
    {
        while (!file.eof())
        {
            file >> j;
            i++;
        }
    }
    file.close();
    return i;
}

void getNumbers(double*& numbers)
{
    int i = 0;
    ifstream file;
    file.open("numbers.txt");
    if (!file) cout << "Cannot open file" << endl;
    else
    {
        while (!file.eof())
        {
            file >> numbers[i];
            i++;
        }
    }
    file.close();
}

void getFunctions(string*& functions)
{
    int i = 0;
    ifstream file;
    file.open("functions.txt");
    if (!file) cout << "Cannot open file" << endl;
    else
    {
        while (!file.eof())
        {
            file >> functions[i];
            i++;
        }
    }
    file.close();
}