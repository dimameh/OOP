#include "stdafx.h"
#include "PersonList.h"
#include "PersonInstruments.h"
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
//Добавить запись в конец списка
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
			return nodeIndex->Data;
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
		if (nodeIndex->Data == person)
		{
			return current;
		}
		current++;
		nodeIndex = nodeIndex->next;
	}
	//TODO: Если Person отсутствует в списке, то такие функции обычно возвращают -1, а не выбрасывают exception
	exception noPerson("There is no person like this");
	throw noPerson;
}
//удалить человека из списка
void PersonList::Remove(Person* person)
{
	//если нужный элемент в начале
	if (_head->Data == person)
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
			if (nodeIndex->next->Data == person)
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
	//Проверка индекса
	//Если индекс меньше нуля или больше количества записей в списке -> вылететь с ошибкой
	if (index <= 0 || index > _count)
	{
		exception indexExeption("The index is not in range.");
		throw indexExeption;
	}
	//Если список пустой -> вылететь с ошибкой
	if (_head == NULL)
	{
		exception emptyExeption("The list is empty.");
		throw emptyExeption;
	}
	//Если индекс является последним элементом -> удаляем узел последний с использованием указателя _head
	if (index == _count)
	{
		//Если элемент единственный в списке
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
	//Если индекс существует и он не первый и не последний
	else
	{
		ListNode* nodeIndex = _head;
		int current = 1;
		//пока не будет выбран указатель на узел с пустым значением
		while (nodeIndex != NULL)
		{
			//если счетчик находится перед искомым индексом -> произвести удаление узла
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
		cout << *nodeIndex->Data;
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

	int index = IndexOf(&person);
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
		cout << nodeIndex->Data;
		//Раскраска элементов консоли в светло-зеленый
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
		count++;
	}
}
//Вывод описания всех элементов списка
void PersonList::DescribeList()
{
	if(_count <= 0)
	{
		//TODO: Почему exception? Разве пустой список это ошибка? Свежесозданный, например, список не может быть пустым?
		exception emptyList("The list is empty");
		throw emptyList;
	}
	ListNode* nodeIndex = _head;
	while (nodeIndex)
	{
		cout << nodeIndex->Data->GetDescription() << endl;
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
	}
}