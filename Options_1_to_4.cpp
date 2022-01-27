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
* <file with functions for options from 1 to 4>
*
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Menu.h"
using namespace std;

void viewInputNumbers(double* numbers, int NumberOfNumbers)
{
    cout << "The input numbers are: " << endl;
    for (int i = 0; i < NumberOfNumbers; i++)
    {
        cout << numbers[i] << endl;
    }
}

void saveNewNumbersToTheFile(double* numbers, int numberOfNumbers)
{
    ofstream file;
    file.open("numbers.txt");
    for (int i = 0; i < numberOfNumbers - 1; i++)
    {
        file << numbers[i] << endl;
    }
    file << numbers[numberOfNumbers - 1];
    file.close();
}

void changeOneNumber(double* numbers, int numberOfNumbers)
{

    int row, newNumber, option;
    cout << "Choose in which row to change the number (1 to " << numberOfNumbers << "): ";
    cin >> row;
    cout << "Enter the new number: ";
    cin >> newNumber;
    numbers[row - 1] = newNumber;
    system("CLS");
    cout << "You have changes the number!" << endl << endl;
    Menuformatting();
    cout << "|1. View the new input numbers" << setw(43) << "|" << endl;
    Optionsformatting();
    cout << "|2. Save the new numbers to the text file." << setw(31) << "|" << endl;
    Optionsformatting();
    cout << "|3. View the new input numbers and save them to the text file." << setw(11) << "|" << endl;
    Menuformatting();
    cout << "Chose an option: ";
    cin >> option;
    while (option < 1 || option > 3)
    {
        cout << "Invalid option. Choose an option again (1 to 3): ";
        cin >> option;
    }
    cout << endl;
    switch (option)
    {
        case 1:
        {
            viewInputNumbers(numbers, numberOfNumbers);
            break;
        }
        case 2:
        {
            saveNewNumbersToTheFile(numbers, numberOfNumbers);
            break;
        }
        case 3:
        {
            viewInputNumbers(numbers, numberOfNumbers);
            saveNewNumbersToTheFile(numbers, numberOfNumbers);
            break;
        }
    }
}

void viewInputFunctions(string* functions, int numberOfFunctions)
{
    cout << "The input functions are: " << endl;
    for (int i = 0; i < numberOfFunctions; i++)
    {
        cout << functions[i] << endl;
    }
}

void saveNewFunctionsToTheFile(string* functions, int numberOfFunctions)
{
    ofstream file;
    file.open("functions.txt");
    for (int i = 0; i < numberOfFunctions - 1; i++)
    {
        file << functions[i] << endl;
    }
    file << functions[numberOfFunctions - 1];
    file.close();
}

void changeOneFunction(string* functions, int numberOfFunctions)
{
    int row, option;
    string newFunction;
    cout << "Choose in which row to change the function (1 to " << numberOfFunctions << "): ";
    cin >> row;
    cout << "Enter the new function: ";
    cin >> newFunction;
    cout << endl;
    functions[row - 1] = newFunction;
    system("CLS");
    cout << "You have changes the function!" << endl << endl;
    Menuformatting();
    cout << "|1. View the new input functions" << setw(43) << "|" << endl;
    Optionsformatting();
    cout << "|2. Save the new functions to the text file." << setw(31) << "|" << endl;
    Optionsformatting();
    cout << "|3. View the new input functions and save them to the text file." << setw(11) << "|" << endl;
    Menuformatting();
    cout << "Chose an option: ";
    cin >> option;
    while (option < 1 || option > 3)
    {
        cout << "Invalid option. Choose an option again (1 to 3): ";
        cin >> option;
    }
    cout << endl;
    switch (option)
    {
        case 1:
        {
            viewInputFunctions(functions, numberOfFunctions);
            break;
        }
        case 2:
        {
            saveNewFunctionsToTheFile(functions, numberOfFunctions);
            break;
        }
        case 3:
        {
            viewInputFunctions(functions, numberOfFunctions);
            saveNewFunctionsToTheFile(functions, numberOfFunctions);
            break;
        }
    }
}