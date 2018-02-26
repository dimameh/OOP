#include "stdafx.h"
#include "Lab4.h"

////������ ���� ������� ������������ ������
void LaunchTask4()
{
	const int menuSize = 7;
	int choice = 0; //���������� �������� ����� ������ ����
					//������ ����
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
		//����� ���� �� �����

		cout << "-----The fourth laboratory work-----" << endl << endl;

		//������ ��� ����� ���������� �������� (�������) ���������� ����� ������
		choice = ShowMenu(menu, menuSize);

		//���������� ������� ����
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
//������������ ������ ������� Add
void AddFunctionDemo()
{
	cout << "---Demonstrating \"Add\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 5; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	Show(head);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//������������ ������ ������� Get
void GetFunctionDemo()
{
	cout << "---Demonstrating \"Get\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 5; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	Show(head);

	int index=0;
	cout << "Please select the record index: ";
	cin >> index;
	PrintPerson(*Get(index,head,tail));

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//������������ ������ ������� Remove
void RemoveFunctionDemo()
{
	cout << "---Demonstrating \"Remove\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 4; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	Show(head);

	int index = 0;
	cout << "Please select the record index to delete: ";
	cin >> index;

	Remove(index, head, tail);
	Show(head);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//������������ ������ ������� Insert
void InsertFunctionDemo()
{
	cout << "---Demonstrating \"Insert\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 4; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	Show(head);

	int index = 0;
	cout << "Please select the index for new record: ";
	cin >> index;

	person = MakeRandomPerson();
	Insert(person, index, head, tail);
	Show(head);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
//������������ ������ ������� Clear
void ClearFunctionDemo()
{
	cout << "---Demonstrating \"Clear\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	for (int i = 0; i < 4; i++)
	{
		person = MakeRandomPerson();
		Add(person, head, tail);
	}
	Show(head);

	Clear(head, tail);
	
	Show(head);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}