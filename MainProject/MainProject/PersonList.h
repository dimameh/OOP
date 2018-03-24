#pragma once
#include "Lab3Functions.h"
#include "ListNode.h"
//Список с данными структуры Person
struct PersonList
{
	ListNode* head = NULL;
	ListNode* tail = NULL;
	int length = 0;
};

//Добавить запись в конец списка
void Add(Person& person, PersonList *&list);
//Вывод содержимого списка
void Show(PersonList *&list);
//Получение данных узла по его индексу
Person *Get(int index, PersonList *&list);
//Удаление узла по индексу
void Remove(int index, PersonList *&list);
//Добавить запись на выбранный индекс
void Insert(Person& person, int index, PersonList *&list);
//Очистить список
void Clear(PersonList *&list);
//Задать случайные параметры для объекта структуры Person
Person& MakeRandomPerson();
//Возвращает количество элементов списка
int GetCount(PersonList *&list);