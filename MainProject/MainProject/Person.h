#pragma once
#include "Gender.h"
#include "Lab3Functions.h"
//����� Person
//�������� ����: _name, _surname, _patronymic, _age, _sex;
class Person
{
private:
	std::string _name;
	std::string _surname;
	std::string _patronymic;
	int _age;
	Sex _sex;

	//---���������� ������� ������---//
	//��������� ����� ���� ����������� 
	void InputName(std::string string);
	//�������� ��� ��������� ����� ���� ����������� 
	bool IsNameCorrect(std::string str);
	//-------------------------------//
public:
	Person();
	//---Get/Set---//

	//������ ���������� name_
	void SetName(std::string name);
	//���������� ���������� name_
	std::string GetName();
	//������ ���������� surname_
	void SetSurname(std::string surname);
	//���������� ���������� surname_
	std::string GetSurname();
	//������ ���������� patronymic_
	void SetPatronymic(std::string patronymic);
	//���������� �������� patronymic_
	std::string GetPatronymic();
	//������ ���������� age_
	void SetAge(int age);
	//���������� ���������� age_
	int GetAge();
	//������ ���������� sex_
	void SetSex(Sex sex);
	//���������� ���������� sex_
	Sex GetSex();
	//-------------//

	//---���������� ����������---//

	//���������
	bool operator==(Person& person);
	//��������� �����
	friend std::ostream& operator<<(std::ostream& os, Person& person);
	//---------------------------//
};