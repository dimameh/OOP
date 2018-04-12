#pragma once
#include "Person.h"
//Класс Adult
//Содержит информацию о взрослом
class Adult :public Person
{
private:
	Person* _marriedOn;
	string _workPlace;
public:
	Adult();
	//---Get/Set---//

	//Возвращает переменную В_браке
	Person* GetMarriedOn();
	//Задать переменную В_браке
	void SetMarriedOn(Person* person);
	//Возвращает переменную Работа
	string GetWorkPlace();
	//Задать переменную Работа
	void SetWorkPlace(string workPlace);
	//Задать переменную Возраст
	void SetAge(int age);
	//-------------//

	//получить описание Взрослого
	std::string GetDescription();

	//Задать случайные параметры для объекта структуры Adult
	static void MakeRandomAdult(Adult& person, Person& partner);
};