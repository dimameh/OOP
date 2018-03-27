#include "stdafx.h"
#include "Person.h"

//---Get/Set---//
//������ ���������� name_
void Person::SetName(char name[20])
{
	strcpy(_name, name);
}
//���������� �������� name
char* Person::GetName() 
{
	return _name;
}
//������ ���������� surname_
void Person::SetSurname(char surname[20])
{
	strcpy(_surname, surname);
}
//���������� �������� surname_
char* Person::GetSurname()
{
	return _surname;
}
//������ ���������� patronymic_
void Person::SetPatronymic(char patronymic[30])
{
	strcpy(_patronymic, patronymic);
}
//���������� �������� patronymic
char* Person::GetPatronymic()
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
Person::Person()
{
	strcpy(_name, "No Name");
	strcpy(_surname, "No Surname");
	strcpy(_patronymic, "No Patronymic");
	_age = -1;
	_sex = Other;
}
//������ ��������� �������� ��� ������� ��������� Person
void Person::MakeRandomPerson()
{
	char names[15][20] =
	{
		"Sophia",
		"Alvina" ,
		"Arina" ,
		"Amira" ,
		"Alice" ,
		"Safine" ,
		"Liza" ,
		"Leonard" ,
		"Condratiy" ,
		"Felix" ,
		"Victor" ,
		"Rodion" ,
		"Daniil" ,
		"August" ,
		"Antuan"
	};
	char surnames[15][40] =
	{
		"Cvetkova",
		"Cononova" ,
		"Belousva" ,
		"Voronova" ,
		"Emelyanova" ,
		"Bespalova" ,
		"Novikova" ,
		"Tretyakov" ,
		"Miheev" ,
		"Terentyev" ,
		"Pavlov" ,
		"Maslov" ,
		"Solovyov" ,
		"Bobylyov" ,
		"Grobovozov"
	};
	char patronymics[15][25] =
	{
		"Ivanovna",
		"Antoninovna" ,
		"Serpantinovna" ,
		"Petrovna" ,
		"Maximovna" ,
		"Evseevna" ,
		"Artemovna" ,
		"Agafonovich" ,
		"Mihailovich" ,
		"Germanovich" ,
		"Vladimirovich" ,
		"Aristarkhovich" ,
		"Glebovich" ,
		"Melsovich" ,
		"Borisovich"
	};
	const int maleMinIndex = 8, maleIndexAmount = 7, femaleMaxIndex = 7, indexAmount = 15;
	SetSex (static_cast<Sex>(rand() % 3));

	if (GetSex() == Male)
	{
		int randomNumber = rand() % (maleMinIndex)+maleIndexAmount;
		SetName(names[randomNumber]);

		randomNumber = rand() % (maleMinIndex)+maleIndexAmount;
		SetSurname(surnames[randomNumber]);

		randomNumber = rand() % (maleMinIndex)+maleIndexAmount;
		SetPatronymic (patronymics[randomNumber]);
	}
	else
	{
		if (GetSex() == Female)
		{
			int randomNumber = rand() % femaleMaxIndex;
			SetName(names[randomNumber]);

			randomNumber = rand() % femaleMaxIndex;
			SetSurname(surnames[randomNumber]);

			randomNumber = rand() % femaleMaxIndex;
			SetPatronymic(patronymics[randomNumber]);
		}
		else
		{
			int randomNumber = rand() % indexAmount;
			SetName(names[randomNumber]);

			randomNumber = rand() % indexAmount;
			SetSurname(surnames[randomNumber]);

			randomNumber = rand() % indexAmount;
			SetPatronymic(patronymics[randomNumber]);
		}
	}

	SetAge(rand() % 120);
}
//����� ������ ������� �� �����
void Person::Print()
{
	cout << "Name: " << _name << endl;
	cout << "Surname: " << _surname << endl;
	cout << "Patronymic: " << _patronymic << endl;
	switch (_sex)
	{
	case Male:
		cout << "Sex: " << "male";
		break;
	case Female:
		cout << "Sex: " << "female";
		break;
	case Other:
		cout << "Sex: " << "other";
		break;

	default:
		break;
	}
	cout << endl << "Age: " << _age << endl;
}
//������ ������� � ����������
void Person::Read()
{
	cout << "---Fill in the form---" << endl;
	cout << "Name: ";
	InputName(_name);
	cout << endl << "Surname: ";
	InputName(_surname);
	cout << endl << "Patronymic: ";
	InputName(_patronymic);

	cout << endl << "Sex. Enter '1' for male, '0' for female and '2' for other: ";
	int sex;
	sex = InputIntegerOnInterval(0, 2);

	_sex = static_cast<Sex>(sex);

	cout << endl << "Age: ";
	_age = InputIntegerOnInterval(0, 120);
}