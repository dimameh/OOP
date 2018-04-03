#include "stdafx.h"
#include "ClassDemo.h"
#include "PersonList.h"
#include "PersonInstruments.h"
//������������ ������ ������ PersonList
void ClassDemo()
{
	//��������� ��������� ������� � �������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---PersonList class---" << endl << endl;
	/*---------------------���������� 3 ������� � ������ ������---------------------*/
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	PersonList list1, list2;
	Person randomPerson;
	for (int i = 0; i < 3; i++)
	{
		MakeRandomPerson(randomPerson);
		list1.Add(randomPerson);
		MakeRandomPerson(randomPerson);
		list2.Add(randomPerson);
	}
	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "3 people were added to each list." << endl << endl;
	system("pause");
	/*---------------------����� ���� ������� - 1---------------------*/
	cout << endl << endl << "List output: " << endl << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST 1________________" << endl;
	list1.PrintList();
	cout << "________________LIST 2________________" << endl;
	list2.PrintList();
	system("pause");
	/*---------------------���������� � ������ ������ ������ ��������---------------------*/
	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Adding new person at list 1..." << endl << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	MakeRandomPerson(randomPerson);
	list1.Add(randomPerson);
	system("pause");
	/*---------------------����� ���� ������� - 2---------------------*/
	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Second person from list 1 copies to list 2" << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));

	randomPerson = list1.Find(2);
	list2.Add(randomPerson);
	cout << "________________LIST 1________________" << endl;
	list1.PrintList(randomPerson);
	cout << "________________LIST 2________________" << endl;
	list2.PrintList(randomPerson);
	system("pause");
	/*---------------------�������� �������� �� ������� ������ � ����� ���� ������� - 3---------------------*/
	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Deleting this person from list 1" << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));


	list1.Remove(randomPerson);
	cout << "________________LIST 1________________" << endl;
	list1.PrintList();
	cout << "________________LIST 2________________" << endl;
	list2.PrintList(randomPerson);
	system("pause");


	/*---------------------������� ������� ������---------------------*/
	list2.Clear();
	//��������� ��������� ������� � �����
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Now, list 2 is cleared" << endl;

	//��������� ��������� ������� � �������
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//��������� ��������� ������� � ������-�������
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}
