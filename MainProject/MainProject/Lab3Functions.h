#pragma once
#include <iostream>
#include "Input.h"
#include "Gender.h"
#include "Person.h"
using namespace std;

//Возвращает длину подаваемой на вход строки
int GetLength(char* string);
//Сливает две строки в одну и возвращает строку-результат
char* Concatenate(char* string1, char* string2);
//Возвращает подстроку выбранной длины из строки, начиная с указанного индекса
char* GetSubstring(char* string, int startIndex, int charCount);
//Возвращает индекс указанной подстроки в данной строке
int FindSubstring(char* string, char* substring);
//Переводит все символы строки в верхний регистр
char* MakeStringUppercase(char* string);
//Переводит все символы строки в нижний регистр
char* MakeStringLowercase(char* string);
//Разбивает имя файла на путь, название и расширение
void SplitFilename(char* source, char* path, char* name, char* extension);
//Заменяет символы табулатуры на пробелы
char* ReplaceTabsOnSpaces(char* string);
//Сдвигает строку вправо, начиная с выбранного индекса, на указанное количество символов
void RightShiftString(char * string, int startPosition, int &size, int numberOfPositions);
//Сдвигает строку влево, начиная с выбранного индекса, на указанное количество символов
char* ReplaceSpacesOnTabs(char* string);
//Заменяет пробелы на символы табулатуры
void LeftShiftString(char * string, int startPosition, int &size, int numberOfPositions);
//Скопировать строку в другую
void CopyString(char* resultString, char* source);
//Заполнить структуру данными
Person ReadPerson();
//Вывести объект структуры
void PrintPerson(Person person);