#pragma once
#include "Lab3Functions.h"
//TODO: ������������ ��������!
//TODO: � ������ ������ ListNode ������ ���� ��������� ������� � ������ PersonList ��� ������������� private.
// ��� �����, ����� PersonList, �� ������ ��������� ���������� ListNode - � ��� ���������, ������ ��� �� ����� ������ ��� ���������� ������
struct ListNode
{
	//TODO: ��������� ���������� ����� �� RSDN
	Person* Data;			// ���� ������
	ListNode *next;			// ��������� �� ��������� �������
	ListNode(Person* data)	// �����������
	{
		Data = data;
		next = NULL;
	}
};

