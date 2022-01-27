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

#pragma once
using namespace std;
void getNumbersFromFunctions(string* functions, double*& functionNumbers, int numberOfFunctions);
void matrixCalculationWithoutCarryMode(double* numbers, string* functions, double* functionNumbers, double**& matrix, int numberOfNumbers, int numberOFunctions);
void matrixCalculationWithCarryMode(double* numbers, string* functions, double* functionNumbers, double**& matrix, int numberOfNumbers, int numberOFunctions);
void outputMatrixInPlainText(double** matrix, int numberOfNumbers, int numberOfFunctions);
void outputMatrixInJSONFormat(double** matrix, int numberOfNumbers, int numberOfFunctions);
void saveMatrixInFileInPlainText(double** matrix, int numberOfNumbers, int numberOfFunctions);
void saveMatrixInFileInJSONFormat(double** matrix, int numberOfNumbers, int numberOfFunctions);
int MenuMatrix();