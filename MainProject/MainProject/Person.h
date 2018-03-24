#pragma once
#include "Gender.h"
//Структура Person хранит Фамилию (Surname), имя(Name), отчество(Patronymic), пол(Sex) и возраст(Age) человека
struct Person
{
	char Surname[40];
	char Name[20];
	char Patronymic[25];
	Gender Sex;
	int Age;
};