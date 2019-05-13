#include"citiesLogic.h"


CitiesLogic::CitiesLogic(string fileDir) {
	ifstream file;
	file.open(fileDir);
	string str;
	getline(file, str);
	while (!file.eof()) {
		getline(file, str);//до конца строки
		if (str.rfind(';') != str.npos)//string::npos
			cities.push_back(str.substr(str.rfind(';') + 1));
	}
	file.close();
}

//1 норм, 2 использовался,3 буквы не совпадают,0 нет города
int CitiesLogic::check(const string & city)
{
	int c = 0;
	for (size_t i = 0; i < cities.size(); i++)
	{
		if (city == cities[i])
		{
			for (size_t i = 0; i < usedCities.size(); i++)
			{
				if (city == usedCities[i])
					return 2;
			}
			if (usedCities.size() > 0)
				if (city[0] + 32 != usedCities[usedCities.size() - 1][usedCities[usedCities.size() - 1].length() - 1])
					return 3;
			//*((*(end(usedCities)-1)).end()-1)
			usedCities.push_back(city);
			return 1;
		}
	}
	return 0;

}
