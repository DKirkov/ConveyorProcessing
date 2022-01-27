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
* <main program>
*
*/

#include <iostream>
#include <string>
#include "Menu.h"
#include "Main.h"
using namespace std;
const string options[] =
{

    "1. View the input numbers." , "2. Change one input number (in row)." , "3. View the input functions." ,
    "4. Change one input function (in row)." , "5. Performing a matrix calculation (without carry mode, plain text)." ,
    "6. Performing a matrix calculation (without carry mode, JSON format)." ,
    "7. Performing a matrix calculation (with carry mode, plain text)." ,
    "8. Performing a matrix calculation (with carry mode, JSON format)."

};

int main()
{
    Menu();
    int option;
    cout << "Choose an option (1 to 8): ";
    cin >> option;
    while (option < 1 || option > 8)
    {
        cout << "Invalid option. Choose an option again (1 to 8): ";
        cin >> option;
    }
    system("CLS");
    cout << "You choose the option" << ": " << options[option - 1] << endl << endl;
    Main(option);
    return 0;
}