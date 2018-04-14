#pragma once
//������ � ������� ��������� Person
using namespace std;
template <typename DataType>
class List
{
private:
	struct ListNode
	{
		DataType _data;			// ���� ������
		ListNode* _next;				// ��������� �� ��������� �������
		ListNode(DataType data)	// �����������
		{
			_data = data;
			_next = NULL;
		}
	} *_head;	//��������� �� ������ ������
	int _count;			//���������� ��������� � ������
public:
	//�����������
	List()
	{
		_head = NULL;
		_count = 0;
	}
	//�������� ���������� ���������
	int GetCount()
	{
		return _count;
	}
	//�������� ������ � ����� ������
	void Add(DataType data)
	{
		if (_head == NULL)
		{
			_head = new ListNode(data);
		}
		//���� � ������ ��� ���� ��������
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
	//�������� ������ � ����� ������
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
	//����� �������� �� ���������� �������
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
	//������� ������ ��������, ���� �� ���� � ������
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
	//������� �������� �� ������
	void Remove(DataType* data)
	{
		//���� ������ ������� � ������
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
	//������� �������� �� ������ �� �������
	void RemoveAt(int index)
	{
		//�������� �������
		//���� ������ ������ ���� ��� ������ ���������� ������� � ������ -> �������� � �������
		if (index <= 0 || index > _count)
		{
			exception indexExeption("The index is not in range.");
			throw indexExeption;
		}
		//���� ������ ������ -> �������� � �������
		if (_head == NULL)
		{
			exception emptyExeption("The list is empty.");
			throw emptyExeption;
		}
		//���� ������ �������� ��������� ��������� -> ������� ���� ��������� � �������������� ��������� _head
		if (index == _count)
		{
			//���� ������� ������������ � ������
			if (_head->_next == NULL)
			{
				delete _head;
				_head = NULL;
			}
			//���� ��������� � ������ ������ ������
			else
			{
				ListNode* temp = _head;
				_head = _head->_next;
				delete temp;
			}
		}
		//���� ������ ���������� � �� �� ������ � �� ���������
		else
		{
  			ListNode* nodeIndex = _head;
			int current = 1;
			//���� �� ����� ������ ��������� �� ���� � ������ ���������
			while (nodeIndex != NULL)
			{
				//���� ������� ��������� ����� ������� �������� -> ���������� �������� ����
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
	//�������� ������
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