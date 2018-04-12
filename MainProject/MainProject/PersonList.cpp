#include "stdafx.h"
#include "PersonList.h"
#include "PersonTools.h"
using namespace std;

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
//ƒобавить запись в конец списка
void PersonList::Add(Person* person)
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
Person* PersonList::Find(int index)
{
	if (index <= 0 || index > _count)
	{
		exception indexException("Index is not in range");
		throw indexException;
	}
	ListNode* nodeIndex = _head;
	int current = 1;
	while (nodeIndex != NULL)
	{
		if (current == index)
		{
			return nodeIndex->_data;
		}
		current++;
		nodeIndex = nodeIndex->next;
	}
}
//вернуть индекс человека, если он есть в списке
int PersonList::IndexOf(Person* person)
{
	ListNode* nodeIndex = _head;
	int current = 1;
	while (nodeIndex != NULL)
	{
		if (*nodeIndex->_data == *person)
		{
			return current;
		}
		current++;
		nodeIndex = nodeIndex->next;
	}
	return -1;
}
//удалить человека из списка
void PersonList::Remove(Person* person)
{
	//если нужный элемент в начале
	if (_head->_data == person)
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
			if (nodeIndex->next->_data == person)
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
	//ѕроверка индекса
	//≈сли индекс меньше нул€ или больше количества записей в списке -> вылететь с ошибкой
	if (index <= 0 || index > _count)
	{
		exception indexExeption("The index is not in range.");
		throw indexExeption;
	}
	//≈сли список пустой -> вылететь с ошибкой
	if (_head == NULL)
	{
		exception emptyExeption("The list is empty.");
		throw emptyExeption;
	}
	//≈сли индекс €вл€етс€ последним элементом -> удал€ем узел последний с использованием указател€ _head
	if (index == _count)
	{
		//≈сли элемент единственный в списке
		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
		}
		//если элементов в списке больше одного
		else
		{
			ListNode* temp = _head;
			_head = _head->next;
			delete temp;
		}
	}
	//≈сли индекс существует и он не первый и не последний
	else
	{
		ListNode* nodeIndex = _head;
		int current = 1;
		//пока не будет выбран указатель на узел с пустым значением
		while (nodeIndex != NULL)
		{
			//если счетчик находитс€ перед искомым индексом -> произвести удаление узла
			if (current + 1 == index)
			{
				ListNode* temp = nodeIndex->next;
				nodeIndex->next = nodeIndex->next->next;
				delete temp;
			}
			nodeIndex = nodeIndex->next;
			current++;
		}
		//если прошли до конца и почему то индекс не был найден -> вылететь с ошибкой
		exception noPerson("Index error. There is no index like this.");
		throw noPerson;
	}
	_count--;
}
//ќчистить список
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
//¬ывод элементов списка
void PersonList::PrintList()
{
	if (_count <= 0)
	{
		cout << "List is empty";
	}
	ListNode* nodeIndex = _head;
	while (nodeIndex)
	{
		cout << *nodeIndex->_data;
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
	}
}
//¬ывод элементов списка с выделением персоны
void PersonList::PrintList(Person person)
{
	if (_count <= 0)
	{
		cout << "List is empty";
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int index = IndexOf(&person);
	ListNode* nodeIndex = _head;
	int count = 1;
	while (nodeIndex)
	{
		//–аскраска элементов консоли в светло-зеленый
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		if (count == index)
		{
			//–аскраска элементов консоли в голубой
			SetConsoleTextAttribute(hConsole, (WORD)(3));
		}
		cout << *nodeIndex->_data;
		//–аскраска элементов консоли в светло-зеленый
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
		count++;
	}
}
//¬ывод описани€ всех элементов списка
void PersonList::DescribeList()
{
	if(_count <= 0)
	{
		cout << "List is empty";
	}
	ListNode* nodeIndex = _head;
	while (nodeIndex)
	{
		cout << nodeIndex->_data->GetDescription() << endl;
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
	}
}