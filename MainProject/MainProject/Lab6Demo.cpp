#include "stdafx.h"
#include "Lab6Demo.h"
#include "PersonList.h"
#include "Person.h"
#include "Adult.h"
#include "Child.h"
void Lab6Demo()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	PersonList list;
	Adult randomAdults[7];
	Person randomPersons[7];
	Child randomChildren[7];
	int randomNumber;

	for (int i = 0; i < 7; i++)
	{
		Person::MakeRandomPerson(randomPersons[i]);
	}
	for (int i = 0; i < 7; i++)
	{
		Adult::MakeRandomAdult(randomAdults[i], randomPersons[rand() % 6]);
		Child::MakeRandomChild(randomChildren[i], randomPersons[rand() % 6], randomPersons[rand() % 6]);
	}
	
	for (int i = 0; i < 7; i++)
	{	
		randomNumber = rand() % 2;
		if (randomNumber == 1)
		{
			list.Add(&randomAdults[rand() % 6]);
		}
		else
		{
			list.Add(&randomChildren[rand() % 6]);
		}
	}

	list.DescribeList();

	Person* check = list.Find(4);

	if (check->GetAge() < 18)
	{
		cout << "This is a child: ";
		Child* child = (Child*)check;
		auto* mother = child->GetMother();
		if (mother)
		{
			cout << *mother;
		}
	}
	else
	{
		cout << "This is an adult: ";
		Adult* adult = (Adult*)check;
		auto* married = adult->GetMarriedOn();
		if (married)
		{
			cout << *married;
		}
	}
	
	//Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}