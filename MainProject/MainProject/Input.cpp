#include "stdafx.h"
#include "Input.h"
#include "Lab3Functions.h"

using namespace std;
//��������� ����� �������������� �����
int InputInteger()
{
	char c[11];
	bool isCorrect = false;

	while (!isCorrect)
	{
		string s;
		cin >> s;
		int length = s.length();
		for (int i = 0; i < length; i++)
		{
			c[i] = s[i];
		}

		isCorrect = true;
		for (int i = 0; i < length; i++)
		{
			if ((c[i] < '0') || (c[i] > '9'))
			{
				cout << "ERROR: That's not integer value. Enter the number from 0 to " << INT_MAX << ": ";
				isCorrect = false;
				cin.clear();
				cin.ignore(LONG_MAX, '\n');

				break;
			}
		}
	}
	return atoi(c);
}
//��������� ����� �������������� �����, �������� �� �������� ���������
int InputIntegerOnInterval(int min, int max)
{
	char c[11];
	bool isCorrect = false;
	int value;
	if (min > max)
	{
		exception intervalError("Wrong interval borders");
		throw intervalError;
	}
	while (!isCorrect)
	{
		
		isCorrect = true;
		
		value = InputInteger();
			
		if (value < min || value > max)
		{
			cout << "ERROR: That value is not in range from " << min << " to " << max << ". Please re-enter correctly: ";
			isCorrect = false;
			cin.clear();
			cin.ignore(LONG_MAX, '\n');
			break;
		}
	}
	return atoi(c);
}
//��������� ����� ���� �����������
void InputName(char* string)
{
	char c[100];
	bool isCorrect = false;

	while (!isCorrect)
	{
		std::string s;
		cin >> s;

		int length = s.length();
		for (int i = 0; i < length+1; i++)
		{
			c[i] = s[i];
		}

		isCorrect = true;
		for (int i = 0; i < length; i++)
		{
			if (!((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z')))
			{
				cout << "ERROR: Invalid input string. Please re-enter correctly: ";
				isCorrect = false;
				cin.clear();
				cin.ignore(LONG_MAX, '\n');
				break;
			}
		}
	}
	if (c[0] >= 'a' && c[0] <= 'z')
	{
		//��� ������������� ������ ������ ����� ���������
		c[0] = c[0] - 32;
	}

	for (int i = 1; i < GetLength(c); i++)
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
		{
			//��� ������������� ������ ��������� ����������
			c[i] = c[i] + 32;
		}
	}
	CopyString(string, c);
}
//����� ����
int ShowMenu(string menu[], int menuSize)
{
	//��������� ������ � ������� � ������-�������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(11));
	for (int i = 1; i < menuSize; i++)
	{
		cout << menu[i] << endl;
	}
	for (int i = 0; i < 12; i++)
	{
		cout << endl;
	}

	int choice = 0;
	//����� ������ ����
	while ((choice < 1) || (choice > menuSize - 1))
	{
		//��������� ������ � ������� � ������-�������
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << "---Choose function number for testing (1-" << menuSize - 1 << "): ";
		cin >> choice;
		if ((choice >= 1) && (choice <= menuSize))
		{ 
			break;
		}
		else
		{ 
			cout << "There is no such category";
		}
	}
	return choice;
}