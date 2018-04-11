#pragma once
#include "Person.h"
//����� Adult
//TODO: �� ���� � ������������ � ������ ��������� ��� ����. ���� �������, ��� ���� �� �����.
//�������� ����: _name, _surname, _patronymic, _age, _sex;
//_marriedOn, _workPlace
class Adult :public Person
{
private:
	Person* _marriedOn;
	string _workPlace;
public:
	Adult();
	//---Get/Set---//

	//���������� ���������� _marriedOn
	Person* GetMarriedOn();
	//������ ���������� _marriedOn
	void SetMarriedOn(Person* person);
	//���������� ���������� _workPlace
	string GetWorkPlace();
	//������ ���������� _workPlace
	void SetWorkPlace(string workPlace);
	//������ ���������� _Age
	void SetAge(int age);
	//-------------//

	//�������� �������� ���������
	std::string GetDescription();

	//TODO: �� ������ �������� ��� ���� ������������ ��������� �������
	//������ ��������� ��������� ��� ������� ��������� Adult
	static void MakeRandomAdult(Adult& person, Person& partner);
};