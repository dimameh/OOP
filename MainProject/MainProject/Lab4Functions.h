#pragma once
#include "Lab3Functions.h"
//TODO: Файл логичнее назвать PersonList, lab4Functions - плохое название
//TODO: Комментарий к типу данных
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

//TODO: Комментарий к функции в заголовочном файле тоже
//TODO: Неправильная реализация списка!
// Должна быть еще одна структура PersonList, которая хранит в себе указатели на голову и хвост списка.
// Функции должны работать с PersonList, а про Node ничего знать не должны - нарушает сокрытие реализации
void Add(Person& person, Node *&head, Node *&tail);
void Show(Node *head);
//TODO: Зачем передавать хвост в этот метод?
Person *Get(int index, Node *&head, Node *&tail);
void Remove(int index, Node *&head, Node *&tail);
void Insert(Person& person, int index, Node *&head, Node *&tail);
void Clear(Node *&head, Node *&tail);
Person& MakeRandomPerson();
//TODO: Еще нужна функция GetCount(), возвращающая количество элементов списка.
// С такой функцией даже лабораторную было бы делать удобнее