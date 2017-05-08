#include "dataCruncher.h"
#include "customer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <random>
#include <sstream>
using namespace std;
/*
The challenge for this was trying to make a random number generator that could constantly be called.
After a few hours trying to make rand and srand work. I looked up how those functions work and they take the system clock and work off of it. Meaning you cannot perform continous operations.
So after journeying through the internet with no help, I stumbled through a microsoft talk on the subject. And they said to use the random family of functions, ensuring that it can be continously called.
uniform_int_distribution<int> PurHev(31, 50); <- the important things to know is that the only things needed to change are the numbers to change the range.
uniform_int_distribution<int><- this is the kind of value we want returned.
*/
int dataCruncher::deterPurHev() 
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> PurHev(31, 50);
	int amount = PurHev(mt);
	return amount;
}

int dataCruncher::deterPurMed() //determining the amount of purchases
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> PurMed(11, 30);
	int amount = PurMed(mt);
	return amount;
}

int dataCruncher::deterPurLight() //determining the amount of purchases
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> PurLight(0, 10);
	int amount = PurLight(mt);
	return amount;
}

int dataCruncher::clkRndHev() //determining the amount windowshopping
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> clkLight(1, 50);
	int amount = clkLight(mt);
	return amount;
}

int dataCruncher::clkRndMed() //determining the amount windowshopping
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> clkMed(51, 150);
	int amount = clkMed(mt);
	return amount;
}

int dataCruncher::clkRndlight() //determining the amount windowshopping
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> clkHev(151, 300);
	int amount = clkHev(mt);
	return amount;
}

int dataCruncher::purchaseAmount()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> PurLight(1, 300);
	int amount = PurLight(mt);
	return amount;
}

int dataCruncher::clickAmount() 
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> CA(1, 50);
	int amount = CA(mt);
	return amount;
}

int dataCruncher::departmentNumber()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> DN(0, 16);
	int amount = DN(mt);
	return amount;
}

int dataCruncher::NAME()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> NAME(0, 39);
	int amount = NAME(mt);
	return amount;
}

int dataCruncher::LAST()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> LAST(0, 19);
	int amount = LAST(mt);
	return amount;
}

int dataCruncher::ID()
{
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> ID(1, 10000);
	int amount = ID(mt);
	return amount;
}

void dataCruncher::Output()
{
	customer Output[500]; //The amount of customer data can be changed by incrementing or decrementing this number
	ofstream myfile ("ServerOutput.txt");
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 99);
	for (int x = 0; x < 500; x++) //Any changes made above need to be made for this for loop
	{
		Output[x].changeID(x + ID());

		int beginningName = NAME();
		int finalName = LAST();

		Output[x].firstname = firstName[beginningName];
		Output[x].lastname = lastName[finalName];

		Output[x].updateID(); // Gives ID to the customer

		/*
		Every customer can be a light, medium, or heavy user.
		This can be changed to include more or less variations as long as new if conditions are created or old ones deleted.
		Light users sight=see the highest and purchase the least.
		Heavy users sight-see the least and make the most purchases.
		Medium users are the middle ground users.
		The customer type has no affect on the price of the objects they buy por the amount of clicks.
		This can be expanded to so that it does have an influence.
		*/

		int userheaviness = dist(mt);
		if (userheaviness <= 33)
		{

			for (int y = 0; y < deterPurLight(); y++)
			{
				Output[x].amountSpent = purchaseAmount();
				Output[x].makeAPurchase(departmentNumber());
				myfile << Output[x].updatedID.str() << " " << Output[x].newPurchase.str() << endl;
			}
			for (int z = 0; z < clkRndlight(); z++)
			{
				Output[x].amountOfClicks = clickAmount();
				Output[x].newClicks(departmentNumber());
				myfile << Output[x].updatedID.str() << " " << Output[x].dataClicks.str() << endl;
			}
			continue;
		}
		if (userheaviness > 33 && userheaviness <= 66)
		{
			for (int y = 0; y < deterPurMed(); y++)
			{
				Output[x].amountSpent = purchaseAmount();
				Output[x].makeAPurchase(departmentNumber());
				myfile << Output[x].updatedID.str() << " " << Output[x].newPurchase.str() << endl;
			}
			for (int z = 0; z < clkRndMed(); z++)
			{
				Output[x].amountOfClicks = clickAmount();
				Output[x].newClicks(departmentNumber());
				myfile << Output[x].updatedID.str() << " " << Output[x].dataClicks.str() << endl;
			}
			continue;
		}
		if (userheaviness > 66)
		{
			for (int y = 0; y < deterPurHev(); y++)
			{
				Output[x].amountSpent = purchaseAmount();
				Output[x].makeAPurchase(departmentNumber());
				myfile << Output[x].updatedID.str() << " " << Output[x].newPurchase.str() << endl;
			}
			for (int z = 0; z < clkRndHev(); z++)
			{
				Output[x].amountOfClicks = clickAmount();
				Output[x].newClicks(departmentNumber());
				myfile << Output[x].updatedID.str() << " " << Output[x].dataClicks.str() << endl;
			}
			continue;
		}
		/*
		the output will have the ID name whether they were buying or sightseeing (denoted by b or s) and then the amount bought or the amount of clicks
		*/
		myfile.close();
	}
}