#include "stdafx.h"
#include "List.h"
using namespace std;

//�����������
template <typename DataType>
List<DataType>::List()
{
	_head = NULL;
	_count = 0;
}
//�������� ���������� ���������
template <typename DataType>
int List<DataType>::GetCount()
{
	return _count;
}
//�������� ������ � ����� ������
template <typename DataType>
void List<DataType>::Add(DataType* data)
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
		while (nodeIndex->next)
		{
			nodeIndex = nodeIndex->next;
		}
		nodeIndex->next = temp;
	}
	_count++;
}
//����� �������� �� ���������� �������
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
//������� ������ ��������, ���� �� ���� � ������
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
//������� �������� �� ������
template <typename DataType>
void List<DataType>::Remove(DataType* data)
{
	//���� ������ ������� � ������
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
//������� �������� �� ������ �� �������
template <typename DataType>
void List<DataType>::RemoveAt(int index)
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
		if (_head->next == NULL)
		{
			delete _head;
			_head = NULL;
		}
		//���� ��������� � ������ ������ ������
		else
		{
			ListNode* temp = _head;
			_head = _head->next;
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
				ListNode* temp = nodeIndex->next;
				nodeIndex->next = nodeIndex->next->next;
				delete temp;
			}
			nodeIndex = nodeIndex->next;
			current++;
		}
		//���� ������ �� ����� � ������ �� ������ �� ��� ������ -> �������� � �������
		exception noData("Index error. There is no index like this.");
		throw noData;
	}
	_count--;
}
//�������� ������
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
//����� ��������� ������
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
//����� ��������� ������ � ���������� �������
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
		//��������� ��������� ������� � ������-�������
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		if (count == index)
		{
			//��������� ��������� ������� � �������
			SetConsoleTextAttribute(hConsole, (WORD)(3));
		}
		cout << nodeIndex->_data;
		//��������� ��������� ������� � ������-�������
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
		count++;
	}
}
//����� �������� ���� ��������� ������
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