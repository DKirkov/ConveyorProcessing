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
* <file with functions for options from 5 to 8>
*
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Menu.h"
using namespace std;

void getNumbersFromFunctions(string* functions, double*& functionNumbers, int numberOfFunctions)
{
    for (int i = 0; i < numberOfFunctions; i++)
    {
        string currentFunction = functions[i];
        if (functions[i][1] == '<' || functions[i][1] == '>') currentFunction.erase(0, 2);
        else currentFunction.erase(0, 1);
        functionNumbers[i] = stod(currentFunction);
    }
}

void matrixCalculationWithoutCarryMode(double* numbers, string* functions, double* functionNumbers, double**& matrix, int numberOfNumbers, int numberOFunctions)
{
    for (int i = 0; i < numberOfNumbers; i++)
    {
        if (functions[i][0] == '+')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                matrix[j][i] = numbers[j] + functionNumbers[i];
            }
        }
        else if (functions[i][0] == '*')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                matrix[j][i] = numbers[j] * functionNumbers[i];
            }
        }
        else if (functions[i][0] == '-')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                matrix[j][i] = numbers[j] - functionNumbers[i];
            }
        }
        else if (functions[i][0] == '%')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                int a = functionNumbers[i];
                int b = numbers[j];
                if (a != functionNumbers[i] || b != numbers[j]) matrix[j][i] = 0;
                else if (numbers[j] < 0 || functionNumbers[i] <= 0) matrix[j][i] = 0;
                else matrix[j][i] = b % a;
            }
        }
        else if (functions[i][0] == '/')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                if (functionNumbers[i] == 0) matrix[j][i] = 0;
                else matrix[j][i] = numbers[j] / functionNumbers[i];
            }
        }
        else if (functions[i][0] == '<')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                int a = functionNumbers[i];
                int b = numbers[j];
                if (a != functionNumbers[i] || b != numbers[j]) matrix[j][i] = 0;
                else if (functionNumbers[i] < 0) matrix[j][i] = 0;
                else matrix[j][i] = b * pow(2, a);
            }
        }
        else if (functions[i][0] == '>')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                int a = functionNumbers[i];
                int b = numbers[j];
                if (a != functionNumbers[i] || b != numbers[j]) matrix[j][i] = 0;
                else if (functionNumbers[i] < 0) matrix[j][i] = 0;
                else matrix[j][i] = b / pow(2, a);
            }
        }
    }
}

void matrixCalculationWithCarryMode(double* numbers, string* functions, double* functionNumbers, double**& matrix, int numberOfNumbers, int numberOFunctions)
{
    for (int i = 0; i < numberOfNumbers; i++)
    {
        if (functions[i][0] == '+')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                if (i == 0) matrix[j][i] = numbers[j] + functionNumbers[i];
                else matrix[j][i] = (numbers[j] + matrix[j][i - 1]) + functionNumbers[i];
            }
        }
        else if (functions[i][0] == '*')
        {
            for (int j = 0; j < 5; j++)
            {
                if (i == 0) matrix[j][i] = numbers[j] * functionNumbers[i];
                else matrix[j][i] = (numbers[j] + matrix[j][i - 1]) * functionNumbers[i];
            }
        }
        else if (functions[i][0] == '-')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                if (i == 0) matrix[j][i] = numbers[j] - functionNumbers[i];
                else matrix[j][i] = (numbers[j] + matrix[j][i - 1]) - functionNumbers[i];
            }
        }
        else if (functions[i][0] == '%')
        {
            int a, b;
            double c;
            for (int j = 0; j < numberOFunctions; j++)
            {
                if (i == 0)
                {
                    a = numbers[j];
                    c = numbers[j];
                }
                else
                {
                    a = numbers[j] + matrix[j][i - 1];
                    c = numbers[j] + matrix[j][i - 1];
                }
                b = functionNumbers[i];
                if (a != c || b != functionNumbers[i]) matrix[j][i] = 0;
                else if (a < 0 || functionNumbers[i] <= 0) matrix[j][i] = 0;
                else matrix[j][i] = a % b;
            }
        }
        else if (functions[i][0] == '/')
        {
            for (int j = 0; j < numberOFunctions; j++)
            {
                if (functionNumbers[i] == 0) matrix[j][i] = 0;
                else
                {
                    if (i == 0) matrix[j][i] = numbers[j] / functionNumbers[i];
                    else matrix[j][i] = (numbers[j] + matrix[j][i - 1]) / functionNumbers[i];
                }
            }
        }
        else if (functions[i][0] == '<')
        {
            int a, b;
            for (int j = 0; j < numberOFunctions; j++)
            {
                if (i == 0) a = numbers[j];
                else a = numbers[j] + matrix[j][i - 1];
                b = functionNumbers[i];
                if (a != numbers[j] + matrix[j][i - 1] || b != functionNumbers[i]) matrix[j][i] = 0;
                else if (a < 0) matrix[j][i] = 0;
                else matrix[j][i] = a * pow(2, b);
            }
        }
        else if (functions[i][0] == '>')
        {
            int a, b;
            for (int j = 0; j < numberOFunctions; j++)
            {
                if (i == 0) a = numbers[j];
                else a = numbers[j] + matrix[j][i - 1];
                b = functionNumbers[i];
                if (a != numbers[j] + matrix[j][i - 1] || b != functionNumbers[i]) matrix[j][i] = 0;
                else if (a < 0) matrix[j][i] = 0;
                else matrix[j][i] = a / pow(2, b);
            }
        }
    }
}

