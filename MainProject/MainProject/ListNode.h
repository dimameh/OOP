#pragma once
#include "Lab3Functions.h"
//TODO: � ������ ������ ListNode ������ ���� ��������� ������� � ������ PersonList ��� ������������� private.
// ��� �����, ����� PersonList, �� ������ ��������� ���������� ListNode - � ��� ���������, ������ ��� �� ����� ������ ��� ���������� ������
struct ListNode
{
	Person* Data;			// ���� ������
	ListNode *next;			// ��������� �� ��������� �������
	ListNode(Person* data)	// �����������
	{
		Data = data;
		next = NULL;
	}
};

