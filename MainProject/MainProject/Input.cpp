#include "stdafx.h"
#include "Input.h"

using namespace std;

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
		cout << "What do you want to do? --->";
		cin >> choice;
		if ((choice >= 1) && (choice <= menuSize))
			break;
		else
			cout << "There is no such category";
	}
	return choice;
}