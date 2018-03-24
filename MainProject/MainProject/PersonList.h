#pragma once
#include "Lab3Functions.h"
#include "ListNode.h"
//������ � ������� ��������� Person
struct PersonList
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
	int length = 0;
};

//�������� ������ � ����� ������
void Add(Person& person, PersonList *&list);
//����� ����������� ������
void Show(PersonList *&list);
//��������� ������ ���� �� ��� �������
Person *Get(int index, PersonList *&list);
//�������� ���� �� �������
void Remove(int index, PersonList *&list);
//�������� ������ �� ��������� ������
void Insert(Person& person, int index, PersonList *&list);
//�������� ������
void Clear(PersonList *&list);
//������ ��������� ��������� ��� ������� ��������� Person
Person& MakeRandomPerson();
//���������� ���������� ��������� ������
int GetCount(PersonList *&list);