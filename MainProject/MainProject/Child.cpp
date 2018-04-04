#include "stdafx.h"
#include "Child.h"

Child::Child()
{
	SetMother(NULL);
	SetFather(NULL);
	SetSchool("");
	Person();
}
//---Get/Set---//

//���������� ���������� _mother
Person* Child::GetMother()
{
	return _mother;
}
//������ ���������� _mother
void Child::SetMother(Person* person)
{
	_mother = person;
}
//���������� ���������� _father
Person* Child::GetFather()
{
	return _father;
}
//������ ���������� _father
void Child::SetFather(Person* person)
{
	_father = person;
}
//���������� ���������� _school
string Child::GetSchool()
{
	return _school;
}
//������ ���������� _school
void Child::SetSchool(string school)
{
	_school = school;
}
//������ ���������� _Age
void Child::SetAge(int age)
{
	if (age >= 0 && age < 18)
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

//�������� �������� �������
string Child::GetDescription()
{
	string description = Person::GetDescription();

	description[description.length()] = '.';

	//���� ������� ��� ��������
	if (GetMother() != NULL && GetFather() != NULL)
	{
		description += " Parents are " + GetMother()->GetName() + ' ' +GetMother()->GetSurname() + ' ' + GetMother()->GetPatronymic() + " and " + GetFather()->GetName() + ' ' + GetFather()->GetSurname() + ' ' + GetFather()->GetPatronymic() + ". School: " + GetSchool();
	}
	//���� ������ ������ ����
	else if (GetMother() == NULL && GetFather() != NULL)
	{
		description += " Father are " + GetFather()->GetName() + ' ' + GetFather()->GetSurname() + ' ' + GetFather()->GetPatronymic() + ". School: " + GetSchool();
	}
	//���� ������� ������ ����
	else if (GetMother() != NULL && GetFather() == NULL)
	{
		description += " Mother are " + GetMother()->GetName() + ' ' + GetMother()->GetSurname() + ' ' + GetMother()->GetPatronymic() + ". School: " + GetSchool();
	}
	//���� �� ������ �� ���� �� ���������
	else if (GetMother() == NULL && GetFather() == NULL)
	{
		description += " Parents are not specified. School: " + GetSchool();
	}
	return description;
}
//������ ��������� ��������� ��� ������� ��������� Child
void Child::MakeRandomChild(Child& child, Person& father, Person& mother)
{
	string schools[5] =
	{
		"Miras international school",
		"School No.60",
		"School No.12",
		"School No.402",
		"Lyceum \"Stolichny\""
	};
	GeneretePerson(child);

	int randomNumber = rand() % 4 + 1;

	if (randomNumber == 1)
	{
		child.SetFather(NULL);
		child.SetMother(NULL);
	}
	else if (randomNumber == 2)
	{
		child.SetFather(&father);
		child.SetMother(NULL);
	}
	else if (randomNumber == 3)
	{
		child.SetFather(NULL);
		child.SetMother(&mother);
	}
	else if (randomNumber == 4)
	{
		child.SetFather(&father);
		child.SetMother(&mother);
	}

	randomNumber = rand() % 17;
	child.SetAge(randomNumber);

	randomNumber = rand() % 5;
	child.SetSchool(schools[randomNumber]);
}