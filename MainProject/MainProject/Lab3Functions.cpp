#include "stdafx.h"
#include "Lab3Functions.h"

using namespace std;

//Возвращает длину подаваемой на вход строки
int GetLength(char* string)
{
	//TODO: Ничем не отличается от следующего метода. Уберите дублирование!
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
//Возвращает длину константной строки
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
//Сливает две строки в одну и возвращает строку-результат
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
//Возвращает подстроку выбранной длины из строки, начиная с указанного индекса
char* GetSubstring(char* string, int startIndex, int charCount)
{
	int length = GetLength(string);
	if ((startIndex < 0) || (charCount < 0))
	{
		return NULL;
	}
	if (charCount + startIndex - 1 > length - 1)
	{
		return NULL;
	}
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
//Возвращает индекс указанной подстроки в данной строке
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
			{ 
				return -1;
			}
			else
			{
				//сравниваем строки. Если функция возвращает ноль значит строки одинаковые
				if (strcmp(checkingSubstring, substring) == 0)
				{
					return i;
				}
			}
		}
	}
	return -1;
}
//Переводит все символы строки в нижний регистр
char* Lowercase(char* string)
{
	int length = GetLength(string);
	char* stringRes = new char[length];
	CopyString(stringRes, string);

	for (int i = 0; i < length; i++)
	{
		if ((stringRes[i] >= 'A') && (stringRes[i] <= 'Z'))
		{
			stringRes[i] = stringRes[i] + 32;
		}
	}
	return stringRes;
}
//Переводит все символы строки в верхний регистр
char* Uppercase(char* string)
{
	int length = GetLength(string);
	char* resultString = new char[length];
	CopyString(resultString, string);

	for (int i = 0; i < length; i++)
	{
		if ((resultString[i] >= 'a') && (resultString[i] <= 'z'))
		{
			resultString[i] = resultString[i] - 32;
		}
	}
	return resultString;
}
//Разбивает имя файла на путь, название и расширение
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
//Заменяет символы табулатуры на пробелы
char* ReplaceTabsOnSpaces(char* string)
{
	int length = GetLength(string);
	int counter = 0;
	char spaceSymbol = ':';
	char* resultString = new char[length * 4];
	CopyString(resultString, string);

	for (int i = 0; i < length; i++)
	{
		counter++;
		if (counter == 5)
		{
			counter = 1;
		}
		if (resultString[i] == '\t')
		{
			RightShiftString(resultString, i, length, 4 - counter);
			for (int j = i; j < i + 4 + 1 - counter; j++)
			{
				resultString[j] = spaceSymbol;
			}
		}
	}

	return resultString;
}
//Сдвигает строку вправо, начиная с выбранного индекса, на указанное количество символов
void RightShiftString(char * string, int startPosition, int &size, int numberOfPositions)
{
	for (int j = size; j > startPosition; j--)
	{
		string[j + numberOfPositions] = string[j];
	}
	size = size + numberOfPositions + 1;
}
//Сдвигает строку влево, начиная с выбранного индекса, на указанное количество символов
void LeftShiftString(char * string, int startPosition, int &size, int numberOfPositions)
{
	for (int j = startPosition; j < size-1; j++)
	{
		string[j] = string[j + numberOfPositions];

	}
	size = size - numberOfPositions + 1;
}
//Заменяет пробелы на символы табулатуры
char* ReplaceSpacesOnTabs(char* string)
{
	int length = GetLength(string);
	int counter = 0;
	char spaceSymbol = ':';
	char* resultString = new char[length * 4];

	CopyString(resultString, string);

	for (int i = 0; i < length; i++)
	{
		counter++;
		if (counter == 5)
		{
			counter = 1;
		}
		if (resultString[i] == ':')
		{
			bool isTab = true;
			for (int j = 1; j <= 4-counter ; j++)
			{
				if (resultString[i + j] != ':')
				{
					isTab = false;
				}
			}
			if (isTab == true)
			{
				LeftShiftString(resultString, i, length, 4-counter);
				resultString[i] = '\t';
				i -= 4 - counter;
			}
		}
	}

	return resultString;
}
//Заполнить структуру данными
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
	sex = InputIntegerOnInterval(0, 2);

	newPerson.Sex = static_cast<Gender>(sex);

	cout << endl << "Age: ";
	newPerson.Age = InputIntegerOnInterval(0, 120);

	return newPerson;
}
//Вывести объект структуры
void PrintPerson(Person person)
{
	cout << "Name: " << person.Name << endl;
	cout << "Surname: " << person.Surname << endl;
	cout << "Patronymic: " << person.Patronymic << endl;

	switch (person.Sex)
	{
	case Male:
		cout << "Sex: " << "male";
		break;
	case Female:
		cout << "Sex: " << "female";
		break;
	case Other:
		cout << "Sex: " << "other";
		break;

	default:
		break;
	}
	cout << endl << "Age: " << person.Age << endl;
}
//Скопировать строку в другую
void CopyString(char* resultString, char* source)
{
	for (int i = 0; i <= GetLength(source); i++)
	{
		resultString[i] = source[i];
	}
}
//Скопировать константную строку в другую
void CopyConstString(char* newString, const char source[])
{
	for (int i = 0; i <= GetConstLength(source); i++)
	{
		newString[i] = source[i];
	}
}