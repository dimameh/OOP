#pragma once
#include "Gender.h"
#include "Lab3Functions.h"
//Класс Person
//Содержит поля: _name, _surname, _patronymic, _age, _sex;
class Person
{
private:
	char _name[20];
	char _surname[20];
	char _patronymic[30];
	int _age;
	Sex _sex;
public:
	Person();
	//---Get/Set---//
	//Задать переменную name_
	void SetName(char name[20]);
	//Возвращает переменную name_
	char* GetName();
	//Задать переменную surname_
	void SetSurname(char surname[20]);
	//Возвращает переменную surname_
	char* GetSurname();
	//Задать переменную patronymic_
	void SetPatronymic(char patronymic[30]);
	//Возвращает значение patronymic_
	char* GetPatronymic();
	//Задать переменную age_
	void SetAge(int age);
	//Возвращает переменную age_
	int GetAge();
	//Задать переменную sex_
	void SetSex(Sex sex);
	//Возвращает переменную sex_
	Sex GetSex();
	//-------------//
	//Задать случайные параметры для объекта структуры Person
	void MakeRandomPerson();
	//Вывести в консоль содержимое объекта структуры
	void Print();
	//Чтение персоны с клавиатуры
	void Read();
	//Вывод данных персоны на экран
	void Show();
};