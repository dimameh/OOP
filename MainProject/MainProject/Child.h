#pragma once
#include "Person.h"
//Класс Adult
//TODO: не надо в комментарии класса перечислять поля. Надо писать, для чего класс нужен
//Содержит поля: _name, _surname, _patronymic, _age, _sex;
//_mother, _father, _school
class Child :public Person
{
private:
	Person* _mother;
	Person* _father;
	string _school;
public:
	Child();
	//---Get/Set---//

	//TODO: Не надо в комментарии указывать, как называется поле. Просто "мать". Аналогично для остальных комментариев
	//Возвращает переменную _mother
	Person* GetMother();
	//Задать переменную _mother
	void SetMother(Person* person);
	//Возвращает переменную _father
	Person* GetFather();
	//Задать переменную _father
	void SetFather(Person* person);
	//Возвращает переменную _school
	string GetSchool();
	//Задать переменную _school
	void SetSchool(string person);
	//Задать переменную _Age
	void SetAge(int age);
	//-------------//

	//получить описание ребенка
	std::string GetDescription();

	//Задать случайные параметры для объекта структуры Child
	//TODO: не должен ребенок генерировать сам себя
	static void MakeRandomChild(Child& person, Person& father, Person& mother);
};

