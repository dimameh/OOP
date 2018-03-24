#include "stdafx.h"
#include "PersonListDemo.h"

////������ ���� ��������� ������������ ������
void LaunchTask4()
{
	const int menuSize = 7;
	int choice = 0; //���������� �������� ����� ������ ����
					//������ ����
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
		//����� ���� �� �����
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(12));
		cout << "-----The fourth laboratory work-----" << endl << endl;

		//������ ��� ����� ���������� �������� (�������) ���������� ����� ������
		choice = ShowMenu(menu, menuSize);

		//���������� ������� ����
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
//������������ ������ ������� Add
void DemoAddFunction()
{
	//��������� ��������� ������� � �������
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
//������������ ������ ������� Get
void DemoGetFunction()
{
	//��������� ��������� ������� � �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Get\" function---" << endl << endl;

	PersonList* list = new PersonList;

	AddRandomPersons(3, list);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	int index=0;
	//��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(2));
	cout << "Please select the record index: ";
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cin >> index;
	PrintPerson(*Get(index, list));
	
	Clear(list);
	//��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//������������ ������ ������� Remove
void DemoRemoveFunction()
{
	//��������� ��������� ������� � ������-�������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Remove\" function---" << endl << endl;

	PersonList* list = new PersonList;
	
	AddRandomPersons(3, list);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	int index = 0;
	//��������� ��������� ������� � �������
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
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	Clear(list);
	//��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//������������ ������ ������� Insert
void DemoInsertFunction()
{
	//��������� ��������� ������� � �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Insert\" function---" << endl << endl;

	PersonList* list = new PersonList;

	AddRandomPersons(3, list);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	int index = 0;
	cout << "Please select the index for new record: ";
	cin >> index;

	Person person = MakeRandomPerson();
	Insert(person, index, list);
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	Clear(list);
	//��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//������������ ������ ������� Clear
void DemoClearFunction()
{
	//��������� ��������� ������� � �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---Demonstrating \"Clear\" function---" << endl << endl;

	PersonList* list = new PersonList;
	
	AddRandomPersons(3, list);

	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	Clear(list);
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	Show(list);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//�������� � ������ ��������� ���������� ��������� �����
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