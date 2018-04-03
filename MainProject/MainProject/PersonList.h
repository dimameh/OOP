#pragma once
#include "Lab3Functions.h"
#include "ListNode.h"
//������ � ������� ��������� Person
class PersonList
{
private:
	ListNode * _head;	//��������� �� ������ ������
	int _count;			//���������� ��������� � ������
public:
	//����������� ������
	PersonList();
	//�������� ���������� ���������
	int GetCount();
	//�������� �������� � ������
	void Add(Person person);
	//����� �������� �� ���������� �������
	Person Find(int index);
	//������� ������ ��������, ���� �� ���� � ������
	int IndexOf(Person person);
	//������� �������� �� ������
	void Remove(Person person);
	//������� �������� �� ������ �� �������
	void RemoveAt(int index);
	//�������� ������
	void Clear();
	//����� ��������� ������
	void PrintList();
	//����� ��������� ������ � ���������� �������
	void PrintList(Person person);
};