#include "stdafx.h"
#include "PersonInstruments.h"
using namespace std;
//Задать случайные значения для объекта структуры Person
void MakeRandomPerson(Person& person)
{
	string femaleNames[7] =
	{
		"Sophia",
		"Alvina" ,
		"Arina" ,
		"Amira" ,
		"Alice" ,
		"Safine" ,
		"Liza"
	};
	string femaleSurnames[7] =
	{
		"Cvetkova",
		"Cononova" ,
		"Belousva" ,
		"Voronova" ,
		"Emelyanova" ,
		"Bespalova" ,
		"Novikova"
	};
	string femalePatronymics[7] =
	{
		"Ivanovna",
		"Antoninovna" ,
		"Serpantinovna" ,
		"Petrovna" ,
		"Maximovna" ,
		"Evseevna" ,
		"Artemovna"
	};
	string maleNames[8] =
	{
		"Leonard" ,
		"Condratiy" ,
		"Felix" ,
		"Victor" ,
		"Rodion" ,
		"Daniil" ,
		"August" ,
		"Antuan"
	};
	string maleSurnames[8] =
	{
		"Tretyakov" ,
		"Miheev" ,
		"Terentyev" ,
		"Pavlov" ,
		"Maslov" ,
		"Solovyov" ,
		"Bobylyov" ,
		"Grobovozov"
	};
	string malePatronymics[8] =
	{
		"Agafonovich" ,
		"Mihailovich" ,
		"Germanovich" ,
		"Vladimirovich" ,
		"Aristarkhovich" ,
		"Glebovich" ,
		"Melsovich" ,
		"Borisovich"
	};
	person.SetSex(static_cast<Sex>(rand() % 2));

	if (person.GetSex() == Male)
	{
		int randomNumber = rand() % 7;
		person.SetName(maleNames[randomNumber]);

		randomNumber = rand() % 7;
		person.SetSurname(maleSurnames[randomNumber]);

		randomNumber = rand() % 7;
		person.SetPatronymic(malePatronymics[randomNumber]);
	}
	//TODO: дублируется код с предыдущим if. Подумай, как можно избавиться от дублирования
	else if (person.GetSex() == Female)
	{
		int randomNumber = rand() % 6;
		person.SetName(femaleNames[randomNumber]);

		randomNumber = rand() % 6;
		person.SetSurname(femaleSurnames[randomNumber]);

		randomNumber = rand() % 6;
		person.SetPatronymic(femalePatronymics[randomNumber]);
	}
	person.SetAge(rand() % 120);
}
//Вывод данных персоны на экран
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
//Чтение персоны с клавиатуры
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