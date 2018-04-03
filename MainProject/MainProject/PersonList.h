#pragma once
#include "Lab3Functions.h"
#include "ListNode.h"
//Список с данными структуры Person
class PersonList
{
private:
	ListNode * _head;	//указатель на голову списка
	int _count;			//количество элементов в списке
public:
	//конструктор класса
	PersonList();
	//получить количество элементов
	int GetCount();
	//добавить человека в список
	void Add(Person person);
	//найти человека по указанному индексу
	Person Find(int index);
	//вернуть индекс человека, если он есть в списке
	int IndexOf(Person person);
	//удалить человека из списка
	void Remove(Person person);
	//удалить человека из списка по индексу
	void RemoveAt(int index);
	//очистить список
	void Clear();
	//Вывод элементов списка
	void PrintList();
	//Вывод элементов списка с выделением персоны
	void PrintList(Person person);
};