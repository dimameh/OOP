#pragma once
#include "Lab3Functions.h"
#include "ListNode.h"
//—писок с данными структуры Person
class PersonList
{
private:
	struct ListNode
	{
		Person* Data;			// поле данных
		ListNode *next;			// указатель на следующий элемент
		ListNode(Person* data)	// конструктор
		{
			Data = data;
			next = NULL;
		}
	} * _head;	//указатель на голову списка
	int _count;			//количество элементов в списке
public:
	//конструктор класса
	PersonList();
	//получить количество элементов
	int GetCount();
	//добавить человека в список
	void Add(Person* person);
	//найти человека по указанному индексу
	Person* Find(int index);
	//вернуть индекс человека, если он есть в списке
	int IndexOf(Person* person);
	//удалить человека из списка
	void Remove(Person* person);
	//удалить человека из списка по индексу
	void RemoveAt(int index);
	//очистить список
	void Clear();
	//¬ывод элементов списка
	void PrintList();
	//¬ывод элементов списка с выделением персоны
	void PrintList(Person person);
	//¬ывод описани€ всех элементов списка
	void DescribeList();
};