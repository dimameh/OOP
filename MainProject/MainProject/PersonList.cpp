#include "stdafx.h"
#include "PersonList.h"
#include "PersonTools.h"
using namespace std;

//�����������
PersonList::PersonList()
{
	_head = NULL;
	_count = 0;
}
//�������� ���������� ���������
int PersonList::GetCount()
{
	return _count;
}
//�������� ������ � ����� ������
void PersonList::Add(Person* person)
{
	if (_head == NULL)
	{
		_head = new ListNode(person);
	}
	//���� � ������ ��� ���� ��������
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
//����� �������� �� ���������� �������
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
//������� ������ ��������, ���� �� ���� � ������
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
//������� �������� �� ������
void PersonList::Remove(Person* person)
{
	//���� ������ ������� � ������
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
//������� �������� �� ������ �� �������
void PersonList::RemoveAt(int index)
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
		exception noPerson("Index error. There is no index like this.");
		throw noPerson;
	}
	_count--;
}
//�������� ������
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
//����� ��������� ������
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
//����� ��������� ������ � ���������� �������
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
		//��������� ��������� ������� � ������-�������
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		if (count == index)
		{
			//��������� ��������� ������� � �������
			SetConsoleTextAttribute(hConsole, (WORD)(3));
		}
		cout << *nodeIndex->_data;
		//��������� ��������� ������� � ������-�������
		SetConsoleTextAttribute(hConsole, (WORD)(10));
		cout << "-------------------------" << endl;
		nodeIndex = nodeIndex->next;
		count++;
	}
}
//����� �������� ���� ��������� ������
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