// MainProject.cpp: определяет точку входа для консольного приложения.
//TODO: Так и не переделал структуру проекта и не избавился от папок с номерами лабораторных
#include "stdafx.h"
#include "ClassDemo.h"
#include "PersonListDemo.h"
#include "Input.h"
#include "Lab6Demo.h"
#include "DemoLab7.h"
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
	const int menuSize = 5;
	int choice = 0; //переменная хранящая выбор пункта меню
	//пункты меню
	string menu[menuSize] =
	{
		"",
		"1) Lab 5.",
		"2) Lab 6.",
		"3) Lab 7.",
		"4) Exit."
	};

	while (choice != menuSize - 1)
	{
		//вывод меню на экран
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		cout << "-----Main menu-----" << endl << endl;

		//каждый раз после выполнения программ (заданий) обнуляется выбор пункта
		choice = ShowMenu(menu, menuSize);

		//функционал пунктов меню
		system("cls");
		switch (choice)
		{
		case 1:
			ClassDemo();
			break;
		case 2:
			Lab6Demo();
			break;
		case 3:
			Lab7Menu();
			break;
		case 4:
			cout << "Closing program";
			break;
		default:
			break;
		}
		system("cls");
	}
}