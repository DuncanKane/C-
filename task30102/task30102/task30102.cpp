// task30102.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	for (int i = 2; i<100; i++)
	{
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime) cout << i << " ";

	}


	
	_getch();
	return 0;
}

