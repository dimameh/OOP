#pragma once
#include "Gender.h"
//TODO: Комментарий к типу данных
//TODO: Зачем здесь комментарии о функциях, для которых здесь нет даже прототипов?
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