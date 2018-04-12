#include "stdafx.h"
#include "PersonTools.h"
using namespace std;
//����� ������ ������� �� �����
void Print(Person person)
{
	cout << person.GetName() << ' ' << person.GetSurname() << ' ' << person.GetPatronymic() << ' ';
	switch (person.GetSex())
	{
	case Male:
		cout << "male" << ' ';
		break;
	case Female:
		cout << "female" << ' ';
		break;
	default:
		break;
	}
	cout << person.GetAge() << endl;
}
//������ ������� � ����������
void Read(Person person)
{
	string names;
	cout << "---Fill in the form---" << endl;
	cout << "Name: ";
	cin >> names;
	person.SetName(names);
	cout << endl << "Surname: ";
	person.SetSurname(names);
	cout << endl << "Patronymic: ";
	person.SetPatronymic(names);

	cout << endl << "Sex. Enter '1' for male, '0' for female and '2' for other: ";
	int sex;
	sex = InputIntegerOnInterval(0, 2);

	person.SetSex(static_cast<Sex>(sex));

	cout << endl << "Age: ";
	person.SetAge(InputIntegerOnInterval(0, 120));
}