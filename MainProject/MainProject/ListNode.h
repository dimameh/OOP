#pragma once
#include "Lab3Functions.h"
struct ListNode
{
	Person Data;			// ���� ������
	ListNode *next;			// ��������� �� ��������� �������
	ListNode(Person data)	// �����������
	{
		Data = data;
		next = NULL;
	}
};

