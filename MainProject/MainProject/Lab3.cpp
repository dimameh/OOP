#include "stdafx.h"
#include "Lab3.h"

using namespace std;

//Запуск меню с третьей лабораторной работой
void LaunchTask3()
{
	const int menuSize = 4;
	int choice = 0; //переменная хранящая выбор пункта меню
					//пункты меню
	string menu[menuSize] =
	{
		"",
		"1) Grand Menu",
		"2) Struct Person",
		"3) Main Menu"
	};

	while (choice != menuSize - 1)
	{
		//вывод меню на экран

		cout << "-----The third laboratory work-----" << endl << endl;

		//каждый раз после выполнения программ (заданий) обнуляется выбор пункта
		choice = ShowMenu(menu, menuSize);

		//функционал пунктов меню
		system("cls");
		switch (choice)
		{
		case 1:
			Lab3Menu();
			break;
		case 2:
			PersonTasks();
			break;
		case 3:
			cout << "Closing lab3";
			break;
		default:
			break;
		}
		system("cls");
	}
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 1

//Посчитать длину строки
void CountLengthOfString()
{
	cout << "---Counting length of string function program---" << endl << endl;

	char string[30] = { "String" };

	cout << "The string is: " << string << endl << endl;

	cout << "Length of string: " << GetLength(string);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 2

//Слияние двух строк в одну
void DemoConcatenate()
{
	cout << "---Concatenating two strings---" << endl << endl;

	char string1[6] = { "Hi, " };

	cout << "The first string is: " << string1 << endl << endl;

	char string2[10] = { "there!" };

	cout << "The second string is: " << string2 << endl << endl;

	cout << "First string plus second string: " << Concatenate(string1, string2) << endl << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 3

//Получение подстроки
void DemoGetSubsring()
{
	cout << "---Geting substrings---" << endl << endl;

	char string[14] = { "Hello, World!" };
	char* substring = new char[14];

	cout << "The string is: " << string << endl << endl;
	
	cout << "Substring [startIndex = 2], [charCount = 4]: ";
	if (GetSubstring(string, 2, 4) != NULL)
	{
		substring = GetSubstring(string, 2, 4);
		cout << substring << endl << endl;
	}
	else
	{
		cout << "NULL" << endl << endl;
	}

	cout << "Substring [startIndex = -3], [charCount = 3]: ";
	if (GetSubstring(string, -3, 3) != NULL)
	{
		substring = GetSubstring(string, -3, 3);
		cout << substring << endl << endl;
	}
	else
	{
		cout << "NULL" << endl << endl;
	}

	cout << "Substring [startIndex = 2], [charCount = -4]: ";
	if (GetSubstring(string, 2, -4) != NULL)
	{
		substring = GetSubstring(string, 2, -4);
		cout << substring << endl << endl;
	}
	else
	{
		cout << "NULL" << endl << endl;
	}

	cout << "Substring [startIndex = 7], [charCount = 8]: ";
	if (GetSubstring(string, 7, 8) != NULL)
	{
		substring = GetSubstring(string, 7, 8);
		cout << substring << endl << endl;
	}
	else
	{
		cout << "NULL" << endl << endl;
	}
	delete[] substring;
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 4

//Поиск подстроки
void FindSubstringIndex()
{
	cout << "---Finding index of substrings---" << endl << endl;

	char string1[22] = { "Lorem ipsum aset amet" };
	char string2[25] = { "Lorem ipsum aset ametsum" };

	char substring1[8] = { "ipsum a" };
	char substring2[5] = { "Arom" };
	char substring3[4] = { "sum" };

	cout << "The string 1 is: " << string1 << endl << endl;

	cout << "Index of \"" << substring1 << "\" is: ";
	cout << FindSubstring(string1, substring1) << endl << endl;

	cout << "Index of \"" << substring2 << "\" is: ";
	cout << FindSubstring(string1, substring2) << endl << endl;

	cout << "The string 2 is: " << string2 << endl << endl;

	cout << "Index of \"" << substring3 << "\" is: ";
	cout << FindSubstring(string2, substring3) << endl << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 5

//Перевести строку в верхний регистр
void DemoUppercase()
{
	cout << "---Uppercase---" << endl << endl;

	char* string = new char[54] { "Different cases in That string, also 1 and 2 numbers!" };

	cout << "The string is: " << string << endl << endl;

	cout << "Uppercase: ";
	string = MakeStringUppercase(string);
	cout << string << endl << endl;

	delete[] string;
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Перевести строку в нижний регистр
void DemoLowercase()
{
	cout << "---Lowercase---" << endl << endl;

	char* string = new char[54]{ "Different cases in That string, also 1 and 2 numbers!" };
	cout << "The string is: " << string << endl << endl;

	cout << "Lowercase: ";
	string = MakeStringLowercase(string);
	cout << string << endl << endl;

	delete[] string;
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 6

//Разбить имя файла на путь, название файла и его расширение
void DemoSplitFilename()
{
	cout << "---Split Filename---" << endl << endl;

	char strings[5][29] =
	{
		"d:\\folder\\file.exe" ,
		"d:\\folder\\subfolder\\file.exe" ,
		"d:\\folder\\subfolder\\file" ,
		"file.txt" ,
		"d:\\folder\\.exe"
	};

	char path[100];
	char name[20];
	char extension[10];
	
	for (int i = 0; i < 5; i++)
	{
		cout << "The string "<< i <<" is: " << strings[i] << endl << endl;
		SplitFilename(strings[i], path, name, extension);
		cout << "Path: " << path << endl << "Name: " << name << endl << "Extension: " << extension << endl << endl;
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 7

//Заменить табуляцию на пробелы
void DemoReplaceTabsOnSpaces()
{
	cout << "---Replacing Tabs---" << endl << endl;
	char strings[3][16] = 
	{ 
		"Cake\tis\ta lie!",
		"Cake\t\tis a lie!",
		"\tCake is \tlie!" 
	};

	char* stringRes = new char[100];

	for (int i = 0; i < 3; i++)
	{
		stringRes = ReplaceTabsOnSpaces(strings[i]);
		cout << "String "<< i << ": " << endl << endl << strings[i] << endl << "!\t!\t!\t!\t!\t!\t!\t!\t" << endl;
		cout << "Result: " << endl << "!\t!\t!\t!\t!\t!\t!\t!\t" << endl;
		cout << stringRes;
		cout << endl << "_________________________________________" << endl;
	}

	delete[] stringRes;
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 8

//заменить пробелы на табуляцию
void DemoReplaceSpacesOnTabs()
{
	cout << "---Replacing Tabs---" << endl << endl;
	char strings[4][21] =
	{
		"Cake::::is::a:lie!",
		"Cake::::is::::a:lie!",
		"Cake:is:a::::::lie!",
		"Cake:is::a:lie!" 
	};
	char* stringRes = new char[100];

	for (int i = 0; i < 4; i++)
	{
		stringRes = ReplaceSpacesOnTabs(strings[i]);
		cout << "String " << i << ": " << endl << endl << strings[i] << endl << "!\t!\t!\t!\t!\t!\t!\t!\t" << endl;
		cout << "Result: " << endl << "!\t!\t!\t!\t!\t!\t!\t!\t" << endl;
		cout << stringRes;
		cout << endl << "_________________________________________" << endl;
	}
	
	delete[] stringRes;
	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 10, 11, 12

//Заполнить данные о человеке, затем вывести их
void PersonTasks()
{
	/*cout << "---Struct \"Person\"---" << endl << endl;

	Person dima;

	dima = ReadPerson();

	cout << endl << endl << "Profile data:"<< endl;

	PrintPerson(dima);

	cout << endl << endl << "______________________________________________________" << endl;*/
	cout << "Not available in this version" << endl;

	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 9

//Меню из девятого задания третьей лабораторной работы
void Lab3Menu()
{
	const int menuSize = 11;
	int choice = 0; //переменная хранящая выбор пункта меню
					//пункты меню
	string menu[menuSize] =
	{
		"",
		"1. GetLength() ",
		"2. Concatenate() ",
		"3. GetSubstring() ",
		"4. FindSubstring() ",
		"5. Uppercase() ",
		"6. Lowercase() ",
		"7. SplitFilename() ",
		"8. ReplaceTabsOnSpaces() ",
		"9. ReplaceSpacesOnTabs() ",
		"10. Exit"
	};

	while (choice != menuSize - 1)
	{
		//вывод меню на экран

		cout << "---Program Menu---" << endl << endl;

		//каждый раз после выполнения программ (заданий) обнуляется выбор пункта
		choice = ShowMenu(menu, menuSize);

		//функционал пунктов меню
		system("cls");
		switch (choice)
		{
		case 1:
			CountLengthOfString();
			break;
		case 2:
			DemoConcatenate();
			break;
		case 3:
			DemoGetSubsring();
			break;
		case 4:
			FindSubstringIndex();
			break;
		case 5:
			DemoUppercase();///////////////
			break;
		case 6:
			DemoLowercase();//////////////////
			break;
		case 7:
			DemoSplitFilename();
			break;
		case 8:
			DemoReplaceTabsOnSpaces();
			break;
		case 9:
			DemoReplaceSpacesOnTabs();
			break;
		case 10:
			cout << "Closing program menu";
			break;
		default:
			break;
		}
		system("cls");
	}
}