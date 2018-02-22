#include "stdafx.h"
#include "Lab3.h"

using namespace std;

int LaunchTask3()
{
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 1

int Lab3Task1()
{
	cout << "---Counting length of string function program---" << endl << endl;

	char string[30] = { "String" };

	cout << "The string is: " << string << endl << endl;

	cout << "Length of string: " << GetLength(string);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 2

int Lab3Task2()
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
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 3

int Lab3Task3()
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
	else cout << "NULL" << endl << endl;

	cout << "Substring [startIndex = -3], [charCount = 3]: ";
	if (GetSubstring(string, -3, 3) != NULL)
	{
		substring = GetSubstring(string, -3, 3);
		cout << substring << endl << endl;
	}
	else cout << "NULL" << endl << endl;

	cout << "Substring [startIndex = 2], [charCount = -4]: ";
	if (GetSubstring(string, 2, -4) != NULL)
	{
		substring = GetSubstring(string, 2, -4);
		cout << substring << endl << endl;
	}
	else cout << "NULL" << endl << endl;

	cout << "Substring [startIndex = 7], [charCount = 8]: ";
	if (GetSubstring(string, 7, 8) != NULL)
	{
		substring = GetSubstring(string, 7, 8);
		cout << substring << endl << endl;
	}
	else cout << "NULL" << endl << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 4

int Lab3Task4()
{
	cout << "---Finding index of substrings---" << endl << endl;

	char string1[22] = { "Lorem ipsum aset amet" };
	char string2[25] = { "Lorem ipsum aset ametsum" };

	char substring1[8] = { "ipsum a" };
	char substring2[5] = { "Arom" };
	char substring3[4] = { "sum" };



	cout << "The string 1 is: " << string1 << endl << endl;

	cout << "Index of " << substring1 << "is: " << FindSubstring(string1, substring1) << endl << endl;
	cout << "Index of " << substring2 << "is: " << FindSubstring(string1, substring2) << endl << endl;

	cout << "The string 2 is: " << string2 << endl << endl;

	cout << "Index of " << substring3 << "is: " << FindSubstring(string2, substring3) << endl << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 5

int Lab3Task5()
{
	cout << "---Uppercase/Lowercase---" << endl << endl;


	char string[54] = { "Different cases in That string, also 1 and 2 numbers!" };
	char string2[54] = { "Different cases in That string, also 1 and 2 numbers!" };
	cout << "The string is: " << string << endl << endl;

	cout << "Uppercase: ";
	Uppercase(string);
	cout << string << endl << endl;


	cout << "Lowercase: ";
	Lowercase(string2);
	cout << string2 << endl << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 6

int Lab3Task6()
{
	cout << "---Split Filename---" << endl << endl;


	char string1[] = { "d:\\folder\\file.exe" };
	char string2[] = { "d:\\folder\\subfolder\\file.exe" };
	char string3[] = { "d:\\folder\\subfolder\\file" };
	char string4[] = { "file.txt" };
	char string5[] = { "d:\\folder\\.exe" };

	char path[100];
	char name[20];
	char extension[10];

	cout << "The string 1 is: " << string1 << endl << endl;
	SplitFilename(string1, path, name, extension);
	cout << "Path: " << path << endl << "Name: " << name << endl << "Extension: " << extension << endl << endl;

	cout << "The string 2 is: " << string2 << endl << endl;
	SplitFilename(string2, path, name, extension);
	cout << "Path: " << path << endl << "Name: " << name << endl << "Extension: " << extension << endl << endl;

	cout << "The string 3 is: " << string3 << endl << endl;
	SplitFilename(string3, path, name, extension);
	cout << "Path: " << path << endl << "Name: " << name << endl << "Extension: " << extension << endl << endl;

	cout << "The string 4 is: " << string4 << endl << endl;
	SplitFilename(string4, path, name, extension);
	cout << "Path: " << path << endl << "Name: " << name << endl << "Extension: " << extension << endl << endl;

	cout << "The string 5 is: " << string5 << endl << endl;
	SplitFilename(string5, path, name, extension);
	cout << "Path: " << path << endl << "Name: " << name << endl << "Extension: " << extension << endl << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 7

int Lab3Task7()
{
	cout << "---Replacing Tabs---" << endl << endl;


	char string1[25] = { "Cake\tis\ta lie!" };
	char string2[25] = { "Cake\t\tis a lie!" };
	char string3[25] = { "\tCake is \tlie!" };
	char* stringRes = new char[100];
	stringRes = ReplaceTabsOnSpaces(string1);
	cout << "String 1: " << endl << endl << string1 << endl << endl;
	cout << "Result: " << endl << endl;
	cout << stringRes;
	cout << endl << "_________________________________________" << endl;
	stringRes = ReplaceTabsOnSpaces(string2);
	cout << "String 2: " << endl << endl << string2 << endl << endl;
	cout << "Result: " << endl << endl;
	cout << stringRes;
	cout << endl << "_________________________________________" << endl;
	stringRes = ReplaceTabsOnSpaces(string3);
	cout << "String 3: " << endl << endl << string3 << endl << endl;
	cout << "Result: " << endl << endl;
	cout << stringRes;
	cout << endl << "_________________________________________" << endl;



	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
	return 0;
}

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 8

int Lab3Task8();

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 9

int Lab3Task9();

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 10

int Lab3Task10();

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 11

int Lab3Task11();

////////////////////////////////////////////////////////////////////// ÇÀÄÀÍÈÅ 12

int Lab3Task12();




