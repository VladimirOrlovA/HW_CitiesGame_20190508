#pragma once
#include<vector>
#include<string>
#include<fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

class CitiesLogic {
	vector<string> cities;
	vector<string> usedCities;
public:
	CitiesLogic(string fileDir); 
	int check(const string & city);
};