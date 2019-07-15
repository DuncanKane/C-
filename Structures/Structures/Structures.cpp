// Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <array>

using namespace std;
 

// object created above the main
struct Game
{
	string sTitle;
	int iQuantity;
	double dPrice;
};




int main()
{
	// 3 objects with their own variable as above
	Game oDoW, oHoI, oMlP;

	/* cout << "Welcome to the program \n";
	// inputting all the data in 2 of the data stores
	cout << "Please input the details for Dawn of War \n";
	cin >> oDoW.sTitle;
	// strings with spaces in don't work
	cout << "Please input the details for Heart of Iron \n";
	cin >> oHoI.sTitle;

	cout << "Please input the quantity for Dawn of War \n";
	cin >> oDoW.iQuantity;

	cout << "Please input the quantity for Heart of Iron \n";
	cin >> oHoI.iQuantity;

	cout << "Please input the price for Dawn of War \n";
	cin >> oDoW.dPrice;

	cout << "Please input the price for Heart of Iron \n";
	cin >> oHoI.dPrice;
	// outputting from the structures
	cout << "The Title " << oDoW.sTitle << " has the quantity of " << oDoW.iQuantity << "\n";
	cout << "The Title " << oHoI.sTitle << " has the quantity of " << oHoI.iQuantity << "\n";
	*/

	// an array for the structure
	Game oInStock[3];
	// loop for inputting into the 3 structures 
	for (int iCount = 0; iCount < 3; iCount++)
	{
		cout << "Please input the details for game " << iCount + 1 << "\n";
		cin >> oInStock[iCount].sTitle;
		cin >> oInStock[iCount].iQuantity;
		cin >> oInStock[iCount].dPrice;
	}
	// loop for outputting into the 3 structures
	for (int iCount = 0; iCount < 3; iCount++)
	{
		cout << "The details for " << oInStock[iCount].sTitle << " is \n";
		cout << "Inventory: " << oInStock[iCount].iQuantity << "\n";
		cout << "Price: " << oInStock[iCount].dPrice << "\n";

	}



	_getch();
	return 0;
}

