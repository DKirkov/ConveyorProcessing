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
* <file with the start menu>
*
*/

#include <iostream>
#include <iomanip>
using namespace std;

const string options[] =
{
    "1. View the input numbers." , "2. Change one input number (in row)." , "3. View the input functions." ,
    "4. Change one input function (in row)." , "5. Performing a matrix calculation (without carry mode, plain text)." ,
    "6. Performing a matrix calculation (without carry mode, JSON format)." ,
    "7. Performing a matrix calculation (with carry mode, plain text)." ,
    "8. Performing a matrix calculation (with carry mode, JSON format)."
};

void Menuformatting()
{
    for (int i = 0; i < 73; i++)
    {
        cout << "=";
    }
    cout << endl;
}

void Optionsformatting()
{
    for (int i = 0; i < 73; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void Menu()
{
    Menuformatting();
    cout << "|" << setw(38) << "MENU" << setw(34) << "|" << endl;
    Menuformatting();
    cout << "|" << options[0] << setw(46) << "|" << endl;
    Optionsformatting();
    cout << "|" << options[1] << setw(36) << "|" << endl;
    Optionsformatting();
    cout << "|" << options[2] << setw(44) << "|" << endl;
    Optionsformatting();
    cout << "|" << options[3] << setw(34) << "|" << endl;
    Optionsformatting();
    cout << "|" << options[4] << setw(4) << "|" << endl;
    Optionsformatting();
    cout << "|" << options[5] << setw(3) << "|" << endl;
    Optionsformatting();
    cout << "|" << options[6] << setw(7) << "|" << endl;
    Optionsformatting();
    cout << "|" << options[7] << setw(6) << "|" << endl;
    Menuformatting();
}