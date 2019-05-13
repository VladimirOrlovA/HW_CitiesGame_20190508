#include "citiesConsol.h"

citiesConsol::citiesConsol() :model("city.csv")
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int r = 10 + rand() % 6;
	int x = 0;
	for (size_t i = 0; i < r; i++)
	{
		cout << "Добро пожаловать в игру ГОРОДА!\n\n";
		cout << "Загрузка ";
		for (size_t i = 0; i < x; i++)
		{
			cout << ">";
		}
		Sleep(0);
		x++;
		if (x == 4) x = 0;
		system("cls");
	}
}

void citiesConsol::menu()
{
	int choice = 1;
	while (choice)
	{
		cout << "1. Начать играть\n";
		cout << "2. Ввод игроков\n";
		cout << "3. Правила игры\n";
		cout << "4. Выход\n";
		cout << "\n-> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cin.get();
			start();
			break;
		case 2:
			gamer();
			break;
		case 3:
			info();
			break;
		case 4:
			choice = 0;
			cout << "\n\nСпасибо! До_свидания :) \n\n";
			break;
		default:
			cout << "Ошибочный ввод номера меню...\n";
			cout << "Хотите продожить или выйти 0/1 ? \n";
			cin >> choice;
			system("cls");
			break;
		}
	}
	system("pause");
}

void citiesConsol::gamer()
{
	system("cls");
	cout << "\n\nМаксимальное число игроков - 5 \n\n";
	cout << "Сейчас в игре - " << players.size() << "\n\n";
	//players.reserve(5);
	int oneMore = 1;
	while (oneMore)
	{
		if (countPlayers == 5) {
			system("cls");
			cout << "Введено максимальное кол-во игроков\n"
				<< "Ввод нового игрока возможен после выбития одного из действующих игроков\n\n";
			system("pause");
			system("cls");
			return;
		}
		else {
			cout << "\nХотите ввести еще одного игрока 0/1 ? -> ";
			cin >> oneMore;
			if (!oneMore) break;
		}
		countPlayers++;
		string name;
		cout << "\nВведите имя " << countPlayers << " игрока -> ";
		cin >> name;
		players.push_back(name);


	}
	system("cls");
	cout << "\n\nВ игре принимают участие игроки:\n\n";
	for (size_t i = 0; i < countPlayers; i++)
		cout << i + 1 << " - " << players[i] << endl;
	cout << "\n\n\n";
	system("pause");
	system("cls");
}

void citiesConsol::start()
{
	if (players.size()<=1) {
		system("cls");
		cout << "\nДля игры необходимо как минимум 2 игрока!\n"
			<< "Введите игроков...\n\n";
		system("pause");
		system("cls");
		menu();
		}
	
	while (1) {
		
		for (size_t i = 0; i < players.size(); i++)
		{
			if (players.size() == 1) {
				system("cls");
				cout << "\n\n\n" << players[i] << ", поздравляем, Вы выиграли!!!\n\n\n";
				return;
			}
			cout << "Очередь игрока " << players[i] << endl;
			cout << "Введите город\n";
			string city;
			getline(cin, city);
			int res = model.check(city);
			switch (res)
			{
			case 0:
				cout << "\n\nНет такого города! Вы выбываете из игры\n";
				players.erase(players.begin()+i);
				break;
			case 1:
				cout << "\nУдача!\n";
				break;
			case 2:
				cout << "\n\nГород уже был! Вы выбываете из игры\n";
				break;
			case 3:
				cout << "\n\nБуквы не совпадают. Вы выбываете из игры\n";
				break;
			}
		}
	}

	/*for (size_t i = 192; i< 224; i++)
	{
		cout << i << " " << char(i) <<" "<< char(i+32) <<"\t";
	}*/
}

void citiesConsol::info()
{
	int anyKey = 1;
	system("cls");
	cout << "\n\n\n\n\n\n\n";
	cout << "Города́ — игра для нескольких(двух или более) человек, в которой каждый " <<
		"участник в свою очередь называет реально существующий город любой страны, " <<
		"название которого начинается на ту букву, которой оканчивается название " <<
		"предыдущего участника\n\n";
	cout << "\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}
