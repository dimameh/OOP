#pragma once
#include "Person.h"
//����� Child
//�������� ���������� � �������
class Child :public Person
{
private:
	Person* _mother;
	Person* _father;
	string _school;
public:
	Child();
	//---Get/Set---//

	//���������� ���������� ����
	Person* GetMother();
	//������ ���������� ����
	void SetMother(Person* person);
	//���������� ���������� ����
	Person* GetFather();
	//������ ���������� ����
	void SetFather(Person* person);
	//���������� ���������� �����
	string GetSchool();
	//������ ���������� �����
	void SetSchool(string person);
	//������ ���������� �������
	void SetAge(int age);
	//-------------//

	//�������� �������� �������
	std::string GetDescription();

	//������ ��������� ��������� ��� ������� ��������� Child
	static void MakeRandomChild(Child& person, Person& father, Person& mother);
};

