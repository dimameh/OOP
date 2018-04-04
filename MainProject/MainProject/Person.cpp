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
	if (age >= 0 && age < 120)
	{ 
		_age = age;
	}
	else
	{
		exception incorrectAge("Incorrect person age");
		throw incorrectAge;
	}
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
//Задать переменную sex_
void Person::SetSex(string sexString)
{
	if (sexString == "male" || sexString == "Male")
	{
		_sex = Male;
	}
	else if (sexString == "female" || sexString == "Female")
	{
		_sex = Female;
	}
	else
	{
		exception incorrectSex("Incorrect person sex");
		throw incorrectSex;
	}
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
//Потоковый ввод
istream& operator>> (istream& is, Person& person)
{
	string input;
	int age;
	cin >> input;
	person.SetName(input);
	cin >> input;
	person.SetSurname(input);
	cin >> input;
	person.SetPatronymic(input);
	cin >> input;
	person.SetSex(input);
	//ввод возраста
	cin >> age;
	person.SetAge(age);
	return is;
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

//получить описание объекта
string Person::GetDescription()
{
	string description = "";
	if (GetName() != "")
	{
		description += GetName() + ' ';
	}
	if (GetSurname() != "")
	{
		description += GetSurname() + ' ';
	}
	if (GetPatronymic() != "")
	{
		description += GetPatronymic() + ' ';
	}

	description[description.length()] = ',';

	description += to_string(GetAge()) + " years old, " + (GetSex() == Male ? "male" : "female") + '.';

	return description;
}
//Задать случайные значения для объекта структуры Person
void Person::MakeRandomPerson(Person& person)
{
	GeneretePerson(person);
	person.SetAge(rand() % 120);
}
void Person::GeneretePerson(Person& person)
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
}