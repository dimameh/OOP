#include "stdafx.h"
#include "Lab4.h"

void LaunchTask4()
{
	const int menuSize = 8;
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
		"6) Make random person",
		"7) Exit"
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

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:
			cout << "Closing fourth lab";
			break;
		default:
			break;
		}
		system("cls");
	}
}

void AddFunctionDemo()
{
	cout << "---Demonstrating \"Add\" function---" << endl << endl;

	Node *head, *tail;
	head = tail = NULL;
	Person person;
	//������ �� ������ �� ��������
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