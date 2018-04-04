#include "stdafx.h"
#include "Adult.h"

Adult::Adult()
{
	SetMarriedOn(NULL);
	SetWorkPlace("");
	Person();
}
//---Get/Set---//

//Возвращает переменную _marriedOn
Person* Adult::GetMarriedOn()
{
	return _marriedOn;
}
//Задать переменную _marriedOn
void Adult::SetMarriedOn(Person* person)
{
	_marriedOn = person;
}
//Возвращает переменную _workPlace
string Adult::GetWorkPlace()
{
	return _workPlace;
}
//Задать переменную _workPlace
void Adult::SetWorkPlace(string workPlace)
{
	_workPlace = workPlace;
}
//Задать переменную _Age
void Adult::SetAge(int age)
{
	if (age >= 18 && age <= 120)
	{
		_age = age;
	}
	else
	{
		exception incorrectAge("Incorrect person age");
		throw incorrectAge;
	}
}
//-------------//

//получить описание Взрослого
string Adult::GetDescription()
{
	string description = Person::GetDescription();
	description[description.length() - 1] = ',';

	if (GetMarriedOn() == NULL)
	{
		description += " single";
	}
	else
	{
		description += " married on " + GetMarriedOn()->GetName() + ' ' + GetMarriedOn()->GetSurname() + ' ' + GetMarriedOn()->GetPatronymic();
	}
	if (GetWorkPlace() != "")
	{
		description += ", " + GetWorkPlace() + '.';
	}
	else
	{
		description += '.';
	}
	
	return description;
}
//Задать случайные параметры для объекта структуры Adult
void Adult::MakeRandomAdult(Adult& adult, Person& partner)
{
	string workplaces[5] =
	{
		"Programmer in Apple",
		"Team Lead in Apple",
		"SEO-manager in Google",
		"Front-end designer in Yahoo",
		"Data scientist in Yandex"
	};

	GeneretePerson(adult);

	int randomNumber = rand() % 2 + 1;

	if (randomNumber == 1)
	{
		adult.SetMarriedOn(&partner);
	}
	else if (randomNumber == 2)
	{
		adult.SetMarriedOn(NULL);
	}

	randomNumber = rand() % 102 + 18;
	adult.SetAge(randomNumber);

	randomNumber = rand() % 5;
	adult.SetWorkPlace(workplaces[randomNumber]);
}
