#pragma once
//—писок с данными структуры Person

template <typename DataType>
class List
{
private:
	struct ListNode
	{
		DataType* _data;			// поле данных
		ListNode* next;				// указатель на следующий элемент
		ListNode(DataType* data)	// конструктор
		{
			_data = data;
			next = NULL;
		}
	} *_head;	//указатель на голову списка
	int _count;			//количество элементов в списке
public:
	//конструктор класса
	List();
	//получить количество элементов
	int GetCount();
	//добавить человека в список
	void Add(DataType* data);
	//найти человека по указанному индексу
	DataType* Find(int index);
	//вернуть индекс человека, если он есть в списке
	int IndexOf(DataType* data);
	//удалить человека из списка
	void Remove(DataType* data);
	//удалить человека из списка по индексу
	void RemoveAt(int index);
	//очистить список
	void Clear();
	//¬ывод элементов списка
	void PrintList();
	//¬ывод элементов списка с выделением персоны
	void PrintList(DataType data);
	//¬ывод описани€ всех элементов списка
	void DescribeList();
};