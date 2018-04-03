#include "stdafx.h"
#include "ClassDemo.h"
#include "PersonList.h"
#include "PersonInstruments.h"
//Демонстрация работы класса PersonList
void ClassDemo()
{
	//Раскраска элементов консоли в голубой
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(3));
	cout << "---PersonList class---" << endl << endl;
	/*---------------------ДОБАВЛЕНИЕ 3 ЧЕЛОВЕК В КАЖДЫЙ СПИСОК---------------------*/
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	PersonList list1, list2;
	Person randomPerson;
	for (int i = 0; i < 3; i++)
	{
		MakeRandomPerson(randomPerson);
		list1.Add(randomPerson);
		MakeRandomPerson(randomPerson);
		list2.Add(randomPerson);
	}
	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << "3 people were added to each list." << endl << endl;
	system("pause");
	/*---------------------ВЫВОД ДВУХ СПИСКОВ - 1---------------------*/
	cout << endl << endl << "List output: " << endl << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	cout << "________________LIST 1________________" << endl;
	list1.PrintList();
	cout << "________________LIST 2________________" << endl;
	list2.PrintList();
	system("pause");
	/*---------------------ДОБАВЛЕНИЕ В ПЕРВЫЙ СПИСОК ОДНОГО ЧЕЛОВЕКА---------------------*/
	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Adding new person at list 1..." << endl << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	MakeRandomPerson(randomPerson);
	list1.Add(randomPerson);
	system("pause");
	/*---------------------ВЫВОД ДВУХ СПИСКОВ - 2---------------------*/
	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Second person from list 1 copies to list 2" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));

	randomPerson = list1.Find(2);
	list2.Add(randomPerson);
	cout << "________________LIST 1________________" << endl;
	list1.PrintList(randomPerson);
	cout << "________________LIST 2________________" << endl;
	list2.PrintList(randomPerson);
	system("pause");
	/*---------------------УДАЛЕНИЕ ЭЛЕМЕНТА ИЗ ПЕРВОГО СПИСКА И ВЫВОД ДВУХ СПИСКОВ - 3---------------------*/
	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Deleting this person from list 1" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));


	list1.Remove(randomPerson);
	cout << "________________LIST 1________________" << endl;
	list1.PrintList();
	cout << "________________LIST 2________________" << endl;
	list2.PrintList(randomPerson);
	system("pause");


	/*---------------------ОЧИСТКА ВТОРОГО СПИСКА---------------------*/
	list2.Clear();
	//Раскраска элементов консоли в белый
	SetConsoleTextAttribute(hConsole, (WORD)(7));
	cout << endl << endl << "Now, list 2 is cleared" << endl;

	//Раскраска элементов консоли в красный
	SetConsoleTextAttribute(hConsole, (WORD)(4));
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	//Раскраска элементов консоли в светло-зеленый
	SetConsoleTextAttribute(hConsole, (WORD)(10));
	system("pause");
}
