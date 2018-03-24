#pragma once
#include <iostream>
#include "Input.h"
#include "Gender.h"
#include "Person.h"
using namespace std;

//���������� ����� ���������� �� ���� ������
int GetLength(char* string);
//������� ��� ������ � ���� � ���������� ������-���������
char* Concatenate(char* string1, char* string2);
//���������� ��������� ��������� ����� �� ������, ������� � ���������� �������
char* GetSubstring(char* string, int startIndex, int charCount);
//���������� ������ ��������� ��������� � ������ ������
int FindSubstring(char* string, char* substring);
//��������� ��� ������� ������ � ������� �������
char* MakeStringUppercase(char* string);
//��������� ��� ������� ������ � ������ �������
char* MakeStringLowercase(char* string);
//��������� ��� ����� �� ����, �������� � ����������
void SplitFilename(char* source, char* path, char* name, char* extension);
//�������� ������� ���������� �� �������
char* ReplaceTabsOnSpaces(char* string);
//�������� ������ ������, ������� � ���������� �������, �� ��������� ���������� ��������
void RightShiftString(char * string, int startPosition, int &size, int numberOfPositions);
//�������� ������ �����, ������� � ���������� �������, �� ��������� ���������� ��������
char* ReplaceSpacesOnTabs(char* string);
//�������� ������� �� ������� ����������
void LeftShiftString(char * string, int startPosition, int &size, int numberOfPositions);
//����������� ������ � ������
void CopyString(char* resultString, char* source);
//��������� ��������� �������
Person ReadPerson();
//������� ������ ���������
void PrintPerson(Person person);