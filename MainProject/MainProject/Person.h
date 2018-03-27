#pragma once
#include "Gender.h"
#include "Lab3Functions.h"
//����� Person
//�������� ����: _name, _surname, _patronymic, _age, _sex;
class Person
{
private:
	char _name[20];
	char _surname[20];
	char _patronymic[30];
	int _age;
	Sex _sex;
public:
	Person();
	//---Get/Set---//
	//������ ���������� name_
	void SetName(char name[20]);
	//���������� ���������� name_
	char* GetName();
	//������ ���������� surname_
	void SetSurname(char surname[20]);
	//���������� ���������� surname_
	char* GetSurname();
	//������ ���������� patronymic_
	void SetPatronymic(char patronymic[30]);
	//���������� �������� patronymic_
	char* GetPatronymic();
	//������ ���������� age_
	void SetAge(int age);
	//���������� ���������� age_
	int GetAge();
	//������ ���������� sex_
	void SetSex(Sex sex);
	//���������� ���������� sex_
	Sex GetSex();
	//-------------//
	//������ ��������� ��������� ��� ������� ��������� Person
	void MakeRandomPerson();
	//������� � ������� ���������� ������� ���������
	void Print();
	//������ ������� � ����������
	void Read();
	//����� ������ ������� �� �����
	void Show();
};