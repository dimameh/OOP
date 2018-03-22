#pragma once
#include "Lab3Functions.h"
//TODO: ���� �������� ������� PersonList, lab4Functions - ������ ��������
//TODO: ����������� � ���� ������
struct Node
{
	Person data; // ���� ������
	Node *next; // ��������� �� ��������� �������
	Node *prev;
	Node(Person data)
	{
		this->data = data;
		prev = next = NULL;
	}
};

//TODO: ����������� � ������� � ������������ ����� ����
//TODO: ������������ ���������� ������!
// ������ ���� ��� ���� ��������� PersonList, ������� ������ � ���� ��������� �� ������ � ����� ������.
// ������� ������ �������� � PersonList, � ��� Node ������ ����� �� ������ - �������� �������� ����������
void Add(Person& person, Node *&head, Node *&tail);
void Show(Node *head);
//TODO: ����� ���������� ����� � ���� �����?
Person *Get(int index, Node *&head, Node *&tail);
void Remove(int index, Node *&head, Node *&tail);
void Insert(Person& person, int index, Node *&head, Node *&tail);
void Clear(Node *&head, Node *&tail);
Person& MakeRandomPerson();
//TODO: ��� ����� ������� GetCount(), ������������ ���������� ��������� ������.
// � ����� �������� ���� ������������ ���� �� ������ �������