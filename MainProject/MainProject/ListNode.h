#pragma once
#include "Lab3Functions.h"
struct ListNode
{
	Person data;			// ���� ������
	ListNode *next;			// ��������� �� ��������� �������
	ListNode *prev;			// ��������� �� ���������� �������
	ListNode(Person data)	// �����������
	{
		this->data = data;
		prev = next = NULL;
	}
};

