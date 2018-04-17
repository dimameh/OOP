#pragma once
//Список с данными структуры Person
//TODO: Не надо использовать hpp для расширения файла. Должно быть единообразно. Переименовать в h
//TODO: Реализацию вынести в cpp-файл
using namespace std;
template <typename DataType>
class List
{
private:
	struct ListNode
	{
		//TODO: неправильное именование открытого поля
		//TODO: ЕЩЕ РАЗ - элементы списка должны храниться по указателю
		// Если хранить по значению, то: 
		// - 1) объекты при помещении в список будут копироваться
		// - 2) нельзя хранить в списке динамически созданные объекты
		DataType _data;			// поле данных
		//TODO: неправильное именование открытого поля
		ListNode* _next;				// указатель на следующий элемент
		ListNode(DataType data)	// конструктор
		{
			_data = data;
			_next = NULL;
		}
	} *_head;	//указатель на голову списка
	//TODO: не надо объявлять переменные сразу после объявления структуры - это усложняет структуры.
	int _count;			//количество элементов в списке
public:
	//конструктор
	List()
	{
		//TODO: лучше сделать инициализацию полей по умолчанию вместо инициализации внутри конструктора
		_head = NULL;
		_count = 0;
	}
	//получить количество элементов
	int GetCount()
	{
		return _count;
	}
	//TODO: принимать объект надо по ссылке. Потом на вопросах ответить, почему правильнее по ссылке
	//Добавить запись в конец списка
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
	//TODO: по ссылке
	//TODO: переименовать InsertAt
	//Добавить запись в конец списка
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
	//TODO: по ссылке - это избавит от лишних разыменований при работе со списком
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
	//TODO: по ссылке
	//TODO: Если объекты хранятся по значению, то почему удаление через указатель?
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
	//Очистить список
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