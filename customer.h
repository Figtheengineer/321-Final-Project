#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <random>
#include <sstream>
using namespace std;
class customer
{
public:
	string firstname = "First";
	string lastname = "Last";
	int amountSpent = 0;
	int costumerID = 0;
	int amountOfClicks = 0;
	stringstream newPurchase;
	stringstream dataClicks;
	stringstream updatedID;
	void updateID();
	void changeID(int newID);
	void makeAPurchase(int departmentNumber);
	void newClicks(int departmentNumber);
};

