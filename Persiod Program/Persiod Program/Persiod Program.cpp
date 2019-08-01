// Persiod Program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <array>

using namespace std;

// Structure for users and logging persiods
struct Users
{
	string sUsername;
	string sLocation;
	int iLog1;
	int iLog2;
	int iLog3;
};

// function to add the logs together 
int iTotal(int iLog1, int iLog2, int iLog3)
{
	return iLog1 + iLog2 + iLog3;
}

// function to find the difference in logs
double iDhour(int iLog1, int iLog2)
{
	if (iLog1 > iLog2)
	{
		return iLog1 - iLog2;
	}
	else if (iLog2 > iLog1)
	{
		return iLog2 - iLog1;
	}
	else
	{
		return iLog1 - iLog2;
	}
}
// funciton to out put the average persieds per hour
int iAhour(int iLog1, int iLog2)
{
	return (iLog1 + iLog2) / 2;
}
// funciton to out put the average persieds per hour per minute
double dAminute(int iLog1, int iLog2)
{
	return ((iLog1 + iLog2) / 2) / 60.0;
}
// function for out putting the average overall
int iDall(int iLog1, int iLog2, int iLog3)
{
	return (iLog1 + iLog2 + iLog3) / 3;
}
// functionb for working out the overall difference - there has to be a better way
/*int iDall(int iLog1, int iLog2, int iLog3, int iLog4, int iLog5)
{
	for (int iCount = 0; iCount < 5; iCount++)
	if (iLog(iCount) > iLog2 && iLog3 && iLog4 && iLog5)
	{
		return iLog1 - iLog2;
	}
	else if (iLog2 > iLog1)
	{
		return iLog2 - iLog1;
	}
	else
	{
		return iLog1 - iLog2;
	}*/

