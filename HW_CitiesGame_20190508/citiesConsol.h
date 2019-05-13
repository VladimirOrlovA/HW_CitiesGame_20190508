#include "citiesLogic.h"
using namespace std;

class citiesConsol
{
	CitiesLogic model;
	vector<string> players;
	int countPlayers = 0;
public:
	citiesConsol();
	void menu();
	void gamer();
	void start();
	void info();
};
