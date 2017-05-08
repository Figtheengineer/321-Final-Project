#define _CRT_SECURE_NO_WARNINGS
#include "dataCruncher.h"
#include "customer.h"
#include"Maintree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <random>
#include <sstream>


using namespace std;


int main() 
{
	//Initiates a user.
	dataCruncher user;

	//This creates a "ServerOutput.txt" file. It only needs to be ran once to initialize the file. 
	//It will be placed in the project debug folder but "add existing item" will need to be performed to add it to the project window.
	user.Output();
	
	//Initiates tree to read the "ServerOutput.txt" file.
	Maintree inTree;
	
	//Opens "ServerOutput.txt" for reading
	//Calls the Maintree function that reads the "ServerOutput.txt" data into the initiated "inTree".
	inTree.readintree();
	//Opens "TreeOutput.txt" for writing 
	
	inTree.exportTree();




	
	system("Pause");
	return 1;
}
