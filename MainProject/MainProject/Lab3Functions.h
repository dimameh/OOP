#pragma once
#include <iostream>
#include "Input.h"

using namespace std;

int GetLength(char* string);
int GetLength(const char string[]);
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
void CopyString(char* resultString, char* source);
void CopyConstString(char* newString, const char source[]);
//Структура Person
//ReadPerson() - ввод данных. Возвращает объект
//PrintPerson(Person person) - Вывод данных

//TODO: Каждую сущность (структуру, перечисление) в отдельный файл.
//TODO: Оформление не по RSDN
enum Gender { female, male, other };
struct Person
{
	char Surname[40];
	char Name[20];
	char Patronymic[25];
	Gender Sex;
	int Age;
};
Person ReadPerson();
void PrintPerson(Person person);