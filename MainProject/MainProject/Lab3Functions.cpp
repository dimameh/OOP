#include "stdafx.h"
#include "Lab3Functions.h"

using namespace std;

//���������� ����� ���������� �� ���� ������
int GetLength(char* string)
{
	int length = 0;
	char symbol;
	symbol = string[0];

	while (symbol != '\0')
	{
		length++;
		symbol = string[length];
	}
	return length;
}
//���������� ����� ����������� ������
int GetConstLength(const char string[])
{
	int length = 0;
	char symbol;
	symbol = string[0];

	while (symbol != '\0')
	{
		length++;
		symbol = string[length];
	}
	return length;
}
//������� ��� ������ � ���� � ���������� ������-���������
char* Concatenate(char* string1, char* string2)
{
	int length1 = GetLength(string1);
	int length2 = GetLength(string2);
	int length3 = length1 + length2;
	char* string3 = new char[length3 + 1];
	for (int i = 0; i < length1; i++)
	{
		string3[i] = string1[i];
	}
	for (int i = 0; i < length2; i++)
	{
		string3[length1] = string2[i];
		length1++;
	}
	string3[length3] = '\0';

	return string3;
}
//���������� ��������� ��������� ����� �� ������, ������� � ���������� �������
char* GetSubstring(char* string, int startIndex, int charCount)
{
	int length = GetLength(string);
	if ((startIndex < 0) || (charCount < 0))
		return NULL;
	if (charCount + startIndex - 1 > length - 1)
		return NULL;
	char* substring = new char[charCount + 1];
	int counter = -1;
	for (int i = startIndex; i < charCount + startIndex; i++)
	{
		counter++;
		substring[counter] = string[i];
	}
	substring[charCount] = '\0';
	return substring;
}
//���������� ������ ��������� ��������� � ������ ������
int FindSubstring(char* string, char* substring)
{
	int length = GetLength(string);
	int subLength = GetLength(substring);
	for (int i = 0; i < length; i++)
	{
		if (string[i] == substring[0])
		{
			char* checkingSubstring = new char[subLength];
			checkingSubstring = GetSubstring(string, i, subLength);
			if (checkingSubstring == NULL)
				return -1;
			else
			{
				//���������� ������. ���� ������� ���������� ���� ������ ������ ����������
				if (strcmp(checkingSubstring, substring) == 0)
				{
					return i;
				}
			}
		}
	}
	return -1;
}
//��������� ��� ������� ������ � ������ �������
char* Lowercase(char* string)
{
	int length = GetLength(string);
	char* stringRes = new char[length];
	CopyString(stringRes, string);

	for (int i = 0; i < length; i++)
	{
		if ((stringRes[i] > 64) && (stringRes[i] < 91))
		{
			stringRes[i] = stringRes[i] + 32;
		}
	}
	return stringRes;
}
//��������� ��� ������� ������ � ������� �������
char* Uppercase(char* string)
{
	int length = GetLength(string);
	char* stringRes = new char[length];
	CopyString(stringRes, string);

	for (int i = 0; i < length; i++)
	{
		if ((stringRes[i] > 96) && (stringRes[i] < 123))
		{
			stringRes[i] = stringRes[i] - 32;
		}
	}
	return stringRes;
}
//��������� ��� ����� �� ����, �������� � ����������
void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int length = GetLength(source);
	int count = 0;
	bool isFile = 1;
	bool isPath = 0;
	path[0] = '\0';
	name[0] = '\0';
	extension[0] = '\0';
	for (int i = length - 1; i >= 0; i--)
	{
		count++;
		if (source[i] == '.')
		{
			if (source[i - 1] == '\\')
			{
				isFile = 0;
				break;
			}
			CopyString(extension, GetSubstring(source, i, count));
			count = 0;
		}
		if (source[i] == '\\')
		{
			isPath = 1;
			CopyString(name, GetSubstring(source, i + 1, count - 1));
			count = i;
			break;
		}
		if ((isPath == 0) && (i == 0))
		{
			CopyString(name, GetSubstring(source, 0, count));
		}
	}

	if (isFile)
	{
		if (isPath != 0)
		{
			CopyString(path, GetSubstring(source, 0, count + 1));
		}
	}
	else
	{
		CopyConstString(path, "NULL");
		CopyConstString(name, "NULL");
		CopyConstString(extension, "NULL");
	}
}
//�������� ������� ���������� �� �������
char* ReplaceTabsOnSpaces(char* string)
{
	int length = GetLength(string);
	int counter = 0;
	char spaceSymbol = ':';
	char* stringRes = new char[length * 4];
	CopyString(stringRes, string);

	for (int i = 0; i < length; i++)
	{
		counter++;
		if (counter == 5)
		{
			counter = 1;
		}
		if (stringRes[i] == '\t')
		{
			switch (counter)
			{
			case 1://4
				RightShiftString(stringRes, i, length, 3);

				for (int j = i; j < i + 4; j++)
				{
					stringRes[j] = spaceSymbol;
				}
				//length += 4;

				break;
			case 2://3
				RightShiftString(stringRes, i, length, 2);

				for (int j = i; j < i + 3; j++)
				{
					stringRes[j] = spaceSymbol;
				}
				//length += 3;

				break;
			case 3://2
				RightShiftString(stringRes, i, length, 1);
				for (int j = i; j < i + 2; j++)
				{
					stringRes[j] = spaceSymbol;
				}
				//length += 2;

				break;
			case 4://1

				stringRes[i] = spaceSymbol;
				length += 1;

				break;
			default:
				break;
			}
		}
	}

	return stringRes;
}
//�������� ������ ������, ������� � ���������� �������, �� ��������� ���������� ��������
void RightShiftString(char * string, int startPosition, int &size, int numberOfPositions)
{
	for (int j = size; j > startPosition; j--)
	{
		string[j + numberOfPositions] = string[j];
	}
	size = size + numberOfPositions + 1;
}
//�������� ������ �����, ������� � ���������� �������, �� ��������� ���������� ��������
void LeftShiftString(char * string, int startPosition, int &size, int numberOfPositions)
{
	for (int j = startPosition; j < size-1; j++)
	{
		string[j] = string[j + numberOfPositions];

	}
	size = size - numberOfPositions + 1;
}
//�������� ������� �� ������� ����������
char* ReplaceSpacesOnTabs(char* string)
{
	int length = GetLength(string);
	int counter = 0;
	char spaceSymbol = ':';
	char* stringRes = new char[length * 4];

	CopyString(stringRes, string);

	for (int i = 0; i < length; i++)
	{
		counter++;
		if (counter == 5)
		{
			counter = 1;
		}
		if (stringRes[i] == ':')
		{
			switch (counter)
			{
			case 1://4
				if ((stringRes[i + 1] == ':') && (stringRes[i + 2] == ':') && (stringRes[i + 3] == ':'))
				{
					LeftShiftString(stringRes, i, length, 3);
					stringRes[i] = '\t';
					i -= 3;
				}
				break;
			case 2://3
				if ((stringRes[i + 1] == ':') && (stringRes[i + 2] == ':'))
				{
					LeftShiftString(stringRes, i, length, 2);
					stringRes[i] = '\t';
					i -= 2;
				}
				break;
			case 3://2
				if ((stringRes[i + 1] == ':'))
				{
					LeftShiftString(stringRes, i, length, 1);
					stringRes[i] = '\t';
					i -= 1;
				}
				break;
			case 4://2
					stringRes[i] = '\t';
				break;
			default:
				break;
			}
		}
	}

	return stringRes;
}
//��������� ��������� �������
Person ReadPerson()
{
	Person newPerson;
	cout << "---Fill in the form---" << endl;
	cout << "Name: ";
	InputName(newPerson.Name);
	cout << endl << "Surname: ";
	InputName(newPerson.Surname);
	cout << endl << "Patronymic: ";
	InputName(newPerson.Patronymic);

	cout << endl << "Sex. Enter '1' for male, '0' for female and '2' for other: ";
	int sex;
	InputIntegerOnInterval(sex, 0, 2);

	newPerson.Sex = static_cast<Gender>(sex);

	cout << endl << "Age: ";
	InputIntegerOnInterval(newPerson.Age, 0, 120);

	return newPerson;
}
//������� ������ ���������
void PrintPerson(Person person)
{
	cout << "Name: " << person.Name << endl;
	cout << "Surname: " << person.Surname << endl;
	cout << "Patronymic: " << person.Patronymic << endl;

	switch (person.Sex)
	{
	case male:
		cout << "Sex: " << "male";
		break;
	case female:
		cout << "Sex: " << "female";
		break;
	case other:
		cout << "Sex: " << "other";
		break;

	default:
		break;
	}
	cout << endl << "Age: " << person.Age << endl;
}
//����������� ������ � ������
void CopyString(char* resultString, char* source)
{
	for (int i = 0; i <= GetLength(source); i++)
	{
		resultString[i] = source[i];
	}
}
//����������� ����������� ������ � ������
void CopyConstString(char* newString, const char source[])
{
	for (int i = 0; i <= GetConstLength(source); i++)
	{
		newString[i] = source[i];
	}
}