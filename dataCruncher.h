#include <cstdlib>
#include <random>
#include <sstream>
using namespace std;

class dataCruncher
{
public:
	string firstName[40];// = { "William", "Liam", "Noah", "Mason", "Owen", "Benjamin", "Henry", "Jackson", "Elijah", "Oliver", "Wyatt", "Ezekiel", "Carter", "Logan", "Aiden", "Alexander", "Samuel", "Jack", "Lucas", "Ethan", "Ava", "Olivia", "Ashley", "Sophia", "Emma", "Mia", "Genesis", "Isabella", "Harper", "Evelyn", "Charlotte", "Aurora", "Amelia", "Aria", "Emily", "Zoey", "Lillian", "Avery", "Nora", "Elizabeth" };
	string lastName[20];// = { "Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", "Garcia", "Rodriguez", "Wilson", "Martinez", "Anderson", "Taylor", "Thomas", "Hernandez", "Moore", "Martin", "Jackson", "Thompson", "Lopez" };
	int deterPurHev();
	int deterPurMed();
	int deterPurLight();
	int clkRndHev();
	int clkRndMed();
	int clkRndlight();
	int purchaseAmount();
	int clickAmount();
	int departmentNumber();
	int NAME();
	int LAST();
	int ID();
	void Output();
	dataCruncher()
	{
		char *list[] = { "William", "Liam", "Noah", "Mason", "Owen", "Benjamin", "Henry", "Jackson", "Elijah", "Oliver", "Wyatt", "Ezekiel", "Carter", "Logan", "Aiden", "Alexander", "Samuel", "Jack", "Lucas", "Ethan", "Ava", "Olivia", "Ashley", "Sophia", "Emma", "Mia", "Genesis", "Isabella", "Harper", "Evelyn", "Charlotte", "Aurora", "Amelia", "Aria", "Emily", "Zoey", "Lillian", "Avery", "Nora", "Elizabeth" };
		char *llist[] = { "Smith", "Johnson", "Williams", "Brown", "Jones", "Miller", "Davis", "Garcia", "Rodriguez", "Wilson", "Martinez", "Anderson", "Taylor", "Thomas", "Hernandez", "Moore", "Martin", "Jackson", "Thompson", "Lopez" };
		for (int i = 0; i < 40; ++i)
			firstName[i] = list[i];
		for (int i = 0; i < 20; ++i)
			lastName[i] = llist[i];
	}
};
