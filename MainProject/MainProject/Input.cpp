#pragma once
#include "stdafx.h"
#include "Input.h"
#include "Lab3Functions.h"

using namespace std;
//Валидация ввода положительного числа
void InputInteger(int &value)
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
			if ((c[i] < 48) || (c[i] > 57))
			{
				cout << "ERROR: That's not integer value. Enter the number from " << INT_MIN << " to " << INT_MAX << ": ";
				isCorrect = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				break;
			}
		}
	}
	value = atoi(c);
}
//Валидация ввода числа, лежащего на заданном интервале
void InputIntegerOnInterval(int &value, int intervalLeftBorder, int intervalRightBorder)
{
	char c[11];
	bool isCorrect = false;

	if (intervalLeftBorder > intervalRightBorder)
	{
		int temp;
		temp = intervalLeftBorder;
		intervalLeftBorder = intervalRightBorder;
		intervalRightBorder = temp;
	}
	while (!isCorrect)
	{
		string s;
		cin >> s;
		int length = s.length();
		for (int i = 0; i < length+1; i++)
		{
			c[i] = s[i];
		}

		isCorrect = true;
		for (int i = 0; i < length; i++)
		{
			if ((c[i] < 48) || (c[i] > 57))
			{
				cout << "ERROR: That's not integer value. Enter the number from " << intervalLeftBorder << " to " << intervalRightBorder << ": ";
				isCorrect = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		for (int i = 0; i < length; i++)
		{
			if (!((atoi(c) >= intervalLeftBorder) && (atoi(c) <= intervalRightBorder)))
			{
				cout << "ERROR: That value is not in range from " << intervalLeftBorder << " to " << intervalRightBorder << ". Please re-enter correctly: ";
				isCorrect = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
	}
	value = atoi(c);
}
//Валидация ввода двух положительных чисел
void InputInteger(int &value, int &value2)
{
	char c1[11], c2[11];
	bool isCorrect = false;

	while (!isCorrect)
	{
		string s;
		cin >> s;
		int length = s.length();
		for (int i = 0; i < length; i++)
		{
			c1[i] = s[i];
		}
		isCorrect = true;
		for (int i = 0; i < length; i++)
		{
			if ((c1[i] < 48) || (c1[i] > 57))
			{
				cout << "ERROR: That's not integer values. Enter the number from " << INT_MIN << " to " << INT_MAX << ": ";
				isCorrect = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		if (isCorrect)
		{
			value = atoi(c1);
			string s;
			cin >> s;
			int length = s.length();
			for (int i = 0; i < length; i++)
			{
				c2[i] = s[i];
			}
			for (int i = 0; i < length; i++)
			{
				if ((c2[i] < 48) || (c2[i] > 57))
				{
					cout << "ERROR: That's not integer values. Enter the number from " << INT_MIN << " to " << INT_MAX << ": ";
					isCorrect = false;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}
		}
	}
	value2 = atoi(c2);
}
//Валидация ввода трех положительных чисел
void InputInteger(int &value, int &value2, int &value3)
{
	char c1[11], c2[11], c3[11];
	bool isCorrect = false;

	while (!isCorrect)
	{
		string s;
		cin >> s;
		int length = s.length();
		for (int i = 0; i < length; i++)
		{
			c1[i] = s[i];
		}
		isCorrect = true;
		for (int i = 0; i < length; i++)
		{
			if ((c1[i] < 48) || (c1[i] > 57))
			{
				cout << "ERROR: That's not integer values. Enter the number from " << INT_MIN << " to " << INT_MAX << ": ";
				isCorrect = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
		if (isCorrect)
		{
			value = atoi(c1);
			string s;
			cin >> s;
			int length = s.length();
			for (int i = 0; i < length; i++)
			{
				c2[i] = s[i];
			}
			for (int i = 0; i < length; i++)
			{
				if ((c2[i] < 48) || (c2[i] > 57))
				{
					cout << "ERROR: That's not integer values. Enter the number from " << INT_MIN << " to " << INT_MAX << ": ";
					isCorrect = false;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}
		}
		if (isCorrect)
		{
			value2 = atoi(c2);
			string s;
			cin >> s;
			int length = s.length();
			for (int i = 0; i < length; i++)
			{
				c3[i] = s[i];
			}
			for (int i = 0; i < length; i++)
			{
				if ((c3[i] < 48) || (c3[i] > 57))
				{
					cout << "ERROR: That's not integer values. Enter the number from " << INT_MIN << " to " << INT_MAX << ": ";
					isCorrect = false;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					break;
				}
			}
		}
	}
	value3 = atoi(c3);
}
//Валидация ввода имен собственных
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
			if (!(((c[i] >= 65) && (c[i] <= 90)) || ((c[i] >= 97) && (c[i] <= 122))))
			{
				cout << "ERROR: Invalid input string. Please re-enter correctly: ";
				isCorrect = false;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
			}
		}
	}
	if ((c[0] > 96) && (c[0] < 123))
	{
		c[0] = c[0] - 32;
	}

	for (int i = 1; i < GetLength(c); i++)
	{
		if ((c[i] > 64) && (c[i] < 91))
		{
			c[i] = c[i] + 32;
		}
	}
	strcpy(string, c);
}
//Вывод меню
int ShowMenu(string menu[], int menuSize)
{
	for (int i = 1; i < menuSize; i++)
	{
		cout << menu[i] << endl;
	}
	for (int i = 0; i < 12; i++)
	{
		cout << endl;
	}

	int choice = 0;
	//выбор строки меню
	while ((choice < 1) || (choice > menuSize - 1))
	{
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