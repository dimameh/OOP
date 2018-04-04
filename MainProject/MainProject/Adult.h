#pragma once
#include "Person.h"
//Класс Adult
//Содержит поля: _name, _surname, _patronymic, _age, _sex;
//_marriedOn, _workPlace
class Adult :public Person
{
private:
	Person* _marriedOn;
	string _workPlace;
public:
	Adult();
	//---Get/Set---//

	//Возвращает переменную _marriedOn
	Person* GetMarriedOn();
	//Задать переменную _marriedOn
	void SetMarriedOn(Person* person);
	//Возвращает переменную _workPlace
	string GetWorkPlace();
	//Задать переменную _workPlace
	void SetWorkPlace(string workPlace);
	//Задать переменную _Age
	void SetAge(int age);
	//-------------//

	//получить описание Взрослого
	std::string GetDescription();

	//Задать случайные параметры для объекта структуры Adult
	static void MakeRandomAdult(Adult& person, Person& partner);
};