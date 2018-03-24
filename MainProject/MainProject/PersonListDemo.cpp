#include "stdafx.h"
#include "PersonListDemo.h"

////Запуск меню четвертой лабораторной работы
void LaunchTask4()
{
	const int menuSize = 7;
	int choice = 0; //переменная хранящая выбор пункта меню
					//пункты меню
	string menu[menuSize] =
	{
		"",
		"1) Add person to list",
		"2) Get person",
		"3) Remove person from list",
		"4) Insert person to list",
		"5) Clear list",
		"6) Main Menu"
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
			DemoAddFunction();
			break;
		case 2:
			DemoGetFunction();
			break;
		case 3:
			DemoRemoveFunction();
			break;
		case 4:
			DemoInsertFunction();
			break;
		case 5:
			DemoClearFunction();
			break;
		case 6:
			cout << "Closing fourth lab";
			break;
		default:
			break;
		}
		system("cls");
	}
}
//Демонстрация работы функции Add
void DemoAddFunction()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));

	cout << "---Demonstrating \"Add\" function---" << endl << endl;

	PersonList* list = new PersonList;

	AddRandomPersons(3, list);

	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	Clear(list);
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Get
void DemoGetFunction()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Get\" function---" << endl << endl;

	PersonList* list = new PersonList;

	AddRandomPersons(3, list);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	int index=0;
	//Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(2));
	cout << "Please select the record index: ";
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cin >> index;
	PrintPerson(*Get(index, list));
	
	Clear(list);
	//Раскраска элементов консоли в зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Remove
void DemoRemoveFunction()
{
	//Раскраска элементов консоли в светло-зеленый
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Remove\" function---" << endl << endl;

	PersonList* list = new PersonList;
	
	AddRandomPersons(3, list);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	int index = 0;
	//Раскраска элементов консоли в зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(2));
	cout << "Please select the record index to delete: ";
	cin >> index;
	try
	{
		Remove(index, list);
	}
	catch (exception e)
	{
		cout << "Error!" << e.what();
		index = 0;
	}
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	Clear(list);
	//Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Insert
void DemoInsertFunction()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Insert\" function---" << endl << endl;

	PersonList* list = new PersonList;

	AddRandomPersons(3, list);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	int index = 0;
	cout << "Please select the index for new record: ";
	cin >> index;

	Person person = MakeRandomPerson();
	Insert(person, index, list);
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	Clear(list);
	//Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Clear
void DemoClearFunction()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Clear\" function---" << endl << endl;

	PersonList* list = new PersonList;
	
	AddRandomPersons(3, list);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	Clear(list);
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Добавить в список указанное количество случайных людей
void AddRandomPersons(int count, PersonList *&list)
{
	Person person;
	try
	{
		for (int i = 0; i < 3; i++)
		{
			person = MakeRandomPerson();

			Add(person, list);
		}
	}
	catch (exception e)
	{
		cout << "Error!" << e.what();
	}
}