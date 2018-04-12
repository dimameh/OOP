#include "stdafx.h"
#include "DemoLab7.h"
#include "List.hpp"
#include "Person.h"
#include "Adult.h"
void DemoDouble()
{
	//��������� ��������� ������� � �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Template List class demonstration with double data---" << endl << endl;
	List<double> list;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	double data[5] = {2.4, 3.5, 0.6, 1.1, 0.02};

	for (int i = 0; i < 5; i++)
	{
		list.Add(data[i]);
	}
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Removing 3-rd element" << endl << endl;

	list.RemoveAt(3);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Addint new 4-th element" << endl << endl;


	list.AddOnPosition(7.77, 4);
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	// ��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}
void DemoPersonPtr()
{
	//��������� ��������� ������� � �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Template List class demonstration with Person* data---" << endl << endl;
	List<Person*> list;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Person* data[6];

	for (int i = 0; i < 6; i++)
	{
		Person::MakeRandomPerson(*data[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		list.Add(data[i]);
	}
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Removing 3-rd element" << endl << endl;

	list.RemoveAt(3);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Addint new 4-th element" << endl << endl;

	list.AddOnPosition(data[5], 4);
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	// ��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}
void DemoDubleArr()
{
	//��������� ��������� ������� � �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Template List class demonstration with Person* data---" << endl << endl;
	List<double*> list;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	double data[5][6];

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			data[i][j] = rand() % 10;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		list.Add(data[i]);
	}
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Removing 3-rd element" << endl << endl;

	list.RemoveAt(3);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "Addint new 4-th element" << endl << endl;

	list.AddOnPosition(data[5], 4);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST________________" << endl;

	list.PrintList();

	// ��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}