void outputMatrixInPlainText(double** matrix, int numberOfNumbers, int numberOfFunctions)
{
    for (int i = 0; i < numberOfNumbers; i++)
    {
        for (int j = 0; j < numberOfFunctions - 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << matrix[i][numberOfFunctions - 1] << endl;
    }
}

void outputMatrixInJSONFormat(double** matrix, int numberOfNumbers, int numberOfFunctions)
{
    cout << "{" << endl;
    cout << "    ";
    cout << "byRows: [" << endl;
    for (int i = 0; i < numberOfNumbers; i++)
    {
        cout << "        ";
        cout << "[";
        for (int j = 0; j < numberOfFunctions - 1; j++)
        {
            cout << matrix[i][j] << ", ";
        }
        cout << matrix[i][numberOfFunctions - 1] << "]";
        if (i != numberOfNumbers - 1) cout << ",";
        cout << endl;
    }
    cout << endl;
    cout << "    ";
    cout << "]," << endl;
    cout << "    ";
    cout << "byCols: [" << endl;
    for (int i = 0; i < numberOfFunctions; i++)
    {
        cout << "        ";
        cout << "[";
        for (int j = 0; j < numberOfNumbers - 1; j++)
        {
            cout << matrix[j][i] << ", ";
        }
        cout << matrix[numberOfNumbers - 1][i] << "]";
        if (i != numberOfFunctions - 1) cout << ",";
        cout << endl;
    }
    cout << endl;
    cout << "    ";
    cout << "]," << endl;
    cout << "}";
}

void saveMatrixInFileInPlainText(double** matrix, int numberOfNumbers, int numberOfFunctions)
{
    ofstream file;
    file.open("matrix.txt");
    for (int i = 0; i < numberOfNumbers; i++)
    {
        for (int j = 0; j < numberOfFunctions - 1; j++)
        {
            file << matrix[i][j] << " ";
        }
        file << matrix[i][numberOfFunctions - 1] << endl;
    }
    file.close();
}

void saveMatrixInFileInJSONFormat(double** matrix, int numberOfNumbers, int numberOfFunctions)
{
    ofstream file;
    file.open("matrix.txt");
    file << "{" << endl;
    file << "    ";
    file << "byRows: [" << endl;
    for (int i = 0; i < numberOfNumbers; i++)
    {
        file << "        ";
        file << "[";
        for (int j = 0; j < numberOfFunctions - 1; j++)
        {
            file << matrix[i][j] << ", ";
        }
        file << matrix[i][numberOfFunctions - 1] << "]";
        if (i != numberOfNumbers - 1) file << ",";
        file << endl;
    }
    file << endl;
    file << "    ";
    file << "]," << endl;
    file << "    ";
    file << "byCols: [" << endl;
    for (int i = 0; i < numberOfFunctions; i++)
    {
        file << "        ";
        file << "[";
        for (int j = 0; j < numberOfNumbers - 1; j++)
        {
            file << matrix[j][i] << ", ";
        }
        file << matrix[numberOfNumbers - 1][i] << "]";
        if (i != numberOfFunctions - 1) file << ",";
        file << endl;
    }
    file << endl;
    file << "    ";
    file << "]," << endl;
    file << "}";
    file.close();
}

int MenuMatrix()
{
    int option;
    Menuformatting();
    cout << "|" << setw(38) << "MENU" << setw(34) << "|" << endl;
    Menuformatting();
    cout << "|1. Output the matrix." << setw(51) << "|" << endl;
    Optionsformatting();
    cout << "|2. Save the matrix to the file." << setw(41) << "|" << endl;
    Optionsformatting();
    cout << "|3. Output the matrix and save it to the file." << setw(27) << "|" << endl;
    Menuformatting();
    cout << "Choose an option (1 to 3): ";
    cin >> option;
    return option;
}