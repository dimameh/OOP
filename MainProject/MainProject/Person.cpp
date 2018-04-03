#include "stdafx.h"
#include "Person.h"

//��������� ����� ���� ����������� 
void Person::InputName(string string)
{
	bool isCorrect = false;
	while (!isCorrect)
	{
		cin >> string;
		isCorrect = IsNameCorrect(string);
	}
}
//�������� ��� ��������� ����� ���� ����������� 
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
//�����������
Person::Person()
{
	SetName("");
	SetSurname("");
	SetPatronymic("");
	_age = 0;
	_sex = Male;
}
//---Get/Set---//

//������ ���������� name_
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
//���������� �������� name
string Person::GetName()
{
	return _name;
}
//������ ���������� surname_
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
//���������� �������� surname_
string Person::GetSurname()
{
	return _surname;
}
//������ ���������� patronymic_
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
//���������� �������� patronymic
string Person::GetPatronymic()
{
	return _patronymic;
}
//������ ���������� age_
void Person::SetAge(int age)
{
	_age = age;
}
//���������� �������� age_
int Person::GetAge()
{
	return _age;
}
//������ ���������� sex_
void Person::SetSex(Sex sex)
{
	_sex = sex;
}
//���������� �������� sex_
Sex Person::GetSex()
{
	return _sex;
}
//-------------//

//---���������� ����������---//

//���������
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
//��������� �����
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