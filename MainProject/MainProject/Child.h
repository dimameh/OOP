#pragma once
#include "Person.h"
//����� Adult
//�������� ����: _name, _surname, _patronymic, _age, _sex;
//_mother, _father, _school
class Child :public Person
{
private:
	Person* _mother;
	Person* _father;
	string _school;
public:
	Child();
	//---Get/Set---//

	//���������� ���������� _mother
	Person* GetMother();
	//������ ���������� _mother
	void SetMother(Person* person);
	//���������� ���������� _father
	Person* GetFather();
	//������ ���������� _father
	void SetFather(Person* person);
	//���������� ���������� _school
	string GetSchool();
	//������ ���������� _school
	void SetSchool(string person);
	//������ ���������� _Age
	void SetAge(int age);
	//-------------//

	//�������� �������� �������
	std::string GetDescription();

	//������ ��������� ��������� ��� ������� ��������� Child
	static void MakeRandomChild(Child& person, Person& father, Person& mother);
};

