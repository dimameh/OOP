#pragma once
#include "Lab3Functions.h"
struct ListNode
{
	Person data;			// поле данных
	ListNode *next;			// указатель на следующий элемент
	ListNode *prev;			// указатель на предыдущий элемент
	ListNode(Person data)	// конструктор
	{
		this->data = data;
		prev = next = NULL;
	}
};

