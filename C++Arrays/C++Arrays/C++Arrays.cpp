// C++Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
	//int iNumChoice = 0;
	//cout << "Please choose how many number you would like to input \n";
	//cin >> iNumChoice;


	//const int iNumChoice2 = iNumbChoice;
	//array to store many variables of the same datatype
	int iNumbers[5];
	//for storing values into the array
	for (int iCount = 0; iCount < 5; iCount++)
	{
		cout << "Please insert a number into cell " << iCount << "\n";
		cin >> iNumbers[iCount];
	}

	int iTotal = 0;
	//for adding the array values together and out putting them
	for (int iCount = 0; iCount < 5; iCount++)
	{
		iTotal += iNumbers[iCount];
		cout << "The total is at the current value of " << iTotal << "\n";
	}

	cout << "The final value is " << iTotal;

	_getch();

	return 0;
}

