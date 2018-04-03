#include "stdafx.h"
#include "Person.h"

//Валидация ввода имен собственных 
void Person::InputName(string string)
{
	bool isCorrect = false;
	while (!isCorrect)
	{
		cin >> string;
		isCorrect = IsNameCorrect(string);
	}
}
//Проверка для валидации ввода имен собственных 
bool Person::IsNameCorrect(string str)
{

	if (str[0] == '-' || str[str.length()] == '-')
	{
		cout << "ERROR: Invalid input string. Please re-enter correctly: ";
		cin.clear();
		cin.ignore(LONG_MAX, '\n');
		return false;
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || ((str[i] == '-') && (str[i + 1] != '-'))))
		{
			cout << "ERROR: Invalid input string. Please re-enter correctly: ";
			cin.clear();
			cin.ignore(LONG_MAX, '\n');
			return false;
		}
	}

	if (str[0] >= 'a' && str[0] <= 'z')
	{
		cout << "ERROR: Invalid input string. Please re-enter correctly: ";
		cin.clear();
		cin.ignore(LONG_MAX, '\n');
		return false;
	}

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			cout << "ERROR: Invalid input string. Please re-enter correctly: ";
			cin.clear();
			cin.ignore(LONG_MAX, '\n');
			return false;
		}
	}
	return true;
}
//Конструктор
Person::Person()
{
	SetName("");
	SetSurname("");
	SetPatronymic("");
	_age = 0;
	_sex = Male;
}
//---Get/Set---//

//Задать переменную name_
void Person::SetName(string name)
{
	if (IsNameCorrect(name))
	{
		_name = name;
	}
	else
	{
		exception incorrectName("Incorrect person name");
		throw incorrectName;
	}
}
//Возвращает значение name
string Person::GetName()
{
	return _name;
}
//Задать переменную surname_
void Person::SetSurname(string surname)
{
	if (IsNameCorrect(surname))
	{
		_surname = surname;
	}
	else
	{
		exception incorrectName("Incorrect person surname");
		throw incorrectName;
	}
}
//Возвращает значение surname_
string Person::GetSurname()
{
	return _surname;
}
//Задать переменную patronymic_
void Person::SetPatronymic(string patronymic)
{
	if (IsNameCorrect(patronymic))
	{
		_patronymic = patronymic;
	}
	else
	{
		exception incorrectName("Incorrect person patronymic");
		throw incorrectName;
	}
}
//Возвращает значение patronymic
string Person::GetPatronymic()
{
	return _patronymic;
}
//Задать переменную age_
void Person::SetAge(int age)
{
	_age = age;
}
//Возвращает значение age_
int Person::GetAge()
{
	return _age;
}
//Задать переменную sex_
void Person::SetSex(Sex sex)
{
	_sex = sex;
}
//Возвращает значение sex_
Sex Person::GetSex()
{
	return _sex;
}
//-------------//

//---Перегрузки операторов---//

//Сравнение
bool Person::operator==(Person& person)
{
	if (GetName() != person.GetName())
	{
		return false;
	}
	if (GetSurname() != person.GetSurname())
	{
		return false;
	}
	if (GetPatronymic() != person.GetPatronymic())
	{
		return false;
	}
	if (GetAge() != person.GetAge())
	{
		return false;
	}
	if (GetSex() != person.GetSex())
	{
		return false;
	}
	return true;
}
//Потоковый вывод
ostream& operator<<(ostream& os, Person& person)
{
	os << person.GetName() << ' ' << person.GetSurname() << ' ' << person.GetPatronymic() << ' ';
	switch (person.GetSex())
	{
	case Male:
		os << "male" << ' ';
		break;
	case Female:
		os << "female" << ' ';
		break;
	default:
		break;
	}
	os << person.GetAge() << endl;
	return os;
}
//---------------------------//