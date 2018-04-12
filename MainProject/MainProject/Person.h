#pragma once
#include "Sex.h"
#include "Lab3Functions.h"
//Класс Person
//Хранит информацию о человеке
class Person
{
private:
	std::string _name;
	std::string _surname;
	std::string _patronymic;
	Sex _sex;

	//---Внутренние функции класса---//

	//Валидация ввода имен собственных 
	void InputName(std::string string);
	//Проверка для валидации ввода имен собственных 
	bool IsNameCorrect(std::string str);
	//-------------------------------//

protected:
	int _age;
	static void GeneretePerson(Person& person);
public:
	Person();
	//---Get/Set---//

	//Задать переменную name_
	void SetName(std::string name);
	//Возвращает переменную name_
	std::string GetName();
	//Задать переменную surname_
	void SetSurname(std::string surname);
	//Возвращает переменную surname_
	std::string GetSurname();
	//Задать переменную patronymic_
	void SetPatronymic(std::string patronymic);
	//Возвращает значение patronymic_
	std::string GetPatronymic();
	//Задать переменную age_
	virtual void SetAge(int age);
	//Возвращает переменную age_
	int GetAge();
	//Задать переменную sex_
	void SetSex(Sex sex);
	//Задать переменную sex_ через строку
	void SetSex(std::string sexString);
	//Возвращает переменную sex_
	Sex GetSex();
	//-------------//

	//---Перегрузки операторов---//

	//Сравнение
	bool operator==(Person& person);
	//Потоковый ввод
	friend std::istream& operator>>(std::istream& is, Person& person);
	//Потоковый вывод
	friend std::ostream& operator<<(std::ostream& os, Person& person);
	//---------------------------//

	//получить описание объекта
	virtual std::string GetDescription();

	//Задать случайные параметры для объекта структуры Person
	static void MakeRandomPerson(Person& person);
};