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

	LaunchTask1();	//Запуск Лабораторной работы №1
	
	LaunchTask2();	//Запуск Лабораторной работы №2

	LaunchTask3();	//Запуск Лабораторной работы №3

	LaunchTask4();		//Запуск Лабораторной работы №4
	
    return 0;
}

