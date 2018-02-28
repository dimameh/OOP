#pragma once
#include "Lab3Functions.h"

struct Node
{
	Person data; // поле данных
	Node *next; // указатель на следующий элемент
	Node *prev;
	Node(Person data)
	{
		this->data = data;
		prev = next = NULL;
	}
};

void Add(Person& person, Node *&head, Node *&tail);
void Show(Node *head);
Person *Get(int index, Node *&head, Node *&tail);
void Remove(int index, Node *&head, Node *&tail);
void Insert(Person& person, int index, Node *&head, Node *&tail);
void Clear(Node *&head, Node *&tail);
Person& MakeRandomPerson();