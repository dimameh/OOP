#include "stdafx.h"
#include "PersonList.h"
using namespace std;

//Сравнение полей двух структур Person
bool IsSamePersons(Person person1, Person person2)
{
	if (strcmp(person1.GetName(), person2.GetName()) != 0)
	{ 
		return false;
	}
	if (strcmp(person1.GetSurname(), person2.GetSurname()) != 0)
	{
		return false;
	}
	if (strcmp(person1.GetPatronymic(), person2.GetPatronymic()) != 0)
	{
		return false;
	}
	if (person1.GetAge() != person2.GetAge())
	{
		return false;
	}
	if (person1.GetSex() != person2.GetSex())
	{
		return false;
	}
	return true;
}

//конструктор
PersonList::PersonList()
{
	_head = NULL;
	_count = 0;
}
//получить количество элементов
int PersonList::GetCount()
{
	return _count;
}
//Добавить запись в конец списка
void PersonList::Add(Person person)
{
	if (_head == NULL)
	{
		_head = new ListNode(person);
	}
	//если в списке уже есть элементы
	else
	{
		ListNode * temp = new ListNode(person);
		ListNode* nodeIndex = _head;
		while (nodeIndex->next)
		{
			nodeIndex = nodeIndex->next;
		}
		nodeIndex->next = temp;
	}
	_count++;
}
//найти человека по указанному индексу
Person PersonList::Find(int index)
{
	if (index <= 0 || index > _count)
	{
		exception indexException("Index is not in range");
		throw indexException;
	}
	ListNode* nodeIndex = _head;
	int count = 1;
	while (nodeIndex != NULL)
	{
		if (count == index)
		{
			return nodeIndex->Data;
		}
		count++;
		nodeIndex = nodeIndex->next;
	}
}
//вернуть индекс человека, если он есть в списке
int PersonList::IndexOf(Person person)
{
	ListNode* nodeIndex = _head;
	int count=1;
	while (nodeIndex != NULL)
	{
		if (IsSamePersons(nodeIndex->Data, person))
		{
			return count;
		}
		count++;
		nodeIndex = nodeIndex->next;
	}
	exception noPerson("There is no person like this");
	throw noPerson;
}
//удалить человека из списка
void PersonList::Remove(Person person)
{
	//если нужный элемент в начале
	if (IsSamePersons(_head->Data, person))
	{
		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
		}
		else
		{
			ListNode* temp = _head;
			_head = _head->next;
			delete temp;
		}
	}
	else
	{
		ListNode* nodeIndex = _head;
		while (nodeIndex->next != NULL)
		{
			if (IsSamePersons(nodeIndex->next->Data, person))
			{
				ListNode* temp = nodeIndex->next;
				nodeIndex->next = nodeIndex->next->next;
				delete temp;
				break;
			}
			nodeIndex = nodeIndex->next;
		}
	}
	_count--;
}
//удалить человека из списка по индексу
void PersonList::RemoveAt(int index)
{
	//проверка индекса
	if (index <= 0 || index > _count)
	{
		exception indexExeption("The index is not in range.");
		throw indexExeption;
	}
	//если список пустой
	if (_head == NULL)
	{
		exception emptyExeption("The list is empty.");
		throw emptyExeption;
	}
	if (index == _count)
	{
		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
		}
		else
		{
			ListNode* temp = _head;
			_head = _head->next;
			delete temp;
		}
	}
	else
	{
		ListNode* nodeIndex = _head;
		int indexCount = 1;
		while (nodeIndex != NULL)
		{
			if (indexCount+1 == index)
			{
				ListNode* temp = nodeIndex->next;
				nodeIndex->next = nodeIndex->next->next;
				delete temp;
			}
			nodeIndex = nodeIndex->next;
			indexCount++;
		}
		exception noPerson("There is no person like this");
		throw noPerson;
	}
	_count--;
}
//Очистить список
void PersonList::Clear()
{
	ListNode* nodeIndex = _head;
	while (nodeIndex != NULL)
	{
		ListNode* temp = nodeIndex->next;
		nodeIndex->next = nodeIndex->next->next;
		delete temp;
		nodeIndex = nodeIndex->next;
	}
}
//Вывод элементов списка
void PersonList::PrintList()
{
	if (_count <= 0)
	{
		exception emptyList("The list is empty");
		throw emptyList;
	}
	ListNode* nodeIndex = _head;
	while (nodeIndex)
	{
		nodeIndex->Data.Print();
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
	}
}
//Вывод элементов списка с выделением персоны
void PersonList::PrintList(Person person)
{
	if (_count <= 0)
	{
		exception emptyList("The list is empty");
		throw emptyList;
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int index = IndexOf(person);
	ListNode* nodeIndex = _head;
	int count = 1;
	while (nodeIndex)
	{
		//Раскраска элементов консоли в светло-зеленый
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		if (count == index)
		{
			//Раскраска элементов консоли в голубой
			SetConsoleTextAttribute(hConsole, (WORD)(3));
		}
		nodeIndex->Data.Print();
		//Раскраска элементов консоли в светло-зеленый
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
		count++;
	}
}