#include "stdafx.h"
#include "Lab1.h"
#include "Input.h"
using namespace std;


//Запуск меню с первой лабораторной работой
void LaunchTask1()
{
	const int menuSize = 14;
	int choice = 0; //переменная хранящая выбор пункта меню
	//пункты меню
	string menu[menuSize] = 
	{ 
		"",
		"1) 2 Task: \"Hello, World\" program",
		"2) 3 Task: Initialization and output of sum of numbers",
		"3) 4 Task: Divisions of float and integer values",
		"4) 5 Task: Input 2 numbers, then output their sum",
		"5) 6 Task: Pointer's work demonstration",
		"6) 7 Task: Check value on even/odd",
		"7) 8 Task: Check for multiplicity of two and five",
		"8) 9 Task: Cycle with precondition",
		"9) 10 Task: Cycle with Postcondition",
		"10) 11 Task: Demonstration of the iteration cycle",
		"11) 12 Task: \"Breaking\" program (Demonstrating break instruction)",
		"12) 13 Task: Type conversion",
		"13) Next Lab (Lab #2)" 
	};
	

	while (choice != menuSize-1)
	{
		//вывод меню на экран

		cout << "-----The first laboratory work-----" << endl << endl;

		choice = ShowMenu(menu, menuSize);
		system("cls");
		//функционал пунктов меню
		switch (choice)
		{
		case 1:
			Lab1Task2();
			break;
		case 2:
			Lab1Task3();
			break;
		case 3:
			Lab1Task4();
			break;
		case 4:
			Lab1Task5();
			break;
		case 5:
			Lab1Task6();
			break;
		case 6:
			Lab1Task7();
			break;
		case 7:
			Lab1Task8();
			break;
		case 8:
			Lab1Task9();
			break;
		case 9:
			Lab1Task10();
			break;
		case 10:
			Lab1Task11();
			break;
		case 11:
			Lab1Task12();
			break;
		case 12:
			Lab1Task13();
			break;
		case 13:
			cout << "Closing lab1";
			break;
		default: 
			break;
		}
		system("cls");
	}
}

//Вывод фразы "Hello, World"
void Lab1Task2()
{
	cout << "---\"Hello, World\" program---" << endl << endl;

	cout << "Hello,World!\n";

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Вывод суммы двух переменных
void Lab1Task3()
{
	cout << "---Sum of 2 variables---" << endl << endl;

	int a, b;
	a = b = 2;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "a + b = " << a + b << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Вывод на экран деления двух переменных float и integer
void Lab1Task4()
{
	cout << "---Result of division---" << endl << endl;
	int a, b;
	float a1, b1;

	a = 5;
	b = 3;

	a1 = 5.0;
	b1 = 3.0;

	cout << "Float: " << a1 / b1 << endl;
	cout << "Integer: " << 5 / 3 << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Ввод двух чисел, вывод их суммы
void Lab1Task5()
{
	int a; int b;

	cout << "---Program for integer summation---" << endl << endl;

	cout << "\n\n Enter first integer value: ";
	InputInteger(a);
	cout << " Enter second integer value: ";
	InputInteger(b);

	cout << " \n Summ of " << a << " and " << b << " equals " << a + b;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Демонстрация работы указателей
void Lab1Task6()
{
	cout << "---Pointers---" << endl << endl;

	int value = 5;
	int* pointer = &value;
	int intPointer = *pointer;
	cout << "Value, stored in pointer: " << intPointer << endl; // Вывод адреса, который хранится в указателе
	cout << "Address in pointer: " << pointer << endl; // Вывод результата разыменования указателя 
	cout << "Value in pointer: " << *pointer << endl; //Вывод значения в указателе

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Проверка числа на четность/нечетность
void Lab1Task7()
{
	int value;

	cout << "---Checking value on even/odd---" << endl << endl;

	cout << "Enter value for check on even/odd: ";

	InputInteger(value);

	if (value % 2 == 0)
	{
		cout << "\n Value " << value << "is even! \n";
	}
	else
	{
		cout << "\n Value " << value << " is odd! \n";
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Проверка делимости на 2 и 5
void Lab1Task8()
{
	cout << "---Checking multiply on 2 or/and 5---" << endl << endl;
	int value;
	cout << "Enter value for check on multiply: ";
	InputInteger(value);

	if (value % 5 == 0)
	{
		cout << "\n Value " << value << "multiples 5! \n";
	}
	if (value % 2 == 0)
	{
		cout << "\n Value " << value << "multiples 2! \n";
	}
	else
	{
		cout << "\n Value " << value << "doesn`t multiply 5 or 2!  \n";
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

// Демонстрация работы цикла с предусловием
void Lab1Task9()
{
	cout << "---Demonstation cycle with precondition---" << endl << endl;

	int a = 0;
	while (a != 12)
	{
		cout << "WOW! Now value is " << a <<"! SUPER COOL!\n";
		a++;
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

// Демонстрация работы цикла с постусловием
void Lab1Task10()
{
	cout << "---Demonstation cycle with postcondition---" << endl << endl;
	int a = 13;

	do
	{
		if (a % 2 == 0)
			cout << "Rofl, now value is " << a << endl;
		else cout << "Value is " << a << " now\n";
		a--;
	} while (a != -1);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Демонстрация работы цикла "for"
void Lab1Task11()
{
	cout << "---Counting to 10---" << endl << endl;
	for (int i = 1; i <= 10; i++)
	{
		cout << i << endl;
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Демонстрация работы оператора "break"
void Lab1Task12()
{
	int value = 12;
	cout << "---Demonstrating \"break\"---" << endl << endl;
	while (1)
	{
		if (value != 16)
		{
			cout << "It will end on 15. Now it's " << value << endl;
			value++;
		}
		else break;
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

//Преобразования типов
void Lab1Task13()
{
	cout << "---Type conversion---" << endl << endl;

	int a = 5; int b = 3; float z;


	// Неявное приведение типов 
	z = a;
	cout << "Value of z is " << z << endl;


	// Ошибка - невозможное приведение типов! 
	//---------Ошибки нет---------
	// переменной "а" всегда присваивается значение округленное в меньшую сторону
	++z = ++z / 2 + 0.4;
	a = z;
	cout << "Value of a is " << a << endl;

	// Явное приведение типов 
	a = (int)z;
	cout << "Value of a is " << a << endl;
	// Неявное приведение результата деления 
	// целочисленных переменных 
	z = a / b;
	cout << "Value of z is " << z << endl;
	// Явное приведение а к float и неявное b к float
	// для выполнения деления 
	z = ((float)a) / b;
	cout << "Value of z is " << z << endl;

	//к слову о приведениях типов, можно присвоить код ASCI символа к численной переменной 
	char c = 'p';
	a = c;
	cout << "Value of a is " << a << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}
