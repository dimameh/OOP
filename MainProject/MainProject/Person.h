#pragma once
#include "Gender.h"
//ReadPerson() - ввод данных. Возвращает объект
//PrintPerson(Person person) - Вывод данных
struct Person
{
	char Surname[40];
	char Name[20];
	char Patronymic[25];
	Gender Sex;
	int Age;
};