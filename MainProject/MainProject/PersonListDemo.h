#pragma once
#include "PersonList.h"
//Запуск меню четвертой лабораторной работы
void LaunchTask4();
//Демонстрация работы функции Add
void DemoAddFunction();
//Демонстрация работы функции Get
void DemoGetFunction();
//Демонстрация работы функции Remove
void DemoRemoveFunction();
//Демонстрация работы функции Insert
void DemoInsertFunction();
//Демонстрация работы функции Clear
void DemoClearFunction();
//Добавить в список указанное количество случайных людей
void AddRandomPersons(int count, PersonList *&list);