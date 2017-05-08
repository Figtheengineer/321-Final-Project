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


void customer::updateID() 
{
	updatedID << costumerID << " " << firstname << " " << lastname;
};

void customer::changeID(int newID)
{
	costumerID = newID;
};

void customer::makeAPurchase(int departmentNumber)
{
	newPurchase.str("");
	newPurchase << departmentNumber << " b " << amountSpent;
};

void customer::newClicks(int departmentNumber)
{
	dataClicks.str("");
	dataClicks << departmentNumber << " c " << amountOfClicks;
};