int main()
{
	// variable for amount of people going to log perseids
	int iLoggers = 0;
	cout << "Welcome to the Perseid logging program \n\n";
	cout << "Please enter the amount of users logging data \n\n";
	
	cin >> iLoggers;
	// statement to stop error inputs 
	/*if (iLoggers == 1 || 2 || 3 || 4 || 5)
	{
		cout << "You have entered " << iLoggers << "\n\n";
	}
	else
	{
		cout << "Incorrect input \n\n";
	}*/

	//Array for creating 5 objects to log users and perseids
	Users oLogin[5];
	//for loop to create a number of objects specified my user
	for (int iCount = 0; iCount < iLoggers; iCount++)
	{
		// inputs to populate specified objects variables
		cout << "Please enter your first name \n";
		cin >> oLogin[iCount].sUsername;
		cout << "Please enter your location \n";
		cin >> oLogin[iCount].sLocation;
		cout << "Time log 1, amount of perseids ";
		cin >> oLogin[iCount].iLog1;
		cout << "Time log 2, amount of perseids ";
		cin >> oLogin[iCount].iLog2;
		cout << "Time log 3, amount of perseids ";
		cin >> oLogin[iCount].iLog3;
	}

	// variables for menu selection
	int iChoice = 0, iPtotal = 0;
	bool bChoice = false;

	do
	{
		cout << "1. All loggers and total Perseids logged \n";
		cout << "2. Difference in Perseids per hour \n";
		cout << "3. Average Perseids per hour \n";
		cout << "4. Difference of Perseids overall \n";
		cout << "5. Average of Perseids overall \n";
		cout << "6. Average Perseids per minute per hour \n";
		cout << "7. Average Perseids per minute overall \n";
		cout << "8. Largest amount of Perseids seen \n";
		cout << "9. Range of Persieds seen \n";
		cout << "10. Mean of Persieds seen \n";
		cout << "0. Exit the program \n";
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
			// the FOR statement will out put depending on the amount of people logged in using a funtion
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				cout << oLogin[iCount].sUsername << " logged " << iTotal(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3) << "\n";
				iPtotal += iTotal(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3);
			}
			cout << "The total Perseids seen is " << iPtotal << "\n\n";
			iPtotal = 0;
			break;

		case 2:
			// FOR statement to run for the amount of users using a function for the difference per hour 
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				cout << oLogin[iCount].sUsername << ": \n";
				cout << "Difference for the between log1 and log2 is " << iDhour(oLogin[iCount].iLog1, oLogin[iCount].iLog2) << "\n";
				cout << "Difference for the between log2 and log3 is " << iDhour(oLogin[iCount].iLog2, oLogin[iCount].iLog3) << "\n\n";
			}
			break;
			// case and for statment for the average persieds per hour
		case 3:
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				cout << oLogin[iCount].sUsername << ": \n";
				cout << "Average persieds between log1 and log2 is " << iAhour(oLogin[iCount].iLog1, oLogin[iCount].iLog2) << "\n";
				cout << "Average persieds between log2 and log3 is " << iAhour(oLogin[iCount].iLog2, oLogin[iCount].iLog3) << "\n\n";
			}
			break;
			// case and for statment for the difference of pereids over all 
		case 4:
		{
			int iDoverall[5];
			int iMin = 999;
			int iMax = -999;

			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				iDoverall[iCount] = iTotal(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3);
			}


			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				if (iDoverall[iCount] < iMin)
					iMin = iDoverall[iCount];
				if (iDoverall[iCount] > iMax)
					iMax = iDoverall[iCount];
			}

			cout << "The difference in perseids overall is " << iDhour(iMax, iMin) << "\n\n";

			break;
		}
			// case and for statment for the average pereids over all 
		case 5:
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				cout << oLogin[iCount].sUsername << " logged an average of " << iDall(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3) << "\n";
				iPtotal += iDall(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3);
			}
			cout << "The total average for Perseids seen is " << iPtotal << "\n\n";
			iPtotal = 0;
			break;
			// case to output the perseids seen per hour per minute
		case 6:
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				cout << oLogin[iCount].sUsername << ": \n";
				cout << "Average persieds between log1 and log2 per minute is " << dAminute(oLogin[iCount].iLog1, oLogin[iCount].iLog2) << "\n";
				cout << "Average persieds between log2 and log3 per minute is " << dAminute(oLogin[iCount].iLog2, oLogin[iCount].iLog3) << "\n\n";
			}
			break;
			// case to output the Average Perseids per minute overall
		case 7:
		{
			double iDoverall[5];
			int iMin = 999;
			int iMax = -999;

			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				iDoverall[iCount] = dAminute(oLogin[iCount].iLog1, oLogin[iCount].iLog2);
				iDoverall[iCount] = dAminute(oLogin[iCount].iLog2, oLogin[iCount].iLog3);
			}
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				if (iDoverall[iCount] < iMin)
					iMin = iDoverall[iCount];
				if (iDoverall[iCount] > iMax)
					iMax = iDoverall[iCount];
			}

			cout << "The difference in perseids per minute overall is " << iDhour(iMax, iMin) << "\n\n";

			break;
		}
		case 8:
			//case for the largest amount of persieds seen 
		{
			int iDoverall[5];
			int iMax = -999;

			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				iDoverall[iCount] = iTotal(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3);
			}
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				if (iDoverall[iCount] > iMax)
					iMax = iDoverall[iCount];
			} 
			cout << "The largest amount seen overall is " << iMax << "\n\n";
			break;
		}

		case 9:
			// case for the range fo perseids seen
		{
			int iDoverall[5];
			int iMin = 999;
			int iMax = -999;

			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				iDoverall[iCount] = iTotal(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3);
			}


			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				if (iDoverall[iCount] < iMin)
					iMin = iDoverall[iCount];
				if (iDoverall[iCount] > iMax)
					iMax = iDoverall[iCount];
			}

			cout << "The Range of Persieds seen is " << iDhour(iMax, iMin) << "\n\n";

			break;
		}

		case 10:
			// case for the mean fo perseids seen
			for (int iCount = 0; iCount < iLoggers; iCount++)
			{
				cout << oLogin[iCount].sUsername << " logged an average of " << iDall(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3) << "\n";
				iPtotal += iDall(oLogin[iCount].iLog1, oLogin[iCount].iLog2, oLogin[iCount].iLog3);
			}
			cout << "The Mean of Persieds seen is " << iPtotal << "\n\n";
			iPtotal = 0;
			break;


		case 0:
			bChoice = true;
			break;

		default:
			cout << "Input not recognised \n";
			break;
		}

	} while (bChoice == false);

	_getch();
	return 0;
}

