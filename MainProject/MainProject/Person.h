#pragma once
#include "Gender.h"
//ReadPerson() - ���� ������. ���������� ������
//PrintPerson(Person person) - ����� ������
struct Person
{
	char Surname[40];
	char Name[20];
	char Patronymic[25];
	Gender Sex;
	int Age;
};