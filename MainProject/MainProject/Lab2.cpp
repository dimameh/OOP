#include "stdafx.h"
#include "Lab2.h"
#include "Input.h"

using namespace std;

//Запуск меню со второй лабораторной работой
void LaunchTask2()
{
	const int menuSize = 15;
	int choice = 0; //переменная хранящая выбор пункта меню
					//пункты меню
	string menu[menuSize] = 
	{ 
		"",
		"1) 1 Task: Function, that outputing \"Something\"",
		"2) 2 Task: Function, that outputing \"Hello, World!\",announced previously",
		"3) 3 Task: Making calculations",
		"4) 4 Task: Get division",
		"5) 5 Task: The search for the roots of the quadratic equation, using pointers",
		"6) 6 Task: The search for the roots of the quadratic equation, using links",
		"7) 7 Task: Overloading of functions",
		"8) 8 Task: Global variables",
		"9) 9 Task: \"Get power\" function",
		"10) 10 Task: Random",
		"11) 11 Task: Work with array",
		"12) 12 Task: Sorting function",
		"13) 13 Task: \"Multiply Matrices\" function",
		"14) Next Lab (Lab #3)" 
	};

	while (choice != menuSize - 1)
	{
		//вывод меню на экран

		cout << "-----The second laboratory work-----" << endl << endl;

		//каждый раз после выполнения программ (заданий) обнуляется выбор пункта
		choice = ShowMenu(menu, menuSize);

		//функционал пунктов меню
		system("cls");
		switch (choice)
		{
		case 1:		
			Lab2Task1();
			break;
		case 2:
			Lab2Task2();
			break;
		case 3:
			Lab2Task3();
			break;
		case 4:
			Lab2Task4();
			break;
		case 5:
			Lab2Task5();
			break;
		case 6:
			Lab2Task6();
			break;
		case 7:
			Lab2Task7();
			break;
		case 8:
			Lab2Task8();
			break;
		case 9:
			Lab2Task9();
			break;
		case 10:
			Lab2Task10();
			break;
		case 11:
			Lab2Task11();
			break;
		case 12:
			Lab2Task12();
			break;
		case 13:
			Lab2Task13();
			break;
		case 14:
			cout << "Closing lab2";

			break;
		default:
			break;
		}
		system("cls");
	}
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 1

// Вывод слова "Something"
void PrintSomething()
{
	cout << "Something";
}

//Вывод слова "Something" через функцию
void Lab2Task1()
{
	cout << "---Print something by function---" << endl << endl;

	PrintSomething();

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}


////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 2

//Вывод "Hello, World!"
void PrintHelloWorld();

//Вывод через "Hello, World!" функцию PrintHelloWorld!"
void Lab2Task2()
{
	cout << "---Print \"Hello, World\" by function---" << endl << endl;

	PrintHelloWorld();

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

void PrintHelloWorld()
{
	std::cout << "Hello, World!";
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 3


//Производит арифметическое действие с двумя целыми числами
double MakeCalculation(int value1, int value2, char operationKey)
{
	switch (operationKey)
	{
	case '+':
		return value1 + value2;
		break;
	case '-':
		return value1 - value2;
		break;
	case '/':
		return value1 / value2;
		break;
	case '*':
		return value1 * value2;
		break;
	default:
		return value1 % value2;
		break;
	}
}

//Арифметическая операция с двумя целыми числами
void Lab2Task3()
{
	cout << "---Arithmetic operations---" << endl << endl;

	int a, b;
	a = b = 1;
	char key = '+';

	cout << "Enter the arithmetic operation like \"a + b\" with spaces). \nThere (+, -, *, /, %) are allowed:\n";
	InputInteger(a);
	cin >> key;
	InputInteger(b);

	while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
	{
		cout << "\nINCORRECT SYMBOL!!!\nPlease, enter (+, -, *, /, %):";


		key = getchar();
		fflush(stdin);
	}

	double result = MakeCalculation(a, b, key);
	cout << result;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 4

//Возвращает результат деления целого числа на целое число
int Divide(int dividend, int divisor)
{
	int result;
	result = dividend / divisor;
	return result;
}

//Деление двух целых чисел
void Lab2Task4()
{
	cout << "---Division---" << endl << endl;

	int a = 0;
	int b = 0;
	cout << "\nEnter dividend: ";
	InputInteger(a);
	cout << "\nEnter divisor: ";
	InputInteger(b);
	int result = Divide(a, b);
	cout << "\nDivision result: "<< result << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 5

//Находит количество корней квадратного уравнения и возвращает их количество
int GetRoots1(int a, int b, int c, double* x1, double* x2)
{
	if ((a == 0) && (b == 0))
	{
		return 0;
	}

	if (a == 0)
	{
		(*x1) = (-c) / b;
		return 1;
	}

	int d = b * b - 4 * a * c;
	if (d < 0)
		return 0;
	if (d == 0)
	{
		(*x1) = (-b) / (2 * a);
		return 1;
	}
	else
	{
		(*x1) = (-b + sqrt(d)) / (2 * a);
		(*x2) = (-b - sqrt(d)) / (2 * a);
		return 2;
	}
}

//Решение квадратного уравнения
void Lab2Task5()
{
	cout << "---Roots---" << endl << endl;

	double x1, x2;
	double *x1Pointer = &x1;
	double *x2Pointer = &x2;

	int result;
	int arr[3][6] = 
	{	
		1, 1, 0, 0, 0, 4,
		3, 4, 1, 0, 1, 1,
		2, 0, 2, 3, 0, 4 
	};
	for (int i = 0; i < 6; i++)
	{
		result = GetRoots1(arr[0][i], arr[1][i], arr[2][i], x1Pointer, x2Pointer);
		if (result == 2)
		{ 
			cout << result << " roots: " << x1 << " and " << x2 << "\n\n";
		}
		else
		{ 
			if (result == 1)
			{ 
				cout << result << " root: " << x1 << "\n\n";
			}
			else
			{ 
				cout << "No roots\n\n";
			}
		}
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 6

//Находит количество корней квадратного уравнения и возвращает их количество
int GetRoots2(int a, int b, int c, double& x1, double& x2)
{
	if ((a == 0) && (b == 0))
	{
		return 0;
	}

	if (a == 0)
	{
		x1 = (-c) / b;
		return 1;
	}

	int d = b * b - 4 * a * c;
	if (d < 0)
		return 0;
	if (d == 0)
	{
		x1 = (-b) / (2 * a);
		return 1;
	}
	else
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		return 2;
	}
}

//Решение квадратного уравнения
void Lab2Task6()
{
	cout << "---Roots 2---" << endl << endl;

	double x1, x2;
	int result;
	int arr[3][6] = 
	{
		1, 1, 0, 0, 0, 4,
		3, 4, 1, 0, 1, 1,
		2, 0, 2, 3, 0, 4
	};
	for (int i = 0; i < 6; i++)
	{
		result = GetRoots2(arr[0][i], arr[1][i], arr[2][i], x1, x2);
		if (result == 2)
			cout << result << " roots: " << x1 << " and " << x2 << "\n\n";
		else
			if (result == 1)
				cout << result << " root: " << x1 << "\n\n";
			else
				cout << "No roots\n\n";
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 7

//Возвращает результат сложения трех чисел
int Sum(int a, int b, int c)
{
	return a + b + c;
}

//Возвращает результат сложения двух чисел
int Sum(int a, int b)
{
	return a + b;
}

//Выполнить сложение первых двух чисел из трех, затем сумму всех трех
void Lab2Task7()
{
	cout << "---2 \"Sum\" functions---" << endl << endl;

	int a, b, c;
	cout << "Enter 3 values: ";
	InputInteger(a, b, c);

	cout << "The sum of " << a << " and " << b << ": " << Sum(a, b) << endl << endl;
	cout << "The sum of " << a << ", " << b << " and " << c << ": " << Sum(a, b, c) << endl << endl;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 8

//Глобальная переменная
int globalVariable = 23;

//globalVariable + 2
void GlobalPlusTwo()
{
	globalVariable += 2;
}

//globalVariable * 3
void GlobalMultiplyThree()
{
	globalVariable *= 3;
}

//globalVariable присваивается 1
void GlobalEqualsOne()
{
	globalVariable = 1;
}

//Производит операцию присваивания единице и арифметические операции с переменной globalVariable
//Результаты выводит на экран
void Lab2Task8()
{
	cout << "---Global variables---" << endl << endl;

	cout << "Global Variable: " << globalVariable << "\n";

	GlobalPlusTwo();
	cout << "Global Variable: " << globalVariable << "\n";

	GlobalMultiplyThree();
	cout << "Global Variable: " << globalVariable << "\n";

	GlobalEqualsOne();
	cout << "Global Variable: " << globalVariable << "\n";

	globalVariable = 5;
	cout << "Global Variable: " << globalVariable << "\n";

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 9

//Возводит число в степень
int GetPower(int base, int power)
{
	if ((power == 1) || (power == -1))
	{ 
		return base;
	}
	else
	{ 
		if (power == 0)
		{ 
			return 1;
		}
		else
		{ 
			if (power>0)
			{ 
				return base * GetPower(base, power - 1);
			}
			else
			{ 
				if (power<0)
				{ 
					return base * GetPower(base, (-1 * power) - 1);
				}
			}
		}
	}
	return NULL;
}

//Возводит введенное число в степень и выводит результат
void Lab2Task9()
{
	cout << "---Get Power---" << endl << endl;

	int value, power;
	cout << "Enter the value: ";
	InputInteger(value);
	cout << endl << endl << "Enter the power of value:";
	cin >> power;

	cout << GetPower(value, power);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 10

//Запуск игры "Угадай число"
void Lab2Task10()
{
	bool isEndOfGame = 0;
	while (!isEndOfGame)
	{
		cout << "\n---Game: Guess the Number---\n";

		int guessNumber = rand() % 10; // генерация угадываемого числа 
		int enteredNumber = -1; // вводимое пользователем число 
		int shots = 0; // количество попыток 
		int maxShots = 3;
		bool isWin = 0;
		char choice = 'n';

		cout << endl << maxShots - shots << " shots left. Enter number from 0 to 9: ";
		InputInteger(enteredNumber);
		while ((guessNumber != enteredNumber) && ((maxShots - shots) > 1))
		{
			shots++;
			if (enteredNumber < guessNumber)
				cout << "\nYour number is less!!! " << maxShots - shots << " shots left Try again!\nEnter number from 0 to 9: ";
			else
				cout << "\nYour number is bigger!!! " << maxShots - shots << " shots left Try again!\nEnter number from 0 to 9: ";
			InputInteger(enteredNumber);
		}

		if (guessNumber == enteredNumber)
			cout << "\nCorrect! You win in " << shots << "shots!\n";
		else
			cout << "\nYou lose :(\n";

		cout << "\nTry againt??? (y/n): ";
		cin >> choice;

		while (choice != 'n' && choice != 'y')
		{
			cout << "Type 'y' if you want to try again, else type 'n'";
			cin >> choice;
		}
		if (choice == 'n')
			isEndOfGame = true;
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 11

//Вывод элементов массива
void Lab2Task11()
{
	cout << "---Work with array---" << endl << endl;

	int a[4];
	double b[] = { 1.2, 4.3, 0, 1 };
	char c[2];

	a[0] = 5;

	for (int i = 0; i < 4; i++)
	{
		a[i] = i;
		cout << a[i] << ' ';
	}

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 12

//Выводит массив
void PrintArray(int arr[10])
{
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl << endl;
}

//Сортировка элементов одномерного массива выбором
void SelectSort(int *array, int size)
{
	int element;
	for (int i = 0; i < size; ++i)
	{
		int min = i;
		element = array[i];
		for (int j = i + 1; j < size; ++j) // цикл выбора наименьшего элемента
		{
			if (array[j] < element)
			{
				min = j;
				element = array[j];
			}
		}
		array[min] = array[i];
		array[i] = element; // меняем местами наименьший с a[i]
	}
	cout << "---Sorted array---\n";
	PrintArray(array);
}

//Заполняет массив случайными значениями
void RandomlyFillArray(int massiv[], int size)
{
	for (int i = 0; i < size; i++)
	{
		massiv[i] = rand() % 10;
	}
	cout << "---Randomed array---\n";
	PrintArray(massiv);
}

//Создает массив случайных целых чисел, сортирует его и выводит
void Lab2Task12()
{
	cout << "---Sorting array---" << endl << endl;

	srand(time(NULL));

	int a[10];

	RandomlyFillArray(a, 10);
	SelectSort(a, 10);

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}

////////////////////////////////////////////////////////////////////// ЗАДАНИЕ 13

//Перемножает две матрицы и присваивает ответ третьей
void MultiplyMatrices(int** matricsA, int rowsA, int colsA, int** matricsB, int rowsB, int colsB, int** resultMatrics)
{
	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < colsB; j++)
		{
			resultMatrics[i][j] = 0;
			for (int k = 0; k < colsA; k++)
			{ 
				resultMatrics[i][j] += (matricsA[i][k] * matricsB[k][j]);
			}
		}
	}
}

//Вывод двумерного массива
void PrintMatrics(int** matrics, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrics[i][j] << ' ';
		}
		cout << endl;
	}
}

//Производит перемножение заданных матриц
void Lab2Task13()
{
	cout << "---MultiplyMatrices---" << endl << endl;
	srand(time(NULL));

	int arrayRowsA, arrayRowsB, arrayColsA, arrayColsB;
	int arrayRowsResult, arrayColsResult;

	arrayColsA = 0;

	arrayRowsB = 1;

	//число столбцов первой = количеству строк второй
	while (arrayColsA != arrayRowsB)
	{
		cout << "!!!---For multiplication of matrices, it is necessary that the number of columns of the first is equal to the number of rows of the second---!!!" << endl << endl;
		cout << "Enter number of columns of first array: ";
		InputInteger(arrayColsA);
		cout << "Enter number of rows of first array: ";
		InputInteger(arrayRowsA);
		cout << "Enter number of columns of second array: ";
		InputInteger(arrayColsB);
		cout << "Enter number of rows of second array: ";
		InputInteger(arrayRowsB);
	}

	arrayRowsResult = arrayRowsA;
	arrayColsResult = arrayColsB;

	//Инициализация
	int** arrayA = new int*[arrayRowsA];
	for (int i = 0; i < arrayRowsA; i++)
		arrayA[i] = new int[arrayColsA];

	int** arrayB = new int*[arrayRowsB];
	for (int i = 0; i < arrayRowsB; i++)
		arrayB[i] = new int[arrayColsB];

	int** arrayResult = new int*[arrayRowsResult];
	for (int i = 0; i < arrayRowsResult; i++)
		arrayResult[i] = new int[arrayColsResult];

	//Заполнение
	for (int i = 0; i < arrayRowsA; i++)
		for (int j = 0; j < arrayColsA; j++)
			arrayA[i][j] = rand() % 10;

	for (int i = 0; i < arrayRowsB; i++)
		for (int j = 0; j < arrayColsB; j++)
			arrayB[i][j] = rand() % 10;

	//Умножение
	MultiplyMatrices(arrayA, arrayRowsA, arrayColsA, arrayB, arrayRowsB, arrayColsB, arrayResult);

	cout << "First matrics:" << endl;
	PrintMatrics(arrayA, arrayColsA, arrayRowsA);
	cout << endl << "____________________________" << endl;
	cout << "Second matrics:" << endl;
	PrintMatrics(arrayB, arrayColsB, arrayRowsB);
	cout << endl << "____________________________" << endl;
	cout << "Result matrics:" << endl;
	PrintMatrics(arrayResult, arrayColsResult, arrayRowsResult);

	//Очистка памяти
	for (int i = 0; i < arrayRowsA; i++)
		delete[] arrayA[i];
	for (int i = 0; i < arrayRowsB; i++)
		delete[] arrayB[i];
	for (int i = 0; i < arrayRowsResult; i++)
		delete[] arrayResult[i];

	delete[] arrayA, arrayB, arrayResult;

	cout << endl << endl << "______________________________________________________" << endl;
	cout << "---the program is complete---" << endl;
	system("pause");
}




