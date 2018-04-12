#pragma once
#include "Person.h"
//Класс Child
//Содержит информацию о ребенке
class Child :public Person
{
private:
	Person* _mother;
	Person* _father;
	string _school;
public:
	Child();
	//---Get/Set---//

	//Возвращает переменную Мать
	Person* GetMother();
	//Задать переменную Мать
	void SetMother(Person* person);
	//Возвращает переменную Отец
	Person* GetFather();
	//Задать переменную Отец
	void SetFather(Person* person);
	//Возвращает переменную Школа
	string GetSchool();
	//Задать переменную Школа
	void SetSchool(string person);
	//Задать переменную Возраст
	void SetAge(int age);
	//-------------//

	//получить описание ребенка
	std::string GetDescription();

	//Задать случайные параметры для объекта структуры Child
	static void MakeRandomChild(Child& person, Person& father, Person& mother);
};

