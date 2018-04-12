#include "stdafx.h"
#include "DemoLab7.h"
#include "List.h"
void DemoDouble()
{
	List<double> list;

	double a;
	for (int i = 0; i < 5; i++)
	{
		a = 2.4;
		list.Add(&a);
	}
	
	list.PrintList();
}