#pragma once
#include <iostream>
#include "Input.h"

using namespace std;

int GetLength(char* string);
char* Concatenate(char* string1, char* string2);
char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);
char* Uppercase(char* string);
char* Lowercase(char* string);
void SplitFilename(char* source, char* path, char* name, char* extension);
char* ReplaceTabsOnSpaces(char* string);
void RightShiftString(char * string, int startPosition, int &size, int numberOfPositions);
char* ReplaceSpacesOnTabs(char* string);
void LeftShiftString(char * string, int startPosition, int &size, int numberOfPositions);
//Структура Person
//ReadPerson() - ввод данных. Возвращает объект
//PrintPerson(Person person) - Вывод данных
struct Person
{
	enum Gender { female, male, other };

	char Surname[40];
	char Name[20];
	char Patronymic[25];
	Gender Sex;
	int Age;

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
		InputIntegerOnInterval(sex,0,2);

		newPerson.Sex = static_cast<Person::Gender>(sex);

		cout << endl << "Age: ";
		InputIntegerOnInterval(newPerson.Age, 0, 120);

		return newPerson;
	}
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
};