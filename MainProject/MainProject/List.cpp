#include "stdafx.h"
#include "List.h"
using namespace std;

//конструктор
template <typename DataType>
List<DataType>::List()
{
	_head = NULL;
	_count = 0;
}
//получить количество элементов
template <typename DataType>
int List<DataType>::GetCount()
{
	return _count;
}
//ƒобавить запись в конец списка
template <typename DataType>
void List<DataType>::Add(DataType* data)
{
	if (_head == NULL)
	{
		_head = new ListNode(data);
	}
	//если в списке уже есть элементы
	else
	{
		ListNode * temp = new ListNode(data);
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
template <typename DataType>
DataType* List<DataType>::Find(int index)
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
template <typename DataType>
int List<DataType>::IndexOf(DataType* data)
{
	ListNode* nodeIndex = _head;
	int current = 1;
	while (nodeIndex != NULL)
	{
		if (nodeIndex->_data == data)
		{
			return current;
		}
		current++;
		nodeIndex = nodeIndex->next;
	}
	exception noPerson("There is no person like this");
	throw noPerson;
}
//удалить человека из списка
template <typename DataType>
void List<DataType>::Remove(DataType* data)
{
	//если нужный элемент в начале
	if (_head->_data == data)
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
			if (nodeIndex->next->_data == data)
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
template <typename DataType>
void List<DataType>::RemoveAt(int index)
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
		exception noData("Index error. There is no index like this.");
		throw noData;
	}
	_count--;
}
//ќчистить список
template <typename DataType>
void List<DataType>::Clear()
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
template <typename DataType>
void List<DataType>::PrintList()
{
	if (_count <= 0)
	{
		exception emptyList("The list is empty");
		throw emptyList;
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
template <typename DataType>
void List<DataType>::PrintList(DataType data)
{
	if (_count <= 0)
	{
		cout << "List is empty";
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int index = IndexOf(&data);
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
		cout << nodeIndex->_data;
		//–аскраска элементов консоли в светло-зеленый
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
		count++;
	}
}
//¬ывод описани€ всех элементов списка
template <typename DataType>
void List<DataType>::DescribeList()
{
	if (_count <= 0)
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