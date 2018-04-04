#pragma once
#include "Lab3Functions.h"
//TODO: В данном случае ListNode должен быть ВЛОЖЕННЫМ классом в классе PersonList под модификатором private.
// Так никто, кроме PersonList, не сможет создавать экземпляры ListNode - и это правильно, потому что он нужен только для реализации списка
struct ListNode
{
	Person* Data;			// поле данных
	ListNode *next;			// указатель на следующий элемент
	ListNode(Person* data)	// конструктор
	{
		Data = data;
		next = NULL;
	}
};

