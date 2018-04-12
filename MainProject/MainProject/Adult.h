#pragma once
#include "Person.h"
//����� Adult
//�������� ���������� � ��������
class Adult :public Person
{
private:
	Person* _marriedOn;
	string _workPlace;
public:
	Adult();
	//---Get/Set---//

	//���������� ���������� �_�����
	Person* GetMarriedOn();
	//������ ���������� �_�����
	void SetMarriedOn(Person* person);
	//���������� ���������� ������
	string GetWorkPlace();
	//������ ���������� ������
	void SetWorkPlace(string workPlace);
	//������ ���������� �������
	void SetAge(int age);
	//-------------//

	//�������� �������� ���������
	std::string GetDescription();

	//������ ��������� ��������� ��� ������� ��������� Adult
	static void MakeRandomAdult(Adult& person, Person& partner);
};