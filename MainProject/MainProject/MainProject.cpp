// MainProject.cpp: определяет точку входа для консольного приложения.

#include "stdafx.h"
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "PersonListDemo.h"
#include "Input.h"

using namespace std;

void MainMenu();

int main()
{
	srand(time(NULL));
	MainMenu();
    return 0;
}

void MainMenu()
{
	const int menuSize = 6;
	int choice = 0; //переменная хранящая выбор пункта меню
	//пункты меню
	string menu[menuSize] =
	{
		"",
		"1) Lab 1",
		"2) Lab 2",
		"3) Lab 3",
		"4) Lab 4",
		"5) Exit"
	};

	while (choice != menuSize - 1)
	{
		//вывод меню на экран
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		cout << "-----The fourth laboratory work-----" << endl << endl;

		//каждый раз после выполнения программ (заданий) обнуляется выбор пункта
		choice = ShowMenu(menu, menuSize);

		//функционал пунктов меню
		system("cls");
		switch (choice)
		{
		case 1:
			LaunchTask1();
			break;
		case 2:
			LaunchTask2();
			break;
		case 3:
			LaunchTask3();
			break;
		case 4:
			LaunchTask4();
			break;
		case 5:
			cout << "Closing program";
			break;
		default:
			break;
		}
		system("cls");
	}
}