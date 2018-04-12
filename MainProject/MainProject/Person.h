#pragma once
#include "Sex.h"
#include "Lab3Functions.h"
//����� Person
//������ ���������� � ��������
class Person
{
private:
	std::string _name;
	std::string _surname;
	std::string _patronymic;
	Sex _sex;

	//---���������� ������� ������---//

	//��������� ����� ���� ����������� 
	void InputName(std::string string);
	//�������� ��� ��������� ����� ���� ����������� 
	bool IsNameCorrect(std::string str);
	//-------------------------------//

protected:
	int _age;
	static void GeneretePerson(Person& person);
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
	virtual void SetAge(int age);
	//���������� ���������� age_
	int GetAge();
	//������ ���������� sex_
	void SetSex(Sex sex);
	//������ ���������� sex_ ����� ������
	void SetSex(std::string sexString);
	//���������� ���������� sex_
	Sex GetSex();
	//-------------//

	//---���������� ����������---//

	//���������
	bool operator==(Person& person);
	//��������� ����
	friend std::istream& operator>>(std::istream& is, Person& person);
	//��������� �����
	friend std::ostream& operator<<(std::ostream& os, Person& person);
	//---------------------------//

	//�������� �������� �������
	virtual std::string GetDescription();

	//������ ��������� ��������� ��� ������� ��������� Person
	static void MakeRandomPerson(Person& person);
};