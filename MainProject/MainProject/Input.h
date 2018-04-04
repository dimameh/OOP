#pragma once
//Валидация ввода положительного числа
int InputInteger();
//Валидация ввода положительного числа, лежащего на заданном интервале
int InputIntegerOnInterval(int min, int max);
//Валидация ввода имен собственных
//void InputName(char* string);
//Вывод меню
int ShowMenu(std::string menu[], int menuSize);