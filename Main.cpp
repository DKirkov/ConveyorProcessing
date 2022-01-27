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
* <file with function for choosing an option from 1 to 8>
*
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include "Menu.h"
#include "Numbers_And_Functions.h"
#include "Options_1_to_4.h"
#include "Options_5_to_8.h"
using namespace std;

void Main(int option)
{
    switch (option)
    {
        case 1:
        {
            int numberOfNumbers = getNumberOfNumbers();
            double* numbers = new double[numberOfNumbers];
            getNumbers(numbers);
            viewInputNumbers(numbers, numberOfNumbers);
            delete[] numbers;
            break;
        }
        case 2:
        {
            int numberOfNumbers = getNumberOfNumbers();
            double* numbers = new double[numberOfNumbers];
            getNumbers(numbers);
            changeOneNumber(numbers, numberOfNumbers);
            delete[] numbers;
            break;
        }
        case 3:
        {
            int numberOfFunctions = getNumberOfFunctions();
            string* functions = new string[numberOfFunctions];
            getFunctions(functions);
            viewInputFunctions(functions, numberOfFunctions);
            delete[] functions;
            break;
        }
        case 4:
        {
            int numberOfFunctions = getNumberOfFunctions();
            string* functions = new string[numberOfFunctions];
            getFunctions(functions);
            changeOneFunction(functions, numberOfFunctions);
            delete[] functions;
            break;
        }
        case 5:
        {
            int numberOfNumbers = getNumberOfNumbers();
            double* numbers = new double[numberOfNumbers];
            getNumbers(numbers);
            int numberOfFunctions = getNumberOfFunctions();
            string* functions = new string[numberOfFunctions];
            getFunctions(functions);
            double* functionNumbers = new double[numberOfFunctions];
            double** matrix = new double* [numberOfNumbers];
            for (int i = 0; i < numberOfFunctions; i++)
            {
                matrix[i] = new double[numberOfFunctions];
            }
            getNumbersFromFunctions(functions, functionNumbers, numberOfFunctions);
            matrixCalculationWithoutCarryMode(numbers, functions, functionNumbers, matrix, numberOfNumbers, numberOfFunctions);
            int option = MenuMatrix();
            if (option == 1) outputMatrixInPlainText(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 2) saveMatrixInFileInPlainText(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 3)
            {
                outputMatrixInPlainText(matrix, numberOfNumbers, numberOfFunctions);
                saveMatrixInFileInPlainText(matrix, numberOfNumbers, numberOfFunctions);
            }
            delete[] numbers;
            delete[] functions;
            delete[] functionNumbers;
            for (int i = 0; i < numberOfFunctions; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
        case 6:
        {
            int numberOfNumbers = getNumberOfNumbers();
            double* numbers = new double[numberOfNumbers];
            getNumbers(numbers);
            int numberOfFunctions = getNumberOfFunctions();
            string* functions = new string[numberOfFunctions];
            getFunctions(functions);
            double* functionNumbers = new double[numberOfFunctions];
            double** matrix = new double* [numberOfNumbers];
            for (int i = 0; i < numberOfFunctions; i++)
            {
                matrix[i] = new double[numberOfFunctions];
            }
            getNumbersFromFunctions(functions, functionNumbers, numberOfFunctions);
            matrixCalculationWithoutCarryMode(numbers, functions, functionNumbers, matrix, numberOfNumbers, numberOfFunctions);
            int option = MenuMatrix();
            if (option == 1) outputMatrixInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 2) saveMatrixInFileInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 3)
            {
                outputMatrixInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
                saveMatrixInFileInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
            }
            delete[] numbers;
            delete[] functions;
            delete[] functionNumbers;
            for (int i = 0; i < numberOfFunctions; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
        case 7:
        {
            int numberOfNumbers = getNumberOfNumbers();
            double* numbers = new double[numberOfNumbers];
            getNumbers(numbers);
            int numberOfFunctions = getNumberOfFunctions();
            string* functions = new string[numberOfFunctions];
            getFunctions(functions);
            double* functionNumbers = new double[numberOfFunctions];
            double** matrix = new double* [numberOfNumbers];
            for (int i = 0; i < numberOfFunctions; i++)
            {
                matrix[i] = new double[numberOfFunctions];
            }
            getNumbersFromFunctions(functions, functionNumbers, numberOfFunctions);
            matrixCalculationWithCarryMode(numbers, functions, functionNumbers, matrix, numberOfNumbers, numberOfFunctions);
            int option = MenuMatrix();
            if (option == 1) outputMatrixInPlainText(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 2) saveMatrixInFileInPlainText(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 3)
            {
                outputMatrixInPlainText(matrix, numberOfNumbers, numberOfFunctions);
                saveMatrixInFileInPlainText(matrix, numberOfNumbers, numberOfFunctions);
            }
            delete[] numbers;
            delete[] functions;
            delete[] functionNumbers;
            for (int i = 0; i < numberOfFunctions; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
        case 8:
        {
            int numberOfNumbers = getNumberOfNumbers();
            double* numbers = new double[numberOfNumbers];
            getNumbers(numbers);
            int numberOfFunctions = getNumberOfFunctions();
            string* functions = new string[numberOfFunctions];
            getFunctions(functions);
            double* functionNumbers = new double[numberOfFunctions];
            double** matrix = new double* [numberOfNumbers];
            for (int i = 0; i < numberOfFunctions; i++)
            {
                matrix[i] = new double[numberOfFunctions];
            }
            getNumbersFromFunctions(functions, functionNumbers, numberOfFunctions);
            matrixCalculationWithCarryMode(numbers, functions, functionNumbers, matrix, numberOfNumbers, numberOfFunctions);
            int option = MenuMatrix();
            if (option == 1) outputMatrixInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 2) saveMatrixInFileInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
            else if (option == 3)
            {
                outputMatrixInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
                saveMatrixInFileInJSONFormat(matrix, numberOfNumbers, numberOfFunctions);
            }
            delete[] numbers;
            delete[] functions;
            delete[] functionNumbers;
            for (int i = 0; i < numberOfFunctions; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            break;
        }
    }
}