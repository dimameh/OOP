#pragma once
#include "Gender.h"
//��������� Person ������ ������� (Surname), ���(Name), ��������(Patronymic), ���(Sex) � �������(Age) ��������
struct Person
{
	char Surname[40];
	char Name[20];
	char Patronymic[25];
	Gender Sex;
	int Age;
};