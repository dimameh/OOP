// MainProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Input.h"

using namespace std;

int main()
{
	srand(time(NULL));
	//TODO: Может, имеет смысл уже добавить менюшку для выбора лабораторной?
	//TODO: Не надо пустые строки
	LaunchTask1();	//Запуск Лабораторной работы №1
					//TODO: Не надо пустые строки
	LaunchTask2();	//Запуск Лабораторной работы №2
					//TODO: Не надо пустые строки
	LaunchTask3();	//Запуск Лабораторной работы №3
					//TODO: Не надо пустые строки
	LaunchTask4();		//Запуск Лабораторной работы №4
						//TODO: Не надо пустые строки
    return 0;
}

