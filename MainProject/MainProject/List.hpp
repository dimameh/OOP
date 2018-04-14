#pragma once
//—писок с данными структуры Person
using namespace std;
template <typename DataType>
class List
{
private:
	struct ListNode
	{
		DataType _data;			// поле данных
		ListNode* _next;				// указатель на следующий элемент
		ListNode(DataType data)	// конструктор
		{
			_data = data;
			_next = NULL;
		}
	} *_head;	//указатель на голову списка
	int _count;			//количество элементов в списке
public:
	//конструктор
	List()
	{
		_head = NULL;
		_count = 0;
	}
	//получить количество элементов
	int GetCount()
	{
		return _count;
	}
	//ƒобавить запись в конец списка
	void Add(DataType data)
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
			while (nodeIndex->_next)
			{
				nodeIndex = nodeIndex->_next;
			}
			nodeIndex->_next = temp;
		}
		_count++;
	}
	//ƒобавить запись в конец списка
	void AddOnPosition(DataType data, int index)
	{
		ListNode * nodeIndex = _head;
		int count = 0;
		while (nodeIndex != NULL)
		{
			if (count == index - 2)
			{
				ListNode * newData = new ListNode(data);
				newData->_next = nodeIndex->_next;
				nodeIndex->_next = newData;
			}
			count++;
			nodeIndex = nodeIndex->_next;
		}
		_count++;
	}
	//найти человека по указанному индексу
	DataType& Find(int index)
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
			nodeIndex = nodeIndex->_next;
		}
	}
	//вернуть индекс человека, если он есть в списке
	int IndexOf(DataType* data)
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
			nodeIndex = nodeIndex->_next;
		}
		exception noPerson("There is no person like this");
		throw noPerson;
	}
	//удалить человека из списка
	void Remove(DataType* data)
	{
		//если нужный элемент в начале
		if (_head->_data == data)
		{
			if (_head->_next == NULL)
			{
				delete _head;
				_head = NULL;
			}
			else
			{
				ListNode* temp = _head;
				_head = _head->_next;
				delete temp;
			}
		}
		else
		{
			ListNode* nodeIndex = _head;
			while (nodeIndex->_next != NULL)
			{
				if (nodeIndex->_next->_data == data)
				{
					ListNode* temp = nodeIndex->next;
					nodeIndex->next = nodeIndex->next->next;
					delete temp;
					break;
				}
				nodeIndex = nodeIndex->_next;
			}
		}
		_count--;
	}
	//удалить человека из списка по индексу
	void RemoveAt(int index)
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
			if (_head->_next == NULL)
			{
				delete _head;
				_head = NULL;
			}
			//если элементов в списке больше одного
			else
			{
				ListNode* temp = _head;
				_head = _head->_next;
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
					ListNode* temp = nodeIndex->_next;
					nodeIndex->_next = nodeIndex->_next->_next;
					delete temp;
					break;
				}
				nodeIndex = nodeIndex->_next;
				current++;
			}
		}
		_count--;
	}
	//ќчистить список
	void Clear()
	{
		ListNode* nodeIndex = _head;
		while (nodeIndex != NULL)
		{
			ListNode* temp = nodeIndex->_next;
			nodeIndex->_next = nodeIndex->_next->_next;
			delete temp;
			nodeIndex = nodeIndex->_next;
		}
	}
};