#pragma once
#include "Lab3Functions.h"
struct ListNode
{
	Person Data;			// поле данных
	ListNode *next;			// указатель на следующий элемент
	ListNode(Person data)	// конструктор
	{
		Data = data;
		next = NULL;
	}
};

