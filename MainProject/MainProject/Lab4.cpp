#include "stdafx.h"
#include "Lab4.h"

////Запуск меню третьей лабораторной работы
void LaunchTask4()
{
	const int menuSize = 7;
	int choice = 0; //переменная хранящая выбор пункта меню
					//пункты меню
	string menu[menuSize] =
	{
		"",
		"1) Add person at list",
		"2) Get person",
		"3) Remove person from list",
		"4) Insert person in list",
		"5) Clear list",
		"6) Exit"
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
			AddFunctionDemo();
			break;
		case 2:
			GetFunctionDemo();
			break;
		case 3:
			RemoveFunctionDemo();
			break;
		case 4:
			InsertFunctionDemo();
			break;
		case 5:
			ClearFunctionDemo();
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
void AddFunctionDemo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Add\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 5; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Get
void GetFunctionDemo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Get\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 5; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);

	int index=0;
	SetConsoleTextAttribute(hConsole, (WORD)(2));
	cout << "Please select the record index: ";
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cin >> index;
	PrintPerson(*Get(index,head,tail));
	
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Remove
void RemoveFunctionDemo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Remove\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 4; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);

	int index = 0;
	SetConsoleTextAttribute(hConsole, (WORD)(2));
	cout << "Please select the record index to delete: ";
	cin >> index;

	Remove(index, head, tail);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);

	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Insert
void InsertFunctionDemo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Insert\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 4; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);

	int index = 0;
	cout << "Please select the index for new record: ";
	cin >> index;

	person = MakeRandomPerson();
	Insert(person, index, head, tail);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);

	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//Демонстрация работы функции Clear
void ClearFunctionDemo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Clear\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 4; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);

	Clear(head, tail);
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(head);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}