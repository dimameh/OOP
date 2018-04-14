#include "stdafx.h"
#include "DemoLab7.h"
#include "List.hpp"
#include "Person.h"
#include "Adult.h"
#include "Input.h"

void PrintDoubleList(List<double> list)
{
	for (int i = 1; i < list.GetCount(); i++)
	{
		cout << list.Find(i) << ' ';
	}
	cout << endl;
}
void DemoDouble()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Template List class demonstration with double data---" << endl << endl;
	List<double> list;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	double data[5] = {2.4, 3.5, 0.6, 1.1, 0.02};

	for (int i = 0; i < 5; i++)
	{
		list.Add(data[i]);
	}
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintDoubleList(list);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Removing 3-rd element" << endl << endl;

	list.RemoveAt(3);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintDoubleList(list);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Addint new 4-th element" << endl << endl;


	list.AddOnPosition(7.77, 4);
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintDoubleList(list);

	// Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}

void PrintPersonPtrList(List<Person*> list) 
{
	for (int i = 1; i < list.GetCount(); i++)
	{
		cout << *list.Find(i);
	}
}
void DemoPersonPtr()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Template List class demonstration with Person* data---" << endl << endl;
	List<Person*> list;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Person* data = new Person[6];

	for (int i = 0; i < 6; i++)
	{
		Person::MakeRandomPerson(data[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		list.Add(&data[i]);
	}
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintPersonPtrList(list);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Removing 3-rd element" << endl << endl;

	list.RemoveAt(3);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintPersonPtrList(list);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Addint new 4-th element" << endl << endl;

	list.AddOnPosition(&data[5], 4);
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintPersonPtrList(list);

	// Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}

void PrintDoubleArrayList(List<double*> list)
{
	double* array = new double[5];
	int n = list.GetCount();
	for (int i = 1; i <= n; i++)
	{
		array = list.Find(i);
		for (int j = 0; j < 5; j++)
		{
			cout << array[j] << ' ';
		}
		cout << endl;
	}
}
void DemoDoubleArr()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Template List class demonstration with Person* data---" << endl << endl;
	List<double*> list;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	double data[6][5];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			data[i][j] = j + i;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		list.Add(data[i]);
	}
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintDoubleArrayList(list);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Removing 3-rd element" << endl << endl;

	list.RemoveAt(3);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintDoubleArrayList(list);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Addint new 4-th element" << endl << endl;

	list.AddOnPosition(data[5], 4);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	PrintDoubleArrayList(list);

	// Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}

void PrintDoubleList(List<List<double>> list)
{
	for (int i = 1; i < list.GetCount(); i++)
	{
		cout << "List " << i << ": ";
		PrintDoubleList(list.Find(i));
	}
	cout << endl;
}
void DemoDoubleList()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Template List class demonstration with Person* data---" << endl << endl;
	List<List<double>> MainList;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));

	List<double> doubleList[6];
	double data[6][5];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			data[i][j] = (double)rand() / (double)RAND_MAX * 20;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			doubleList[i].Add(data[i][j]);
		}
	}

	for (int i = 0; i < 6; i++)
	{
		MainList.Add(doubleList[i]);
	}

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________MAIN LIST________________" << endl;

	PrintDoubleList(MainList);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Removing 3-rd element" << endl << endl;

	MainList.RemoveAt(3);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________MAIN LIST________________" << endl;

	PrintDoubleList(MainList);

	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Addint new 4-th element" << endl << endl;

	MainList.AddOnPosition(doubleList[5], 4);

	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________MAIN LIST________________" << endl;

	PrintDoubleList(MainList);

	// Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}

void Lab7Menu()
{
	const int menuSize = 6;
	int choice = 0;
	std::string menu[menuSize] =
	{
		"",
		"1) List with double variables",
		"2) List with person pointers",
		"3) List with double array",
		"4) List with list with double variables",
		"5) Back"
	};

	while (choice != menuSize-1)
	{
		//вывод меню на экран
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		cout << "-----The seventh laboratory work-----" << endl << endl;

		//каждый раз после выполнения программ (заданий) обнуляется выбор пункта
		choice = ShowMenu(menu, menuSize);

		//функционал пунктов меню
		system("cls");
		switch (choice)
		{
		case 1:
			DemoDouble();
			break;
		case 2:
			DemoPersonPtr();
			break;
		case 3:
			DemoDoubleArr();
			break;
		case 4:
			DemoDoubleList();
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